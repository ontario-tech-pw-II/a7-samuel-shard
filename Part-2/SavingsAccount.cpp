#include "SavingsAccount.h"

using namespace std;

// constructor initializes balance and interest rate
SavingsAccount::SavingsAccount( double initialBalance, double rate ) : Account( initialBalance ) 
{
	// your code
    //cout << "This is SavingsAccount( double initialBalance, double rate ) constructor for Account class." << endl; //testing
    if (rate < 0){
        interestRate = 0;
    }
    else{
        interestRate = rate;
    }
}

double SavingsAccount::calculateInterest() {
	// your code
    return getBalance()*interestRate; //total money + interest, or only interest earned? 
} 
void SavingsAccount::display(ostream & os) const
{
	// your code
    os.precision(2); //To output...
    os << fixed; //2 decimal place formatting (for money)
    os << "Account type: Savings Account\n";
    os << "Balance: $" << getBalance() << endl;
    os << "Interest Rate: " << interestRate*100 << "%\n"; 
}