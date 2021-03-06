# DS 实验2 顺序表

## 前言

> 刚做了数据结构实验，主要是顺序表的内容



## A DS顺序表——类实现

### 题目内容

> 用C++语言和类实现顺序表
>
> 属性包括：数组、实际长度、最大长度（设定为1000）
>
> 操作包括：创建、插入、删除、查找
>
> 
>
> **输入**
>
> 第1行先输入n表示有n个数据，即n是实际长度；接着输入n个数据
> 第2行输入要插入的位置和新数据
> 第3行输入要插入的位置和新数据
> 第4行输入要删除的位置
> 第5行输入要删除的位置
> 第6行输入要查找的位置
> 第7行输入要查找的位置
>
> **输出**
>
> 数据之间用空格隔开
>
> 第1行输出创建后的顺序表内容，包括顺序表实际长度和数据
>
> 每成功执行一次操作（插入或删除），输出执行后的顺序表内容
>
> 每成功执行一次查找，输出查找到的数据
>
> 如果执行操作失败（包括插入、删除、查找等失败），输出字符串error，不必输出顺序表内容



按照参考写，基本上就行了。

对于插入和删除查找需要先判断位置是否正确，然后打印的时候注意一下格式

### code	C++

```C++
#include<iostream>

using namespace std;

#define ok 0
#define error -1

// 顺序表定义
class SeqList
{
private:
	int* list;		// 元素数组
	int maxsize;	// 顺序表最大长度
	int size;		// 顺序表实际长度
public:
	SeqList();		//	构造函数
	~SeqList();		// 析构函数
	int list_size();	// 获取顺序表实际长度
	int list_insert(int i, int item);	// 插入一个元素，参数为插入的位置
	int list_del(int i);				// 删除一个元素，参数是删除的位置
	int list_get(int i);				// 获取一个元素，参数是获取的位置
	void list_display();				// 获取一个元素，参数是获取的位置
	SeqList(const int n, const int* arr);			//  写多一个构造函数，方便一点
};

// 构造函数，对象初始化设定
SeqList::SeqList()
{
	maxsize = 1000;
	size = 0;
	list = new int[maxsize];
}

// 析构函数
SeqList::~SeqList()
{
	// 回收空间
	delete[]list;
}

/// <summary>
/// 含参构造
/// 并且调用打印函数
/// </summary>
/// <param name="n">参数的长度</param>
/// <param name="arr">数组</param>
SeqList::SeqList(const int n, const int* arr)
{
	maxsize = 100;
	list = new int[maxsize];
	size = n;
	for (int i = 0; i < n; ++i)
	{
		list[i] = arr[i];
	}
	list_display();
}

// 打印函数
void SeqList::list_display()
{
	cout << size;
	for (int i = 0; i < size; ++i)
	{
		cout << " " << list[i];
	}
	cout << " " << endl;
}

// 插入
int SeqList::list_insert(int i, int item)
{
	// 先判断能否插入
	if (i <= 0 || i > size + 1)
	{
		cout << "error" << endl;
		return 0;
	}
	// 先将插入位置及之后的原位置不断向后移动
	for (int k = size; k > i - 1; --k)
	{
		list[k] = list[k - 1];
	}
	list[i - 1] = item;
	size++;
	list_display();

	return 0;
}

// 删除
int SeqList::list_del(int i)
{
	// 先判断位置是否正确
	if (i <= 0 || i > size)
	{
		cout << "error" << endl;
		return 0;
	}
	// 直接将删除位置之后的数据向前覆盖即可
	for (int k = i - 1; k < size - 1; ++k)
	{
		list[k] = list[k + 1];
	}
	// 尺寸-1
	size--;
	list_display();

	return 0;
}

// 查找
int SeqList::list_get(int i)
{
	// 先判断位置是否正确
	if (i <= 0 || i > size)
	{
		cout << "error" << endl;
		return 0;
	}

	cout << list[i - 1] << endl;
	return 0;
}

int main(int argc, char** argv)
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> *(arr + i);
	}
	// 建立对象
	SeqList* seqlist = new SeqList(n, arr);

	int pos, data;
	cin >> pos >> data;
	seqlist->list_insert(pos, data);
	
	cin >> pos >> data;
	seqlist->list_insert(pos, data);

	cin >> pos;
	seqlist->list_del(pos);

	cin >> pos;
	seqlist->list_del(pos);

	cin >> pos;
	seqlist->list_get(pos);

	cin >> pos;
	seqlist->list_get(pos);

	return 0;
}
```



