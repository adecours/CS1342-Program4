/* File: program4.cpp
Name: Abby DeCoursin
Date: 10-30-2019
Description: This program reads in data from a csv file and assigns each line of
the file with a Sales object and fills that object with the data from the line. 
After all of the lines have been accounted for, the CompanySales object holds all
of the Sales objects. The formatted table of Sales objects is displayed in the terminal
by calling the displayCompany function. The program has the ability to read in from the
file, sort the Sales objects by ID, determine the highest, lowest, and average unit or 
extended price, and get the maximum extended price for the same ID.
*/
#include <iostream>
#include <string>
#include "sales.h"
#include "companySales.h"

using namespace std;

// Contains lines that demonstrate the functions of the program, first by 
// creating a company. It then displays the company's sales and gets the statistics
// of the unit prices. It then sorts the Sales and gets the highest Ext price for
// matching IDs.
int main() {
    CompanySales myCompany("AAAcompany", "Dallas", "CompanySalesData.csv");
    myCompany.displayCompany();
    myCompany.getStats("UnitPrice");
    vector<Sales> sorted = myCompany.sortSales();  
    myCompany.groupSum(sorted);  
}