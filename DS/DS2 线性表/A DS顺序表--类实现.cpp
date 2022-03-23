//#include<iostream>
//
//using namespace std;
//
//#define ok 0
//#define error -1
//
//// ˳�����
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
//// ����
//int SeqList::list_insert(int i, int item)
//{
//	// ���ж��ܷ����
//	if (i <= 0 || i > size + 1)
//	{
//		cout << "error" << endl;
//		return 0;
//	}
//	// �Ƚ�����λ�ü�֮���ԭλ�ò�������ƶ�
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
//// ɾ��
//int SeqList::list_del(int i)
//{
//	// ���ж�λ���Ƿ���ȷ
//	if (i <= 0 || i > size)
//	{
//		cout << "error" << endl;
//		return 0;
//	}
//	// ֱ�ӽ�ɾ��λ��֮���������ǰ���Ǽ���
//	for (int k = i - 1; k < size - 1; ++k)
//	{
//		list[k] = list[k + 1];
//	}
//	// �ߴ�-1
//	size--;
//	list_display();
//
//	return 0;
//}
//
//// ����
//int SeqList::list_get(int i)
//{
//	// ���ж�λ���Ƿ���ȷ
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
//	// ��������
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