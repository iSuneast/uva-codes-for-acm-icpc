/*
620 - Cellular Structure

DP...
状态一直没有分析清楚...
按照题目描述
只有 o=A	o=oAB	o=BoA
才是正确的基因形式...
除此之外都是MUTANT

而只要中间过程的变化是正确的..
则基因的形态趋最后一种有效的变化...
与之前无关...
*/

#include<iostream>
#include<string>
using namespace std;

string s;

int dp(int start,int end)
{
	if(start==end-1 && s[start]=='A')
		return 1;
	else if(start+2<end)
	{
		if(s[start=='B'] && s[end-1]=='A')
		{
			int key=dp(start+1,end-1);
			return key==4?4:3;
		}
		else if(s[end-2]=='A' && s[end-1]=='B')
		{
			int key=dp(start,end-2);
			return key==4?4:2;
		}
		return 4;
	}
	else
		return 4;

}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n;
	cin>>n;
	while(n--)
	{
		cin>>s;
		switch(dp(0,s.length()))
		{
		case 1:
			puts("SIMPLE");break;
		case 2:
			puts("FULLY-GROWN");break;
		case 3:
			puts("MUTAGENIC");break;
		default:
			puts("MUTANT");break;
		}
	}

	return 0;
}
