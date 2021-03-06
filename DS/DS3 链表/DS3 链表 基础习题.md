# DS3 链表 基础习题

[TOC]

## 前言

> 今天刚做了数据结构实验，今天的主题的是链表。
>
> 采用的语言是C++。



## A DS单链表--类实现

### 题目描述

> 用C++语言和类实现单链表，含头结点
>
> 属性包括：data数据域、next指针域
>
> 操作包括：插入、删除、查找
>
> 注意：单链表不是数组，所以位置从1开始对应首结点，头结点不放数据

> 类定义参考
>
> ![L2Tbot.jpg](https://s6.jpg.cm/2022/03/15/L2Tbot.jpg)

#### 输入

> 第1行先输入n表示有n个数据，接着输入n个数据
> 第2行输入要插入的位置和新数据
> 第3行输入要插入的位置和新数据
> 第4行输入要删除的位置
> 第5行输入要删除的位置
> 第6行输入要查找的位置
> 第7行输入要查找的位置

#### 输出

> 数据之间用空格隔开，
>
> 第1行输出创建后的单链表的数据
>
> 每成功执行一次操作（插入或删除），输出执行后的单链表数据
>
> 每成功执行一次查找，输出查找到的数据
>
> 如果执行操作失败（包括插入、删除、查找等失败），输出字符串error，不必输出单链表

#### 输入样例

> 6 11 22 33 44 55 66
> 3 777
> 1 888
> 1
> 11
> 0
> 5

#### 输出样例

> 11 22 33 44 55 66 
> 11 22 777 33 44 55 66 
> 888 11 22 777 33 44 55 66 
> 11 22 777 33 44 55 66 
> error
> error
> 44

### 题目分析

这题一开始是要用一组数据构造链表，所以不妨在参考代码中的链表类中加一个含参构造函数。然后只需增加插入、查找以及删除函数的实现即可。

值得注意的是，像插入、查找以及删除函数的操作需要先进行对位置的判断。

而像插入、删除操作，需要指定位置的前置节点，所以我们需要额外的变量去存储前置节点。

### code（C++）

```c++
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
	int i, item;
	for (int j = 0; j < 2; ++j)
	{
		cin >> i >> item;
		list->LL_insert(i, item);
	}
	for (int j = 0; j < 2; ++j)
	{
		cin >> i;
		list->LL_del(i);
	}
	for (int j = 0; j < 2; ++j)
	{
		cin >> i;
		list->LL_index(i);
	}
	delete[]arr;
	delete list;

	return 0;
}
```



## B DS单链表--结点交换

### 题目描述

> 用C++实现含头结点的单链表，然后实现单链表的两个结点交换位置。
>
> 注意不能简单交换两个结点包含数据，必须通过修改指针来实现两个结点的位置交换
>
> 交换函数定义可以参考：
>
> swap（int  pa, int pb)  //pa和pb表示两个结点在单链表的位置序号
>
> swap (ListNode * p, ListNode * q)  //p和q表示指向两个结点的指针

#### 输入

> 第1行先输入n表示有n个数据，接着输入n个数据
>
> 第2行输入要交换的两个结点位置
>
> 第3行输入要交换的两个结点位置

#### 输出

> 第一行输出单链表创建后的所有数据，数据之间用空格隔开
>
> 第二行输出执行第1次交换操作后的单链表数据，数据之间用空格隔开
>
> 第三行输出执行第2次交换操作后的单链表数据，数据之间用空格隔开
>
> 如果发现输入位置不合法，输出字符串error，不必输出单链表

#### 输入样例

> 5 11 22 33 44 55
> 1 4
> 2 6

#### 输出样例

> 11 22 33 44 55 
> 44 22 33 11 55 
> error



### 题目分析

在A题代码的基础上加一个节点交换函数，题目要求必须交换节点而不是节点值。

关于交换节点的实现可以参考下图，其中虚线表示交换前，实线表示交换后。

