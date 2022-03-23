#include<iostream>
using namespace std;
#define ok 0
#define error -1

// 链表节点类定义
class ListNode
{
public:
	int data;
	ListNode* next;
	ListNode()
	{
		next = NULL;
	}
	// 新增一个含参构造
	ListNode(int val)
	{
		data = val;
		next = NULL;
	}
};
// 带头节点的单链表类定义
class LinkList
{
public:
	ListNode* head;
	int len;
	// 操作定义
	LinkList();
	// 新增一个含参构造
	LinkList(int n, int* arr);
	~LinkList();
	ListNode* LL_index(int i);		// 返回第i个结点的指针，如果不存在返回NULL
	int LL_get(int i);				// 返回第i个元素的数据
	int LL_insert(int i, int item);	// 把数值item插入第i个位置
	int LL_del(int i);				// 删除第i个节点
	void LL_display();				// 输出单链表的内容
	void swap(int pa, int pb);		// pa和pb表示两个结点在单链表的位置序号
};

LinkList::LinkList()
{
	head = new ListNode();
	len = 0;
}
// 链表回收，要逐个节点回收
LinkList::~LinkList()
{
	ListNode* p, * q;
	p = head;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		delete q;
	}
	len = 0;
	head = NULL;
}
/// <summary>
/// 利用数组构造单链表
/// </summary>
/// <param name="n">数组长度</param>
/// <param name="arr">数组</param>
LinkList::LinkList(int n, int* arr)
{
	head = new ListNode();
	len = n;
	// 新增第一个数值节点，即头节点之后的节点
	ListNode* node = new ListNode(arr[0]);
	head->next = node;
	// 将剩下的元素存进链表中
	for (int i = 1; i < n; ++i)
	{
		ListNode* newNode = new ListNode(arr[i]);
		node->next = newNode;
		node = node->next;
	}
}

void LinkList::LL_display()
{
	ListNode* p;
	p = head->next;
	while (p)
	{
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
}

// 查找元素
ListNode* LinkList::LL_index(int i)
{
	// 先判断位置
	if (i < 1 || i > len)
	{
		cout << "error" << endl;
		return NULL;
	}
	ListNode* node = head->next;
	for (int index = 1; index < i; ++index)
	{
		node = node->next;
	}
	cout << node->data << endl;
	return node;
}

// 插入元素
int LinkList::LL_insert(int i, int item)
{
	// 先判断
	if (i < 1 || i > len + 1)
	{
		cout << "error" << endl;
		return 0;
	}
	// 找到插入位置原节点和前置节点
	ListNode* node = head->next;
	ListNode* pre = head;
	for (int index = 1; index < i; ++index)
	{
		pre = pre->next;
		node = node->next;
	}
	ListNode* insertNode = new ListNode(item);
	pre->next = insertNode;
	insertNode->next = node;
	len++;
	LL_display();

	return 0;
}

// 删除元素
int LinkList::LL_del(int i)
{
	// 先判断
	if (i < 1 || i > len)
	{
		cout << "error" << endl;
		return 0;
	}
	// 找到插入位置原节点和前置节点
	ListNode* node = head->next;
	ListNode* pre = head;
	for (int index = 1; index < i; ++i)
	{
		pre = pre->next;
		node = node->next;
	}
	// 用前置节点的next指针指向当前节点的next指针
	pre->next = node->next;
	--len;
	// 去除node的空间
	delete node;

	LL_display();
	return 0;
}

// 交换结点
void LinkList::swap(int pa, int pb)
{
	// 先判断
	if (pa < 0 || pa > len || pb < 0 || pb > len)
	{
		cout << "error" << endl;
		return;
	}
	// 两个节点的前置节点
	ListNode* pre1 = head, *pre2 = head;
	// 循环找到位置
	for (int i = 1; i < pa || i < pb; ++i)
	{
		if (i < pa)
		{
			pre1 = pre1->next;
		}
		if (i < pb)
		{
			pre2 = pre2->next;
		}
	}
	ListNode* node1 = pre1->next, *node2 = pre2->next;
	// 用于交换
	ListNode* temp = node1->next;
	node1->next = node2->next;
	node2->next = temp;
	pre1->next = node2;
	pre2->next = node1;

	LL_display();
}

int main(int argc, char** argv)
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	LinkList* list = new LinkList(n, arr);
	list->LL_display();
	for (int i = 0; i < 2; ++i)
	{
		int pa, pb;
		cin >> pa >> pb;
		list->swap(pa, pb);
	}

	delete[]arr;
	delete list;

	return 0;
}