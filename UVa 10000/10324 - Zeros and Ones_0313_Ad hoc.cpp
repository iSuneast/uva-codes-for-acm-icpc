/*
10324 - Zeros and Ones
*/

#include<iostream>
#define MAXN 1000001
using namespace std;
char buf[MAXN];
int key[MAXN];		//保存相同序列的起点信息
int main()
{
//	freopen("in.txt","r",stdin);
	int n,s,e,i,cas=1,l,p;
	while(gets(buf))
	{
		memset(key,0,sizeof(key));
		l=strlen(buf);
		p=0;
		i=1;
		while(i<l)
		{
			while(i<l && buf[i]==buf[p])
				key[i++]=p;
			p=i;
		}
		cin>>n;
		cout<<"Case "<<cas++<<":"<<endl;
		for(i=0;i<n;i++)
		{
			cin>>s>>e;
			if(s>e)
				swap(s,e);
			if(s<key[e])
				cout<<"No"<<endl;
			else
				cout<<"Yes"<<endl;
		}
		getchar();
	}

return 0;
}
