/*
10739 - String to Palindrome

DP...
�����ģ��...
�༭����...

��ʵ���ģ�ͺ;������˺���...
�������߶���O(n^3)�ĸ��Ӷ�...
���Ҷ��Ǵӳ��ȶ̵����п�ʼ���Ƶ�...

��start,target�ֱ�Ϊ��ǰ���е���β����...
����Եõ�...
case 1: start>=target dp[start][target]=0;	//����Ϊ�յ����
case 2: str[start]==str[target] dp[start][target]=
		1+min(dp[start+1][target-1],dp[start+1][target],dp[start][target-1]);
		�����ǵ���������ĵ�����ȡ��С�ļ���...
�����ü��仯����...
��������TLEϣ���ܴ�...
��Ϊ���õ��ƶ�����1.0s...
����...
*/

#include<iostream>
#include<string>
#define min(a,b) ((a)<(b)?(a):(b))
#define MAXN 1010
using namespace std;

int dp[MAXN][MAXN];
string s;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset,cas=1;
	cin>>dataset;
	while(dataset--)
	{
		cin>>s;
		int len=s.length();
		memset(dp,0,sizeof(dp));
		for(int l=1;l<len;++l)
			for(int start=0;start<len-l;++start)
				for(int target=start+1;target<=start+l;++target)
					if(s[start]==s[target])
						dp[start][target]=dp[start+1][target-1];
					else
						dp[start][target]=1+min(dp[start+1][target-1],
							min(dp[start+1][target],dp[start][target-1]));
		cout<<"Case "<<cas++<<": "<<dp[0][len-1]<<endl;
	}

	return 0;
}
