//#include<iostream>
//#include<string>
//
//using namespace std;
//
//const string ms[12] = { "January", "February", "March", "April", "May", "June", "July", "Aguest",
//					"Setpetmber", "October", "November", "December" };
//
//
//int main(int argc, char** argv)
//{
//	string** month = new string * [12];
//	for (int i = 0; i < 12; ++i)
//	{
//		month[i] = new string;
//		*month[i] = ms[i];
//	}
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int num;
//		cin >> num;
//		if (num >= 1 && num <= 12)
//		{
//			cout << *month[num - 1] << endl;
//		}
//		else
//		{
//			cout << "error" << endl;
//		}
//	}
//	
//
//	return 0;
//}