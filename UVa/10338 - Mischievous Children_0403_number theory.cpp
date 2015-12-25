/*
10338 - Mischievous Children

组合数学...
算C(l,a)的时候注意点就是了...
foro有好方法...

key=n*(n-1)/2			一定是整数
key=n*(n-1)*(n-2)/3		一定是整数
......
所以......
*/

#include<iostream>
#include<string>
using namespace std;

long long c(int l,int a)
{
	long long key=l;
	for(int i=l-1;i>l-a;--i)
		key=key*i/(l-i+1);
	return key;
}

int main()
{
//	freopen("in.txt","r",stdin);

	long long ans;
	int dataset,i,hash[30],l;
	string buf;

	cin>>dataset;
	for(int cas=1;cas<=dataset;++cas)
	{
		cin>>buf;
		l=buf.length();
		memset(hash,0,sizeof(hash));
		for(i=0;i<l;++i)
			++hash[buf[i]-'A'];
		ans=1;
		for(i=0;i<30;++i)
			if(hash[i])
			{
				ans*=c(l,hash[i]);
				l-=hash[i];
			}
		cout<<"Data set "<<cas<<": "<<ans<<endl;
	}

	return 0;
}
