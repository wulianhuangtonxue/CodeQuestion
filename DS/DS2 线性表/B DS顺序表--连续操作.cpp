//#include<iostream>
//using namespace std;
//
//class SeqList
//{
//private:
//	int* list;		// 元素数组
//	int maxsize;	// 顺序表最大长度
//	int size;		// 顺序表实际长度
//public:
//	SeqList();		//	构造函数
//	~SeqList();		// 析构函数
//	int list_size();	// 获取顺序表实际长度
//	int list_insert(int i, int item);	// 插入一个元素，参数为插入的位置
//	int list_del(int i);				// 删除一个元素，参数是删除的位置
//	int list_get(int i);				// 获取一个元素，参数是获取的位置
//	void list_display();				// 获取一个元素，参数是获取的位置
//	SeqList(const int n, const int* arr);			//  写多一个构造函数，方便一点
//	void multiinsert(int i, int n, int item[]);		// 插入多个数据
//	void multidel(int i, int n);						// 删除多个数据
//};
//
//// 构造函数，对象初始化设定
//SeqList::SeqList()
//{
//	maxsize = 1000;
//	size = 0;
//	list = new int[maxsize];
//}
//
//// 析构函数
//SeqList::~SeqList()
//{
//	// 回收空间
//	delete[]list;
//}
//
//// 打印函数
//void SeqList::list_display()
//{
//	cout << size;
//	for (int i = 0; i < size; ++i)
//	{
//		cout << " " << list[i];
//	}
//	cout << " " << endl;
//}
//
//
///// <summary>
///// 含参构造
///// 并且调用打印函数
///// </summary>
///// <param name="n">参数的长度</param>
///// <param name="arr">数组</param>
//SeqList::SeqList(const int n, const int* arr)
//{
//	maxsize = 100;
//	list = new int[maxsize];
//	size = n;
//	for (int i = 0; i < n; ++i)
//	{
//		list[i] = arr[i];
//	}
//	list_display();
//}
//
///// <summary>
///// 插入多个连续的数据
///// </summary>
///// <param name="i">插入位置</param>
///// <param name="n">插入数据的长度</param>
///// <param name="item">插入的数据</param>
//void SeqList::multiinsert(int i, int n, int item[])
//{
//	// 先判断能否插入，就是位置是否正确
//	if (i <= 0 || i > size + 1)
//	{
//		cout << "error" << endl;
//		return;
//	}
//	size += n;
//	// 先将插入位置及之后的原位置不断向后移动
//	for (int k = size - 1; k > i + n - 2; --k)
//	{
//		list[k] = list[k - n];
//	}
//	// 然后再将数据插入
//	for (int k = i - 1; k - (i - 1) < n; ++k)
//	{
//		list[k] = item[k - (i - 1)];
//	}
//	list_display();
//}
//
///// <summary>
///// 删除多个数据
///// </summary>
///// <param name="i">删除开始位置</param>
///// <param name="n">删除的数据长度</param>
//void SeqList::multidel(int i, int n)
//{
//	// 先判断删除的位置和长度是否正确
//	if (i <= 0 || i + n - 1 > size)
//	{
//		cout << "error" << endl;
//		return;
//	}
//	// 直接将删除位置之后的数据向前覆盖即可
//	for (int k = i - 1; k < size - n; ++k)
//	{
//		list[k] = list[k + n];
//	}
//	size -= n;
//	list_display();
//}
//
//int main(int argc, char** argv)
//{
//	int n;
//	cin >> n;
//	int* arr = new int[n];
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> *(arr + i);
//	}
//	// 建立对象
//	SeqList* seqlist = new SeqList(n, arr);
//
//	int pos;
//	int* data;
//	cin >> pos >> n;
//	data = new int[n];
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> data[i];
//	}
//	seqlist->multiinsert(pos, n, data);
//
//	cin >> pos >> n;
//	seqlist->multidel(pos, n);
//
//	delete[] data, arr;
//	
//	return 0;
//}