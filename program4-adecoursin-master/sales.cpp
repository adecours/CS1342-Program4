/* File: sales.cpp
Name: Abby DeCoursin
Date: 10-30-2019
Description: This file contains the implementation for the Sales object constructor.
The constructor creates different Sales objects for each line of the input file. 
The other functions are using to get, set, and print aspects of the Sales object.
*/
#include <iostream>
#include <string>
#include "sales.h"

using namespace std;

/* Constructs a Sales object and takes in 5 parameters containing attributes 
of the object.
*/
Sales::Sales(int customerNum, string category, int quantity, double unitPrice, double extPrice) {
    custNum = customerNum;
    saleCategory = category;
    saleQuantity = quantity;
    saleUnitPrice = unitPrice;
    saleExtPrice = extPrice;
}

// sets the customer number to the argument specified, no return
void Sales::setCustomerNum(int newNum) {
    custNum = newNum;
}

// gets the customer number of the Sales object, returns an int
int Sales::getCustomerNum() {
    return custNum;
}

// sets the category to the argument specified, no return
void Sales::setCategory(string newCategory) {
    saleCategory = newCategory;
}

// gets the category of the Sales object, returns a string
string Sales::getCategory() {
    return saleCategory;
}

// sets the quantity to the argument specified, no return
void Sales::setQuantity(int newQuantity) {
    saleQuantity = newQuantity;
}

// gets the quantity of the Sales object, returns an int
int Sales::getQuantity() {
    return saleQuantity;
}

// sets the unit price to the argument specified, no return
void Sales::setUnitPrice(double newUnitPrice) {
    saleUnitPrice = newUnitPrice;
}

// gets the unit price of the Sales object, returns a double
double Sales::getUnitPrice() {
    return saleUnitPrice;
}

// sets the extended price to the argument specified, no return
void Sales::setExtPrice(double newExtPrice) {
    saleExtPrice = newExtPrice;
}

// gets the extended price of the Sales object, returns a double
double Sales::getExtPrice() {
    return saleExtPrice;
}

// prints all attributes of the Sales object
void Sales::display() {
    cout << "Customer Number: " << custNum << endl;
    cout << "Category: " << saleCategory << endl;
    cout << "Quantity: " << saleQuantity << endl;
    cout << "Unit Price: " << saleUnitPrice << endl;
    cout << "Extended Price: " << saleExtPrice << endl;

    cout << endl;
}