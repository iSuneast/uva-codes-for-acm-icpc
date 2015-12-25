/*
116 - Unidirectional TSP

一定要用心去思考.
尽量把问题简化.
不要越想越复杂 : )
*/

#include<iostream>
#include<algorithm>
using namespace std;

int mat[11][110],flag[11][110];
bool first;
struct buf	{	int v,p;	}tmp[3];

void print(int p1,int p2)
{
	if(p2<0)
		return ;
	if(first)
		first=false;
	else
		cout<<' ';
	cout<<p1+1;
	print(flag[p1][p2],p2-1);
}

int cmp(const buf a,const buf b)
{
	if(a.v==b.v)
		return a.p<b.p;
	return a.v<b.v;
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("116.txt","w",stdout);

	int m,n,i,j,k,p;
	while(cin>>m>>n)
	{
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				cin>>mat[i][n-j-1];	//这里有个小小的技巧.AC.
		memset(flag,0,sizeof(flag));
		for(i=1;i<n;i++)
			for(j=0;j<m;j++)
			{
				for(k=-1;k<2;k++)
				{
					tmp[k+1].p=(j+k+m)%m;
					tmp[k+1].v=mat[tmp[k+1].p][i-1];
				}
				sort(tmp,tmp+3,cmp);
				flag[j][i]=tmp[0].p;
				mat[j][i]+=mat[tmp[0].p][i-1];
			}
		for(p=0,i=1;i<m;i++)
			if(mat[p][n-1]>mat[i][n-1])
				p=i;
		first=true;
		print(p,n-1);
		cout<<endl<<mat[p][n-1]<<endl;
	}
	
	return 0;
}

/*
楼下为传说中的TLE代码...
用DFS搜索结果...
调试了N久...
变量之间的关系实在是复杂啊...

#include<iostream>
#include<string>
using namespace std;

int mat[11][110],flag[11][110],m,n;
string ans;

void dfs(int p1,int p2,string key)
{
	string buf=" ";
	buf+=(char)(p1+1+'0')+key;
	if(p2<=0)
	{
		if(ans=="")
			ans=buf;
		else if(ans>buf)
			ans=buf;
		return ;
	}
	for(int k=-1;k<2;k++)	//这里好抽象啊...
		if((mat[ (p1+k+m)%m ][p2-1])==(mat[ flag[p1][p2] ][p2-1]))
			dfs((p1+k+m)%m,p2-1,buf);
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("116.txt","w",stdout);

	int i,j,k,p;
	while(cin>>m>>n)
	{
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				cin>>mat[i][j];
		memset(flag,0,sizeof(flag));
		for(i=1;i<n;i++)
			for(j=0;j<m;j++)
			{
				for(p=-1,k=0;k<2;k++)
					if(mat[(j+p+m)%m][i-1] > mat[(j+k+m)%m][i-1])
						p=k;
				flag[j][i]=(j+p+m)%m;
				mat[j][i]+=mat[(j+p+m)%m][i-1];
			}
		for(p=0,i=1;i<m;i++)
			if(mat[p][n-1]>mat[i][n-1])
				p=i;
		ans="";
		for(i=p;i<m;i++)
			if(mat[i][n-1]==mat[p][n-1])
				dfs(i,n-1,"");
		cout<<ans.substr(1,ans.length())<<endl<<mat[p][n-1]<<endl;
	}

return 0;
}

*/