//#include<iostream>
//
//using namespace std;
//
//class ListNode
//{
//public:
//	int val;
//	ListNode* next, *pre;
//public:
//	ListNode() {};
//	ListNode(int v) : val(v), next(nullptr), pre(nullptr){}
//};
//
//class LinkList
//{
//private:
//	ListNode* head, * tail;
//	int len;
//public:
//	LinkList(int len, int* arr)
//	{
//		this->len = len;
//		head = new ListNode(arr[0]);
//		ListNode* node = head->next;
//		ListNode* pre = head;
//		for (int i = 1; i < len; ++i)
//		{
//			node = new ListNode(arr[i]);
//			pre->next = node;
//			node->pre = pre;
//			node = node->next;
//			pre = pre->next;
//		}
//		tail = node;
//	}
//	void getKey(int key)
//	{
//		ListNode* node = head;
//		for (int i = 0; i < len; ++i)
//		{
//			if (node->val == key)
//			{
//				break;
//			}
//			node = node->next;
//		}
//		if (node != nullptr)
//		{
//			if (node->pre != nullptr && node->next != nullptr)
//			{
//				cout << node->pre->val << " " << node->next->val;
//			}
//			else if (node->pre != nullptr)
//			{
//				cout << node->pre->val;
//			}
//			else
//			{
//				cout << node->next->val;
//			}
//			cout << endl;
//		}
//	}
//};
//
//int main(int argc, char** argv)
//{
//	int n;
//	cin >> n;
//	int m;
//	cin >> m;
//	int* arr = new int[n];
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> arr[i];
//	}
//	LinkList* list = new LinkList(n, arr);
//	for (int i = 0; i < m; ++i)
//	{
//		int key;
//		cin >> key;
//		list->getKey(key);
//	}
//
//	return 0;
//}