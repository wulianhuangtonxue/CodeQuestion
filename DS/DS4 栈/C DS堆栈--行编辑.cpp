//#include<iostream>
//#include<stack>
//#include<string>
//using namespace std;
//
//void lineEdit(string s)
//{
//	stack<char> stk1, stk2;
//	for (char& ch : s)
//	{
//		if (ch != '#')
//		{
//			stk1.push(ch);
//		}
//		else if (!stk1.empty())
//		{
//			stk1.pop();
//		}
//	}
//	if (stk1.empty())
//	{
//		cout << "NULL" << endl;
//		return;
//	}
//	while (!stk1.empty())
//	{
//		stk2.push(stk1.top());
//		stk1.pop();
//	}
//	while (!stk2.empty())
//	{
//		cout << stk2.top();
//		stk2.pop();
//	}
//	cout << endl;
//}
//
//int main(int argc, char** argv)
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		string s;
//		cin >> s;
//		lineEdit(s);
//	}
//
//	return 0;
//}