## B  DS 顺序表--连续操作

### 题目内容

> 建立顺序表的类，属性包括：数组、实际长度、最大长度（设定为1000）
>
> 该类具有以下成员函数：
>
> 构造函数：实现顺序表的初始化。
>
> 插入多个数据的multiinsert(int i, int n, int item[])函数，实现在第i个位置，连续插入来自数组item的n个数据，即从位置i开始插入多个数据。
>
> 删除多个数据的multidel(int i, int n)函数，实现从第i个位置开始，连续删除n个数据，即从位置i开始删除多个数据。
>
> 编写main函数测试该顺序表类。
>
> **输入**
>
> 第1行先输入n表示有n个数据，即n是实际长度；接着输入n个数据
>
> 第2行先输入i表示插入开始的位置，再输入k表示有k个插入数据，接着输入k个数据
>
> 第3行先输入i表示删除开始的位置，再输入k表示要删除k个数据
>
> **输出**
>
> 顺序表内容包括顺序表的实际长度和数据，数据之间用空格隔开
>
> 第1行输出创建后的顺序表内容
>
> 第2行输出执行连续插入后的顺序表内容
>
> 第3行输出执行连续删除后的顺序表内容



在第一题的基础上，对于插入和删除多个数据，这里需要做预先判断，插入只需要判断插入位置，删除则还需要判断删除的长度。

其实可以使用A题的代码在调用上做一些处理，但是直接写一个多数据插入删除的代码会更美观。



### code C++

```c++
#include<iostream>
using namespace std;

class SeqList
{
private:
	int* list;		// 元素数组
	int maxsize;	// 顺序表最大长度
	int size;		// 顺序表实际长度
public:
	SeqList();		//	构造函数
	~SeqList();		// 析构函数
	int list_size();	// 获取顺序表实际长度
	int list_insert(int i, int item);	// 插入一个元素，参数为插入的位置
	int list_del(int i);				// 删除一个元素，参数是删除的位置
	int list_get(int i);				// 获取一个元素，参数是获取的位置
	void list_display();				// 获取一个元素，参数是获取的位置
	SeqList(const int n, const int* arr);			//  写多一个构造函数，方便一点
	void multiinsert(int i, int n, int item[]);		// 插入多个数据
	void multidel(int i, int n);						// 删除多个数据
};

// 构造函数，对象初始化设定
SeqList::SeqList()
{
	maxsize = 1000;
	size = 0;
	list = new int[maxsize];
}

// 析构函数
SeqList::~SeqList()
{
	// 回收空间
	delete[]list;
}

// 打印函数
void SeqList::list_display()
{
	cout << size;
	for (int i = 0; i < size; ++i)
	{
		cout << " " << list[i];
	}
	cout << " " << endl;
}


/// <summary>
/// 含参构造
/// 并且调用打印函数
/// </summary>
/// <param name="n">参数的长度</param>
/// <param name="arr">数组</param>
SeqList::SeqList(const int n, const int* arr)
{
	maxsize = 100;
	list = new int[maxsize];
	size = n;
	for (int i = 0; i < n; ++i)
	{
		list[i] = arr[i];
	}
	list_display();
}

/// <summary>
/// 插入多个连续的数据
/// </summary>
/// <param name="i">插入位置</param>
/// <param name="n">插入数据的长度</param>
/// <param name="item">插入的数据</param>
void SeqList::multiinsert(int i, int n, int item[])
{
	// 先判断能否插入，就是位置是否正确
	if (i <= 0 || i > size + 1)
	{
		cout << "error" << endl;
		return;
	}
	size += n;
	// 先将插入位置及之后的原位置不断向后移动
	for (int k = size - 1; k > i + n - 2; --k)
	{
		list[k] = list[k - n];
	}
	// 然后再将数据插入
	for (int k = i - 1; k - (i - 1) < n; ++k)
	{
		list[k] = item[k - (i - 1)];
	}
	list_display();
}

/// <summary>
/// 删除多个数据
/// </summary>
/// <param name="i">删除开始位置</param>
/// <param name="n">删除的数据长度</param>
void SeqList::multidel(int i, int n)
{
	// 先判断删除的位置和长度是否正确
	if (i <= 0 || i + n - 1 > size)
	{
		cout << "error" << endl;
		return;
	}
	// 直接将删除位置之后的数据向前覆盖即可
	for (int k = i - 1; k < size - n; ++k)
	{
		list[k] = list[k + n];
	}
	size -= n;
	list_display();
}

int main(int argc, char** argv)
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> *(arr + i);
	}
	// 建立对象
	SeqList* seqlist = new SeqList(n, arr);

	int pos;
	int* data;
	cin >> pos >> n;
	data = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> data[i];
	}
	seqlist->multiinsert(pos, n, data);

	cin >> pos >> n;
	seqlist->multidel(pos, n);

	delete[] data, arr;
	
	return 0;
}
```



