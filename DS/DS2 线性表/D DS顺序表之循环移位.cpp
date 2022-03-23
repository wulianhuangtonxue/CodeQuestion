#include<iostream>
using namespace std;

class SeqList
{
private:
	int* list;		// Ԫ������
	int maxsize;	// ˳�����󳤶�
	int size;		// ˳���ʵ�ʳ���
public:
	SeqList();		//	���캯��
	~SeqList();		// ��������
	int list_size();	// ��ȡ˳���ʵ�ʳ���
	int list_insert(int i, int item);	// ����һ��Ԫ�أ�����Ϊ�����λ��
	int list_del(int i);				// ɾ��һ��Ԫ�أ�������ɾ����λ��
	int list_get(int i);				// ��ȡһ��Ԫ�أ������ǻ�ȡ��λ��
	void list_display();				// ��ȡһ��Ԫ�أ������ǻ�ȡ��λ��
	SeqList(const int n, const int* arr);			//  д��һ�����캯��������һ��
	void multiinsert(int i, int n, int item[]);		// ����������
	void multidel(int i, int n);						// ɾ���������
	void merge(int n, int* data1, int m, int* data2);		// ���������ݽ��кϲ�����ԭ˳���Ϊ��
	void CyclicShift(int flag, int n);					// ѭ����λ
};

// Ĭ�Ϲ���
SeqList::SeqList()
{
	maxsize = 1000;
	size = 0;
	list = new int[maxsize];
}

// ��������
SeqList::~SeqList()
{
	// ���տռ�
	delete[]list;
}

// ��ӡ����
void SeqList::list_display()
{
	for (int i = 0; i < size; ++i)
	{
		cout << list[i] << " ";
	}
	cout << endl;
}

/// <summary>
/// ���ι���
/// ���ҵ��ô�ӡ����
/// </summary>
/// <param name="n">�����ĳ���</param>
/// <param name="arr">����</param>
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
/// ѭ����λ����
/// �����ȸ����ƶ����򣬺ͳ��Ƚ���һ������
/// ���鱣����ߵĻ����ұߵĳ��ȵ�ԭ����
/// Ȼ��ֱ����λ����
/// ���������������Ҫ��λ�����ݽ��и���
/// </summary>
/// <param name="flag">0��������	1��������</param>
/// <param name="n">�ƶ��ĳ���</param>
void SeqList::CyclicShift(int flag, int n)
{
	int* arr = new int[n];
	if (flag == 0)
	{
		// �洢����
		for (int i = 0; i < n; ++i)
		{
			arr[i] = list[i];
		}
		// �����ֱ���ƶ���ǰ��
		for (int i = 0; i < size - n; ++i)
		{
			list[i] = list[i + n];
		}
		// ���ұߵ����������鸲��
		for (int i = size - n; i < size; ++i)
		{
			list[i] = arr[i - size + n];
		}
	}
	else
	{
		// �洢����
		for (int i = 0; i < n; ++i)
		{
			arr[i] = list[size - n + i];
		}
		// �����������ǰ��ĸ���
		for (int i = size - 1; i >= n; --i)
		{
			list[i] = list[i - n];
		}
		// ǰ��������鸲��
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
	// ��������
	SeqList* seqlist = new SeqList(n, arr);

	int flag;
	cin >> flag >> n;
	seqlist->CyclicShift(flag, n);

	cin >> flag >> n;
	seqlist->CyclicShift(flag, n);

	return 0;
}