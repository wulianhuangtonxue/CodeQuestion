#include<iostream>
using namespace std;

class Node
{
public:
	int coe;	// 系数
	int index;	// 指数
	Node* next;

	Node()
	{
		next = NULL;
	}
	Node(int c, int i) : coe(c), index(i)
	{
		next = NULL;
	}
	Node(Node* node)
	{
		coe = node->coe;
		index = node->index;
		next = NULL;
	}
};

class LinkList
{
public:
	Node* head;		// 头节点
	int len;		// 长度

	LinkList()
	{
		head = new Node();
		len = 0;
	}
	~LinkList()
	{
		Node* a, * b;
		a = head;
		while (a != NULL)
		{
			b = a;
			a = a->next;
			delete b;
		}
		head = NULL;
		len = 0;
	}
	void Push(Node* node)
	{
		// 深拷贝
		Node* backNote = new Node(node);
		// 找到末尾
		Node* preNote = head;
		for (int i = 1; i <= len; ++i)
		{
			preNote = preNote->next;
		}
		preNote->next = backNote;
		len++;
	}
	void display()
	{
		Node* node = head->next;
		for (int i = 1; i <= len; ++i)
		{
			bool flag = false;
			if (node->coe < 0)
			{
				cout << "(";
				flag = true;
			}
			cout << node->coe;
			if (flag)
			{
				cout << ")";
			}
			if (node->index != 0)
			{
				cout << "x^";
				bool f = false;
				if (node->index < 0)
				{
					cout << "(";
					f = true;
				}
				cout << node->index;
				if (f)
				{
					cout << ")";
				}
			}
			if (i < len)
			{
				cout << " + ";
			}
			node = node->next;
		}
		cout << endl;
	}
};

// 全局函数 实现 多项式相加
void add(LinkList& La, LinkList& Lb)
{
	LinkList list;
	Node* term1 = La.head->next;
	Node* term2 = Lb.head->next;
	while (term1 || term2)
	{
		if (term1 && term2 && term1->index < term2->index || term2 == NULL)
		{
			list.Push(term1);
			term1 = term1->next;
		}
		else if (term1 && term2 && term1->index > term2->index || term1 == NULL)
		{
			list.Push(term2);
			term2 = term2->next;
		}
		else
		{
			int coe = term1->coe + term2->coe;
			if (coe != 0)
			{
				list.Push(new Node(coe, term1->index));
			}
			term1 = term1->next;
			term2 = term2->next;
		}
	}
	list.display();
}

int main(int argc, char** argv)
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		LinkList La, Lb;
		for (int i = 0; i < n; ++i)
		{
			int coe, index;
			cin >> coe >> index;
			La.Push(new Node(coe, index));
		}
		La.display();
		int m;
		cin >> m;
		for (int i = 0; i < m; ++i)
		{
			int coe, index;
			cin >> coe >> index;
			Lb.Push(new Node(coe, index));
		}
		Lb.display();
		add(La, Lb);
	}

	return 0;
}