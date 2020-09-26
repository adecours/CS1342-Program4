/* File: sales.h
Name: Abby DeCoursin
Date: 10-30-2019
Description: This file contains the function and constructor definitions for
Sales objects. The constructor defults to their null or 0 values.
*/
#ifndef SALES_H
#define SALES_H

#include <string>
using namespace std;

class Sales {
    public:
        Sales(int customerNum = 0, string category = "null", int quantity = 0, double unitPrice = 0, double extPrice = 0);
        
        // set methods
        void setCustomerNum(int newNum);
        void setCategory(string newCategory);
        void setQuantity(int newQuantity);
        void setUnitPrice(double newUnitPrice);
        void setExtPrice(double newExtPrice);

        // get methods
        int getCustomerNum();
        string getCategory();
        int getQuantity();
        double getUnitPrice();
        double getExtPrice();

        // display method
        void display();

    private:
        int custNum;
        string saleCategory;
        int saleQuantity;
        double saleUnitPrice;
        double saleExtPrice;

};

#endif