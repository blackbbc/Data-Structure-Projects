#include <iostream>
#include <cstring>
#include <fstream>
#pragma warning(disable:4996)

using namespace std;

int i, j, n, m;

/**
a��Ҫ�ҵ��ı�
b�ǹؼ���
text�Ǳ������ı��е��ı�������ֵ����a
temp�����ڶ�ȡ�ı�ʱ�Ļ�����
p��kmp�㷨�ĳ�ʼ������
*/

char b[100], temp[10000], text[10000], a[10000];
int p[100];

ifstream fin;
ofstream fout;

//kmp�㷨Ѱ�� 
int find()
{
	int i, j, sum = 0;
	j = -1;

	for (i = 0; i<n; i++)
	{
		while (j >= 0 && b[j + 1] != a[i])
			j = p[j];

		if (b[j + 1] == a[i])
			j++;
		if (j == m - 1)
		{
			//            return (i-m+1);
			sum = sum + 1;
			j = p[j];
		}

	}

	return sum;
}

//kmp�㷨��ʼ�� 
void initial()
{
	p[0] = -1;
	j = -1;

	for (i = 1; i<m; i++)
	{

		while (j >= 0 && b[j + 1] != b[i])
			j = p[j];
		if (b[j + 1] == b[i])
			j++;
		p[i] = j;
	}
}

//��ȡ�ı����������ļ��� 
void getText()
{
	char filename[255];
	cout << "�ؼ��ּ���ϵͳ" << endl;
	cout << "�������ļ�����";
	cin >> filename;

	fout.open(filename);

	cout << "������һ��Ӣ�ģ�" << endl;
	while (cin.getline(temp, 10000))
		strcat(text, temp);

	//�������λ 
	cin.clear();

	fout << text;
	fout.close();

	cout << "������Ҫ�����Ĺؼ��֣�";
	cin.getline(b, 100);
	m = strlen(b);

	cout << "��ʾԴ�ļ�\" " << filename << " \"" << endl << endl;

	fin.open(filename);
	while (fin.getline(temp, 10000))
		strcat(a, temp);
	n = strlen(a);
	cout << a << endl;

	strlwr(a);

}


void findText()
{
	initial();

	cout << "��Դ�ļ��й���������" << find() << " ���ؼ���\" " << b << " \"" << endl;
}

int main()
{
	getText();
	findText();

	system("pause");
	return 0;
}
