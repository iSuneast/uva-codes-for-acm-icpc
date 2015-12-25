/*
 * 10368 - Euclid's Game
 *
 * DP...
 * game theory
 * �򵥵Ĳ���, DPһ�¾ͺ���
 * ����p0=(a,b), ���Է��ֱ��������һ��ת�Ƶ�p1=(b, a%b)
 * ���p0��p1��ΪP/N��
 *
 * �����������p0��  a/b>1 �Ļ�, ���ֱ�ʤ
 * ���p1ΪP��, �� p0����ת���� p1'=(a%b+b, b), ��p1'ΪN��, p0ΪP��
 * ���p1ΪN��, �� p0����ת���� p1=(b, a%b), ��p0����ΪP��
 *
 * ��map<pair,bool> ������״̬, ���仯��������~
 *
 * happy coding~
 */

#include<cstdio>
#include<map>
using namespace std;

typedef pair<int,int> pii;
map<pii,bool> mpb;

bool dp(const int &a,const int &b)
{
	if(!b)
		return true;
	if(mpb.find( make_pair(a,b) )!=mpb.end())
		return mpb[ make_pair(a,b) ];
	int rem=a%b;
	if(b+rem!=a || !rem)
		return mpb[ make_pair(a,b) ]=true;
	return mpb[ make_pair(a,b) ]=!dp(b,rem);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	for(int a,b; scanf("%d%d",&a,&b)!=EOF && (a||b); )
	{
		mpb.clear();
		if(a<b)
			swap(a,b);
		puts(dp(a,b)?"Stan wins":"Ollie wins");
	}

	return 0;
}
