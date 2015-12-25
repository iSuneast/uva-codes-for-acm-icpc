/*
118 - Mutant Flatworld Explorers

simulation...
模拟题...
*/

#include<iostream>
#include<string>
#define MAXN 60
using namespace std;

int g[MAXN][MAXN];
char hash[]={'N','E','S','W'};

int main()
{
//	freopen("in.txt","r",stdin);

	int r,w,x,y,dir;
	char c;
	cin>>r>>w;
	memset(g,0,sizeof(g));
	while(cin>>x>>y)
	{
		cin>>c;
		if(c=='N')
			dir=0;
		else if(c=='E')
			dir=1;
		else if(c=='S')
			dir=2;
		else
			dir=3;
		string buf;
		cin>>buf;
		int l=buf.length();
		bool out=false;
		for(int i=0;i<l && !out;++i)
		{
			switch(buf[i])
			{
			case'R':
				dir=(dir+1)%4;
				break;
			case'L':
				dir=(dir+3)%4;
				break;
			default:
				int tx=x,ty=y;
				if(dir==0)
					++ty;
				else if(dir==1)
					++tx;
				else if(dir==2)
					--ty;
				else
					--tx;
				if(tx>r || ty>w || tx<0 || ty<0)
				{
					if(g[x][y])		//只要注意一下在这里break就可以了..
						break;
					out=true;
					g[x][y]=1;
				}
				else
					x=tx,y=ty;
				break;
			}
		}
		cout<<x<<' '<<y<<' '<<hash[dir];
		if(out)
			cout<<' '<<"LOST";
		cout<<endl;
	}


	return 0;
}
