/*
11258 - String Partition

DP...
edit steps...

果然发现是递归的问题...
递推的效率无可比拟啊...
而且问题是递归竟然导致了我的TLE...
强烈鄙视UVa的数据...

算法不难...
类似于编辑距离...
每次判断字串的长度...
<10,为int整数...直接转化得到的值必定比拆分然后求和的值大...
=10,与2147483647比较大小,<=的直接转化,>的要拆分...
>10,拆分,枚举中点,取最大值...
	枚举时从长度为1的字串开始递增...
	原理与矩阵链乘相似
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
		//以下的递归算法TLE...
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