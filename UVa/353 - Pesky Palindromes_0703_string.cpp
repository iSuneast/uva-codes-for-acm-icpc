/*
353 - Pesky Palindromes

string...
枚举字符串的子集即可...
当然记得要判重...
直接算出所有解...
排序然后再计算不同串个数...
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