## C DS顺序表--合并操作

### 题目内容

> 建立顺序表的类，属性包括：数组、实际长度、最大长度（设定为1000）
>
> 已知两个递增序列，把两个序列的数据合并到顺序表中，并使得顺序表的数据递增有序
>
> **输入**
>
> 第1行先输入n表示有n个数据，接着输入n个数据，表示第1个序列，要求数据递增互不等
>
> 第2行先输入m表示有m个数据，接着输入m个数据，表示第2个序列，要求数据递增互不等
>
> **输出**
>
> 顺序表内容包括顺序表的实际长度和数据，数据之间用空格隔开
>
> 第1行输出创建后的顺序表内容



合并两个递增序列，欸这题写过，使用双指针，而且这题比较简单，原来的顺序表为空，直接往里边加，使用双指针遍历两个序列即可。



### code C++

```c++
#include<iostream>
using namespace std;

class SeqList
{
private:
	int* list;		// 元素数组
	int maxsize;	// 顺序表最大长度
	int size;		// 顺序表实际长度
public:
	SeqList();		//	构造函数
	~SeqList();		// 析构函数
	int list_size();	// 获取顺序表实际长度
	int list_insert(int i, int item);	// 插入一个元素，参数为插入的位置
	int list_del(int i);				// 删除一个元素，参数是删除的位置
	int list_get(int i);				// 获取一个元素，参数是获取的位置
	void list_display();				// 获取一个元素，参数是获取的位置
	SeqList(const int n, const int* arr);			//  写多一个构造函数，方便一点
	void multiinsert(int i, int n, int item[]);		// 插入多个数据
	void multidel(int i, int n);						// 删除多个数据
	void merge(int n, int* data1, int m, int* data2);		// 将两组数据进行合并，且原顺序表为空
};

SeqList::SeqList()
{
	maxsize = 1000;
	size = 0;
	list = new int[maxsize];
}

// 析构函数
SeqList::~SeqList()
{
	// 回收空间
	delete[]list;
}

// 打印函数
void SeqList::list_display()
{
	cout << size;
	for (int i = 0; i < size; ++i)
	{
		cout << " " << list[i];
	}
	cout << " " << endl;
}

/// <summary>
/// 合并递增序列
/// </summary>
/// <param name="n">序列一的长度</param>
/// <param name="data1">序列一</param>
/// <param name="m">序列二的长度</param>
/// <param name="data2">序列二</param>
void SeqList::merge(int n, int* data1, int m, int* data2)
{
	size = n + m;
	// 两个指针下标
	int p1 = 0, p2 = 0;
	for (int i = 0; i < size; ++i)
	{
		// 指针在范围内时
		if (p1 < n && p2 < m && data1[p1] <= data2[p2])
		{
			list[i] = data1[p1++];
		}
		else if (p1 < n && p2 < m && data1[p1] > data2[p2])
		{
			list[i] = data2[p2++];
		}
		// 指针不在范围内
		else if (p1 == n)
		{
			list[i] = data2[p2++];
		}
		else
		{
			list[i] = data1[p1++];
		}
	}
	list_display();
}


int main(int argc, char** argv)
{
	int n, m;
	cin >> n;
	int* data1 = new int[n];
	for(int i = 0; i < n; ++i)
	{
		cin >> data1[i];
	}
	cin >> m;
	int* data2 = new int[m];
	for (int i = 0; i < m; ++i)
	{
		cin >> data2[i];
	}
	SeqList* seqlist = new SeqList();

	seqlist->merge(n, data1, m, data2);

	delete[] data1, data2;

	return 0;
}
```



## D DS顺序表之循环移位

### 题目内容

