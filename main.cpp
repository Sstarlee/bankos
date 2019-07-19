#include<iostream>
#include<string.h>
#include<Windows.h>

using namespace std;
int main()
{
	int X, Y;
	int o = 0;
	int av[3];//现有资源
	int al[5][3]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};//已分配
	int max[5][3];//最大资源数
	int inmax[10][10];//输入的最大资源树
	int req[3];//请求分配数
	int ned[5][3]={{7,4,3},{1,2,2},{6,0,0},{0,1,1},{4,3,1}};//需求资源数
	char finsh[10][20] = { "false","false","false","false","false" };
	char binsh[10][20] = { "true","true" ,"true" ,"true" ,"true" };
	//是否满足进程要求
	int index[10][10] = {};
	int work[10];
	int count = 0;//排队
	int m = 0;
	int t=0;
	int l = 0;
	int n = 0;
	int p = 0;
	int w, k;
	int c = 0;
	int temp;

	int i, j;
	cout << "请输入进程数：" << endl;
	cin >> X;
	cout << "请输入资源种类数:" << endl;
	cin >> Y;
	/*已经分配资源的输入*/
	/*for (m = 0; m < X; m++)
	{
		cout << "请输入第" << m + 1 << "个进程的资源的已分配数" << endl;
		for (n = 0; n < Y; n++)
		{
			cin >> al[m][n];

		}
	}
	/*已经分配资源数目的输出*/
	cout<<"已经分配的资源（allou。。。）为："<<endl;
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
	/*需求资源的输入*/
	/*for (m = 0; m < X; m++)
	{
		cout << "请输入第" << m + 1 << "个进程的资源的需求（need)数" << endl;
		for (n = 0; n < Y; n++)
		{
			cin >> ned[m][n];

		}
	}
	/*need表的输出*/
	cout<<"需求的资源（need）为："<<endl;
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
	/*max表的输入*/


	/*while (1)
	{
		for (m = 0; m < X; m++)
		{
			cout << "请输入第" << m + 1 << "个进程的资源的max数" << endl;
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
				cout << "输入错误，请重新输入MAX表" << endl;
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



	/*现有资源数的输入和显示*/

	cout << "请输入可用资源数（AV....）：" << endl;
	for (m = 0; m < Y; m++)
	{
		cin >> av[m];
	}


		/*work赋值*/
	for (n = 0; n < Y; n++)
	{
		work[n] = av[n];
	}

	/*安全性算法*/

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
			cout << "进程" << k + 1 << "可满足！" << endl;
			cout <<  k + 1 << "--" << "finsh==" << "true" << endl;
			w--;

		}



	}

	if (count != X)
	{
		cout << "这是个不安全序列！" << endl;
		exit(0);

	}
	if(count==X)
	{
		cout << "这个队列是安全的！" << endl;
		count=0;

	}
	cout << "已分配资源（ALL）数为：" << endl;
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
	cout << "需求资源（need）数为：" << endl;
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

	cout<<"可用资源为："<<endl;
	for(int i = 0; i < Y; ++i)
	{
		cout<<av[i]<<"  ";
	}
	while(1){


	/*请求资源的输入*/
	cout<<"\n请输入要尝试分配的进程："<<endl;
	cin>>temp;
	cout << "请输入尝试请求的资源(request)：" << endl;
	for (m = 0; m < Y; m++)
	{
		cin >> req[m];
	}
	o=0;
	/*银行家算法部分*/
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
				cout<<"请求不合法！未满足need需求"<<"请重新输入："<<endl;

			}
			if (t!= Y)
			{
				cout<<"请求不合法！未满足aviable需求"<<"请重新输入："<<endl;

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
	cout << "分配后，剩余的资源（av）为：" << endl;
	for (int i = 0; i < Y; i++)
	{
		cout << av[i] << "\t";
		if (i == (Y - 1))
		{
			cout << endl;
		}
	}

	cout << "试分配后，已分配资源（ALL）数为：" << endl;
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
	cout << "试分配后，需求资源（need）数为：" << endl;
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

	/*work赋值*/
	for (n = 0; n < Y; n++)
	{
		work[n] = av[n];
	}

	/*安全性算法*/

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
			cout << "进程" << k + 1 << "可满足！" << endl;
			cout <<  k + 1 << "--" << "finsh==" << "true" << endl;
			w--;
		}



	}

	if (count != X)
	{
		cout << "这是个不安全序列！" << endl;

	}
	else {
		cout << "这个队列是安全的！" << endl;
	}


}
