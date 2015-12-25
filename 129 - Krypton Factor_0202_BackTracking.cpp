/*
129 - Krypton Factor
*/

#include<iostream>

using namespace std;

int n,l,cnt;
char ans[100];

int dfs(int cur)
{
	int i,j,k,ok,equal;
	if(cnt++==n)		//如果能运行到这里估计都是满足条件的解了,于是cnt++
	{
		for(i=0;i<cur;i++)
			if(i&&i%64==0)
				putchar('\n'),putchar(ans[i]+'A');
			else if(i&&i%4==0)
				putchar(' '),putchar(ans[i]+'A');
			else
				putchar(ans[i]+'A');
		cout<<endl<<cur<<endl;
		return 0;
	}
	for(i=0;i<l;i++)
	{
		ans[cur]=i;				//构造后字符串的长度变为(cur+1)+1
		ok=1;
		for(j=1;j*2<=cur+1;j++)	//从后面的字串开始检查
		{
			equal=1;
			for(k=0;k<j;k++)	//字串的长度为偶数,所以可以用k,j组合折半对比.
				if(ans[cur-k]!=ans[cur-k-j])
				{
					equal=0;
					break;
				}
			if(equal)
			{
				ok=0;
				break;
			}
		}
		if(ok)
			if(!dfs(cur+1))
				return 0;		//当后面的dfs返回0的时候代表已经找到解了...递归结束
	}
	return 1;
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);

	while(cin>>n>>l&&(n||l))
		cnt=0,dfs(0);

return 0;
}
