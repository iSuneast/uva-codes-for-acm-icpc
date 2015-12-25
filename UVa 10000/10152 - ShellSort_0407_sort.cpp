/*
10152 - ShellSort

好BT的算法啊...
看了n遍题目,++n遍解题报告...
终于弄懂什么意思...

其实就是求龟壳中的有效错位...
从底向上扫描...
第一个有效错位与其正确的位置差值仅能为1...
同理...
第i个有效错位与其正确的位置差值为i...
于是,扫描一遍后...
按其发现的有效位置的正序输出...

当然,可以直接打标记,最后扫描一遍得出结果..
*/

#include<iostream>
#include<string>
#include<map>
#define MAXN 210
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		int n,i,flag[MAXN];
		scanf("%d",&n);getchar();
		string s[MAXN],t[MAXN];
		for(i=0;i<n;++i)
		{
			getline(cin,s[i]);
			flag[i]=0;
		}
		map<string,int> e;
		for(i=0;i<n;++i)
		{
			getline(cin,t[i]);
			e[t[i]]=i;
		}
		int cnt=0;
		for(i=n-1;i>=0;--i)
			if(e[s[i]]-i!=cnt)
			{
				++cnt;
				flag[e[s[i]]]=1;
			}
		for(i=n-1;i>=0;--i)
			if(flag[i])
				cout<<t[i]<<endl;
		cout<<endl;
	}

	return 0;
}
