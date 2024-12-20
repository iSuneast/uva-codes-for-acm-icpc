/*
11403 - Binary Multiplication

simulation...
UVa的水题也可以把人逼疯...
首先,输入文件有问题...
不是0 0结尾.于是只要读数据的时候没有!=EOF判断就会TLE
当然直接用cin是不会有这个问题的...
最后一组数据不是0 0而是其他东西的话应该加个回车.
不然WA...
天哪....
*/

#include<iostream>
#include<cstring>
using namespace std;
#define MAXN 80

char a[MAXN],b[MAXN],ans[MAXN];
int la,lb,l;

void init()
{
	la=strlen(a);
	lb=strlen(b);
	int i;
	memset(ans,0,sizeof(ans));
	for(i=0;i<la/2;++i)
		swap(a[i],a[la-1-i]);
	for(i=0;i<lb/2;++i)
		swap(b[i],b[lb-1-i]);
	for(i=0;i<la;++i)
		for(int j=0;j<lb;++j)
			ans[i+j]+=(a[i]-'0')*(b[j]-'0');
	l=la+lb;
	int carry=0;
	for(i=0;i<l;++i)
	{
		ans[i]+=carry;
		carry=ans[i]/2;
		ans[i]%=2;
		ans[i]+='0';
	}
	while(l>0 && ans[l-1]=='0')
		--l;
	for(i=0;i<l/2;++i)
		swap(ans[i],ans[l-1-i]);
	if(!l)
	{
		l=max(la,lb);
		for(int i=0;i<l;++i)
			ans[i]='0';
	}
	ans[l]=0;
}

void out()
{
	int i,j;
	for(i=0;i<l-la;++i)
		putchar(' ');
	for(i=la-1;i>=0;--i)
		putchar(a[i]);
	putchar('\n');
	for(i=0;i<l-lb;++i)
		putchar(' ');
	for(i=lb-1;i>=0;--i)
		putchar(b[i]);
	putchar('\n');

	int p=l-max(la,lb);
	for(i=0;i<p;++i)
		putchar(' ');
	for(i=p;i<l;++i)
		putchar('-');
	putchar('\n');

	for(i=0;i<lb;++i)
	{
		for(j=0;j<l-la-i;++j)
			putchar(' ');
		for(j=la-1;j>=0;--j)
			putchar((a[j]=='1'&&b[i]=='1')?'1':'0');
		putchar('\n');
	}
	for(i=0;i<l;++i)
		putchar('-');
	putchar('\n');
	puts(ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("11403_out.txt","w",stdout);
#endif

	bool first=true;
	while(scanf("%s%s",a,b)!=EOF && (strcmp(a,"0") || strcmp(b,"0")))
	{
		if(!first)
			putchar('\n');
		first=false;
		init();
		out();
	}
	if((strcmp(a,"0") || strcmp(b,"0")))
		putchar('\n');

	return 0;
}
