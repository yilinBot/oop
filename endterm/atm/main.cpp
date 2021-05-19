#include <iostream>
#include <vector>
#include <fstream>

#include "customer.h"

#include "center.h"
#include "bank.h"
#include "account.h"
#include "card.h"

#include "atm.h"

using namespace std;

int main()
{
	Customer* customer = new Customer("John");

    Center* c = new Center;
	Bank* otp = new Bank("otp");
	c->registrates(otp);

    Account* account = otp->createAccount("otp1001");
    account->add(10500);

    Card* card = otp->createCard(account, "otpcard1001", "0000");
    customer->takeCard(card);
    card->changePin("0000", "1001");

    ATM* atm = new ATM("somewhere", c);
    cout << "Old balance: " << account->getBalance() << endl;
    customer->withdraw(atm);
    cout << "New balance: " << account->getBalance() << endl;

    delete atm;
    delete card;
    delete account;
    delete otp;
    delete c;
    delete customer;

    return 0;
}
