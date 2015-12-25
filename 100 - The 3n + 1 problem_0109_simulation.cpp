/*
100 - The 3n + 1 problem

�򵥵�ģ����.
�������ڼ�������ܻ��д������ظ�����,
������һ�����鱣���м���.
*/

#include<iostream>

using namespace std;

int num[1000003],res;

int calc(int num)
{
	int t=1;
	while(num!=1)
		{
			if(!(num%2))
				num/=2;
			else
				num=3*num+1;
			t++;
		}
	return t;
}

void ans(int i,int j)
{
	res=0;
	for(int t=i;t<=j;t++)
	{
		if(!num[t])
			num[t]=calc(t);
		res=res>num[t]?res:num[t];
	}
}

int main()
{
//	freopen("in.txt","r",stdin);

	int i,j;
	memset(num,0,sizeof(num));
	num[1]=1;
	while(cin>>i>>j)
	{
		if(i>j)
			ans(j,i);
		else
			ans(i,j);
		cout<<i<<' '<<j<<' '<<res<<endl;
	}

return 0;
}