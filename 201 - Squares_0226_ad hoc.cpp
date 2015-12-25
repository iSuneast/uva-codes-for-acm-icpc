/*
201 - Squares
*/

#include<iostream>

using namespace std;

int h[15][15],v[15][15],key[15],n;

void chk(int a,int b)
{
	int l=1,p,flag=0;
	for(int i=a,j=b;i<=n,j<=n;++i,++j,++l)
		if(!h[a][j] || !v[i][b])
			return ;
		else
		{
			flag=0;
			for(p=b;p<b+l;p++)
				if(!h[a+l][p])
				{
					flag=1;
					break;
				}
			if(flag)
				continue;
			for(p=a;p<a+l;p++)
				if(!v[p][b+l])
				{
					flag=1;
					break;
				}
			if(flag)
				continue;
			key[l]++;
		}
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("201.txt","w",stdout);

	bool first=true,flag;
	int m,i,j,a,b,cas=1;
	char c;
	while(cin>>n)
	{
		if(first)
			first=false;
		else
			cout<<endl<<"**********************************"<<endl<<endl;
		cin>>m;
		memset(h,0,sizeof(h));
		memset(v,0,sizeof(v));
		for(i=0;i<m;i++)
		{
			cin>>c>>a>>b;
			if(c == 'V')
				v[b][a]=1;
			else
				h[a][b]=1;
		}
		memset(key,0,sizeof(key));
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				chk(i,j);
		cout<<"Problem #"<<cas++<<endl<<endl;
		flag=true;
		for(i=1;i<=n;i++)
			if(key[i])
			{
				cout<<key[i]<<" square (s) of size "<<i<<endl;
				flag=false;
			}
		if(flag)
			cout<<"No completed squares can be found."<<endl;
	}

return 0;
}
