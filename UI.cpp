#include "UI.h"

UI::UI(){}


UI::~UI(){}


void UI::show(vector<Product> v)
{
    for(int i=0;i<v.size();i++)
        cout<<v[i];
    cout<<endl;
}

void UI::addProduct()
{
    int cod, price;
    char* name = new char[20];
    cout<<"Dati codul:";
    cin>>cod;
    cout<<"Dati numele:";
    cin>>name;
    cout<<"Dati pretul:";
    cin>>price;
    s.addProduct(cod, name, price);
    cout<<"Produsul a fost adaugat!"<<endl;
}

void UI::delProduct()
{
    Product p;
    int cod;
    cout<<"Dati codul produsului care trebuie sters:";
    cin>>cod;
    s.deleteProduct(cod);
    cout<<"Produsul a fost sters :)"<<endl;
    //if(reusit == 0)
    //    cout<<"Produsul a  fost sters :)"<<endl;
    //else
    //    cout<<"Produsul nu a fost sters!"<<endl;
}

void UI::updateProduct()
{
    int cod, newCod, newPrice;
    char* newName = new char[20];
    cout<<"Dati codul produsului care trebuie actualizat:";
    cin>>cod;
    //int poz = s.findPozElem(e1);
    //if(poz != -1 )
    //{
    cout<<"Dati datele noului produs:";
    cout<<"Noul cod:";cin>>newCod;
    cout<<"Noul nume:";cin>>newName;
    cout<<"Noul pret:";cin>>newPrice;
    s.updateProduct(cod, newCod, newName, newPrice);
    cout<<"Produsul a fost actualizat :)"<<endl;

    //}
    //else
    //    cout<<"Produsul nu exista!"<<endl;

}

void UI::showAllProducts()
{
    this->show(s.getALLProducts());
}


void UI::getSizeProducts()
{
    cout<<"Tonomatul contine "<<s.getALLProducts().size()<<" produse"<<endl;

}

void UI::addMonede()
{
    int number, value;
    cout<<"Dati valoarea bancnotei:";cin>>value;
    cout<<"Dati numarul de astfel de bancnote:";cin>>number;
    s.addMonede(number, value);
}

void UI::deleteMonede()
{
    int value;
    cout<<"Dati valoarea bancnotei de eliminat:";
    cin>>value;
    s.deleteMonede(value);
    cout<<"Bancnota stearsa!";
    cout<<endl;
}

void UI::updateMonede()
{
    int newValue, newNumber, oldValue;
    cout<<"Dati valoarea bancnotei de actualizat:";
    cin>>oldValue;
    cout<<"Dati noua valoare:";
    cin>>newValue;
    cout<<"Dati numarul de astfel de bancnote:";
    cin>>newNumber;
    s.updateMonede(oldValue, newValue, newNumber);
}

void UI::showAllMonede()
{
    for(int i=0; i<s.getSizeMonede();i++)
        cout<<s.getALLMonede()[i];
}

void UI::showTotalSum()
{
    cout<<"In prezent in tonomat se afla "<<s.getTotalSum()<<" RON"<<endl;
}

void UI::buyProduct()
{
    s.initializeMap();
    int sum, cod,oneRon,fiveRon,tenRon,fiftyRon,hundredRon, number, value;
    cout<<"Precizati suma pe care o introduceti: ";cin>>sum;
    int copySum = sum;
    cout<<"Introduceti bancnotele: ";
    while(copySum > 0)
    {
        cout<<"Dati valoarea bancnotei:";cin>>value;
        cout<<"Dati numarul de astfel de bancnote:";cin>>number;
        s.addMonede(number, value);
        copySum -= number* value;

    }
    cout<<"Produsele disponibile sunt:"<<endl;
    showAllProducts();
    cout<<"Introduceti codul produsului:";cin>>cod;
    int rez = s.buyProduct(cod,sum,oneRon,fiveRon,tenRon,fiftyRon,hundredRon);
    if(rez == -1)
        cout<<"Bani insuficienti!"<<endl;
    else
        if(rez == -2)
            cout<<"Aparatul nu poate da rest! Incercati din nou cu alte bancnote"<<endl;
            else
                if(rez == 1)
               {
                   cout<<"Restul dvs este: "<<hundredRon*100<<"+"<<fiftyRon*50<<"+"<<tenRon*10<<"+"
                   <<fiveRon*5<<"+"<<oneRon<<"RON"<<endl;
               }
               else
                if(rez == 2)
                    cout<<"Produsul nu exista! Incercati din nou!"<<endl;



}

void UI::setService(const Service& s)
{
    this->s = s;
}


void UI::menu()
{
    cout<<"Meniul disponibil este:........................................................."<<endl;
    cout<<".......................1.Vezi produsele........................................."<<endl;
    cout<<".......................2.Cumpara produse........................................"<<endl;
    cout<<".......................3.Setari................................................."<<endl;
    cout<<".......................0.Exit..................................................."<<endl;

}

void UI::settings()
{

        cout<<"Produse:..................................................................."<<endl;
        cout<<".........4.Adaugare produs................................................."<<endl;
        cout<<".........5.Stergere produs................................................."<<endl;
        cout<<".........6.Actualizare produs.............................................."<<endl;
        cout<<".........7.Vezi numarul de produse........................................."<<endl;
        cout<<"Bani:......................................................................"<<endl;
        cout<<"..........8.Arata toate monedele..........................................."<<endl;
        cout<<"..........9.Adauga monede.................................................."<<endl;
        cout<<".........10.Sterge monede.................................................."<<endl;
        cout<<".........11.Actualizeaza monede............................................"<<endl;
        cout<<".........12.Arata suma totala din tonomat.................................."<<endl;
        cout<<"0.Inapoi..................................................................."<<endl;


}


void UI::console()
{
    int op;
    bool gata = false;
    while(!gata)
    {
        menu();
        cout<<"Optiunea dvs este: "<<endl;
        cin>>op;
        switch (op)
        {
            case 0:{gata = true; cout<<"La revedere :)"<<endl;break;}
            case 1:{this->showAllProducts();break;}
            case 2:{this->buyProduct();break;}
            case 3:{
                        int cod;
                        cout<<"Introduceti codul de securitate: ";cin>>cod;
                        if(cod != 1234)
                            cout<<"Cod incoret!"<<endl;
                        else{

                            bool gata2 = false;
                            int op2;
                            while(!gata2)
                            {
                                this->settings();
                                cout<<"Optiunea dvs este: "<<endl;
                                cin>>op2;
                                switch(op2)
                                {
                                     case 4:{this->addProduct();break;}
                                     case 5:{this->delProduct();break;}
                                     case 6:{this->updateProduct();break;}
                                     case 7:{this->getSizeProducts();break;}
                                     case 8:{this->showAllMonede();break;}
                                     case 9:{this->addMonede();break;}
                                     case 10:{this->deleteMonede();break;}
                                     case 11:{this->updateMonede();break;}
                                     case 12:{this->showTotalSum();break;}
                                     case 0:{gata2 = true; break;}
                                }
                            }}
                    }

        }

    }

}
