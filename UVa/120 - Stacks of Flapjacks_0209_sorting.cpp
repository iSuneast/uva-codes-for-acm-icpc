/*
120 - Stacks of Flapjacks
....
*/

#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int stack[35],n,buf[35];
char in[100];

void print()
{
	for(int i=0;i<n;i++)
		cout<<stack[i]<<' ';
	cout<<endl;
}

void rev(int p)
{
	for(int i=0;i<p/2;i++)
		swap(stack[i],stack[p-i-1]);
}

int main()
{
//	freopen("in.txt","r",stdin);

	int j,p;
	while(gets(in))
	{
		n=0;
		puts(in);
		char *token=strtok(in," ");
		while(token!=NULL)
			sscanf(token,"%d",&stack[n++]),
			token=strtok(NULL," ");

		memcpy(buf,stack,sizeof(stack));
		sort(buf,buf+n);
		p=n-1;
		while(p>=0)
		{
			for(j=p;j>=0;j--)
				if(stack[j]==buf[p])
					break;
			if(p==j)
			{	p--;	continue;	}

			if(j)
				cout<<n-j<<' ',
				rev(j+1);
			cout<<n-p<<' ';
			rev(p+1);
		}
		cout<<0<<endl;
	}

return 0;
}
