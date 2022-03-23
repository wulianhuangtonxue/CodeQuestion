//#include<iostream>
//
//using namespace std;
//
//template <class T>
//T* createArr(int n)
//{
//	T* arr = new T[n];
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> *(arr + i);
//	}
//	return arr;
//}
//char findMax(char* arr, int n)
//{
//	char ans = *arr;
//	for (int j = 1; j < n; ++j)
//	{
//		if (*(arr + j) > ans)
//		{
//			ans = *(arr + j);
//		}
//	}
//	return ans;
//}
//int avg(int* arr, int n)
//{
//	int sum = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		sum += *(arr + i);
//	}
//	return sum / n;
//}
//double findMin(double* arr, int n)
//{
//	double ans = *arr;
//	for (int i = 1; i < n; ++i)
//	{
//		if (ans > *(arr + i))
//		{
//			ans = *(arr + i);
//		}
//	}
//	return ans;
//}
//
//int main(int argc, char** args)
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		char op;
//		int n;
//		cin >> op >> n;
//		if (op == 'C')
//		{
//			char* arr = createArr<char>(n);
//			cout << findMax(arr, n) << endl;
//			delete[] arr;
//		}
//		else if (op == 'I')
//		{
//			int* arr = createArr<int>(n);
//			cout << avg(arr, n) << endl;
//			delete[] arr;
//		}
//		else
//		{
//			double* arr = createArr<double>(n);
//			cout << findMin(arr, n) << endl;
//			delete[] arr;
//		}
//	}
//
//	return 0;
//}