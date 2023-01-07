#include <iostream>

class PhoneImplementation
{
public:
	virtual void Feature() = 0;
};

class CameraManufacturer :public PhoneImplementation
{
public:
	void Feature() override;
};

void CameraManufacturer::Feature()
{
	std::cout << "Capture Meri";
}

class WidgetManufacturer :public PhoneImplementation
{
public:
	void Feature() override;
};

void WidgetManufacturer::Feature()
{
	std::cout << "Calling to Meri";
}

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

	void camera() override;
	void call() override;
};

void Apple::camera() 
{
	PIptr->Feature();
}

void Apple::call() 
{
	PIptr->Feature();
}

class Nokia :public Phone
{
public:
	void call() override
	{
		PIptr->Feature();
	}
};

void Nokia::call()
{
	PIptr->Feature();
}

int main()
{
	Phone* p = new Apple;
	Apple a();
}
