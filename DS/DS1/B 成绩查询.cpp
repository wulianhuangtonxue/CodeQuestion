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
//		int n;
//		cin >> n;
//		int* nums = new int[n];
//		for (int i = 0; i < n; ++i)
//		{
//			cin >> nums[i];
//		}
//		int* mid = nums + n / 2;
//		if (n > 1)
//		{
//			mid--;
//		}
//		cout << *mid << " ";
//		mid++;
//		if (n > 2)
//		{
//			mid++;
//		}
//		cout << *mid << endl;
//		mid--;
//		int i;
//		cin >> i;
//		mid += i - 1 - n / 2;
//		cout << *mid << endl;
//
//		delete nums;
//	}
//
//	return 0;
//}