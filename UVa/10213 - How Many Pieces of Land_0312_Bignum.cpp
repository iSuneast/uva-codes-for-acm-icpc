/*
10213 - How Many Pieces of Land ?

Big num...
公式推了好久.

欧拉公式	V-E+F=2
其中		V=n+n/4*[sum(i*(n-2-i))]{from i=0->n-2}
			E=n+n/2*[sum(i*(n-2-i)+1)]{from i=0->n-2}
代入欧拉公式可得
			ans=E-V+1
			   =(n*(n-1)/2) * ((n-2)*(n-3)/12+1) +1;
接下来用大数高精运算即可正确求解.
*/

#include<iostream>
#define MAXN 40
using namespace std;

long long gcd(long long a,long long b)
{
	if(a<=0)
		return 1;
	else
		return b==0?a:gcd(b,a%b);
}

int main()
{
//	freopen("in.txt","r",stdin);

	int s,ans[MAXN],p1,p2,p,i,j,carry;
	long long n,t1,t2,a,b,c,d,t,rem;
	char buf1[MAXN],buf2[MAXN];
	cin>>s;
	while(s--)
	{
		cin>>n;

		a=n;b=n-1;c=n-2;d=n-3;		//消去分母部分
		rem=24;
		t=gcd(a,rem);a/=t;rem/=t;
		t=gcd(b,rem);b/=t;rem/=t;
		t=gcd(c,rem);c/=t;rem/=t;
		t=gcd(d,rem);d/=t;rem/=t;

		t1=a*b;						//产生bignum的种子.
		t2=c*d;
		memset(buf1,0,sizeof(buf1));
		memset(buf2,0,sizeof(buf2));
		sprintf(buf1,"%lld",t1);
		sprintf(buf2,"%lld",t2);

		p1=strlen(buf1);			//初始化bign
		p2=strlen(buf2);
		for(i=0;i<p1/2;i++)
			swap(buf1[i]-='0',buf1[p1-1-i]-='0');
		if(p1%2)
			buf1[p1/2]-='0';
		for(i=0;i<p2/2;i++)
			swap(buf2[i]-='0',buf2[p2-1-i]-='0');
		if(p2%2)
			buf2[p2/2]-='0';

		memset(ans,0,sizeof(ans));	//求解
		ans[0]=1;
		for(i=0;i<p1;i++)
			for(j=0;j<p2;j++)
				ans[i+j]+=buf1[i]*buf2[j];
		p=p1+p2+1;

		t1=n*(n-1)/2;
		sprintf(buf1,"%lld",t1);
		p1=strlen(buf1);
		for(i=0;i<p1/2;i++)
			swap(buf1[i]-='0',buf1[p1-1-i]-='0');
		if(p1%2)
			buf1[p1/2]-='0';
		for(i=0;i<p1;i++)
			ans[i]+=buf1[i];

		carry=0;					//格式化解.
		for(i=0;i<=p;i++)
		{
			ans[i]+=carry;
			carry=ans[i]/10;
			ans[i]%=10;
		}

		while(p>=0 && !ans[p])		//输出.
			p--;
		for(i=p;i>=0;i--)
			cout<<ans[i];
		cout<<endl;
	}

return 0;
}
