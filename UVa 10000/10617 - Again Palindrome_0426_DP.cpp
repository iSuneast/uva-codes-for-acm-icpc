/*
10617 - Again Palindrome

DP...
˭���㲻���濴��Ŀ��...
��������ȻTLE...
û������Ŀ˵�����ַ����ĳ�����60...
����Ϊ��15...
�������15�ǲ�����������= =

��󻹺��ҵ���״̬ת�Ʒ���...
��s[start]==s[target-1]��
		key[start][target]=
		1+dp(start+1,target)+dp(start,target-1)
����
		key[start][target]=
		dp(start+1,target)+dp(start,target-1)-dp(start+1,target-1);
���仯��������...
*/

#include<iostream>
#define MAXN 63
using namespace std;

long long key[MAXN][MAXN];
char s[MAXN];

long long dp(int start,int target)
{
	if(key[start][target]!=-1)
		return key[start][target];
	else if(start==target)
		return 0;
	else if(start+1==target)
		return key[start][target]=1;
	else if(s[start]==s[target-1])
		return key[start][target]=1+dp(start+1,target)+dp(start,target-1);
	else
		return key[start][target]=dp(start+1,target)+dp(start,target-1)-dp(start+1,target-1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	cin>>dataset;
	while(dataset--)
	{
		cin>>s;
		memset(key,-1,sizeof(key));
		cout<<dp(0,strlen(s))<<endl;
	}

	return 0;
}
