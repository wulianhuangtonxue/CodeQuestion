//#include<iostream>
//#include<stack>
//#include<utility>
//using namespace std;
//
//class Solution
//{
//public:
//	// 路径栈，存储路径的坐标
//	stack<pair<int, int>> path;
//	const int dx[4] = { 0, 1, 0, -1 };
//	const int dy[4] = { 1, 0, -1, 0 };
//
//	// 寻找路径函数
//	stack<pair<int, int>> findpath(int n,int** arr)
//	{
//		// 先判断起始点是否可以通过
//		if (arr[0][0] == 1)
//		{
//			return {};
//		}
//		bool flag = true;
//		// 调用dfs函数搜索路径
//		dfs(arr, 0, 0, n, flag);
//		return path;
//	}
//	/// <summary>
//	/// DFS搜索路径
//	/// </summary>
//	/// <param name="arr">迷宫</param>
//	/// <param name="x">当前x坐标</param>
//	/// <param name="y">当前y坐标</param>
//	/// <param name="n">迷宫尺寸</param>
//	/// <param name="flag">是否到达终点标识符</param>
//	void dfs(int** arr, int x, int y, int n, bool& flag)
//	{
//		// 如果到达终点
//		if (x == n - 1 && y == n - 1)
//		{
//			// 压栈
//			path.push({x, y});
//			// 标识符
//			flag = false;
//			return;
//		}
//		// 避免出现下一个位置直接回退，造成不必要的时间浪费
//		arr[x][y] = -1;
//		for (int i = 0; i < 4 && flag; ++i)
//		{
//			// 下一坐标计算
//			int nx = x + dx[i];
//			int ny = y + dy[i];
//			// 判断下一坐标是否可走
//			if (nx >= 0 && nx < n && ny >= 0 && ny < n && arr[nx][ny] == 0)
//			{
//				dfs(arr, nx, ny, n, flag);
//			}
//		}
//		// 找到路径，递归回来直接压栈
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
//	if (!path.empty())	//找到路径
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
//		cout << "no path" << endl; //找不到路径输出no path
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