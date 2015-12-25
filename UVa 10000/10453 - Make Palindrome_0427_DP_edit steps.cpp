/*
10453 - Make Palindrome

DP...
edit step...

��˵�����ҷ��˺ü���ɵ��������...
�������˾����Լ��Ѿ��ܲ�����...
�о���������,˼·�Ѿ���������...

��������鷳�˵�...
��Ҫ�������...
������Ȼ�ǵݹ����...
�����ݹ�һ��...
�������Ҳ�͸㶨��...
*/

#include<iostream>
#define min(a,b) ((a)<(b)?(a):(b))
#define MAXN 1010
using namespace std;

int key[MAXN][MAXN];
char s[MAXN];

int dp(int start,int target)
{
	if(start==target)
		return 0;
	else if(key[start][target]!=-1)
		return key[start][target];
	else if(start+1==target)
		return key[start][target]=0;
	else if(s[start]==s[target-1])
		return key[start][target]=dp(start+1,target-1);
	else
		return key[start][target]=1+min(dp(start+1,target),dp(start,target-1));
}

void put(int start,int target)
{
	for(;start<target;++start)
		putchar(s[start]);
}

void print(int start,int target)
{
	if(start==target)
		return ;
	else if(start+1==target)
		putchar(s[start]);
	else if(key[start][target]==0)
		put(start,target);
	else if(key[start][target]==key[start+1][target]+1)
		putchar(s[start]),print(start+1,target),putchar(s[start]);
	else if(key[start][target]==key[start][target-1]+1)
		putchar(s[target-1]),print(start,target-1),putchar(s[target-1]);
	else if(key[start][target]==key[start+1][target-1])
		putchar(s[start]),print(start+1,target-1),putchar(s[target-1]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(cin>>s)
	{
		memset(key,-1,sizeof(key));
		cout<<dp(0,strlen(s))<<' ';
		print(0,strlen(s));
		putchar('\n');
	}

	return 0;
}
