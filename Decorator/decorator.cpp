#include <iostream>

class ARoom
{
public:
	virtual int getPrice() = 0;
	virtual int getModernity() = 0;
	virtual std::string getFurniture() = 0;
};

class Component :public ARoom
{
private:
	int price = 100;
	int modernity = 1;
	std::string comp = "Walls";

public:
	int getPrice() override
	{
		return price;
	}

	int getModernity() override
	{
		return modernity;
	}

	std::string getFurniture() override
	{
		return comp;
	}
};

class Decorator :public ARoom
{
protected:
	ARoom* room;

public:
	Decorator(ARoom* rm) : room(rm) 
	{}
};

class TV: public Decorator
{
private:
	int tv = 15;
public:
	TV(ARoom* Tv) : Decorator(Tv)
	{}

	int getPrice() override
	{
		return room->getPrice() + tv;
	}

	int getModernity() override
	{
		return room->getModernity() + 1;
	}

	std::string getFurniture() override
	{
		return room->getFurniture() + ", TV";
	}
};

class Sofa : public Decorator
{
private:
	int sofa = 25;
public:
	Sofa(ARoom* Sfa) : Decorator(Sfa)
	{}

	int getPrice()
	{
		return room->getPrice() + sofa;
	}

	int getModernity() override
	{
		return room->getModernity() + 1;
	}

	std::string getFurniture() override
	{
		return room->getFurniture() + ", sofa";
	}
};

int main()
{
	ARoom* simple_room = new Component();
	std::cout << simple_room->getFurniture() << ": ";
	std::cout << simple_room->getPrice() << "$" << std::endl;

	ARoom* add_tv = new TV(new Component());
	std::cout << add_tv->getFurniture() << ": ";
	std::cout << add_tv->getPrice() << "$" << std::endl;

	ARoom* add_sofa = new Sofa(new Component());
	std::cout << add_sofa->getFurniture() << ": ";
	std::cout << add_sofa->getPrice() << "$" << std::endl;

	ARoom* new_room = new TV(new Sofa(new Component()));
	std::cout << new_room->getFurniture() << ": ";
	std::cout << new_room->getPrice() << "$" << std::endl;
}
