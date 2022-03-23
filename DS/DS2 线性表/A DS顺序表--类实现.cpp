//#include<iostream>
//
//using namespace std;
//
//#define ok 0
//#define error -1
//
//// 顺序表定义
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
//// 插入
//int SeqList::list_insert(int i, int item)
//{
//	// 先判断能否插入
//	if (i <= 0 || i > size + 1)
//	{
//		cout << "error" << endl;
//		return 0;
//	}
//	// 先将插入位置及之后的原位置不断向后移动
//	for (int k = size; k > i - 1; --k)
//	{
//		list[k] = list[k - 1];
//	}
//	list[i - 1] = item;
//	size++;
//	list_display();
//
//	return 0;
//}
//
//// 删除
//int SeqList::list_del(int i)
//{
//	// 先判断位置是否正确
//	if (i <= 0 || i > size)
//	{
//		cout << "error" << endl;
//		return 0;
//	}
//	// 直接将删除位置之后的数据向前覆盖即可
//	for (int k = i - 1; k < size - 1; ++k)
//	{
//		list[k] = list[k + 1];
//	}
//	// 尺寸-1
//	size--;
//	list_display();
//
//	return 0;
//}
//
//// 查找
//int SeqList::list_get(int i)
//{
//	// 先判断位置是否正确
//	if (i <= 0 || i > size)
//	{
//		cout << "error" << endl;
//		return 0;
//	}
//
//	cout << list[i - 1] << endl;
//	return 0;
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
//	int pos, data;
//	cin >> pos >> data;
//	seqlist->list_insert(pos, data);
//	
//	cin >> pos >> data;
//	seqlist->list_insert(pos, data);
//
//	cin >> pos;
//	seqlist->list_del(pos);
//
//	cin >> pos;
//	seqlist->list_del(pos);
//
//	cin >> pos;
//	seqlist->list_get(pos);
//
//	cin >> pos;
//	seqlist->list_get(pos);
//
//	return 0;
//}