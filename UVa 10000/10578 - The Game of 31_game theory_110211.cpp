/*
 * 10578 - The Game of 31
 *
 * game theory...
 * �����⡣����
 * ��ɵ��BUG����wa�˺ö��~
 *
 * ѧ��һ��ţ����״̬��ʾ����
 * ��Ϊÿ��������4�ţ���������λ������������
 * ��6���ƣ�����ֻҪ�� 6��*3λ/��=18λ �����������ɰѵ�ǰ״̬��������
 * �磺111126666
 * 4��1 -> 100
 * 1��2 -> 001
 * 4��6 -> 100
 * �� 111126666 -> 100 000 000 000 001 100
 * ͬ��   356656 ->  011 010 000 001 000 000
 *
 * �����Ļ����Ϳ����ü��仯�������������
 *
 * �����״̬S������ʹ��һ����n������
 * sum(s)+n<=31����n���Լ��뵱ǰ״̬���õ��µ�״̬T
 * ����ò����µ�״̬T����ǰ״̬��ʤ
 * ����õ�������T״̬��ʤ����ǰ�ذ�
 * ����ֻҪ��һ��T״̬Ϊ�ܵ㣬��ǰ��ʤ
 *
 * happy coding~
 */

#include<iostream>
#define MAXN (1<<19)
using namespace std;

char dp[MAXN], n[7];

int encode(const int &t)
{
	return 1<<( (t-1)*3 );
}

void ChkMin(char &a, const int &t)
{
	if(a>t)
		a=t;
}

int dfs(int state,int sum, int dep)
{
	if(dp[state] != -1)
		return dp[state];

	bool yes[2]={};
	for(int i=1;i<=6;++i)
	{
		if(sum+i>31)
			break;
		if(n[i])
		{
			--n[i];
			yes[ dfs( state+encode(i), sum+i, dep+1 ) ]=true;
			++n[i];
		}
	}

	if(yes[ dep%2 ])
		dp[state]=dep%2;
	else
		dp[state]=(dep+1)%2;

	return dp[state];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	memset(dp,-1,sizeof(dp));
	for(char s[30]; gets(s); )
	{
		for(int i=1; i<=6; ++i)
		{
			n[i]=4;
		}

		int state=0, sum=0, len=strlen(s);
		for(int i=0; i<len; ++i)
		{
			n[ s[i]-'0' ]--;
			state += encode(s[i]-'0');
			sum+=s[i]-'0';
			if(sum>31)
			{
				dp[state]=i%2;	// pre win
				break;
			}
		}

		printf("%s %c\n", s, dfs(state, sum, len+1)?'A':'B');
	}

	return 0;
}
