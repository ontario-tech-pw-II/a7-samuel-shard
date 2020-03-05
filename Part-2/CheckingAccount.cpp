#include "CheckingAccount.h"

using namespace std;

	
// constructor initializes balance and transaction fee
CheckingAccount::CheckingAccount( double initialBalance, double fee ) : Account( initialBalance ) 
{
	// your code
    if(transactionFee < 0){
        transactionFee = 0;
    }
    else{
        transactionFee = fee;
    }
} 

// credit (add) an amount to the account balance and charge fee
void CheckingAccount::credit( double amount )
{
	// your code
    Account::credit(amount);
    chargeFee();
} 

// debit (subtract) an amount from the account balance and charge fee
bool CheckingAccount::debit( double amount )
{
	// your code
    bool success = Account::debit(amount);
    if (success){
        chargeFee();
        return true; //must also return bool
    } else{
        return false;
    }   
}

// subtract transaction fee
void CheckingAccount::chargeFee()
{
	// your code
    if(getBalance() > transactionFee){
        setBalance(getBalance()-transactionFee);
    }else{
        cout << "The transaction fee is greater than the ammount in your account.\n";
    }

}

void CheckingAccount::display(ostream & os) const
{
	// your code
    os.precision(2); //To output...
    os << fixed; //2 decimal place formatting (for money)
    os << "Account type: Checking Account\n";
    os << "Balance: $" << getBalance() << endl;
    os << "Transaction Fee: $" << transactionFee << endl;
}