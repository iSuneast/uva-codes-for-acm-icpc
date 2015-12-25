/*
11258 - String Partition

DP...
edit steps...

��Ȼ�����ǵݹ������...
���Ƶ�Ч���޿ɱ��Ⱑ...
���������ǵݹ龹Ȼ�������ҵ�TLE...
ǿ�ұ���UVa������...

�㷨����...
�����ڱ༭����...
ÿ���ж��ִ��ĳ���...
<10,Ϊint����...ֱ��ת���õ���ֵ�ض��Ȳ��Ȼ����͵�ֵ��...
=10,��2147483647�Ƚϴ�С,<=��ֱ��ת��,>��Ҫ���...
>10,���,ö���е�,ȡ���ֵ...
	ö��ʱ�ӳ���Ϊ1���ִ���ʼ����...
	ԭ���������������
*/

#include<iostream>
#define max(a,b) ((a)>(b)?(a):(b))
#define MAXN 210
using namespace std;

long long key[MAXN][MAXN];
char s[MAXN],buf[30];

void bufer(int start,int end)
{
	int cnt=0;
	for(;start<end;++start)
		buf[cnt++]=s[start];
	buf[cnt]=0;
}

bool chk(int start,int end)
{
	bufer(start,end);
	if(strcmp(buf,"2147483647")<=0)
		return true;
	return false;
}

int integer(int start,int end)
{
    if(start+10!=end)
    	bufer(start,end);
	int key;
	sscanf(buf,"%d",&key);
	return key;
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
		scanf("%s",s);
		memset(key,0,sizeof(key));
		int len=strlen(s);
		for(int l=1;l<=len;++l)
			for(int start=0;start<len+1-l;++start)
			{
				int end=start+l;
				if(start+10>end || (start+10==end && chk(start,end)))
					key[start][end]=integer(start,end);
				else for(int k=start;k<end;++k)
					key[start][end]=max(key[start][end],key[start][k]+key[k][end]);
			}
		cout<<key[0][len]<<endl;
	}

	return 0;
}
/*
		//���µĵݹ��㷨TLE...
long long dp(int start,int end)
{
	if(start>=end)
		return 0;
	else if(key[start][end]!=-1)
		return key[start][end];
	else if(start+10>end || (start+10==end && chk(start,end)))
		return key[start][end]=integer(start,end);
	else
	{
		for(int i=start+1;i<end-1;++i)
			key[start][end]=max(key[start][end],dp(start,i)+dp(i,end));
		return key[start][end];
	}
}
*/