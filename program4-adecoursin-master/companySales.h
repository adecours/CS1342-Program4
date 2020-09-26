/* File: companySales.h
Name: Abby DeCoursin
Date: 10-30-2019
Description: This file contains the function and constructor definitiojns for 
CompanySales objects. The constructor defaults values to null values. 
*/
#ifndef COMPANYSALES_H
#define COMPANYSALES_H

#include <vector>
#include <string>
#include "sales.h"

using namespace std;

class CompanySales {
    public:
        CompanySales();
        CompanySales(string compName = "null", string compAddress = "null", string saleFile = "null");

        void setCompanyName(string newCompanyName);
        void setCompanyAddress(string newCompanyAddress);

        string getCompanyName();
        string getCompanyAddress();

        void displayCompany();
        void getStats(string priceType);
        vector<Sales> sortSales();
        void groupSum(vector<Sales> sortedSales);

    private:
        string companyName;
        string companyAddress;
        string fileName;
        vector<Sales> compSales;

};


#endif