/*
776 - Monkeys in a Regular Forest
*/

#include<iostream>
#include<cstring>

using namespace std;

char maz[1000][1000],flag[1000][1000],form[1000][1000],len[1000],key;
int l,c,keyn,ans[1000][1000];

void make_form()
{
	int i,j,t;
	for(i=0;i<c;i++)
		for(j=0;j<l;j++)
		{
			t=ans[j][i];
			while(t/10)
				form[j][i]++,t/=10;
			len[i]=form[j][i]>len[i]?form[j][i]:len[i];
		}
}

void print()
{
	int i,j,k;
	if(keyn>9)
		make_form();
	for(i=0;i<l;i++)
	{
		for(j=0;j<c;j++)
		{
			if(j)
				putchar(' ');
			for(k=form[i][j];k<len[j];k++)
				putchar(' ');
			printf("%d",ans[i][j]);
		}
		putchar('\n');
	}
	puts("%");
}

void dfs(int a,int b)
{
	if(!flag[a][b])
		return ;
	if(maz[a][b]==key)
		ans[a][b]=keyn,flag[a][b]=0;
	else
		return ;
	if(a+1<l)
		dfs(a+1,b);
	if(a+1<l&&b+1<c)
		dfs(a+1,b+1);
	if(a-1>=0)
		dfs(a-1,b);
	if(a-1>=0&&b-1>=0)
		dfs(a-1,b-1);
	if(a-1>=0&&b+1<c)
		dfs(a-1,b+1);
	if(b-1>=0)
		dfs(a,b-1);
	if(a+1<l&&b-1>=0)
		dfs(a+1,b-1);
	if(b+1<c)
		dfs(a,b+1);
}
void calc()
{
	int i,j;
	for(i=0;i<l;i++)
		for(j=0;j<c;j++)
			if(flag[i][j])
				key=maz[i][j],dfs(i,j),keyn++;
}

void format(char *a)
{
	int i,j,l=strlen(a);
	for(i=j=0;i<l;i++)
		if(a[i]!=' ')
			a[j++]=a[i];
	a[j]='\0';
}

int get_maze()
{
	l=0;
	memset(maz,0,sizeof(maz));
	memset(form,1,sizeof(form));
	memset(ans,0,sizeof(ans));
	memset(flag,1,sizeof(flag));
	memset(len,1,sizeof(len));

	while(gets(maz[l]))
		if(maz[l][0]!='%')
			format(maz[l]),l++;
		else
			break;

	c=strlen(maz[0]);
	keyn=1;

	if(l)
		return 1;
	return 0;
}

int main()
{
	while(get_maze())
	{
		calc();
		print();
	}

return 0;
}
