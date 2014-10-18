#include <iostream>
#include <string>

using namespace std;

int n, m, sum, upperlim;
int ans[20];//记录状态，用来打印状态 


//输出答案 
void printAns()
{
	int i, j;
	int aa[20];
	for (i = 0; i<20; i++)
		aa[i] = ans[i];


	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			cout << aa[i] % 2 << ' ';
			aa[i] = aa[i] >> 1;

		}
		cout << endl;
	}
	cout << endl;
}

//row、ld和rd，分别表示在纵列和两个对角线方向的限制条件下这一行的哪些地方不能放
void test(int row, int ld, int rd)
{
	int pos, p;
	
	
	if (row != upperlim)
	{
		//取出当前可以放的状态,用1表示可以放 
		pos = upperlim&~(row | ld | rd);
		while (pos)
		{
			//取出最右边的第一个1 
			p = pos&-pos;
			ans[m] = p;
			m++;
			//减去这个状态 
			pos -= p;
			test(row + p, (ld + p) << 1, (rd + p) >> 1);
			m--;
		}

	}
	else
	{ 
		printAns(); //打印答案 
		sum++;
	}

}

int main()
{
	cout << "请输入皇后的个数：";
	cin >> n;
	m = 0;
	
	//先产生掩码，N个1，1表示不能放，0表示可以放 
	upperlim = (1 << n) - 1;
	cout <<endl<< "皇后摆法：" << endl<<endl;
	
	test(0, 0, 0);
	
	cout << "共有"<<sum<<"种解法！"<<endl;
	system("pause");
	return 0;
}
