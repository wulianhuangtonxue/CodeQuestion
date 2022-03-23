//#include<iostream>
//
//using namespace std;
//
//int main(int argc, char** argv)
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int** arr = new int* [2];
//		for (int i = 0; i < 2; ++i)
//		{
//			arr[i] = new int[3];
//			for (int j = 0; j < 3; ++j)
//			{
//				cin >> *(*arr + (j + i * 3));
//			}
//		}
//		for (int j = 2; j >= 0; --j)
//		{
//			for (int i = 0; i < 2; ++i)
//			{
//				cout << *(*arr + (j + i * 3)) << " ";
//			}
//			cout << endl;
//		}
//	}
//
//	return 0;
//}