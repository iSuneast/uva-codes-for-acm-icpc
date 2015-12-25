/*
353 - Pesky Palindromes

string...
ö���ַ������Ӽ�����...
��Ȼ�ǵ�Ҫ����...
ֱ��������н�...
����Ȼ���ټ��㲻ͬ������...
*/

#include<iostream>
#include<string>
#include<algorithm>
#define MAXN 3210
using namespace std;

string key[MAXN],s;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(cin>>s)
	{
		int l=s.length(),tot=0;
		for(int i=0;i<l;++i)
			for(int j=1;i+j<=l;++j)
			{
				key[tot]=s.substr(i,j);
				bool bk=false;
				for(int k=0;k<j/2 && !bk;++k)
					if(key[tot][k]!=key[tot][j-1-k])
						bk=true;
				if(!bk)
					++tot;
			}
		sort(key,key+tot);
		int ans=1;
		for(int i=1;i<tot;++i)
			if(key[i]!=key[i-1])
				++ans;
		cout<<"The string '"<<s<<"' contains "<<ans<<" palindromes."<<endl;
	}

	return 0;
}
