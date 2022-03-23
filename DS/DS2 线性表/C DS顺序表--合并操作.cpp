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
//	void merge(int n, int* data1, int m, int* data2);		// ���������ݽ��кϲ�����ԭ˳���Ϊ��
//};
//
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
///// <summary>
///// �ϲ���������
///// </summary>
///// <param name="n">����һ�ĳ���</param>
///// <param name="data1">����һ</param>
///// <param name="m">���ж��ĳ���</param>
///// <param name="data2">���ж�</param>
//void SeqList::merge(int n, int* data1, int m, int* data2)
//{
//	size = n + m;
//	// ����ָ���±�
//	int p1 = 0, p2 = 0;
//	for (int i = 0; i < size; ++i)
//	{
//		// ָ���ڷ�Χ��ʱ
//		if (p1 < n && p2 < m && data1[p1] <= data2[p2])
//		{
//			list[i] = data1[p1++];
//		}
//		else if (p1 < n && p2 < m && data1[p1] > data2[p2])
//		{
//			list[i] = data2[p2++];
//		}
//		// ָ�벻�ڷ�Χ��
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