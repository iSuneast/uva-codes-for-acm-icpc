/*
10188 - Automated Judge Script

明明知道UVa的数据很严格的...
*/

#include<iostream>
#include<cstring>

using namespace std;
char ans[110][110],key[110][110],bufnum[10010];

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("10188.txt","w",stdout);

	int n,m,cas=1,i,j;
	while(cin>>n && n)
	{
		getchar();
		i=0;
		while(i<n)
			gets(ans[i++]);
		cin>>m;getchar();
		i=0;
		while(i<m)
			gets(key[i++]);
		bool ac=true;
		if(n==m)
			for(i=0;i<n;i++)
				if(strcmp(ans[i],key[i]))
				{
					ac=false;
					break;
				}
		if(n==m && ac)
			cout<<"Run #"<<cas++<<": Accepted"<<endl;
		else
		{
			int pn=0,p=0;
			for(i=0;i<n;i++)
				for(j=0;ans[i][j];j++)
					if(isdigit(ans[i][j]))
						bufnum[p++]=ans[i][j];
			bool wa=false;
			for(i=0;i<m && !wa;i++)
				for(j=0;key[i][j] && !wa;j++)
					if(isdigit(key[i][j]))
						if(key[i][j]!=bufnum[pn++])
							wa=true;
			if(pn!=p)		//在这里要加一段判断语句...
				wa=true;
			if(wa)
				cout<<"Run #"<<cas++<<": Wrong Answer"<<endl;
			else
				cout<<"Run #"<<cas++<<": Presentation Error"<<endl;
		}
	}

return 0;
}
