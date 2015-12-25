/*
170 - Clock Patience

simulation...
牌是倒着放的...
*/

#include<iostream>
#include<string>
using namespace std;
typedef pair<string,int> psi;

psi card[5][14];
int sz[14];

int hash(string s)
{
	if(s[0]=='A')		return 1;
	else if(s[0]=='T')	return 10;
	else if(s[0]=='J')	return 11;
	else if(s[0]=='Q')	return 12;
	else if(s[0]=='K')	return 13;
	else				return s[0]-'0';
}

bool input()
{
	for(int i=4;i>=1;--i)
		for(int j=13;j>=1;--j)
		{
			cin>>card[i][j].first;
			if(i==4 && j==13 && card[i][j].first=="#")
				return false;
			card[i][j].second=hash(card[i][j].first);
		}
	for(int j=1;j<=13;++j)
		sz[j]=4;
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(input())
	{
		int cnt=1,p=13;
		while(true)
		{
			int np=card[ sz[p]-- ][p].second;
			if(sz[np])
			{
				p=np;
				++cnt;
			}
			else
				break;
		}
		printf("%02d,",cnt);
		cout<<card[ sz[p]+1 ][p].first<<endl;
	}

	return 0;
}
