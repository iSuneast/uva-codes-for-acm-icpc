/*
110 - Meta-Loopless Sorts
*/

#include<iostream>

using namespace std;

int n;
char ans[20];

void blank(int dep)
{
	while(dep--)
		cout<<"  ";
}

void insert(char *a,int s,int e)
{
	char t=a[e*2];
	for(;e>s;e--)
		a[e*2]=a[e*2-2];
	a[s*2]=t;
}

void dfs(int cur,char *a)
{
	int i=cur-1;
	char buf[20];

	if(cur==n)
		blank(cur),cout<<"writeln("<<a<<")\n";
	else
	{
		blank(cur);
		cout<<"if "<<a[2*(i--)]<<" < "<<a[cur*2]<<" then\n";
		dfs(cur+1,a);

		for(;i>=0;i--)
		{
			blank(cur);
			cout<<"else if "<<a[2*i]<<" < "<<a[cur*2]<<" then\n";
			strcpy(buf,a);
			insert(a,i+1,cur);
			dfs(cur+1,a);
			strcpy(a,buf);
		}

		blank(cur);
		cout<<"else\n";
		strcpy(buf,a);
		insert(a,0,cur);
		dfs(cur+1,a);
		strcpy(a,buf);
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("110.txt","w",stdout);

	int dataset,i;
	cin>>dataset;
	while(dataset--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			ans[2*i]='a'+i,
			ans[2*i+1]=',';
		ans[2*n-1]='\0';

		cout<<"program sort(input,output);\n"
			"var\n"<<
			ans<<" : integer;\n"
			"begin\n"
			"  readln("<<ans<<");\n";

		if(n==1)
			cout<<"  writeln(a)\n";
		else
			cout<<"  if a < b then\n",
			dfs(2,ans),
			cout<<"  else\n",
			swap(ans[0],ans[2]),dfs(2,ans);

		cout<<"end.\n";
		if(dataset)
			cout<<endl;
	}

return 0;
}
