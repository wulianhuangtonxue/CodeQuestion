//#include<iostream>
//#include<string>
//#include<stack>
//using namespace std;
//
//// À¨ºÅÆ¥Åäº¯Êý
//void ParMatch(string s)
//{
//	stack<char> stk;
//	bool flag = true;
//	for (char& ch : s)
//	{
//		if (ch == '(' || ch == '[' || ch == '{')
//		{
//			stk.push(ch);
//		}
//		else if (!stk.empty() && 
//				(ch == '}'  && stk.top() == '{' 
//				|| ch == ']' && stk.top() == '[' 
//				|| ch == ')' && stk.top() == '('))
//		{
//			stk.pop();
//		}
//		else if (ch == '}' || ch == ')' || ch == ']')
//		{
//			flag = false;
//			break;
//		}
//	}
//	if (!stk.empty() || flag == false)
//	{
//		cout << "error" << endl;
//	}
//	else
//	{
//		cout << "ok" << endl;
//	}
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
//		ParMatch(s);
//	}
//	return 0;
//}