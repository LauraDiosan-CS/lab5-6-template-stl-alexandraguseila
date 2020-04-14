#include "Service.h"


Service::Service(const RepoSTL<Product>& repoP, const RepoSTL<Monede>& repoM)
{
	this->repoProduct = repoP;
	this->repoMonede = repoM;
}


Service::Service(const Service& s)
{
	this->repoProduct = s.repoProduct;
}

void Service::initializeMap()
{
    for(int i=0;i<repoMonede.get_size();i++)
        bancnote[repoMonede.show_elements()[i].getValue()] = repoMonede.show_elements()[i].getNumber();
}

void Service::addProduct(int cod, const char* name, int price)
{
	this->repoProduct.add_element(Product(cod, name, price));
}


void Service::deleteProduct(int cod)
{
	for (int i = 0; i < this->repoProduct.get_size(); i++)
	{
		if (this->repoProduct.show_elements()[i].getCod() == cod)
		{
			Product productToDelete(this->repoProduct.show_elements()[i].getCod(), this->repoProduct.show_elements()[i].getName(), this->repoProduct.show_elements()[i].getPrice());
			this->repoProduct.del_element(productToDelete);
			return;
		}
	}
}


void Service::updateProduct(int oldCod, int newCod, const char* newName, int newPrice)
{
	vector<Product> products = this->repoProduct.show_elements();
	Product newProduct(newCod, newName, newPrice);
	for (int i = 0; i < this->repoProduct.get_size(); i++)
	{
		if (products[i].getCod() == oldCod)
		{
			Product oldProduct(products[i].getCod(), products[i].getName(), products[i].getPrice());
			this->repoProduct.update_element(oldProduct, newProduct);
			return;
		}
	}
}


vector<Product> Service::getALLProducts()
{
	return this->repoProduct.show_elements();
}


int Service::getSizeProducts()
{
   return repoProduct.get_size();
}


Product Service::getProductByPos(int pos)
{
	return this->repoProduct.get_element(pos);
}


int Service::getProductPriceByCod(int cod)
{
	for (int i = 0; i < this->repoProduct.get_size(); i++)
		if (this->repoProduct.show_elements()[i].getCod() == cod)
			return this->repoProduct.show_elements()[i].getPrice();
	return 0;
}




void Service::addMonede(int number, int value)
{
    for(int i=0;i<repoMonede.get_size();i++)
    {
        if(this->repoMonede.show_elements()[i].getValue() == value)
        {
            int nr = this->repoMonede.show_elements()[i].getNumber();
            Monede m(this->repoMonede.show_elements()[i]);
            m.setNumber(nr + number);
            this->repoMonede.update_element(this->repoMonede.show_elements()[i], m);
            bancnote[value] = nr + number;
            return;
        }
    }
    repoMonede.add_element(Monede(number, value));
    bancnote[value] = number;
    return;

}


void Service::deleteMonede(int value)
{
    /*for(int i=0; i<repoMonede.get_size();i++)
        if(repoMonede.get_element(i).getValue() == value)
            repoMonede.get_element(i).setNumber(repoMonede.get_element(i).getNumber() - 1);*/
    initializeMap();
    for(int i=0;i<this->repoMonede.get_size();i++)
    {
        if(this->repoMonede.show_elements()[i].getValue() == value)
        {
            int number = this->repoMonede.show_elements()[i].getNumber() - 1;
            if(number > 0)
            {
                Monede m(this->repoMonede.show_elements()[i]);
                m.setNumber(number );
                this->repoMonede.update_element(this->repoMonede.show_elements()[i], m);
                bancnote[value]--;
            }
            else
            {
                this->repoMonede.del_element(this->repoMonede.show_elements()[i]);
                bancnote[value]=0;
            }

            return;
        }
    }
}


void Service::updateMonede(int oldValue, int newValue, int newNumber)
{
    Monede newMoneda(newNumber, newValue);
    for(int i=0;i<repoMonede.get_size();i++)
        if(repoMonede.get_element(i).getValue() == oldValue)
        {
            if(oldValue == newValue)
                {
                    repoMonede.update_element(repoMonede.show_elements()[i], newMoneda);
                    bancnote[oldValue] = newNumber;
                }
            else
                {
                    this->addMonede(newNumber, newValue);
                    int oldNumber = repoMonede.get_element(i).getNumber();
                    while(oldNumber > 0)
                    {
                        this->deleteMonede(oldValue);
                        oldNumber--;
                    }
                }
        }

}


vector<Monede> Service::getALLMonede()
{
    return repoMonede.show_elements();
}


int Service::getSizeMonede()
{
    return repoMonede.get_size();
}


int Service::getTotalSum()
{
    int sum = 0;
    for(int i=0;i<repoMonede.get_size();i++)
    {
        int value = repoMonede.get_element(i).getValue();
        int number = repoMonede.get_element(i).getNumber();
        sum+=number*value;
    }
    return sum;
}


int Service::giveRest(int sum, int price, int &oneRon,int &fiveRon,int &tenRon,int &fiftyRon,int &hundredRon)
{
    int rest = sum - price;
    if(rest == 0)
        return 0;
    if(rest < 0)
        return -1;

    this->separeRest(rest, oneRon, fiveRon, tenRon, fiftyRon, hundredRon);
    if((hundredRon > bancnote[100]) || (fiftyRon > bancnote[50]) || (tenRon > bancnote[10]) || (fiveRon > bancnote[5])
        || (oneRon > bancnote[1]))
        return -2;

    bancnote[100] = bancnote[100] - hundredRon;
    bancnote[50] -= fiftyRon;
    bancnote[10] -= tenRon;
    bancnote[5] -= fiveRon;
    bancnote[1] -= oneRon;

    for(int i=0; i<repoMonede.get_size(); i++)
        if(repoMonede.show_elements()[i].getNumber() != bancnote[repoMonede.show_elements()[i].getValue()])
        {
            Monede m(bancnote[repoMonede.show_elements()[i].getValue()], repoMonede.show_elements()[i].getValue());
            repoMonede.update_element( repoMonede.show_elements()[i], m);
        }

    return 1;


}


void Service::separeRest(int rest, int& oneRon, int& fiveRon, int &tenRon, int &fiftyRon, int &hundredRon)
{
    oneRon = 0;
    fiveRon = 0;
    tenRon = 0;
    fiftyRon = 0;
    hundredRon = 0;
    while (rest!=0)
    {
        oneRon++;
        if(oneRon == 5)
        {
            fiveRon++;
            oneRon = 0;
        }
        if(fiveRon == 2)
        {
            tenRon++;
            fiveRon = 0;
        }
        if(tenRon == 5)
        {
            fiftyRon++;
            tenRon = 0;
        }
        if(fiftyRon == 2)
        {
            hundredRon++;
            fiftyRon = 0;
        }
        rest --;
    }

}


int Service::buyProduct(int cod, int sum, int& oneRon, int& fiveRon, int &tenRon, int &fiftyRon, int &hundredRon)
{
    for(int i=0; i<repoProduct.get_size(); i++)
        if(repoProduct.show_elements()[i].getCod() == cod)
        {
            int price = repoProduct.show_elements()[i].getPrice();
            return this->giveRest(sum, price, oneRon, fiveRon,tenRon, fiftyRon, hundredRon);
        }
    return 2;
}


