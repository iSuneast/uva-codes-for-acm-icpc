/*
725 - Division
*/

#include<iostream>

using namespace std;

int buf[10];

void div(int a)
{
	if(a<10000)
		buf[0]=1;
	while(a)
	{
		buf[a%10]=1;
		a/=10;
	}
}

int fit(int a,int b)
{
	int i;
	memset(buf,0,sizeof(buf));
	div(a),div(b);
	for(i=0;i<10;i++)
		if(!buf[i])
			return 0;
	return 1;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int a,b,n,flag,end=0;
	while(cin>>n&&n)
	{
		flag=0;
		if(end)
			cout<<endl;
		for(b=1234;b<100000;b++)
		{
			a=b*n;
			if(a>100000)
				break;
			if(fit(a,b))
				printf("%05d / %05d = %d\n",a,b,n),flag=1;
		}
		if(!flag)
			printf("There are no solutions for %d.\n",n);
		end=1;
	}

return 0;
}
