/* File: companySales.cpp
Name: Abby DeCoursin
Date: 10-30-2019
Description: This file contains the implementation of the constructor and functions 
associated with the CompanySales objects. It reads through the file and creates Sales
objects to fill the CompanySales object with. It also contains functions to manipulate
and determinate statistics about the sales. 
*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "companySales.h"

using namespace std;

// default constructor, initializes to null values
CompanySales::CompanySales() {
    companyName = "null";
    companyAddress = "null";
    fileName = "null";
}

// overloaded constructor that initializes variables. The constructor opens the file
// specified by the user and reads in each line. When reading through each line, the
// constructor reads in each attribute into the appropriate variables and assigns 
// these variables to a sale object. At the end, the constructor pushes the current Sale
// back onto the CompanySales and then closes the input file stream.
CompanySales::CompanySales(string compName, string compAddress, string saleFile) {
    companyName = compName;
    companyAddress = compAddress;
    fileName = saleFile;

    ifstream inFile;
    inFile.open(fileName);
        if(!inFile.is_open()) {
        cout << fileName << " could not be opened." << endl;
        }

    string line;
    while(getline(inFile, line)) {
        istringstream ss(line);
        Sales sale;

        int custNum;
        ss >> custNum;
        ss.ignore(256, ',');
        sale.setCustomerNum(custNum);
        
        string custCategory;
        getline(ss, custCategory, ',');
        sale.setCategory(custCategory);

        int custQuantity;
        ss >> custQuantity;
        ss.ignore(256, ',');
        sale.setQuantity(custQuantity);

        double custUnit;
        ss >> custUnit;
        ss.ignore(256, ',');
        sale.setUnitPrice(custUnit);

        double custExt;
        ss >> custExt;
        sale.setExtPrice(custExt);

        if (ss) {
            compSales.push_back(sale);
        }
        
    }
    inFile.close();
}

// sets the company name to the specified argument, no return
void CompanySales::setCompanyName(string newCompanyName) {
    companyName = newCompanyName;
}

// gets the name of the company, returns a string
string CompanySales::getCompanyName() {
    return companyName;
}

// sets the company address to the argument specified, no return
void CompanySales::setCompanyAddress(string newCompanyAddress) {
    companyAddress = newCompanyAddress;
}

// gets the company address, returns a string
string CompanySales::getCompanyAddress() {
    return companyAddress;
}

/* This function first displays the company's name and address. It then prints
each attribute of each Sale of the company in a formatted table. There is no 
return since it is printed to the terminal.
*/
void CompanySales::displayCompany() {
    cout << "Company Name: " << companyName << endl;
    cout << "Company Address: " << companyAddress << endl;

    int width = 12;

    cout << left << setw(width) << setfill(' ') << "ID";
    cout << left << setw(width) << setfill(' ') << "Category";
    cout << left << setw(width) << setfill(' ') << "Quantity";
    cout << left << setw(width) << setfill(' ') << "Unit Price";
    cout << left << setw(width) << setfill(' ') << "Ext. Price" <<  endl;

    for (int i = 0; i < compSales.size(); i++) {
        Sales currSale = compSales.at(i);
        int currentID = currSale.getCustomerNum();
        string currentCategory = currSale.getCategory();
        int currentQuantity = currSale.getQuantity();
        double currentUnit = currSale.getUnitPrice();
        double currentExt = currSale.getExtPrice();

        cout << left << setw(width) << setfill(' ') << currentID;
        cout << left << setw(width) << setfill(' ') << currentCategory;
        cout << left << setw(width) << setfill(' ') << currentQuantity;
        cout << left << setw(width) << setfill(' ') << currentUnit;
        cout << left << setw(width) << setfill(' ') << currentExt << endl;
    }
}

