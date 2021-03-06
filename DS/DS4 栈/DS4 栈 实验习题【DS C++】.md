# DS4 栈 实验习题【DS C++】 

[TOC]

## 前言

> 昨天做数据结构实验，发挥挺拉的，尤其是最后一问求波兰式和逆波兰式课下想了很久才有思路。然后代码实现的时候还是遇到了不少bug，疯狂debug到第二天1点多。。。
>
> 话不多说，来看一下这些折磨人的小妖精吧。
>
> 本次的代码都放在我的GitHub仓库上，需要的可以去看看[CodeQuestion/DS/DS4 栈 at master · wulianhuangtonxue/CodeQuestion (github.com)](https://github.com/wulianhuangtonxue/CodeQuestion/tree/master/DS/DS4 栈)



## A. 前驱后继（线性结构）

### 题目描述

> 在双向链表中，A有一个指针指向了后继节点B，同时，B又有一个指向前驱节点A的指针。这样不仅能从链表头节点的位置遍历整个链表所有节点，也能从链表尾节点开始遍历所有节点。
>
> 对于给定的一列数据，按照给定的顺序建立双向链表，按照关键字找到相应节点，输出此节点的前驱节点关键字及后继节点关键字。

#### 输入

> 第一行两个正整数n（代表节点个数），m（代表要找的关键字的个数）。
>
> 接下来输入n个整数为关键字key（数据保证关键字在数列中没有重复）。
>
> 接下来有m个要查找的关键字，每个占一行。

#### 输出

> 对给定的每个关键字，输出此关键字前驱节点关键字和后继节点关键字。如果给定的关键字没有前驱或者后继，则不输出。给定关键字为每个输出占一行。

#### 输入样例

> 10 3
> 1 2 3 4 5 6 7 8 9 0
> 3
> 1
> 0

#### 输出样例

> 2 4
> 2
> 9



### 编码思路

> 基本上和单链表差不多，加多一个pre指针，指向前置节点。



### Code（C++）

```cpp
#include<iostream>

using namespace std;

// 定义双向链表节点
class ListNode
{
public:
	int val;
	ListNode* next, *pre;
public:
	ListNode() {};
	ListNode(int v) : val(v), next(nullptr), pre(nullptr){}
};

// 定义双向链表
class LinkList
{
private:
	// 头节点和尾节点
	ListNode* head, * tail;
	int len;
public:
	// 构造函数，初始化链表
	// 传入数组
	LinkList(int len, int* arr)
	{
		this->len = len;
		// 先构造头节点
		head = new ListNode(arr[0]);
		ListNode* node = head->next;
		ListNode* pre = head;
		// 遍历数组，和单链表过程差不多，但是需要加一个加节点前置指针指向pre
		for (int i = 1; i < len; ++i)
		{
			node = new ListNode(arr[i]);
			pre->next = node;
			node->pre = pre;
			node = node->next;
			pre = pre->next;
		}
		// 尾节点
		tail = node;
	}
	// 找到Key节点，然后输出前置和后置
	void getKey(int key)
	{
		ListNode* node = head;
		// 这里其实可以使用双指针去遍历，降低到O(n/2)
		for (int i = 0; i < len; ++i)
		{
			if (node->val == key)
			{
				break;
			}
			node = node->next;
		}
		if (node != nullptr)
		{
			// 先判断是不是前置和后置指针都有
			if (node->pre != nullptr && node->next != nullptr)
			{
				cout << node->pre->val << " " << node->next->val;
			}
			else if (node->pre != nullptr)
			{
				cout << node->pre->val;
			}
			else
			{
				cout << node->next->val;
			}
			cout << endl;
		}
	}
};

int main(int argc, char** argv)
{
	int n;
	cin >> n;
	int m;
	cin >> m;
	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	LinkList* list = new LinkList(n, arr);
	for (int i = 0; i < m; ++i)
	{
		int key;
		cin >> key;
		list->getKey(key);
	}

	return 0;
}
```



> 代码中其实有可以优化的地方，比如说构造的时候也可以双向构造，不过影响不大，主要是找到Key的时候，可以采用双指针去遍历，有效降低时间复杂度，提高性能。



## B. DS堆栈--逆序输出（STL栈使用）

### 题目描述

> C++中已经自带堆栈对象stack，无需编写堆栈操作的具体实现代码。
>
> 本题目主要帮助大家熟悉stack对象的使用，然后实现字符串的逆序输出
>
> 输入一个字符串，按字符按输入顺序压入堆栈，然后根据堆栈后进先出的特点，做逆序输出

> ![LCIzz8.png](https://s6.jpg.cm/2022/03/23/LCIzz8.png)



#### 输入

> 第一行输入t，表示有t个测试实例
> 第二起，每一行输入一个字符串，注意字符串不要包含空格
>
> 字符串的输入可以考虑一下代码：
>
> \#include <string>
>
> int main()
>
> { string str;
>
>  Int len;
>
>  cin>>str; //把输入的字符串保存在变量str中
>
>  len = str.length() //获取输入字符串的长度
>
> }

#### 输出

> 每行逆序输出每一个字符串

#### 输入样例

> 2
> abcdef
> aabbcc

#### 输出样例

> fedcba
> ccbbaa

### 编码思路

直接按题目来就行了。



### Code（C++）

```cpp
#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
	int t;
	cin >> t;
	while (t--)
	{
		string str;
		cin >> str;
		stack<char> chstk;
		// 直接遍历字符串
		for (char& ch : str)
		{
			// 压栈
			chstk.push(ch);
		}
		// 然后不断出栈
		while (!chstk.empty())
		{
			cout << chstk.top();
			chstk.pop();
		}
		cout << endl;
	}

	return 0;
}
```



## C. DS堆栈--行编辑

### 题目描述

> 使用C++的STL堆栈对象，编写程序实现行编辑功能。行编辑功能是：当输入#字符，则执行退格操作；如果无字符可退就不操作，不会报错
>
> 本程序默认不会显示#字符，所以连续输入多个#表示连续执行多次退格操作
>
> 每输入一行字符打回车则表示字符串结束
>
> 注意：必须使用堆栈实现，而且结果必须是正序输出

#### 输入

> 第一行输入一个整数t，表示有t行字符串要输入
> 第二行起输入一行字符串，共输入t行

#### 输出

> 每行输出最终处理后的结果，如果一行输入的字符串经过处理后没有字符输出，则直接输出NULL

#### 输入样例

> 4
> chinaa#
> sb#zb#u
> ##shen###zhen###
> chi##a#####

#### 输出样例

> china
> szu
> sz
> NULL

### 编码思路

我们用栈存储字符，识别到#的时候，判断栈是否为空，不空则栈顶出栈。

### Code（C++）

```cpp
#include<iostream>
#include<stack>
#include<string>
using namespace std;

/// <summary>
/// 行编辑函数
/// </summary>
/// <param name="s"></param>
void lineEdit(string s)
{
	// 使用两个栈，一个用于存储，一个用于输出
	stack<char> stk1, stk2;
	for (char& ch : s)
	{
		// 识别到不是 # 则压栈 
		if (ch != '#')
		{
			stk1.push(ch);
		}
		// 判断栈是否空，不空则出栈
		else if (!stk1.empty())
		{
			stk1.pop();
		}
	}
	// 如果遍历完，栈1为空，则直接输出，并跳出
	if (stk1.empty())
	{
		cout << "NULL" << endl;
		return;
	}
	// 否则，则需要使用另外一个栈将原栈的元素顺序倒置，然后才输出
	while (!stk1.empty())
	{
		stk2.push(stk1.top());
		stk1.pop();
	}
	while (!stk2.empty())
	{
		cout << stk2.top();
		stk2.pop();
	}
	cout << endl;
}

int main(int argc, char** argv)
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		lineEdit(s);
	}

	return 0;
}
```



## D. DS堆栈--括号匹配

### 题目描述

> 处理表达式过程中需要对括号匹配进行检验，括号匹配包括三种：“(”和“)”，“[”和“]”，“{”和“}”。例如表达式中包含括号如下：
>
> ```
> (	)	[	(	)	(	[	]	)	]	{	}
> 1	2	3	4	5	6	7	8	9	10	11	12
> ```
>
> 从上例可以看出第1和第2个括号匹配，第3和第10个括号匹配，4和5匹配，6和9匹配，7和8匹配，11和12匹配。从中可以看到括号嵌套的的情况是比较复杂的，使用堆栈可以很方便的处理这种括号匹配检验，可以遵循以下规则：
>
> 1、 当接收第1个左括号，表示新的一组匹配检查开始；随后如果连续接收到左括号，则不断进堆栈。
>
> 2、 当接受第1个右括号，则和最新进栈的左括号进行匹配，表示嵌套中1组括号已经匹配消除
>
> 3、 若到最后，括号不能完全匹配，则说明输入的表达式有错
>
> 建议使用C++自带的stack对象来实现

![LCI2Gi.png](https://s6.jpg.cm/2022/03/23/LCI2Gi.png)

#### 输入

> 第一行输入一个t，表示下面将有t组测试数据。接下来的t行的每行输入一个表达式，表达式只考虑英文半角状态输入，无需考虑中文全角输入

#### 输出

> 对于每一行的表达式，检查括号是否匹配，匹配则输入ok，不匹配则输出error

#### 输入样例

```
2
(a+b)[4*5+(-6)]
[5*8]/{(a+b)-6
```

#### 输出样例

```
ok
error
```

#### 提示

> 算法流程
>
> 1、初始化，i=0，建立堆栈，栈为空
> 2、输入表达式，建立指针指向表达式的头部
> 3、读入表达式的第i个字符
> 4、如果第i个字符是左括号，入栈
> 5、如果第i个字符是右括号，检查栈顶元素是否匹配
>   A.如果匹配，弹出栈顶元素
>   B.如果不匹配，报错退出
> 6、i++，指向下一个字符，是否已经表达式末尾
>   A. 未到末尾，重复步骤3
>   B. 已到达末尾
>    a. 堆栈为空，输出ok
>    b. 堆栈不为空，输出error

### 编码思路

其实提示，写得蛮清楚的了，按照流程来即可。

### Code（C++）

```cpp
#include<iostream>
#include<string>
#include<stack>
using namespace std;

// 括号匹配函数
void ParMatch(string s)
{
	stack<char> stk;
	// 用于记录最终是否成功匹配
	bool flag = true;
	for (char& ch : s)
	{
		// 左括号入栈
		if (ch == '(' || ch == '[' || ch == '{')
		{
			stk.push(ch);
		}
		// 右括号出栈，匹配
		else if (!stk.empty() && 
				(ch == '}'  && stk.top() == '{' 
				|| ch == ']' && stk.top() == '[' 
				|| ch == ')' && stk.top() == '('))
		{
			stk.pop();
		}
		// 匹配不成功 直接退出
		else if (ch == '}' || ch == ')' || ch == ']')
		{
			flag = false;
			break;
		}
	}
	// 判断栈是否为空，以及是否匹配成功
	if (!stk.empty() || flag == false)
	{
		cout << "error" << endl;
	}
	else
	{
		cout << "ok" << endl;
	}
}

int main(int argc, char** argv)
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		ParMatch(s);
	}
	return 0;
}
```



## E. DS堆栈--迷宫求解

### 题目描述

> 给出一个N*N的迷宫矩阵示意图，从起点[0,0]出发，寻找路径到达终点[N-1, N-1]
>
> 要求使用堆栈对象来实现，具体算法参考课本3.2.4节51页

#### 输入

> 第一行输入t，表示有t个迷宫
>
> 第二行输入n，表示第一个迷宫有n行n列
>
> 第三行起，输入迷宫每一行的每个方格的状态，0表示可通过，1表示不可通过
>
> 输入n行
>
> 以此类推输入下一个迷宫

#### 输出

> 逐个输出迷宫的路径
>
> 如果迷宫不存在路径，则输出no path并回车
>
> 如果迷宫存在路径，将路径中每个方格的x和y坐标输出，从起点到终点，每输出四个方格就换行，最终以单词END结尾，具体格式参考示范数据
>
> 输出的代码参考如下：
>
> //path是保存路径的堆栈，堆栈中每个元素都包含x坐标和y坐标，用属性xp和yp表示
>
> //path1是一个临时堆栈，把path的数据倒序输出到path1，使得路径按正序输出
>
> ​	if (!path.empty())	//找到路径
>
> ​	{	//......若干代码，实现path的数据导入path1
>
> ​		i=0;  //以下是输出路径的代码
>
> ​		while (!path1.empty())
>
> ​		{	cpos = path1.top();
>
> ​			if ( (++i)%4 == 0 ) 
>
> ​				cout<<'['<<cpos.xp<<','<<cpos.yp<<']'<<"--"<<endl;
>
> ​			else
>
> ​				cout<<'['<<cpos.xp<<','<<cpos.yp<<']'<<"--";
>
> ​			path1.pop();
>
> ​		}
>
> ​		cout<<"END"<<endl;
>
> ​	}
>
> ​	else
>
> ​		cout<<"no path"<<endl; //找不到路径输出no path

#### 输入样例

```
2
8
0 0 0 1 1 1 1 1
1 0 0 0 1 0 0 1
1 0 0 0 1 0 0 0
1 1 0 0 0 0 0 1
0 0 1 1 0 1 1 0
0 0 0 0 0 0 1 1
1 1 1 1 1 0 0 1
0 0 0 0 1 0 0 0
7
0 0 0 1 1 1 1
1 0 0 1 0 0 1
1 0 0 1 0 0 0
1 1 0 0 0 0 1
0 0 1 1 0 1 0
1 0 0 0 0 1 0
0 0 0 0 1 1 0

```

#### 输出样例

```
[0,0]--[0,1]--[0,2]--[1,2]--
[1,3]--[2,3]--[3,3]--[3,4]--
[4,4]--[5,4]--[5,5]--[6,5]--
[6,6]--[7,6]--[7,7]--END
no path
```

### 编码思路

这里采用DFS还是BFS都可以，推荐使用DFS，函数递归使用程序自身的栈，如果我们能够到达终点，则开始递归将坐标存进栈，注意，我们和题目直接给出的思路不同，题目需要在搜索的过程中将坐标压栈入栈，而我们的思路则可以减少不必要的压栈和出栈操作，性能提高。

注意：因为OJ的原因，即使一个样例有多条路径可选，但只有oj内部答案的样例才算通过，所以根据样例我们可以猜测向右的优先级高于向下。以此类推。

### Code（C++）

```cpp
#include<iostream>
#include<stack>
#include<utility>
using namespace std;

class Solution
{
public:
	// 路径栈，存储路径的坐标
	stack<pair<int, int>> path;
	const int dx[4] = { 0, 1, 0, -1 };
	const int dy[4] = { 1, 0, -1, 0 };

	// 寻找路径函数
	stack<pair<int, int>> findpath(int n,int** arr)
	{
		// 先判断起始点是否可以通过
		if (arr[0][0] == 1)
		{
			return {};
		}
		bool flag = true;
		// 调用dfs函数搜索路径
		dfs(arr, 0, 0, n, flag);
		return path;
	}
	/// <summary>
	/// DFS搜索路径
	/// </summary>
	/// <param name="arr">迷宫</param>
	/// <param name="x">当前x坐标</param>
	/// <param name="y">当前y坐标</param>
	/// <param name="n">迷宫尺寸</param>
	/// <param name="flag">是否到达终点标识符</param>
	void dfs(int** arr, int x, int y, int n, bool& flag)
	{
		// 如果到达终点
		if (x == n - 1 && y == n - 1)
		{
			// 压栈
			path.push({x, y});
			// 标识符
			flag = false;
			return;
		}
		// 避免出现下一个位置直接回退，造成不必要的时间浪费
		arr[x][y] = -1;
		for (int i = 0; i < 4 && flag; ++i)
		{
			// 下一坐标计算
			int nx = x + dx[i];
			int ny = y + dy[i];
			// 判断下一坐标是否可走
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && arr[nx][ny] == 0)
			{
				dfs(arr, nx, ny, n, flag);
			}
		}
		// 找到路径，递归回来直接压栈
		if (!flag)
		{
			path.push({ x, y });
		}

	}
};

void display(stack<pair<int, int>> path)
{
	if (!path.empty())	//找到路径
	{	
		int i = 0;
		while (!path.empty())
		{
			auto cops = path.top();
			cout << '[' << cops.first << "," << cops.second << "]--";
			if ((++i) % 4 == 0)
			{
				cout << endl;
			}
			path.pop();
		}
		cout << "END" << endl;
	}
	else
	{
		cout << "no path" << endl; //找不到路径输出no path
	}
}


int main(int argc, char** argv)
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int** arr = new int*[n];
		for (int i = 0; i < n; ++i)
		{
			arr[i] = new int[n];
			for (int j = 0; j < n; ++j)
			{
				cin >> arr[i][j];
			}
		}
		Solution sol;
		auto path = sol.findpath(n, arr);
		display(path);
	}


	return 0;
}
```



## F. DS栈—波兰式，逆波兰式

### 题目描述

> 表达式有三种表示方法，分别为：
>
>   前缀表示(波兰式)：运算符+操作数1+操作数2
>
>   中缀表示：操作数1+运算符+操作数2
>
>   后缀表示(逆波兰式)：操作数1+操作数2+运算符
>
>   例如：a +b * (c -d ) - e/f
>
>   波兰式：-+a*b-cd/ef   （运算符在操作数的前面，用递归计算波兰式）
>
>   中缀式：a+b*c-d-e/f  
>
>   逆波兰式：abcd-*+ef/-  （运算符在操作数的后面，用栈计算逆波兰式）
>
> ​    中缀表示就是原表达式去掉扣号。    
>
>    根据表达式求波兰式、逆波兰式都是教材第三章表达式求值的思想。   

> 求波兰式，需要操作数栈(注意不是计算结果入栈，有计算式入栈)，运算符栈。区别在于从后往前扫描表达式，‘(’ 换成')','('换成‘)’。栈顶运算符优先级>新读入运算符优先级出栈，教材第三章表3.1中的相同运算符优先级>（从左往右计算）改为<，例如栈顶为‘+‘，新读入的为‘+’，则栈顶优先级<新读入的优先级。
>
>    求逆波兰式，只需要运算符栈。操作数直接输出，操作符按表3.1优先级顺序出栈，输出。
>
> 
>
> ​    输入表达式，求其波兰式和逆波兰式。

#### 输入

>  测试次数
>
> 每组测试数据一行，一个合法表达式

#### 输出

>  对每组测试数据，输出两行
>
> 第一行，表达式的波兰表示
>
> 第二行，表达式的逆波兰表示
>
> 不同组测试数据间以空行分隔。

#### 输入样例

```
2
4+2*3-10/5
12+3*5+(2+10)*5 

```



#### 输出样例

```
- + 4 * 2 3 / 10 5
4 2 3 * + 10 5 / -

+ + 12 * 3 5 * + 2 10 5
12 3 5 * + 2 10 + 5 * +
```



### 编码思路

1. 存储输入数据采用字符串
2. 波兰式，我们需要两个栈，一个用于存储操作符，一个用于存储操作数（其实最终还是需要存储操作符）
3. 波兰式采用逆序遍历，这是波兰式，也就是前缀式的原因，需要将操作符先输出，所以最终需要将操作符栈的元素出栈压栈给操作数栈。
4. 波兰式，对于遍历到的操作符，如果优先级低于栈顶，需要将栈顶出栈再入栈，保证最终的输出符合前缀式。
5. 对于括号，括号内的优先级是最高的，但是最终输出并不需要括号，所以操作数并不需要怎么管，括号内的操作符在遍历完括号操作符（一对）之后则需要将括号内的操作符出栈。
6. 逆波兰式，采取正向遍历即可，而且不需要使用操作数栈，直接输出，而操作符栈则需要存储。
7. 由于遍历的顺序不同，所以需要对于运算符的优先级采取不同的判断。
8. 注意字符串的拼接细节，由于C++的特性，不能将字符串常量直接和char拼接。

### Code（C++）

```cpp
#include<iostream>
#include<string>
#include<stack>
#include<sstream>
using namespace std;

class Solution
{
private:
	stack<string> nums;		// 存储操作数, 实际上会存储操作符的
	stack<char> op;			// 存储操作符

	// 逆向遍历时判断操作符优先级
	bool opcmpRight(char op1, char op2)
	{
		// + - 的时候，只需要判断栈顶是否同级，逆序，同级新的优先级更高
		if (op1 == '+' || op1 == '-')
		{
			return op2 == '+' || op2 == '-';
		}
		// * / 直接入栈
		return true;
	}

	// 正向遍历时判断操作符优先级
	bool opcmpLeft(char op1, char op2)
	{
		// 正向的时候，同级新的优先级会低
		if (op1 == '*' || op1 == '/')
		{
			return op2 != '*' && op2 != '/';
		}
		return false;
	}
public:
	// 求解波兰式
	string poland(string s)
	{
		int len = s.length();
		// 逆序遍历字符串
		for (int i = len - 1; i >= 0; --i)
		{
			// 数字存栈
			if (s[i] >= '0' && s[i] <= '9')
			{
				// 字符串拼接
				string num = "";
				num += s[i];
				// 判断前置是否是数字
				while (i - 1 >= 0 && s[i - 1] >= '0' && s[i - 1] <= '9')
				{
					num = s[--i] + num;
				}
				// 将数字入栈
				nums.push(num);
			}
			// 操作符
			// 判断栈是否空，或者有右括号
			else if (op.empty() || s[i] == ')' || op.top() == ')')
			{
				op.push(s[i]);
			}
			// 识别到左括号，此时需要将括号内的操作符输出
			else if (s[i] == '(')
			{
				// 操作数栈存储括号内的操作符
				while (!op.empty() && op.top() != ')')
				{
					string ops = "";
					ops += op.top();
					nums.push(ops);
					op.pop();
				}
				// 右括号出栈
				op.pop();
			}
			// 优先级高于栈顶，无脑入栈
			else if (opcmpRight(s[i], op.top()))
			{
				op.push(s[i]);
			}
			// 优先级低于栈顶
			else
			{
				// 操作符出栈并存入操作数栈
				while (!op.empty() && !opcmpRight(s[i], op.top()))
				{
					string ops = "";
					ops += op.top();
					nums.push(ops);
					op.pop();
				}
				// 压栈
				op.push(s[i]);
			}
		}
		// 将最终操作符栈压入操作数栈中
		while (!op.empty())
		{
			string ops = "";
			ops += op.top();
			nums.push(ops);
			op.pop();
		}
		// 得出答案
		string ans = "";
		while (!nums.empty())
		{
			ans += nums.top() + (nums.size() > 1 ? " " : "");
			nums.pop();
		}
		return ans;
	}

	// 求解逆波兰式
	string antiPoland(string s)
	{
		int len = s.size();
		string ans = "";
		// 正向遍历
		for (int i = 0; i < len; ++i)
		{
			// 数字直接加入答案
			if (s[i] >= '0' && s[i] <= '9')
			{
				ans += s[i];
				while (i + 1 < len && s[i + 1] >= '0' && s[i + 1] <= '9')
				{
					ans += s[++i];
				}
				ans += " ";
			}
			// 操作符的情况则需要和波兰式类似存栈
			// 栈空，左括号
			else if (op.empty() || s[i] == '(' || op.top() == '(')
			{
				op.push(s[i]);
			}
			// 右括号则需要输出括号内的操作符
			else if (s[i] == ')')
			{
				while (!op.empty() && op.top() != '(')
				{
					ans += op.top();
					ans += " ";
					op.pop();
				}
				op.pop();
			}
			// 判断优先级
			else if (opcmpLeft(s[i], op.top()))
			{
				op.push(s[i]);
			}
			else
			{
				while (!op.empty() && !opcmpLeft(s[i], op.top()))
				{
					ans += op.top();
					ans += " ";
					op.pop();
				}
				op.push(s[i]);
			}
		}
		// 将栈中输出到答案中
		while (!op.empty())
		{
			ans += op.top();
			ans += op.size() > 1 ? " " : "";
			op.pop();
		}
		return ans;
	}
};

int main(int argc, char** argv)
{
	int t;
	cin >> t;
	while (t--)
	{
		Solution sol;
		string s;
		cin >> s;
		cout << sol.poland(s) << endl;
		cout << sol.antiPoland(s) << endl << endl;
	}

	return 0;
}
```



## 后话

> 关于波兰式的问题，有些题目可能会有更多的操作符以及变量，其实后者只需要在比较优先级函数更改即可，前者在遍历的时候加一些语句也可以实现。
>
> 有机会的话，会专门写一篇细谈波兰之类的栈的blog。