//Lab 9-2.cpp - displays two monthly car payments
//Created/revised by <your name> on <current date>

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function prototype
double getPayment(int, double, int);

int main()
{
    // Declare variables
    int carPrice = 0;
    int rebate = 0;
    double creditRate = 0.0; 
    double dealerRate = 0.0;
    int term = 0;           
    double creditPayment = 0.0;
    double dealerPayment = 0.0;

    cout << "Car price (after any trade-in): ";
    cin >> carPrice;
    cout << "Rebate: ";
    cin >> rebate;
    cout << "Credit union rate: ";
    cin >> creditRate;
    cout << "Dealer rate: ";
    cin >> dealerRate;
    cout << "Term in years: ";
    cin >> term;

    // Calculate monthly payments
    creditPayment = getPayment(carPrice - rebate, creditRate / 12, term * 12);
    dealerPayment = getPayment(carPrice, dealerRate / 12, term * 12);

    // Display results
    cout << fixed << setprecision(2) << endl;

    // ---- Credit union results ----
    if (creditPayment == -1)
    {
        cout << "Credit union payment: -1 (Invalid denominator)" << endl;
        cout << "Total amount paid (credit union): N/A" << endl;
    }
    else
    {
        cout << "Credit union payment: $" << creditPayment << endl;
        cout << "Total amount paid (credit union): $"
             << creditPayment * (term * 12) << endl;
    }

    cout << endl;

    // ---- Dealer results ----
    if (dealerPayment == -1)
    {
        cout << "Dealer payment: -1 (Invalid denominator)" << endl;
        cout << "Total amount paid (dealer): N/A" << endl;
    }
    else
    {
        cout << "Dealer payment: $" << dealerPayment << endl;
        cout << "Total amount paid (dealer): $"
             << dealerPayment * (term * 12) << endl;
    }

    return 0;
}


double getPayment(int prin, double monthRate, int months)
{
    
    double denominator = 1.0 - pow(monthRate + 1.0, -months);


    if (fabs(denominator) < 1e-15)
        return -1;

   
    double monthPay = prin * monthRate / denominator;
    return monthPay;
}