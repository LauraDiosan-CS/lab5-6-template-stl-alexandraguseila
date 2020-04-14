#ifndef SERVICE_H_INCLUDED
#define SERVICE_H_INCLUDED
#include "RepoSTL.h"
#include "Product.h"
#include "Monede.h"
#include <vector>
#include <map>

class Service {
private:
	RepoSTL<Product> repoProduct;
	RepoSTL<Monede> repoMonede;
	map<int, int> bancnote;
public:
	Service()
	{
	};
	Service(const RepoSTL<Product>& repoP, const RepoSTL<Monede>& repoM);
	Service(const Service& s);
	~Service()
	{
	    bancnote.clear();
	};

	void initializeMap();
	void addProduct(int cod, const char* name, int price);
	void deleteProduct(int cod);
	void updateProduct(int oldCod, int newCod, const char* newName, int newPrice);
	vector<Product> getALLProducts();
	int getSizeProducts();
	int getProductPriceByCod(int cod);
	Product getProductByPos(int pos);

	void addMonede(int number, int value);
	void deleteMonede(int value);
	void updateMonede(int oldValue, int newValue, int newNumber);
	vector<Monede> getALLMonede();
	int getSizeMonede();
	int getTotalSum();

	int giveRest(int sum, int price, int &oneRon,int &fiveRon,int &tenRon,int &fiftyRon,int &hundredRon);
	void separeRest(int rest, int& oneRon, int& fiveRon, int &tenRon, int &fiftyRon, int &hundredRon);
	int buyProduct(int cod, int sum, int& oneRon, int& fiveRon, int &tenRon, int &fiftyRon, int &hundredRon);
};





#endif // SERVICE_H_INCLUDED
