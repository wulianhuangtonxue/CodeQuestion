//#include<iostream>
//#include<string>
//#include<stack>
//#include<sstream>
//using namespace std;
//
//class Solution
//{
//private:
//	stack<string> nums;		// �洢������, ʵ���ϻ�洢��������
//	stack<char> op;			// �洢������
//
//	// �������ʱ�жϲ��������ȼ�
//	bool opcmpRight(char op1, char op2)
//	{
//		if (op1 == '+' || op1 == '-')
//		{
//			return op2 == '+' || op2 == '-';
//		}
//		return true;
//	}
//
//	// �������ʱ�жϲ��������ȼ�
//	bool opcmpLeft(char op1, char op2)
//	{
//		if (op1 == '*' || op1 == '/')
//		{
//			return op2 != '*' && op2 != '/';
//		}
//		return false;
//	}
//public:
//	string poland(string s)
//	{
//		int len = s.length();
//		for (int i = len - 1; i >= 0; --i)
//		{
//			if (s[i] >= '0' && s[i] <= '9')
//			{
//				string num = "";
//				num += s[i];
//				while (i - 1 >= 0 && s[i - 1] >= '0' && s[i - 1] <= '9')
//				{
//					num = s[--i] + num;
//				}
//				// ��������ջ
//				nums.push(num);
//			}
//			else if (op.empty() || s[i] == ')' || op.top() == ')')
//			{
//				op.push(s[i]);
//			}
//			else if (s[i] == '(')
//			{
//				while (!op.empty() && op.top() != ')')
//				{
//					string ops = "";
//					ops += op.top();
//					nums.push(ops);
//					op.pop();
//				}
//				op.pop();
//			}
//			else if (opcmpRight(s[i], op.top()))
//			{
//				op.push(s[i]);
//			}
//			else
//			{
//				while (!op.empty() && !opcmpRight(s[i], op.top()))
//				{
//					string ops = "";
//					ops += op.top();
//					nums.push(ops);
//					op.pop();
//				}
//				op.push(s[i]);
//			}
//		}
//		
//		while (!op.empty())
//		{
//			string ops = "";
//			ops += op.top();
//			nums.push(ops);
//			op.pop();
//		}
//		string ans = "";
//		while (!nums.empty())
//		{
//			ans += nums.top() + (nums.size() > 1 ? " " : "");
//			nums.pop();
//		}
//		return ans;
//	}
//
//	string antiPoland(string s)
//	{
//		int len = s.size();
//		string ans = "";
//		for (int i = 0; i < len; ++i)
//		{
//			if (s[i] >= '0' && s[i] <= '9')
//			{
//				ans += s[i];
//				while (i + 1 < len && s[i + 1] >= '0' && s[i + 1] <= '9')
//				{
//					ans += s[++i];
//				}
//				ans += " ";
//			}
//			else if (op.empty() || s[i] == '(' || op.top() == '(')
//			{
//				op.push(s[i]);
//			}
//			else if (s[i] == ')')
//			{
//				while (!op.empty() && op.top() != '(')
//				{
//					ans += op.top();
//					ans += " ";
//					op.pop();
//				}
//				op.pop();
//			}
//			else if (opcmpLeft(s[i], op.top()))
//			{
//				op.push(s[i]);
//			}
//			else
//			{
//				while (!op.empty() && !opcmpLeft(s[i], op.top()))
//				{
//					ans += op.top();
//					ans += " ";
//					op.pop();
//				}
//				op.push(s[i]);
//			}
//		}
//		while (!op.empty())
//		{
//			ans += op.top();
//			ans += op.size() > 1 ? " " : "";
//			op.pop();
//		}
//		return ans;
//	}
//};
//
//int main(int argc, char** argv)
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		Solution sol;
//		string s;
//		cin >> s;
//		cout << sol.poland(s) << endl;
//		cout << sol.antiPoland(s) << endl << endl;
//	}
//
//	return 0;
//}