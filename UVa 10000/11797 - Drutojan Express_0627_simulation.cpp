/*
11797 - Drutojan Express

simulation...
貌似很复杂的题目,其实只是一道模拟题...
不过题目很ws,不足以的话就会掉到出题者的tricky里面...
我就wa了半天...
*/

#include<iostream>
#include<string>
#include<map>
#define MAXN 5
using namespace std;

map<string,int> msi;
string dic[MAXN];
void init()
{
	dic[0]="Ja";
	dic[1]="Sam";
	dic[2]="Sha";
	dic[3]="Sid";
	dic[4]="Tan";

	msi["Ja"]=0;
	msi["Sam"]=1;
	msi["Sha"]=2;
	msi["Sid"]=3;
	msi["Tan"]=4;
}

int ppl[MAXN][30],p[MAXN],sz[MAXN],cnt[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	init();

	int dataset;
	cin>>dataset;
	for(int cas=1;cas<=dataset;++cas)
	{
		int m,n;
		cin>>m>>n;
		string name;
		cin>>name;
		int s=msi[name];

		for(int i=0;i<MAXN;++i)
		{
			cin>>sz[i];
			p[i]=cnt[i]=0;
			for(int j=0;j<sz[i];++j)
			{
				cin>>name;
				ppl[i][j]=msi[name];
			}
		}

		while(n>0)
		{
			if(n>=m)
			{
				n-=m;
				cnt[s]+=m;
				int t=ppl[s][p[s]];		//tricky
				p[s]=(p[s]+1)%sz[s];
				s=t;
			}
			else
			{
				cnt[s]+=n;
				break;
			}
			n-=2;
		}
		cout<<"Case "<<cas<<":"<<endl;
		for(int i=0;i<MAXN;++i)
			cout<<dic[i]<<" "<<cnt[i]<<endl;
	}

	return 0;
}