![image-20220315203304606](C:\Users\86152\AppData\Roaming\Typora\typora-user-images\image-20220315203304606.png)



### code（C++）

```c++
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
```



## C DS单链表--合并

### 题目描述

> 假定两个单链表是递增有序，定义并实现以下函数，完成两个单链表的合并，继续保持递增有序
>
> int LL_merge(ListNode *La, ListNode *Lb)

#### 输入

> 第1行先输入n表示有n个数据，接着输入n个数据
>
> 第2行先输入m表示有M个数据，接着输入m个数据

#### 输出

> 输出合并后的单链表数据，数据之间用空格隔开

#### 输入样例

> 3 11 33 55
> 4 22 44 66 88

#### 输出样例

> 11 22 33 44 55 66 88 



### 题目分析

由于题目的原因，我们可以使用一个新的链表来存储合并后的链表，对于两个链表的合并操作采取双指针的思路实现。



### code（C++）

```c++
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
	int LL_merge(ListNode* La, ListNode* Lb);	// 合并有序单链表
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
	ListNode* pre1 = head, * pre2 = head;
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
	ListNode* node1 = pre1->next, * node2 = pre2->next;
	// 用于交换
	ListNode* temp = node1->next;
	node1->next = node2->next;
	node2->next = temp;
	pre1->next = node2;
	pre2->next = node1;

	LL_display();
}

// 合并两个有序单链表
int LinkList::LL_merge(ListNode* La, ListNode* Lb)
{
	ListNode* node = head;
	while (La != NULL || Lb != NULL)
	{
		if (La != NULL && Lb != NULL)
		{
			if (La->data <= Lb->data)
			{
				node->next = new ListNode(La->data);
				La = La->next;
			}
			else
			{
				node->next = new ListNode(Lb->data);
				Lb = Lb->next;
			}
		}
		else if (La == NULL)
		{
			node->next = new ListNode(Lb->data);
			Lb = Lb->next;
		}
		else
		{
			node->next = new ListNode(La->data);
			La = La->next;
		}
		node = node->next;
		len++;
	}
	LL_display();
	return 0;
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
	LinkList* La = new LinkList(n, arr);
	delete[] arr;
	cin >> n;
	arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	LinkList* Lb = new LinkList(n, arr);
	LinkList* list = new LinkList();
	list->LL_merge(La->head->next, Lb->head->next);

	delete[]arr;
	delete La, Lb, list;

	return 0;
}
```



## D DS链表—学生宿舍管理

### 题目描述

> 假设某校有20间宿舍，宿舍编号101，102，...,120。每间只住一名学生。初始部分宿舍已用。用两个链表（已用宿舍链表和可用宿舍链表）维护宿舍的管理，实现宿舍分配、宿舍交回。
>
> 约定已用宿舍链表按宿舍号升序链接。初始可用宿舍链表也按宿舍号升序链接。
>
> 宿舍分配从可用宿舍链表中摘取第一间宿舍分配给学生。学生交回的宿舍挂在可用宿舍链表最后。
>
> 备注：使用list容器或静态链表。不用考虑宿舍分配和交回不成功的情况。

#### 输入

> 初始宿舍状态，第一行输入n，表示已用宿舍n间
>
> 后跟n行数据，每行格式为：宿舍号 学生姓名
>
> 操作次数m，后跟m行操作，操作格式如下：
>
> assign 学生 //为学生分配宿舍，从可用宿舍链表头摘取一间宿舍，
>
> ​          //按宿舍号升序挂在已用宿舍链表中。
>
> return 宿舍号  //学生退宿舍，删除已用宿舍链表中对应结点，
>
> ​             //挂在可用宿舍链表尾部。
>
> display_free  //输出可用宿舍链表信息。
>
> display_used  //输出已用宿舍链表信息。

#### 输出

>  display_free依次输出当前可用宿舍链表中的宿舍号，具体格式见样例。
>
>  display_used依次输出当前已用宿舍链表中的学生和宿舍号，具体格式见样例。

