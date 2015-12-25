/*
10129 - Play on Words

DAG的欧拉回路.
这题好学术啊...
*/

#include<iostream>
#include<string>
#define MAXN 28
using namespace std;

int flag[MAXN],n,g[MAXN][MAXN],id[MAXN],od[MAXN];

void dfs(int p)
{
	for(int i=0;i<MAXN;i++)
		if(!flag[i] && g[p][i])
		{
			flag[i]=1;
			dfs(i);
		}
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("10129.txt","w",stdout);

	int dataset;
	cin>>dataset;
	while(dataset--)
	{
		cin>>n;
		int i=n,p1,p2;
		string s;
		memset(g,0,sizeof(g));
		memset(id,0,sizeof(id));
		memset(od,0,sizeof(od));
		while(i--)
		{
			cin>>s;
			p1=s[0]-'a';
			p2=s[s.length()-1]-'a';
			g[p1][p2]=g[p2][p1]=1;
			++od[p1];
			++id[p2];
		}

		memset(flag,0,sizeof(flag));	//连通性判断
		for(i=0;i<MAXN;i++)
			if(id[i] || od[i])
			{
				flag[i]=1;
				dfs(i);
				break;
			}
		bool next=false;
		int key=1;
		for(i=0;i<MAXN;i++)
			if(flag[i])
			{
				if(id[i]!=od[i])	//不存在回路,许进一步判断有没有通路
					next=true;
			}
			else if(id[i] || od[i])
			{
				key=0;
				break;
			}
		int imore=0,omore=0;
		if(next)		//判断欧拉通路
			for(i=0;i<MAXN;i++)
				if(id[i]-od[i]==1)
					imore++;
				else if(od[i]-id[i]==1)
					omore++;
				else if(od[i]!=id[i])
				{
					key=0;
					break;
				}
		if(next && (imore!=1 || omore!=1))
			key=0;
		if(key)
			puts("Ordering is possible.");
		else
			puts("The door cannot be opened.");
	}

return 0;
}

/*
		in.txt
16
2
acm
ibm
3
acm
malform
mouse
2
ok
ok
4
ab
ba
cd
dc
2
abc
xxa
4
ad
da
pq
qp
4
ad
da
ad
da
2
acm
ibm
3
acm
malform
mouse
2
ok
ok
3
ab
bc
ca
3
ab
bc
cb
1
ab
2
ab
bc
4
ab
ba
ab
ba
4
ab
ba
cd
dc
*/
/*
The door cannot be opened.
Ordering is possible.
The door cannot be opened.
The door cannot be opened.
Ordering is possible.
The door cannot be opened.
Ordering is possible.
The door cannot be opened.
Ordering is possible.
The door cannot be opened.
Ordering is possible.
Ordering is possible.
Ordering is possible.
Ordering is possible.
Ordering is possible.
The door cannot be opened.
*/