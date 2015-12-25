/*
10719 - Quotient Polynomial
*/

#include<iostream>
#include<cstring>

using namespace std;

int a[10010],b[10010],r,k,cnt;
char buf[100000];

void format()
{
	getchar();
	cnt=0;
	gets(buf);
	char *token=strtok(buf," ");
	while(token!=NULL)
	{
		sscanf(token,"%d",&a[cnt++]);
		token=strtok(NULL," ");
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i;
	while(cin>>k)
	{
		format();
		cout<<"q(x):";
		cout<<' '<<(b[1]=a[0]);
		for(i=2;i<cnt;i++)
			cout<<' '<<(b[i]=a[i-1]+k*b[i-1]);
		cout<<"\nr = "<<a[cnt-1]+k*b[cnt-1]<<endl;
		cout<<endl;
	}

return 0;
}
