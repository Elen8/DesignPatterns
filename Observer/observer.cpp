#include <iostream>
#include <memory>
#include <list>
class Responsibilities
{
public:
	void Done(Manager* ob) { m_list.push_back(ob); }
	void Notify()
	{
		std::list<Manager*>::iterator it = m_list.begin();
		while (it != m_list.end())
		{
			(*it)->Update();
			++it;
		}
	}

private:
	int m_time;
	std::list<Manager*> m_list;
};

class Manager
{
protected:
	Responsibilities* presp;
public:
	virtual void Update() = 0;
};

class Worker1 : public Manager
{
public:
	Worker1(Responsibilities* pr)
	{
		presp = pr;
		presp->Done(this);
	}

	void Update()
	{
		presp->Notify();
	}
};
