/*
10896 - Known Plaintext Attack

string...
字符映射..
*/

#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	string key,buf,tmp;
	int dataset;
	scanf("%d",&dataset);
	getline(cin,buf);
	while(dataset--)
	{
		getline(cin,buf);
		getline(cin,key);
		int key_len=key.length();
		char ans[30],cnt=0;

		stringstream sin(buf);		
		while(sin>>tmp)
		{
			int l=tmp.length();
			if(l!=key_len)
				continue;
			int p=(tmp[0]-key[0]+26)%26;
			ans[cnt++]='a'+p;
			for(int i=1;i<l;++i)
				if((key[i]-'a'+p)%26+'a'!=tmp[i])
				{
					--cnt;
					break;
				}
		}
		sort(ans,ans+cnt);
		for(int i=0;i<cnt;++i)
			if(!i || (i && ans[i]!=ans[i-1]))
				putchar(ans[i]);
		putchar('\n');
	}

	return 0;
}
