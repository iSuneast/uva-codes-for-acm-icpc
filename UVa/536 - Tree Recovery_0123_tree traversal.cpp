/*
536 - Tree Recovery
...
二叉树...
前序+中序---->后序...
*/

#include<iostream>
#include<cstring>

using namespace std;

char s1[30],s2[30],ans[30];
int n;

void build(int n,char *s1,char *s2,char *s)
{
	if(n<=0)
		return ;
	int p;
	p=strchr(s2,s1[0])-s2;
	build(p,s1+1,s2,s);
	build(n-p-1,s1+p+1,s2+p+1,s+p);
	s[n-1]=s1[0];
}

int main()
{
	freopen("in.txt","r",stdin);
	while(cin>>s1>>s2)
	{
		n=strlen(s1);
		build(n,s1,s2,ans);
		ans[n]='\0';
		cout<<ans<<endl;
	}

return 0;
}
