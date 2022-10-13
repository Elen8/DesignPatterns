#include <iostream>

class Bank
{
private:
	std::string BankName;
	std::string CardHolder;
	long long CardNumber;

public:
	Bank()
	{
		BankName = "InecoBank";
		CardHolder = "Elen Tonoyan";
		CardNumber = 4576475829182312;
	}

	std::string get_holder()
	{
		return CardHolder;
	}

	std::string get_bank()
	{
		return BankName;
	}

	long long get_number()
	{
		return CardNumber;
	}
};

class CreditCard
{
public:
	virtual void get_bank_details() = 0;
};

class Customer :public CreditCard
{
private:
	Bank* BankDetails;

public:
	void get_bank_details() override
	{
		BankDetails = new Bank();
		std::cout << "Bank Details" << std::endl;
		std::cout << "Bank Name: " << BankDetails->get_bank() << std::endl;
		std::cout << "Card Holder Name: " << BankDetails->get_holder() << std::endl;
		std::cout << "Credit Card: " << BankDetails->get_number() << std::endl;
	}
};

int main()
{
	Customer c;
	c.get_bank_details();
}
