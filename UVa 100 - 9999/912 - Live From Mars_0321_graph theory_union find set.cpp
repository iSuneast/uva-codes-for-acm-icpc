/*
912 - Live From Mars

graph theory
union find set
*/

#include<iostream>
#define MAXN 256
using namespace std;

int fa[MAXN];

int find(int p)
{
	return p==fa[p]?p:fa[p]=find(fa[p]);
}

int main()
{
//	freopen("in.txt","r",stdin);

	int m;
	bool first=true;
	while(cin>>m)
	{
		if(first)
			first=false;
		else
			cout<<endl;
		int i,a,b;
		char s1[MAXN],s2;
		for(i=0;i<MAXN;i++)
			fa[i]=i;
		for(i=0;i<m;i++)
			cin>>s1[i];
		bool no_ans=false;
		for(i=0;i<m;i++)
		{
			cin>>s2;
			a=find(s1[i]);
			b=find(s2);
			if(a!=b)
			{
				if(isdigit(a) && !isdigit(b))
					fa[a]=b;
				else if(!isdigit(a) && isdigit(b))
					fa[b]=a;
				else if(!isdigit(a) && !isdigit(b))
					no_ans=true;
			}
		}
		if(no_ans)
			cout<<"NO"<<endl;
		else
		{
			cout<<"YES"<<endl;
			for(i='0';i<='9';i++)
			{
				if(fa[i]!=i)
					cout<<(char)i<<' '<<(char)fa[i]<<endl;
			}
		}
	}


return 0;
}