> 顺序表的移位是循环移位，例如顺序表：1，2，3，4，5，6。如果左移1位，即原来的头元素移动到末尾，其它元素向左移1位，变成2，3，4，5，6，1。同理，如果右移1位，即原来的尾元素移动到头，其它元素向右移1位，变成6，1，2，3，4，5。以下是移位的多个例子：
>
> 原数据：1，2，3，4，5，6
>
> 左移3位：4，5，6，1，2，3，与原数据对比
>
> 右移4位：3，4，5，6，1，2，与原数据对比
>
> 请编写程序实现顺序表的循环移位操作
>
> **输入**
>
> 第1行输入n表示顺序表包含的·n个数据
>
> 第2行输入n个数据，数据是小于100的正整数
>
> 第3行输入移动方向和移动的位数，左移方向为0，右移方向为1
>
> 第4行输入移动方向和移动的位数，左移方向为0，右移方向为1
>
> 注意：移动操作是针对上一次移动后的结果进行的
>
> **输出**
>
> 第一行输出创建后，顺序表内的所有数据，数据之间用空格隔开
>
> 第二行输出第一次移位操作后，顺序表内的所有数据，数据之间用空格隔开
>
> 第三行输出第二次移位操作后，顺序表内的所有数据，数据之间用空格隔开



直接模拟就行了，用一个数组存储左边或者右边的数据



### code C++

```c++
#include<iostream>
using namespace std;

class SeqList
{
private:
	int* list;		// 元素数组
	int maxsize;	// 顺序表最大长度
	int size;		// 顺序表实际长度
public:
	SeqList();		//	构造函数
	~SeqList();		// 析构函数
	int list_size();	// 获取顺序表实际长度
	int list_insert(int i, int item);	// 插入一个元素，参数为插入的位置
	int list_del(int i);				// 删除一个元素，参数是删除的位置
	int list_get(int i);				// 获取一个元素，参数是获取的位置
	void list_display();				// 获取一个元素，参数是获取的位置
	SeqList(const int n, const int* arr);			//  写多一个构造函数，方便一点
	void multiinsert(int i, int n, int item[]);		// 插入多个数据
	void multidel(int i, int n);						// 删除多个数据
	void merge(int n, int* data1, int m, int* data2);		// 将两组数据进行合并，且原顺序表为空
	void CyclicShift(int flag, int n);					// 循环移位
};

// 默认构造
SeqList::SeqList()
{
	maxsize = 1000;
	size = 0;
	list = new int[maxsize];
}

// 析构函数
SeqList::~SeqList()
{
	// 回收空间
	delete[]list;
}

// 打印函数
void SeqList::list_display()
{
	for (int i = 0; i < size; ++i)
	{
		cout << list[i] << " ";
	}
	cout << endl;
}

/// <summary>
/// 含参构造
/// 并且调用打印函数
/// </summary>
/// <param name="n">参数的长度</param>
/// <param name="arr">数组</param>
SeqList::SeqList(const int n, const int* arr)
{
	maxsize = 100;
	list = new int[maxsize];
	size = n;
	for (int i = 0; i < n; ++i)
	{
		list[i] = arr[i];
	}
	list_display();
}

/// <summary>
/// 循环移位代码
/// 可以先根据移动方向，和长度建立一个数组
/// 数组保存左边的或者右边的长度的原数据
/// 然后直接移位覆盖
/// 最后用数组来将需要移位的数据进行覆盖
/// </summary>
/// <param name="flag">0——左移	1——右移</param>
/// <param name="n">移动的长度</param>
void SeqList::CyclicShift(int flag, int n)
{
	int* arr = new int[n];
	if (flag == 0)
	{
		// 存储数据
		for (int i = 0; i < n; ++i)
		{
			arr[i] = list[i];
		}
		// 后面的直接移动到前面
		for (int i = 0; i < size - n; ++i)
		{
			list[i] = list[i + n];
		}
		// 将右边的数据用数组覆盖
		for (int i = size - n; i < size; ++i)
		{
			list[i] = arr[i - size + n];
		}
	}
	else
	{
		// 存储数据
		for (int i = 0; i < n; ++i)
		{
			arr[i] = list[size - n + i];
		}
		// 后面的数据用前面的覆盖
		for (int i = size - 1; i >= n; --i)
		{
			list[i] = list[i - n];
		}
		// 前面的用数组覆盖
		for (int i = 0; i < n; ++i)
		{
			list[i] = arr[i];
		}
	}
	list_display();
	delete[] arr;
}


int main(int argc, char** argv)
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> *(arr + i);
	}
	// 建立对象
	SeqList* seqlist = new SeqList(n, arr);

	int flag;
	cin >> flag >> n;
	seqlist->CyclicShift(flag, n);

	cin >> flag >> n;
	seqlist->CyclicShift(flag, n);

	return 0;
}
```





## 后话

> 共勉

