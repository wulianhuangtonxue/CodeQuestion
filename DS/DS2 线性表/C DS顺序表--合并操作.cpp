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
//	void merge(int n, int* data1, int m, int* data2);		// 将两组数据进行合并，且原顺序表为空
//};
//
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
///// <summary>
///// 合并递增序列
///// </summary>
///// <param name="n">序列一的长度</param>
///// <param name="data1">序列一</param>
///// <param name="m">序列二的长度</param>
///// <param name="data2">序列二</param>
//void SeqList::merge(int n, int* data1, int m, int* data2)
//{
//	size = n + m;
//	// 两个指针下标
//	int p1 = 0, p2 = 0;
//	for (int i = 0; i < size; ++i)
//	{
//		// 指针在范围内时
//		if (p1 < n && p2 < m && data1[p1] <= data2[p2])
//		{
//			list[i] = data1[p1++];
//		}
//		else if (p1 < n && p2 < m && data1[p1] > data2[p2])
//		{
//			list[i] = data2[p2++];
//		}
//		// 指针不在范围内
//		else if (p1 == n)
//		{
//			list[i] = data2[p2++];
//		}
//		else
//		{
//			list[i] = data1[p1++];
//		}
//	}
//	list_display();
//}
//
//
//int main(int argc, char** argv)
//{
//	int n, m;
//	cin >> n;
//	int* data1 = new int[n];
//	for(int i = 0; i < n; ++i)
//	{
//		cin >> data1[i];
//	}
//	cin >> m;
//	int* data2 = new int[m];
//	for (int i = 0; i < m; ++i)
//	{
//		cin >> data2[i];
//	}
//	SeqList* seqlist = new SeqList();
//
//	seqlist->merge(n, data1, m, data2);
//
//	delete[] data1, data2;
//
//	return 0;
//}