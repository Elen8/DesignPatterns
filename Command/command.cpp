#include <iostream>

class Command
{
public:
	virtual void execute() = 0;
};


class ForbiddenWebs
{
public:
	void Let();
	void DontLet();
};


class Over18Years : public Command
{
public:
	Over18Years(ForbiddenWebs* fw) : mw(fw) {}
	void execute() {
		mw->Let();
	}
private:
	ForbiddenWebs* mw;
};


class Under18Years : public Command
{
public:
	Under18Years(ForbiddenWebs* fw) : mw(fw) {}
	void execute() {
		mw->DontLet();
	}
private:
	ForbiddenWebs* mw;
};


class RemoteControl
{
public:
	void setCommand(Command* cmd) {
		mCmd = cmd;
	}

	void buttonPressed() {
		mCmd->execute();
	}
private:
	Command* mCmd;
};


int main()
{
	
}
