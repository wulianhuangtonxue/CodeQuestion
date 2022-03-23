//#include<iostream>
//#include<iomanip>
//
//using namespace std;
//
//int dayOfMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//
//class Date
//{
//	int year, month, day;
//public:
//	Date();
//	Date(int y, int m, int d);
//	int getYear();
//	int getMonth();
//	int getDay();
//	void setDate(int y, int m, int d);
//	void print();
//	void addOneDay();
//};
//
//Date::Date()
//{
//	year = 1900;
//	month = 1;
//	day = 1;
//}
//Date::Date(int y, int m, int d)
//{
//	year = y;
//	month = m;
//	day = d;
//}
//int Date::getYear()
//{
//	return year;
//}
//int Date::getMonth()
//{
//	return month;
//}
//int Date::getDay()
//{
//	return day;
//}
//void Date::setDate(int y, int m, int d)
//{
//	year = y;
//	month = m;
//	day = d;
//}
//void Date::print()
//{
//	cout << year << "/" << setw(2) << setfill('0') << month << "/" 
//		<< setw(2) << setfill('0') << day << endl;
//}
//bool isLeap(Date& date)
//{
//	int y = date.getYear();
//	if (y % 400 == 0 || y % 100 != 0 && y % 4 == 0)
//	{
//		return true;
//	}
//	return false;
//}
//
//void Date::addOneDay()
//{
//	if (isLeap(*this))
//	{
//		dayOfMonth[1] = 29;
//	}
//	day++;
//	if (day > dayOfMonth[month - 1])
//	{
//		day = 1;
//		month++;
//		if (month > 12)
//		{
//			month = 1;
//			year++;
//		}
//	}
//	dayOfMonth[1] = 28;
//}
//
//int main(int argc, char** argv)
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int y, m, d;
//		cin >> y >> m >> d;
//		Date* d1 = new Date(y, m, d);
//		cout << "Today is ";
//		d1->print();
//		d1->addOneDay();
//		cout << "Tomorrow is ";
//		d1->print();
//		t--;
//		cin >> y >> m >> d;
//		d1->setDate(y, m, d);
//		cout << "Today is ";
//		d1->print();
//		d1->addOneDay();
//		cout << "Tomorrow is ";
//		d1->print();
//	}
//
//	return 0;
//}