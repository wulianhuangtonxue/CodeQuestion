#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

class Point
{
	double x, y;
public:
	Point()
	{
		x = y = 0;
		cout << "Constructor." << endl;
	}
	Point(double xvalue, double yvalue)
	{
		x = xvalue;
		y = yvalue;
		cout << "Constructor." << endl;
	}
	Point(const Point& point)
	{
		x = point.x;
		y = point.y;
		cout << "Constructor." << endl;
	}
	double getX()
	{
		return x;
	}
	double getY()
	{
		return y;
	}
	void setXY(double x1, double y1)
	{
		x = x1;
		y = y1;
	}
	void setX(double xvalue)
	{
		x = xvalue;
	}
	void setY(double yvalue)
	{
		y = yvalue;
	}
	~Point()
	{
		cout << "Distructor." << endl;
	}
	double getDisTo(const Point& p)
	{
		return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
	}
};

void maxDistance(int* pp, double& dis, Point* points, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			double d = points[i].getDisTo(points[j]);
			if (dis < d)
			{
				pp[0] = i;
				pp[1] = j;
				dis = d;
			}
		}
	}
}

int main(int argc, char** argv)
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		Point* points = new Point[n];
		for (int i = 0; i < n; ++i)
		{
			double x, y;
			cin >> x >> y;
			points[i].setXY(x, y);
		}
		int* pp = new int[2];
		double dis = 0;
		maxDistance(pp, dis, points, n);
		cout << "The longeset distance is " << fixed << setprecision(2) << dis
			<< ",between p[" << pp[0] << "] and p[" << pp[1] << "].\n";
		delete pp;

		delete[] points;
	}

	return 0;
}