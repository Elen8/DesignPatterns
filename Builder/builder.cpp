#include <iostream>

class AI
{
public:
	bool exist;
};

class Design
{
public:
	int colour;
};

class Mode
{
public:
	bool for_children;
};

class Robot
{
public:
	AI* ai;
	Design* colour;
	Mode* fch;

	void specification();
};

void Robot::specification()
{
	std::cout << "AI exists: " << ai->exist << std::endl;
	std::cout << "Colour: " << colour->colour << std::endl;
	std::cout << "For children: " << fch->for_children << std::endl;
}

class Builder {
public:
	virtual AI* if_exists() = 0;
	virtual Design* select_colour() = 0;
	virtual Mode* child_mode() = 0;
};

class RobinTheRobot :public Builder
{
public:
	AI* if_exists();
	Design* select_colour();
	Mode* child_mode();
};


AI* RobinTheRobot::if_exists() {
	AI* ai = new AI();
	ai->exist = true;
	return ai;
}

Design* RobinTheRobot::select_colour() {
	Design* design = new Design();
	design->colour = 101;
	return design;
}

Mode* RobinTheRobot::child_mode() {
	Mode* mode = new Mode();
	mode->for_children = true;
	return mode;
}

class ToyRobot :public Builder
{
public:
	AI* if_exists();
	Design* select_colour();
	Mode* child_mode();
};

AI* ToyRobot::if_exists() {
	AI* ai = new AI();
	ai->exist = false;
	return ai;
}

Design* ToyRobot::select_colour() {
	Design* design = new Design();
	design->colour = 144;
	return design;
}

Mode* ToyRobot::child_mode() {
	Mode* mode = new Mode();
	mode->for_children = true;
	return mode;
}

class ServantRobot :public Builder
{
public:
	AI* if_exists();
	Design* select_colour();
	Mode* child_mode();
};

AI* ServantRobot::if_exists() {
	AI* ai = new AI();
	ai->exist = false;
	return ai;
}

Design* ServantRobot::select_colour() {
	Design* design = new Design();
	design->colour = 100;
	return design;
}

Mode* ServantRobot::child_mode() {
	Mode* mode = new Mode();
	mode->for_children = false;
	return mode;
}

class Director {
	Builder* builder;
public:
	void setBuilder(Builder* newBuilder);

	Robot* create();
};

void Director::setBuilder(Builder* newBuilder) {
	builder = newBuilder;
}

Robot* Director::create() {
	Robot* robot = new Robot();
	robot->ai = builder->if_exists();
	robot->colour = builder->select_colour();
	robot->fch = builder->child_mode();
	return robot;
}

int main() {
	Robot* rob;
	Director director;
	RobinTheRobot Robin;
	ServantRobot ServRob;
	ToyRobot ToyRob;

	std::cout << "Robin the Robot" << std::endl;
	director.setBuilder(&Robin);
	rob = director.create();
	rob->specification();

	std::cout << std::endl;

	std::cout << "Servant Robot" << std::endl;
	director.setBuilder(&ServRob);
	rob = director.create();
	rob->specification();

	std::cout << std::endl;

	std::cout << "Toy Robot" << std::endl;
	director.setBuilder(&ToyRob);
	rob = director.create();
	rob->specification();
}
