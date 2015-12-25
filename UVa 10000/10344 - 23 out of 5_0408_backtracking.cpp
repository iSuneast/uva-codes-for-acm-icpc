/*
10344 - 23 out of 5

backtracking...
大概是因为UVa数据是一直改变的...
刚开始理解说每个'o'应该是只能是一个操作符的...
可是WA...(出现在其他地方)
看BBS才知道说数据的顺序是可以调换的...
用next_permutation产生全排列却依旧WA...

现在终于看懂了题意..
'o'只有一个操作符...
不会出现诸如a*(-b)这种情况...
数据的顺序是可以任意交换的...
a,b,c,d,e -> 全排列都有可能...
*/

#include<iostream>
using namespace std;

int num[5],flag[5];

bool dfs(int var,int cur)
{
	if(cur==5)
	{
		if(var==23)		//这里var只能是23,不会有-23出现,也就是说,每个'o'只有一个操作符
			return true;
		else
			return false;
	}
	for(int i=0;i<5;++i)
		if(!flag[i])
		{
			flag[i]=1;
			if(dfs(var+num[i],cur+1)
			|| dfs(var-num[i],cur+1)
			|| dfs(var*num[i],cur+1))
				return true;
			flag[i]=0;
		}
	return false;
}

int main()
{
//	freopen("in.txt","r",stdin);

	while(true)
	{
		bool bk=true;
		int i;
		for(i=0;i<5;++i)
		{
			cin>>num[i];
			if(num[i])
				bk=false;
			flag[i]=0;
		}
		if(bk)
			break;
		bool got=false;
		for(i=0;i<5;++i)
		{
			flag[i]=1;
			if(dfs(num[i],1))
			{
				cout<<"Possible"<<endl;
				got=true;
				break;
			}
			flag[i]=0;
		}
		if(!got)
			cout<<"Impossible"<<endl;
	}

	return 0;
}
