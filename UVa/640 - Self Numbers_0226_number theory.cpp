/*
640 - Self Numbers
*/

#include<iostream>
#define N 1000001
using namespace std;

int num[N],t;

void d(int n)
{
	if(n>=N || !num[n])		//��������һ��n���ж�...
		return ;			//������д������ظ����㵼��TLE
	num[n]=0;
	t=n;
	while(t)
	{
		n+=t%10;
		t/=10;
	}
	d(n);
}

int main()
{
//	freopen("in.txt","r",stdin);

	int i,j;
	memset(num,1,sizeof(num));
	for(i=1;i<N;i++)
		if(num[i])
		{
			cout<<i<<endl;
			d(i);
		}

return 0;
}