#### 输入样例

> 5
> 李明  103
> 张三  106
> 王五  107
> 钱伟  112
> 章立  118
> 8
> assign 李四
> assign 赵六
> return 118
> return 101
> assign 马山
> display_used
> assign 林立
> display_free

#### 输出样例

> 赵六(102)-李明(103)-马山(104)-张三(106)-王五(107)-钱伟(112)
> 108-109-110-111-113-114-115-116-117-119-120-118-101

#### 提示

> list是一种序列式容器, list实际上就构成了一个双向循环链,
>
> List类使用的参考代码
>
> 包含头文件<list> ： #include <list>
>
> List定义和初始化：
>
>   list<int>lst1;     //创建空list
>
>   list<int> lst2(5);    //创建含有5个元素的list
>
>   list<int>lst3(3,2); //创建含有3个元素的list
>
>   list<int>lst4(lst2);  //使用lst2初始化lst4
>
>   list<int>lst5(lst2.begin(),lst2.end()); //同lst4
>
> 创建一个list对象l（注意list是模板类）：list<char> l; //堆栈的数据类型是字符型
>
> 把一个字符ct添加到链表末尾： s.push_back(ct);
>
> 把一个字符ct插入到链表头部： s.push_front(ct);
>
> 获取链表第一个元素和最后一个元素：front()和back()，获取链表第一个元素，放入变量c2： c2 = s.front();
>
> 删除链表第一个元素和最后一个元素pop_front()和pop_back();
>
> 判断 判断list是否为空:empty()： l.empty()，如果为空则函数返回true，如果不空则返回false
>
> begin() 返回指向第一个元素的迭代器 
>
> end() 返回末尾的迭代器
>
> rbegin() 返回指向第一个元素的逆向迭代器 
>
> rend() 指向list末尾的逆向迭代器
>
> 程序示列：
>
> \#include <iostream> 
>
> using namespace std;
>
> typedef list<int> LISTINT; 
>
>   
>
>  void main() 
>
>  { 
>
>   //用LISTINT创建一个list对象 
>
>   LISTINT listOne; 
>
>   //声明i为迭代器 
>
>   LISTINT::iterator i; 
>
>   
>
>   listOne.push_front(3); 
>
>   listOne.push_front(2); 
>
>   listOne.push_front(1); 
>
>   
>
>   listOne.push_back(4); 
>
>   listOne.push_back(5); 
>
>   listOne.push_back(6); 
>
>   
>
>   cout << "listOne.begin()--- listOne.end():" << endl; 
>
>   for (i = listOne.begin(); i != listOne.end(); ++i) 
>
>    cout << *i << " "; 
>
>   cout << endl;  //正向输出
>
>   
>
>   LISTINT::reverse_iterator ir; 
>
>   cout << "listOne.rbegin()---listOne.rend():" << endl; 
>
>   for (ir = listOne.rbegin(); ir != listOne.rend(); ir++) { 
>
>    cout << *ir << " "; 
>
>   }  
>
>   cout << endl;  //反向输出
>
> }



### 题目思路

题目也说了，可以使用list容器实现，这里限制了，输出时，已用宿舍的输出必须按宿舍号升序输出，所以需要对链表进行特殊排序，这里采用list容器自带的sort，注意不能使用泛型sort函数，因为泛型sort需要容器内的任意元素可直接获取，但list实际上是一个双向链表，对于非两端的数据，需要靠头尾指针移动才能访问到，所以只能使用list自定义的sort函数，然后借助lambda表达式进行按宿舍号排序。

而free，我们可以只需要在一开始构造的做处理就不需要排序了。

除了需要排序，我们对删除也需要处理，这里采用list的 erase函数，删除对应迭代器的节点。



### code（C++）

