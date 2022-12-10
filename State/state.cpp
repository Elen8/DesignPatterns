#include <iostream>
#include <memory>

class State;
class CAvailable;
class CNotAvailable;


class Server
{
public:
	Server()
	{
		pCurrent = std::make_shared<State>(new CNotAvailable());
	}

	void setCurrent(std::shared_ptr<State> pState)
	{
		pCurrent = pState;
	}

	void Available()
	{
		pCurrent->ServerAvailable(std::make_shared<Server>(this));
	}
	void NotAvailable()
	{
		pCurrent->ServerNotAvailable(std::make_shared<Server>(this));
	}

private:
	std::shared_ptr<State> pCurrent;
};


class State
{
public:
	virtual void ServerAvailable(std::shared_ptr<Server>) {}
	virtual void ServerNotAvailable(std::shared_ptr<Server>) {}
};

class CAvailable: public State
{
public:
	CAvailable(){}
	~CAvailable(){}

	void ServerNotAvailable(std::shared_ptr<Server> pState) override
	{

	}
};

class CNotAvailable : public State
{
public:
	CNotAvailable(){}
	~CNotAvailable(){}

	void ServerAvailable(std::shared_ptr<Server> pState) override
	{
		pState->setCurrent(std::make_shared<State>(new CAvailable()));
		delete this;
	}
};
