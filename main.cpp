#include<iostream>
#include<string.h>
#include<Windows.h>

using namespace std;
int main()
{
	int X, Y;
	int o = 0;
	int av[3];//������Դ
	int al[5][3]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};//�ѷ���
	int max[5][3];//�����Դ��
	int inmax[10][10];//����������Դ��
	int req[3];//���������
	int ned[5][3]={{7,4,3},{1,2,2},{6,0,0},{0,1,1},{4,3,1}};//������Դ��
	char finsh[10][20] = { "false","false","false","false","false" };
	char binsh[10][20] = { "true","true" ,"true" ,"true" ,"true" };
	//�Ƿ��������Ҫ��
	int index[10][10] = {};
	int work[10];
	int count = 0;//�Ŷ�
	int m = 0;
	int t=0;
	int l = 0;
	int n = 0;
	int p = 0;
	int w, k;
	int c = 0;
	int temp;

	int i, j;
	cout << "�������������" << endl;
	cin >> X;
	cout << "��������Դ������:" << endl;
	cin >> Y;
	/*�Ѿ�������Դ������*/
	/*for (m = 0; m < X; m++)
	{
		cout << "�������" << m + 1 << "�����̵���Դ���ѷ�����" << endl;
		for (n = 0; n < Y; n++)
		{
			cin >> al[m][n];

		}
	}
	/*�Ѿ�������Դ��Ŀ�����*/
	cout<<"�Ѿ��������Դ��allou��������Ϊ��"<<endl;
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
	/*for (m = 0; m < X; m++)
	{
		cout << "�������" << m + 1 << "�����̵���Դ������need)��" << endl;
		for (n = 0; n < Y; n++)
		{
			cin >> ned[m][n];

		}
	}
	/*need������*/
	cout<<"�������Դ��need��Ϊ��"<<endl;
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


	/*while (1)
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


		/*work��ֵ*/
	for (n = 0; n < Y; n++)
	{
		work[n] = av[n];
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

			}

			if (o == Y)
			{
				for (n = 0; n < Y; n++)
				{
					work[n] = work[n] + al[m][n];
					index[m][0] = 2;
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
		exit(0);

	}
	if(count==X)
	{
		cout << "��������ǰ�ȫ�ģ�" << endl;
		count=0;

	}
	cout << "�ѷ�����Դ��ALL����Ϊ��" << endl;
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
	cout << "������Դ��need����Ϊ��" << endl;
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

	cout<<"������ԴΪ��"<<endl;
	for(int i = 0; i < Y; ++i)
	{
		cout<<av[i]<<"  ";
	}
	while(1){


	/*������Դ������*/
	cout<<"\n������Ҫ���Է���Ľ��̣�"<<endl;
	cin>>temp;
	cout << "�����볢���������Դ(request)��" << endl;
	for (m = 0; m < Y; m++)
	{
		cin >> req[m];
	}
	o=0;
	/*���м��㷨����*/
			for(n=0;n<Y;n++)
		{	if (req[n] <= ned[temp][n])
			{
				o++;
			}
			if( req[n] <= av[n])
			{
				t++;
			}
		}

			if (o != Y)
			{
				cout<<"���󲻺Ϸ���δ����need����"<<"���������룺"<<endl;

			}
			if (t!= Y)
			{
				cout<<"���󲻺Ϸ���δ����aviable����"<<"���������룺"<<endl;

			}




		if (o == Y&&t==Y)
		{
			for (n = 0; n < Y; n++)
			{
				av[n] = av[n] - req[n];
				al[temp][n] = al[temp][n] + req[n];
				ned[temp][n] = ned[temp][n] - req[n];
			}
                break;
		}
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

	/*��ȫ���㷨*/

	w = 0;
	o=0;

	for (j = 0; j < X; j++)
	{
		for (m = 0; m < X; m++)
		{
			if (index[m][0] == 3)
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
					index[m][n] = 3;
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
