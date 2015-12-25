/*
101 - The Blocks Problem
*/

#include<iostream>
#include<cstring>

using namespace std;

char cmd[2][25];
int block[25][25],num[25],n,a,b,x,y,x0,y0,t;

void print()
{
	for(int i=0;i<n;i++)
	{
		cout<<i<<':';
		for(int j=0;j<num[i];j++)
			cout<<' '<<block[i][j];
		cout<<endl;
	}
}

void find(int a)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<num[i];j++)
			if(a==block[i][j])
			{
				x=i,y=j;
				return ;
			}
}

void init(int a)
{
	int t;
	find(a);
	t=num[x];
	for(int i=y+1;i<t;i++)
		num[block[x][i]]++,num[x]--;
}

void move_onto(int a,int b)
{
	init(a);
	x0=x,y0=y;
	init(b);
	block[x][num[x]++]=block[x0][y0];
	num[x0]--;
//	print();
}

void move_over(int a,int b)
{
	init(a);
	x0=x,y0=y;
	find(b);
	block[x][num[x]++]=block[x0][y0],num[x0]--;
//	print();
}

void pile_onto(int a,int b)
{
	
	find(a);
	x0=x,y0=y;
	t=num[x0];
	init(b);
	for(int i=y0;i<t;i++)
		block[x][num[x]++]=block[x0][i],num[x0]--;
//	print();
}

void pile_over(int a,int b)
{
	
	find(a);
	x0=x,y0=y;
	t=num[x0];
	find(b);
	for(int i=y0;i<t;i++)
		block[x][num[x]++]=block[x0][i],num[x0]--;
//	print();
}



int main()
{
//	freopen("in.txt","r",stdin);
	int t0,t1;

	cin>>n;getchar();

	memset(block,0,sizeof(block));
	memset(num,0,sizeof(num));

	for(int i=0;i<n;i++)
		block[i][0]=i,num[i]=1;

	while(cin>>cmd[0])
		if(strcmp(cmd[0],"quit"))
		{
			cin>>a>>cmd[1]>>b;
			find(a);
			t0=x;t1=y;
			find(b);
			if(a!=b&&t0!=x)
			{
			if(cmd[0][0]=='m')
			{
				if(cmd[1][2]=='t')
					move_onto(a,b);
				else
					move_over(a,b);
			}
			else
			{
				if(cmd[1][2]=='t')
					pile_onto(a,b);
				else
					pile_over(a,b);
			}
			}
		}
		else
			break;
		print();

return 0;
}
