/*
10044 - Erdos Numbers

BFS.
好复杂的代码啊...

输入输出那边折磨死人了...
*/

#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#define MAXN 10010	//晕死...
using namespace std;

int g[MAXN][MAXN],dis[MAXN];

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("10044.txt","w",stdout);

	int dataset,cas=1;
	cin>>dataset;
	while(dataset--)
	{
		int n,p,i,j,k,l,cnt=0;
		cin>>n>>p;getchar();
		string name,buf;
		map<string,int> m;
		memset(g,0,sizeof(g));
		for(i=0;i<n;i++)
		{
			getline(cin,buf);
			l=buf.length();
			bool flag=true;
			for(j=0;j<l;j++)
			{
				if(buf[j]==':')
				{
					l=j;
					break;
				}
				else if(buf[j]==',')
				{
					if(!flag)
						buf[j]=' ';
					flag=!flag;
				}
				else if(buf[j]==' ')
					buf[j]='_';
			}
			istringstream sin(buf.substr(0,l));
			vector<int> vi;
			string tmp;
			string::size_type pos;
			while(sin>>tmp)
			{
				pos=0;
				while(tmp[pos]=='_')
					++pos;
				name=tmp.substr(pos,tmp.length());
				if(m.find(name)==m.end())
					m[name]=cnt++;
				vi.push_back(m[name]);
			}
			for(j=0;j<vi.size();j++)
				for(k=j+1;k<vi.size();k++)
					g[ vi[j] ][ vi[k] ]
					=g[ vi[k] ][ vi[j] ]=1;
		}

		memset(dis,-1,sizeof(dis));
		queue<int> q;
		int state=m["Erdos,_P."],d;
		q.push(state);
		dis[ state ]=0;
		while(!q.empty())
		{
			state=q.front();
			d=dis[state];
			q.pop();
			for(i=0;i<cnt;++i)
				if(dis[i]==-1 && g[state][i])
				{
					q.push(i);
					dis[i]=d+1;
				}
		}

		cout<<"Scenario "<<cas++<<endl;
		for(i=0;i<p;i++)
		{
			getline(cin,name);
			cout<<name<<' ';
			l=name.length();
			for(j=0;j<l;j++)
				if(name[j]==' ')
					name[j]='_';
//貌似这里也有问题.之前是if(dis[ m[name] ]==-1)...貌似会往MAP里面加数据.
			if(m.find(name)==m.end() || dis[ m[name] ]==-1)
				cout<<"infinity"<<endl;
			else
				cout<<dis[m[name]]<<endl;
		}
	}

return 0;
}
