#include<iostream>
#include<string.h>
#include<Windows.h>

using namespace std;
int main()
{
	int X, Y;
	int o = 0;
	int av[10];//������Դ
	int al[10][10];//�ѷ���
	int max[10][10];//�����Դ��
	int inmax[10][10];//����������Դ��
	int req[10];//���������
	int ned[10][10];//������Դ��
	char finsh[10][20] = { "false","false","false","false","false" };
	char binsh[10][20] = { "true","true" ,"true" ,"true" ,"true" };
	//�Ƿ��������Ҫ��
	int index[10][10] = {};
	int work[10];
	int count = 0;//�Ŷ�
	int m = 0;
	int l = 0;
	int n = 0;
	int p = 0;
	int w, k;
	int c = 0;

	int i, j;
	cout << "�������������" << endl;
	cin >> X;
	cout << "��������Դ������:" << endl;
	cin >> Y;
	/*�Ѿ�������Դ������*/
	for (m = 0; m < X; m++)
	{
		cout << "�������" << m + 1 << "�����̵���Դ���ѷ�����" << endl;
		for (n = 0; n < Y; n++)
		{
			cin >> al[m][n];

		}
	}
	/*�Ѿ�������Դ��Ŀ�����*/
	for (m = 0; m < X; m++)
		for (n = 0; n < Y; n++)
		{
			cout << al[m][n];
			cout << "\t";
			if (n == (Y - 1))
			{
				cout << endl;
			}
		}
	/*������Դ������*/
	for (m = 0; m < X; m++)
	{
		cout << "�������" << m + 1 << "�����̵���Դ������need)��" << endl;
		for (n = 0; n < Y; n++)
		{
			cin >> ned[m][n];

		}
	}
	/*need������*/
	for (m = 0; m < X; m++)
		for (n = 0; n < Y; n++)
		{
			cout << ned[m][n];
			cout << "\t";
			if (n == (Y - 1))
			{

				cout << endl;
			}
		}
	/*max�������*/


	while (1)
	{
		for (m = 0; m < X; m++)
		{
			cout << "�������" << m + 1 << "�����̵���Դ��max��" << endl;
			for (n = 0; n < Y; n++)
			{
				cin >> inmax[m][n];
				max[m][n] = ned[m][n] + al[m][n];
			}
			for (n = 0; n < Y; n++)
			{
				if (inmax[m][n] != max[m][n])
				{
					p = 1;
				}
			}
			if (p == 1)
			{
				cout << "�����������������MAX��" << endl;
				p = 0;
				break;
			}
			else
			{
				l = m;
				continue;
			}

		}
		if (l == (X - 1))
		{
			break;
		}
	}

	

	/*������Դ�����������ʾ*/
	cout << "�����������Դ����AV....����" << endl;
	for (m = 0; m < Y; m++)
	{
		cin >> av[m];
	}

	/*������Դ������*/
	cout << "�����볢���������Դ(request)��" << endl;
	for (m = 0; m < Y; m++)
	{
		cin >> req[m];
	}

	/*���м��㷨����*/
	for (m = 0; m < X; m++)
	{
		for (n = 0; n < Y; n++)
		{
			if (req[n] <= ned[m][n] && req[n] <= av[n])
			{
				o++;
			}
			else
			{
				o = 0;
				break;
			}
		}
		if (o == Y)
		{
			for (n = 0; n < Y; n++)
			{
				av[n] = av[n] - req[n];
				al[m][n] = al[m][n] + req[n];
				ned[m][n] = ned[m][n] - req[n];
			}
			c++;
			break;
		}
	}
	if (c == 1)
	{

		cout << "������request�Ľ�����Ϊ:" << m + 1 << endl;

	}
	if (c == 0)
	{
		cout << "���Է���ʧ�ܣ��޿�������Դ��" << endl;
		exit(0);

	}

	cout << "�����ʣ�����Դ��av��Ϊ��" << endl;
	for (int i = 0; i < Y; i++)
	{
		cout << av[i] << "\t";
		if (i == (Y - 1))
		{
			cout << endl;
		}
	}

	cout << "�Է�����ѷ�����Դ��ALL����Ϊ��" << endl;
	for (m = 0; m < X; m++)
	{
		for (int i = 0; i < Y; i++)
		{
			cout << al[m][i] << "\t";
			if (i == (Y - 1))
			{
				cout << endl;
			}
		}
	}
	cout << "�Է����������Դ��need����Ϊ��" << endl;
	for (m = 0; m < X; m++)
	{
		for (i = 0; i < Y; i++)
		{
			cout << ned[m][i] << "\t";
			if (i == (Y - 1))
			{
				cout << endl;
			}
		}
	}

	/*work��ֵ*/
	for (n = 0; n < Y; n++)
	{
		work[n] = av[n];
	}
	for (n = 0; n < Y; n++)
	{
		cout << work[n];
	}

	
	/*��ȫ���㷨*/
	
	w = 0;

	for (i = 0; i < X; i++)
	{
		for (m = 0; m < X; m++)
		{
			if (index[m][0] == 2)
			{
				continue;
			}

			for (n = 0; n < Y; n++)
			{
				if (ned[m][n] <= work[n])
				{
					o++;
				}
				else
				{
					continue;
				}
			}

			if (o == Y)
			{
				for (n = 0; n < Y; n++)
				{
					work[n] = work[n] + al[m][n];
					index[m][n] = 2;
				}
				w++;
				k = m;
				count++;
				o = 0;
				//strcpy_s(finsh[m], binsh[m]);
				break;
			}
			else
			{
				o = 0;
				continue;
			}
		}
		if (w == 0)
		{
			continue;
		}

		if (w>0 && count>0 && count <= X)


		{
			cout << "����" << k + 1 << "�����㣡" << endl;
			cout <<  k + 1 << "--" << "finsh==" << "true" << endl;
			w--;
		}



	}

	if (count != X)
	{
		cout << "���Ǹ�����ȫ���У�" << endl;

	}
	else {
		cout << "��������ǰ�ȫ�ģ�" << endl;
	}


}