```c++
#include <list>
#include <iostream> 
#include<algorithm>
#include<string>
using namespace std;

class Node
{
public:
    string name;
    int num;
    Node(string name, int num)
    {
        this->name = name;
        this->num = num;
    }
    Node()
    {
        name = "";
        num = 0;
    }
};


int main(int argc, char** argv)
{
    int* arr = new int[20];
    for (int i = 0; i < 20; ++i)
    {
        arr[i] = i + 101;
    }
    int n;
    cin >> n;
    list<Node> used;
    for (int i = 0; i < n; ++i)
    {
        string name;
        int num;
        cin >> name >> num;
        Node node(name, num);
        used.push_back(node);
        arr[num - 101] = 0;
    }
    // 使用list内置的sort 使用lamda表达式进行特殊排序——根据宿舍号升序排序
    used.sort([](const Node& a, const Node& b)
        {
            return a.num < b.num;
        });
    // 未用宿舍
    list<int> free;
    for (int i = 0; i < 20; ++i)
    {
        // 未被使用
        if (arr[i] > 100)
        {
            free.push_back(arr[i]);
        }
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        string op;
        cin >> op;
        if (op == "assign")
        {
            string name;
            cin >> name;
            int num = free.front();
            free.pop_front();
            Node node(name, num);
            used.push_front(node);
        }
        else if (op == "return")
        {
            int num;
            cin >> num;
            // 找到对应迭代器
            list<Node>::iterator it = used.begin();
            while (it->num != num)
            {
                it++;
            }
            // 利用内置的删除函数删除
            used.erase(it);
            free.push_back(num);
        }
        else if (op == "display_used")
        {
            used.sort([](const Node& a, const Node& b)
                {
                    return a.num < b.num;
                });
            int size = used.size();
            int j = 1;
            for (list<Node>::iterator it = used.begin(); j < size; ++it, ++j)
            {
                cout << it->name << "(" << it->num << ")-";
            }
            cout << used.back().name << "(" << used.back().num << ")" << endl;
        }
        else
        {
            int size = free.size();
            int j = 1;
            for (list<int>::iterator it = free.begin(); j < size; ++it, ++j)
            {
                cout << *it << "-";
            }
            cout << free.back() << endl;
        }
    }

    return 0;
}
```



## E DS线性表—多项式相加

### 题目描述

> **对于一元多项式**p(x)=p0+p1x+p2x2+ … +pnxn **，每个项都有系数和指数两部分，例如 p2X2 的系数为 p2, 指数为2。**
>
> **编程实现两个多项式的相加。**
>
> **例如  5+x+2x2+3x3，-5-x+6x2+4x4，两者相加结果：8x2+3x3+4x4**
>
> **其中系数5和-5都是x的0次方的系数，相加后为0，所以不显示。x的1次方同理不显示。**
>
> **可用顺序表或单链表实现。**

#### 输入

> 第1行：输入t表示有t组测试数据
>
> 第2行：输入n表示有第1组的第1个多项式包含n个项
>
> 第3行：输入第一项的系数和指数，以此类推输入n行
>
> 接着输入m表示第1组的第2个多项式包含m项
>
> 同理输入第2个多项式的m个项的系数和指数
>
> 参考上面输入第2组数据，以此类推输入t组
>
> 假设所有数据都是整数

#### 输出

> 对于每1组数据，先用两行输出两个原来的多项式，再用一行输出运算结果，不必考虑结果全为0的情况
>
> 输出格式参考样本数据，格式要求包括：
>
> 1.如果指数或系数是负数，用小括号括起来。
>
> 2.如果系数为0，则该项不用输出。
>
> 3.如果指数不为0，则用符号^表示，例如x的3次方，表示为x^3。
>
> 4.多项式的每个项之间用符号+连接，每个+两边加1个空格隔开。



### 题目思路

我们可以采用单链表实现，毕竟今天的主题时单链表。输入的多项式是默认指数升序的，所以我们可以采用类似C题合并链表的思路，当然输出时需要考虑负数，零指数等问题。



### code（C++）

```C++
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
```



## 后话

> 链表就还好，接下来继续努力。