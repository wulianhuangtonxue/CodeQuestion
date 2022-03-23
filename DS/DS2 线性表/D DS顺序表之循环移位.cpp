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