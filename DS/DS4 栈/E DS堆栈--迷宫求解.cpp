//#include<iostream>
//#include<stack>
//#include<utility>
//using namespace std;
//
//class Solution
//{
//public:
//	// ·��ջ���洢·��������
//	stack<pair<int, int>> path;
//	const int dx[4] = { 0, 1, 0, -1 };
//	const int dy[4] = { 1, 0, -1, 0 };
//
//	// Ѱ��·������
//	stack<pair<int, int>> findpath(int n,int** arr)
//	{
//		// ���ж���ʼ���Ƿ����ͨ��
//		if (arr[0][0] == 1)
//		{
//			return {};
//		}
//		bool flag = true;
//		// ����dfs��������·��
//		dfs(arr, 0, 0, n, flag);
//		return path;
//	}
//	/// <summary>
//	/// DFS����·��
//	/// </summary>
//	/// <param name="arr">�Թ�</param>
//	/// <param name="x">��ǰx����</param>
//	/// <param name="y">��ǰy����</param>
//	/// <param name="n">�Թ��ߴ�</param>
//	/// <param name="flag">�Ƿ񵽴��յ��ʶ��</param>
//	void dfs(int** arr, int x, int y, int n, bool& flag)
//	{
//		// ��������յ�
//		if (x == n - 1 && y == n - 1)
//		{
//			// ѹջ
//			path.push({x, y});
//			// ��ʶ��
//			flag = false;
//			return;
//		}
//		// ���������һ��λ��ֱ�ӻ��ˣ���ɲ���Ҫ��ʱ���˷�
//		arr[x][y] = -1;
//		for (int i = 0; i < 4 && flag; ++i)
//		{
//			// ��һ�������
//			int nx = x + dx[i];
//			int ny = y + dy[i];
//			// �ж���һ�����Ƿ����
//			if (nx >= 0 && nx < n && ny >= 0 && ny < n && arr[nx][ny] == 0)
//			{
//				dfs(arr, nx, ny, n, flag);
//			}
//		}
//		// �ҵ�·�����ݹ����ֱ��ѹջ
//		if (!flag)
//		{
//			path.push({ x, y });
//		}
//
//	}
//};
//
//void display(stack<pair<int, int>> path)
//{
//	if (!path.empty())	//�ҵ�·��
//	{	
//		int i = 0;
//		while (!path.empty())
//		{
//			auto cops = path.top();
//			cout << '[' << cops.first << "," << cops.second << "]--";
//			if ((++i) % 4 == 0)
//			{
//				cout << endl;
//			}
//			path.pop();
//		}
//		cout << "END" << endl;
//	}
//	else
//	{
//		cout << "no path" << endl; //�Ҳ���·�����no path
//	}
//}
//
//
//int main(int argc, char** argv)
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n;
//		cin >> n;
//		int** arr = new int*[n];
//		for (int i = 0; i < n; ++i)
//		{
//			arr[i] = new int[n];
//			for (int j = 0; j < n; ++j)
//			{
//				cin >> arr[i][j];
//			}
//		}
//		Solution sol;
//		auto path = sol.findpath(n, arr);
//		display(path);
//	}
//
//
//	return 0;
//}