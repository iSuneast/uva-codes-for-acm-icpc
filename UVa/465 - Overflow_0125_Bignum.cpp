/*
465 - Overflow

Bign
´óÕûÊı
*/

#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>

using namespace std;

char c,buf[3000],a[1000],b[1000],num[]="2147483647";
int fa,fb;

int big(char *s)
{
	if(strlen(s)>10)
		return 1;
	else if(strlen(s)==10)
		return strcmp(s,num)>0?1:0;
	return 0;
}

int res()
{
	char ans[1000];
	long long x,y;
	x=atoi(a);
	y=atoi(b);
	if(c=='+')
	{
		if(fa||fb)
			return 1;
		if(x+y>2147483647)
			return 1;
		return 0;
	}	
	if(strlen(a)==0||strlen(b)==0)
		return 0;
	if(fa||fb)
		return 1;
	else if(x*y>2147483647||x*y<0)
		return 1;
	return 0;

} 

void format(char *s)
{
	int l=strlen(s),j=0;
	while(s[j]=='0')
		j++;
	strcpy(s,s+j);
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("465.txt","w",stdout);
	int i,j;
	while(gets(buf))
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));

		fa=fb=0;
		cout<<buf<<endl;
		{
			i=j=0;
			while(isdigit(buf[i]))
				a[i]=buf[i],i++;
			a[i]='\0';
			while(buf[i]==' ')
				i++;
			c=buf[i++];
			while(buf[i]==' ')
				i++;
			while(isdigit(buf[i]))
				b[j++]=buf[i++];
			b[j]='\0';

		}
		memset(buf,0,sizeof(buf));
		format(a);
		if(big(a))
			cout<<"first number too big"<<endl,fa=1;
		format(b);
		if(big(b))
			cout<<"second number too big"<<endl,fb=1;
		if(res())
			cout<<"result too big"<<endl;//*/
	}

return 0;
}
