#include <iostream>
#include <string>

using namespace std;

int n, m, sum, upperlim;
int ans[20];//��¼״̬��������ӡ״̬ 


//����� 
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

//row��ld��rd���ֱ��ʾ�����к������Խ��߷����������������һ�е���Щ�ط����ܷ�
void test(int row, int ld, int rd)
{
	int pos, p;
	
	
	if (row != upperlim)
	{
		//ȡ����ǰ���Էŵ�״̬,��1��ʾ���Է� 
		pos = upperlim&~(row | ld | rd);
		while (pos)
		{
			//ȡ�����ұߵĵ�һ��1 
			p = pos&-pos;
			ans[m] = p;
			m++;
			//��ȥ���״̬ 
			pos -= p;
			test(row + p, (ld + p) << 1, (rd + p) >> 1);
			m--;
		}

	}
	else
	{ 
		printAns(); //��ӡ�� 
		sum++;
	}

}

int main()
{
	cout << "������ʺ�ĸ�����";
	cin >> n;
	m = 0;
	
	//�Ȳ������룬N��1��1��ʾ���ܷţ�0��ʾ���Է� 
	upperlim = (1 << n) - 1;
	cout <<endl<< "�ʺ�ڷ���" << endl<<endl;
	
	test(0, 0, 0);
	
	cout << "����"<<sum<<"�ֽⷨ��"<<endl;
	system("pause");
	return 0;
}
