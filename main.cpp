#include <iostream>
#include "Tests.h"
#include "UI.h"
#include "Monede.h"

using namespace std;

int main()
{
	//Test t;
	//t.runTests();
	cout << "Testele au trecut!" << endl;

	RepoSTL<Product> r("Produse.txt");
	RepoSTL<Monede> m("Monede.txt");
	Service s(r, m);
	UI ui;
	ui.setService(s);
	ui.console();

	return 0;
}

