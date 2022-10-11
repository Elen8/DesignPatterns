#include <iostream>
#include <cmath>

class Point
{
private:
	Point(float x, float y)
		: m_x(x)
		, m_y(y)
	{
	}

	class PointFactory
	{
	public:
		static Point MakePolarPoint(float r, float theta)
		{
			return Point{ r * std::cos(theta), r * std::sin(theta) };
		}

		static Point MakeCartesianPoint(float x, float y)
		{
			return Point{ x, y };
		}
	};

public:
	static PointFactory pointFactory;
private:
	float m_x;
	float m_y;
};


int main()
{
	Point::pointFactory.MakePolarPoint(10, 28);

	return;
}
