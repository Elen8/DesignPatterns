#include <iostream>

class PhoneImplementation
{
public:
	virtual void Feature() = 0;
};

class CameraManufacturer :public PhoneImplementation
{
public:
	void Feature() override
	{
		std::cout << "Capture Meri";
	}
};

class WidgetManufacturer :public PhoneImplementation
{
public:
	void Feature() override
	{
		std::cout << "Calling to Meri";
	}
};

class Phone
{
public:
	Phone(PhoneImplementation* phimpl) : PIptr(phimpl) {}
	virtual void call() = 0;
	virtual void camera() = 0;

protected:
	PhoneImplementation* PIptr;
};

class Apple :public Phone
{
public:
	Apple() : Phone(new CameraManufacturer)
	{}

	void camera() override
	{
		PIptr->Feature();
	}
	void call() override
	{
		PIptr->Feature();
	}
};

class Nokia :public Phone
{
public:
	void call() override
	{
		PIptr->Feature();
	}
};


int main()
{
	Phone* p = new Apple;
	Apple a();
}
