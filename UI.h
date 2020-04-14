#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED
#include "Service.h"

class UI
{
private:
    Service s;
    void show(vector<Product>);
    void addProduct();
    void delProduct();
    void updateProduct();
    void showAllProducts();
    void getProduct();
    void getSizeProducts();
    void addMonede();
    void deleteMonede();
    void updateMonede();
    void showAllMonede();
    void showTotalSum();
    void buyProduct();
    void menu();
    void settings();
public:
    UI();
    void setService( const Service& s);
    ~UI();
    void console();

};


#endif // UI_H_INCLUDED

