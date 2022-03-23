//#include<iostream>
//using namespace std;
//
//class SeqList
//{
//private:
//	int* list;		// Ԫ������
//	int maxsize;	// ˳�����󳤶�
//	int size;		// ˳���ʵ�ʳ���
//public:
//	SeqList();		//	���캯��
//	~SeqList();		// ��������
//	int list_size();	// ��ȡ˳���ʵ�ʳ���
//	int list_insert(int i, int item);	// ����һ��Ԫ�أ�����Ϊ�����λ��
//	int list_del(int i);				// ɾ��һ��Ԫ�أ�������ɾ����λ��
//	int list_get(int i);				// ��ȡһ��Ԫ�أ������ǻ�ȡ��λ��
//	void list_display();				// ��ȡһ��Ԫ�أ������ǻ�ȡ��λ��
//	SeqList(const int n, const int* arr);			//  д��һ�����캯��������һ��
//	void multiinsert(int i, int n, int item[]);		// ����������
//	void multidel(int i, int n);						// ɾ���������
//};
//
//// ���캯���������ʼ���趨
//SeqList::SeqList()
//{
//	maxsize = 1000;
//	size = 0;
//	list = new int[maxsize];
//}
//
//// ��������
//SeqList::~SeqList()
//{
//	// ���տռ�
//	delete[]list;
//}
//
//// ��ӡ����
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
///// ���ι���
///// ���ҵ��ô�ӡ����
///// </summary>
///// <param name="n">�����ĳ���</param>
///// <param name="arr">����</param>
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
///// ����������������
///// </summary>
///// <param name="i">����λ��</param>
///// <param name="n">�������ݵĳ���</param>
///// <param name="item">���������</param>
//void SeqList::multiinsert(int i, int n, int item[])
//{
//	// ���ж��ܷ���룬����λ���Ƿ���ȷ
//	if (i <= 0 || i > size + 1)
//	{
//		cout << "error" << endl;
//		return;
//	}
//	size += n;
//	// �Ƚ�����λ�ü�֮���ԭλ�ò�������ƶ�
//	for (int k = size - 1; k > i + n - 2; --k)
//	{
//		list[k] = list[k - n];
//	}
//	// Ȼ���ٽ����ݲ���
//	for (int k = i - 1; k - (i - 1) < n; ++k)
//	{
//		list[k] = item[k - (i - 1)];
//	}
//	list_display();
//}
//
///// <summary>
///// ɾ���������
///// </summary>
///// <param name="i">ɾ����ʼλ��</param>
///// <param name="n">ɾ�������ݳ���</param>
//void SeqList::multidel(int i, int n)
//{
//	// ���ж�ɾ����λ�úͳ����Ƿ���ȷ
//	if (i <= 0 || i + n - 1 > size)
//	{
//		cout << "error" << endl;
//		return;
//	}
//	// ֱ�ӽ�ɾ��λ��֮���������ǰ���Ǽ���
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
//	// ��������
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