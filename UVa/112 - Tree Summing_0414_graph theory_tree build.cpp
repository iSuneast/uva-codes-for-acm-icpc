/*
112 - Tree Summing

graph theory..
tree build...
可以不用建树直接出结果...
*/

#include<stdio.h>

int s,l,key;

bool build(int fa,int ans)
{
	char c;
	if(fa)
		while((c=getchar())!='(')
			;
	while((c=getchar())==' ' || c=='\n' || c=='\r')
		;
	if(c==')')
		return false;
	int var=0,flag=1;
	if(c=='-')
		flag=-1;
	else
		var=c-'0';
	while(c=getchar())
	{
		if(c==' ' || c=='\n' || c=='\r')
			continue;
		if(c=='(')
			break;
		var=var*10+c-'0';
	}
	var*=flag;
	ans+=var;
	bool left=build(0,ans);
	bool right=build(1,ans);
	if(!left && !right && ans==s)	//判断左右子树是否为空
		key=1;
	while((c=getchar())!=')')
		;
	return true;
}

int main()
{
//	freopen("in.txt","r",stdin);

	while(scanf("%d",&s)!=EOF)
	{
		key=0;
		build(1,0);
		puts(key?"yes":"no");
	}

	return 0;
}
