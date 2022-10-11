#include <iostream>
#include <vector>

class IGameObject
{
public:
	using IGameObjectPtr = std::shared_ptr<IGameObject>;

	virtual void Attack() = 0;
	virtual void Defence() = 0;

};

class Person : public IGameObject
{

public:
	using PersonPtr = std::shared_ptr<Person>;

	Person(int id, int attack, int defence, int health)
		: m_id(id)
		, m_attack(attack)
		, m_defence(defence)
		, m_health(health)
	{}

	void Attack() override
	{
		std::cout << "Person.Attack()" << std::endl;
	}

	void Defence() override
	{
		std::cout << "Person.Defence()" << std::endl;
	}
private:
	int m_id;
	int m_attack;
	int m_defence;
	int m_health;
};


class Group : public IGameObject
{
public:
	using GroupPtr = std::shared_ptr<Group>;

	Group(int id)
		: m_id(id)
	{
	}

	void Attack() override
	{
		for (const auto& group : m_groups)
		{
			group->Attack();
		}

		std::cout << "Person.Attack()" << std::endl;
	}

	void Defence() override
	{
		for (const auto& group : m_groups)
		{
			group->Defence();
		}

		std::cout << "Person.Defence()" << std::endl;
	}


	void AddToGroup(const IGameObjectPtr& group)
	{
		m_groups.push_back(group);
	}

private:
	int m_id;
	std::vector<IGameObjectPtr> m_groups;
};

int main()
{
	IGameObject::IGameObjectPtr p1 = std::make_shared<Person>(1, 2, 3, 10);
	IGameObject::IGameObjectPtr p2 = std::make_shared<Person>(1, 2, 3, 10);

	p1->Attack();
	p2->Attack();

  Group::GroupPtr g1 = std::make_shared<Group>(111);
	g1->AddToGroup(p1);

	Group::GroupPtr g2 = std::make_shared<Group>(122);
	g2->AddToGroup(p2);

	g1->AddToGroup(g2);
	g1->Attack();

	return 0;
}