/* This function takes a string parameter of either the extended or unit price. 
It then goes through each sale and calculates the maximum, minimum, and average
for the specified type of price through all of the company's sales. If the user enters
invalid input, the user is prompted to try again. At the end, the max, min, and 
average are printed to the terminal. There is no return.
*/
void CompanySales::getStats(string priceType) {
    double maxPrice;
    double minPrice;
    double averagePrice = 0;
    
    Sales currSale = compSales.at(0);
    double currMaxPrice;
    double currMinPrice;
    if (priceType == "UnitPrice") {
        currMaxPrice = currSale.getUnitPrice();
        double tempPrice;

        for (int i = 0; i < compSales.size(); i++) {
            tempPrice = (compSales.at(i)).getUnitPrice();
            if (tempPrice > currMaxPrice) {
                currMaxPrice = tempPrice;
            }
        }

        currMinPrice = currSale.getUnitPrice();
        for (int i = 0; i < compSales.size(); i++) {
            tempPrice = (compSales.at(i)).getUnitPrice();
            if (tempPrice < currMinPrice) {
                currMinPrice = tempPrice;
            }
        }

        double count  = 0;
        for (int i = 0; i < compSales.size(); i++) {
            averagePrice += (compSales.at(i)).getUnitPrice();
            count++;
        }
        averagePrice = averagePrice / count;
        
    }
    else if (priceType == "ExtPrice") {
        currMaxPrice = currSale.getExtPrice();
        double tempPrice;

        for (int i = 0; i < compSales.size(); i++) {
            tempPrice = (compSales.at(i)).getExtPrice();
            if (tempPrice > currMaxPrice) {
                currMaxPrice = tempPrice;
            }
        }

        currMinPrice = currSale.getExtPrice();
        for (int i = 0; i < compSales.size(); i++) {
            tempPrice = (compSales.at(i)).getExtPrice();
            if (tempPrice < currMinPrice) {
                currMinPrice = tempPrice;
            }
        }

        double count  = 0;
        for (int i = 0; i < compSales.size(); i++) {
            averagePrice += (compSales.at(i)).getExtPrice();
            count++;
        }
        averagePrice = averagePrice / count;
    }
    else {
        cout << "Invalid price type. Please choose either UnitPrice or ExtPrice." << endl;
    }

    cout << "Max Price: " << currMaxPrice << endl;
    cout << "Min Price: " << currMinPrice << endl;
    cout << fixed << setprecision(2) << "Average Price: " << averagePrice << endl;
}

/* This function sorts the sales of a company by the sale's ID number. It
utilizes a selection sort and returns a vector of the sorted sales.
*/
vector<Sales> CompanySales::sortSales() {
    vector<Sales> sortedSales = compSales;

    int indexSmallest;
    Sales temp;

    for (int i = 0; i < sortedSales.size() - 1; i++) {
        indexSmallest = i;

        for (int j = i + 1; j < sortedSales.size(); j++) {
            if ((sortedSales.at(j)).getCustomerNum() < 
                (sortedSales.at(indexSmallest)).getCustomerNum()) {
                indexSmallest = j;
            }
        }

        temp = sortedSales.at(i);
        sortedSales.at(i) = sortedSales.at(indexSmallest);
        sortedSales.at(indexSmallest) = temp;
    } 

/*    // for testing if swaps correctly 
    for (int i = 0; i < sortedSales.size(); i++) {
        cout << (sortedSales.at(i)).getCustomerNum() << " ";
        cout << (sortedSales.at(i)).getExtPrice();
        cout << endl;
    } */
    return sortedSales;
}

/* This function goes through the sorted sales of a company and determines the 
maximum extended price for a group of matching IDs. If the ID does not match 
the previous one, the group total is reset to 0 and starts over with checking
for matching IDs. The maximum group of extended prices of grouped ids is displayed
along with the corresponding id. There is no return.
*/
void CompanySales::groupSum(vector<Sales> sortedSales) {

    double groupTotal = 0;
    double maxExt = 0;
    int maxExtID = 0;


    int pastID = (sortedSales.at(0)).getCustomerNum();
    for (int i = 1; i < sortedSales.size(); i++) {
        int currID = (sortedSales.at(i)).getCustomerNum();
            if (pastID == currID) {
                groupTotal += (sortedSales.at(i)).getExtPrice();
                if (groupTotal > maxExt) {
                    maxExt = groupTotal;
                    maxExtID = (sortedSales.at(i)).getCustomerNum();
                }
            }

            else {
                groupTotal = 0;
                groupTotal += (sortedSales.at(i)).getExtPrice();
            }
            
        pastID = (sortedSales.at(i - 1)).getCustomerNum();
    }

    cout << "Max Ext. Price: $" << maxExt << endl;
    cout << "Max Ext. Number: " << maxExtID << endl;

    
}