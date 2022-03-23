//#include <list>
//#include <iostream> 
//#include<algorithm>
//#include<string>
//using namespace std;
//
//class Node
//{
//public:
//    string name;
//    int num;
//    Node(string name, int num)
//    {
//        this->name = name;
//        this->num = num;
//    }
//    Node()
//    {
//        name = "";
//        num = 0;
//    }
//};
//
//
//int main(int argc, char** argv)
//{
//    int* arr = new int[20];
//    for (int i = 0; i < 20; ++i)
//    {
//        arr[i] = i + 101;
//    }
//    int n;
//    cin >> n;
//    list<Node> used;
//    for (int i = 0; i < n; ++i)
//    {
//        string name;
//        int num;
//        cin >> name >> num;
//        Node node(name, num);
//        used.push_back(node);
//        arr[num - 101] = 0;
//    }
//    // ʹ��list���õ�sort ʹ��lamda���ʽ�����������򡪡������������������
//    used.sort([](const Node& a, const Node& b)
//        {
//            return a.num < b.num;
//        });
//    // δ������
//    list<int> free;
//    for (int i = 0; i < 20; ++i)
//    {
//        // δ��ʹ��
//        if (arr[i] > 100)
//        {
//            free.push_back(arr[i]);
//        }
//    }
//    int m;
//    cin >> m;
//    for (int i = 0; i < m; ++i)
//    {
//        string op;
//        cin >> op;
//        if (op == "assign")
//        {
//            string name;
//            cin >> name;
//            int num = free.front();
//            free.pop_front();
//            Node node(name, num);
//            used.push_front(node);
//        }
//        else if (op == "return")
//        {
//            int num;
//            cin >> num;
//            // �ҵ���Ӧ������
//            list<Node>::iterator it = used.begin();
//            while (it->num != num)
//            {
//                it++;
//            }
//            // �������õ�ɾ������ɾ��
//            used.erase(it);
//            free.push_back(num);
//        }
//        else if (op == "display_used")
//        {
//            used.sort([](const Node& a, const Node& b)
//                {
//                    return a.num < b.num;
//                });
//            int size = used.size();
//            int j = 1;
//            for (list<Node>::iterator it = used.begin(); j < size; ++it, ++j)
//            {
//                cout << it->name << "(" << it->num << ")-";
//            }
//            cout << used.back().name << "(" << used.back().num << ")" << endl;
//        }
//        else
//        {
//            int size = free.size();
//            int j = 1;
//            for (list<int>::iterator it = free.begin(); j < size; ++it, ++j)
//            {
//                cout << *it << "-";
//            }
//            cout << free.back() << endl;
//        }
//    }
//
//    return 0;
//}