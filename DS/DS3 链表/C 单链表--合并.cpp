//#include<iostream>
//using namespace std;
//#define ok 0
//#define error -1
//
//// ����ڵ��ඨ��
//class ListNode
//{
//public:
//	int data;
//	ListNode* next;
//	ListNode()
//	{
//		next = NULL;
//	}
//	// ����һ�����ι���
//	ListNode(int val)
//	{
//		data = val;
//		next = NULL;
//	}
//};
//// ��ͷ�ڵ�ĵ������ඨ��
//class LinkList
//{
//public:
//	ListNode* head;
//	int len;
//	// ��������
//	LinkList();
//	// ����һ�����ι���
//	LinkList(int n, int* arr);
//	~LinkList();
//	ListNode* LL_index(int i);		// ���ص�i������ָ�룬��������ڷ���NULL
//	int LL_get(int i);				// ���ص�i��Ԫ�ص�����
//	int LL_insert(int i, int item);	// ����ֵitem�����i��λ��
//	int LL_del(int i);				// ɾ����i���ڵ�
//	void LL_display();				// ��������������
//	void swap(int pa, int pb);		// pa��pb��ʾ��������ڵ������λ�����
//	int LL_merge(ListNode* La, ListNode* Lb);	// �ϲ���������
//};
//
//LinkList::LinkList()
//{
//	head = new ListNode();
//	len = 0;
//}
//// ������գ�Ҫ����ڵ����
//LinkList::~LinkList()
//{
//	ListNode* p, * q;
//	p = head;
//	while (p != NULL)
//	{
//		q = p;
//		p = p->next;
//		delete q;
//	}
//	len = 0;
//	head = NULL;
//}
///// <summary>
///// �������鹹�쵥����
///// </summary>
///// <param name="n">���鳤��</param>
///// <param name="arr">����</param>
//LinkList::LinkList(int n, int* arr)
//{
//	head = new ListNode();
//	len = n;
//	// ������һ����ֵ�ڵ㣬��ͷ�ڵ�֮��Ľڵ�
//	ListNode* node = new ListNode(arr[0]);
//	head->next = node;
//	// ��ʣ�µ�Ԫ�ش��������
//	for (int i = 1; i < n; ++i)
//	{
//		ListNode* newNode = new ListNode(arr[i]);
//		node->next = newNode;
//		node = node->next;
//	}
//}
//
//void LinkList::LL_display()
//{
//	ListNode* p;
//	p = head->next;
//	while (p)
//	{
//		cout << p->data << ' ';
//		p = p->next;
//	}
//	cout << endl;
//}
//
//// ����Ԫ��
//ListNode* LinkList::LL_index(int i)
//{
//	// ���ж�λ��
//	if (i < 1 || i > len)
//	{
//		cout << "error" << endl;
//		return NULL;
//	}
//	ListNode* node = head->next;
//	for (int index = 1; index < i; ++index)
//	{
//		node = node->next;
//	}
//	cout << node->data << endl;
//	return node;
//}
//
//// ����Ԫ��
//int LinkList::LL_insert(int i, int item)
//{
//	// ���ж�
//	if (i < 1 || i > len + 1)
//	{
//		cout << "error" << endl;
//		return 0;
//	}
//	// �ҵ�����λ��ԭ�ڵ��ǰ�ýڵ�
//	ListNode* node = head->next;
//	ListNode* pre = head;
//	for (int index = 1; index < i; ++index)
//	{
//		pre = pre->next;
//		node = node->next;
//	}
//	ListNode* insertNode = new ListNode(item);
//	pre->next = insertNode;
//	insertNode->next = node;
//	len++;
//	LL_display();
//
//	return 0;
//}
//
//// ɾ��Ԫ��
//int LinkList::LL_del(int i)
//{
//	// ���ж�
//	if (i < 1 || i > len)
//	{
//		cout << "error" << endl;
//		return 0;
//	}
//	// �ҵ�����λ��ԭ�ڵ��ǰ�ýڵ�
//	ListNode* node = head->next;
//	ListNode* pre = head;
//	for (int index = 1; index < i; ++i)
//	{
//		pre = pre->next;
//		node = node->next;
//	}
//	// ��ǰ�ýڵ��nextָ��ָ��ǰ�ڵ��nextָ��
//	pre->next = node->next;
//	--len;
//	// ȥ��node�Ŀռ�
//	delete node;
//
//	LL_display();
//	return 0;
//}
//
//// �������
//void LinkList::swap(int pa, int pb)
//{
//	// ���ж�
//	if (pa < 0 || pa > len || pb < 0 || pb > len)
//	{
//		cout << "error" << endl;
//		return;
//	}
//	// �����ڵ��ǰ�ýڵ�
//	ListNode* pre1 = head, * pre2 = head;
//	// ѭ���ҵ�λ��
//	for (int i = 1; i < pa || i < pb; ++i)
//	{
//		if (i < pa)
//		{
//			pre1 = pre1->next;
//		}
//		if (i < pb)
//		{
//			pre2 = pre2->next;
//		}
//	}
//	ListNode* node1 = pre1->next, * node2 = pre2->next;
//	// ���ڽ���
//	ListNode* temp = node1->next;
//	node1->next = node2->next;
//	node2->next = temp;
//	pre1->next = node2;
//	pre2->next = node1;
//
//	LL_display();
//}
//
//// �ϲ�������������
//int LinkList::LL_merge(ListNode* La, ListNode* Lb)
//{
//	ListNode* node = head;
//	while (La != NULL || Lb != NULL)
//	{
//		if (La != NULL && Lb != NULL)
//		{
//			if (La->data <= Lb->data)
//			{
//				node->next = new ListNode(La->data);
//				La = La->next;
//			}
//			else
//			{
//				node->next = new ListNode(Lb->data);
//				Lb = Lb->next;
//			}
//		}
//		else if (La == NULL)
//		{
//			node->next = new ListNode(Lb->data);
//			Lb = Lb->next;
//		}
//		else
//		{
//			node->next = new ListNode(La->data);
//			La = La->next;
//		}
//		node = node->next;
//		len++;
//	}
//	LL_display();
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
//		cin >> arr[i];
//	}
//	LinkList* La = new LinkList(n, arr);
//	delete[] arr;
//	cin >> n;
//	arr = new int[n];
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> arr[i];
//	}
//	LinkList* Lb = new LinkList(n, arr);
//	LinkList* list = new LinkList();
//	list->LL_merge(La->head->next, Lb->head->next);
//
//	delete[]arr;
//	delete La, Lb, list;
//
//	return 0;
//}