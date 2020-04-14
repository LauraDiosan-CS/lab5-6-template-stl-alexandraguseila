#include "Tests.h"
#include "Monede.h"
#include <assert.h>
#include <string.h>

Test::Test(){}


Test::~Test(){}


void Test::runTests()
{
    testProducts();
    testRepoTemplate();
    testRepoSTL();
    testService();
    testMonede();
}


void Test::testProducts()
{
    testSetter();
    testGetter();
}


void Test::testGetter()
{
    Product e1;
    char* cioco = new char[strlen("ciocolata" + 1)];
    char* suc = new char[4];
    strcpy(cioco, "ciocolata");
    strcpy(suc,"suc");
    Product e2(1, cioco, 3);
    Product e3(e2);
    assert(e1.getCod() == 0);
    assert(e1.getPrice() == 0);
    assert(e1.getName() == NULL);
    assert(e2.getCod() == 1);
    assert(e2.getPrice() == 3);
    assert(strcmp(e2.getName(), cioco) == 0);
    assert(e3 == e2);
}


void Test::testSetter()
{
    Product e2;
    char* suc = new char[4];
    strcpy(suc,"suc");
    e2.setCod(2);
    e2.setName(suc);
    e2.setPrice(5);
    assert(e2.getCod() == 2);
    assert(e2.getPrice() == 5);
    assert(strcmp(e2.getName(), suc) == 0);
}


void Test::testMonede()
{
    testMonedeGetter();
    testMonedeSetter();
}


void Test::testMonedeGetter()
{
   Monede m1(2, 1);
   Monede m2(m1);
   assert(m1 == m2);
   assert(m1.getNumber()== 2);
   assert(m1.getValue() == 1);
}


void Test::testMonedeSetter()
{
    Monede m1(2,1);
    Monede m2;
    m2 = m1;
    m2.setValue(5);
    m2.setNumber(1);
    assert(m1 < m2);
}


void Test::testRepoTemplate()
{
    testRepoTemplateAdd();
    testRepoTemplateDel();
    testRepoTemplateUpdate();
    testRepoTemplateGetAll();
}


void Test::testRepoTemplateAdd()
{
    Repo<Product> r;
    r.add_element(Product(1, "mars", 5));
    assert(r.show_elements().size() == 1);

}


void Test::testRepoTemplateDel()
{
    Repo<Product> r;
    r.add_element(Product(2, "acadea", 4));
    r.del_element(Product(2, "acadea", 4));
    assert(r.get_size() == 0);
}


void Test::testRepoTemplateUpdate()
{
    Repo<Product> r;
    char* name1 = new char[10];
    char* name2 = new char[10];
    strcpy(name1, "suc");
    strcpy(name2, "cioco");
    Product p1(1, name1, 4);
    Product p2(2, name2, 5);
    r.add_element(p1);
    r.update_element(p1, p2);
     assert(r.show_elements()[0] == p2);
}


void Test::testRepoTemplateGetAll()
{
    Repo<Product> r;
    char* name1 = new char[10];
    char* name2 = new char[10];
    strcpy(name1,"suc");
    strcpy(name2,"cioco");
    Product p1(1, name1, 4);
    Product p2(2, name2, 5);
    r.add_element(p1);
    r.add_element(p2);
    assert(r.show_elements()[0] == p1);
    assert(r.show_elements()[1] == p2);
}


void Test::testRepoSTL()
{
    testRepoSTLAdd();
    testRepoSTLDel();
    testRepoSTLUpdate();
}


void Test::testRepoSTLAdd()
{
    RepoSTL<Product> r("Test.txt");
    r.clear();
    r.save_to_file();
    r.add_element(Product(2, "caramea", 1));
    r.add_element(Product(3, "mars", 6));
    r.save_to_file();
    assert(r.get_size() == 2);
    assert(r.show_elements()[0] == Product(2, "caramea", 1));
    assert(r.show_elements()[1] == Product(3, "mars", 6));
}


void Test::testRepoSTLDel()
{
    RepoSTL<Product> r;
    r.set_filename("Test.txt");
    r.load_to_file();
    r.del_element(Product(2, "caramea", 1));
    r.save_to_file();
    assert(r.get_size() == 1);
}


void Test::testRepoSTLUpdate()
{
    RepoSTL<Product> r("Test.txt");
    Product p(1, "Mars", 6);
    r.update_element(r.show_elements()[0], p);
    r.save_to_file();
    assert(r.show_elements()[0] == p);
}


void Test::testServiceBuyProduct()
{
    RepoSTL<Product> p("Test.txt");
    RepoSTL<Monede> m("Monede.txt");
    int rez, one, five, ten, fifty, hundred;
    Service s(p, m);
    s.initializeMap();
    rez = s.buyProduct(1, 10, one, five, ten, fifty, hundred);
    assert(rez == 1);
    assert(hundred == 0 && fifty == 0 && ten == 0 && five == 0 && one == 4);
    assert(s.getALLMonede()[0].getNumber() == 0);
}

void Test::testService()
{
    testServiceAdd();
    testServiceDelete();
    testServiceUpdate();
    testServiceBuyProduct();
}


void Test::testServiceAdd()
{
    RepoSTL<Product> r("TestRepoSTL.txt");
    RepoSTL<Monede> m("TestMonede.txt");
    Service s(r, m);
    char* suc = new char[4];
    char* caramea = new char[8];
    strcpy(suc, "suc");
    strcpy(caramea, "caramea");
    s.addProduct(2, suc, 7);
    s.addProduct(2, caramea, 2);
    assert(s.getProductByPos(1) == Product(2, "suc", 7));

}


void Test::testServiceDelete()
{
    RepoSTL<Product> r("TestRepoSTL.txt");
    RepoSTL<Monede> m("TestMonede.txt");
    Service s(r, m);
    s.deleteProduct(1);
    assert(s.getALLProducts().size() == 0);
}


void Test::testServiceUpdate()
{
    RepoSTL<Product> r("TestRepoSTL.txt");
    RepoSTL<Monede> m("TestMonede.txt");
    Service s(r, m);
    char* caramea = new char[8];
    strcpy(caramea, "caramea");
    Product p(1, caramea, 15);
    s.updateProduct(1, 1, caramea, 15);
    assert(s.getProductByPos(0)==p);

}
