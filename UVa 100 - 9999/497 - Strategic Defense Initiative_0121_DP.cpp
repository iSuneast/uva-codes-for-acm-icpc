/*
497 - Strategic Defense Initiative
...
...
*/

#include<iostream>
#include<cstring>

using namespace std;

int hint[1000],num[1000],n,m,t,cas,flag=1;

void input()
{
	char str[32];
	n=0;
	if(flag)
		getchar(),getchar(),flag=0;
	while(gets(str))
		if(str[0])
			num[n++]=atoi(str);
		else
			break;
	memset(hint,0,sizeof(hint));
	hint[0]=1;
}

void calc()
{
	int i,t,j;
	for(i=1;i<n;i++)
	{
		t=i;
		for(j=0;j<i;j++)
			if((num[j]<=num[i])&&(hint[t]<hint[j]))
				t=j;
			hint[i]=hint[t]+1;
	}
	for(m=0,i=1;i<n;i++)
		if(hint[i]>hint[m])
			m=i;
}

void output(int p)
{
	int i;
	for(i=p-1;i>=0;i--)
		if((hint[i]==(hint[p]-1))&&(num[i]<=num[p]))
		{
			output(i),cout<<num[p]<<endl;
			return ;
		}
		cout<<num[p]<<endl;
}

int main()
{
	cin>>cas;
	while(cas--)
	{
		input();
		calc();
		cout<<"Max hits: "<<hint[m]<<endl;
		output(m);
		if(cas)
			cout<<endl;
	}

return 0;
}
