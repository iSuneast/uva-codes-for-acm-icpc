/*
156 - Ananagrams
*/

#include<iostream>
#include<cstdlib>

using namespace std;

struct dict
{
	char in[30];
	char s[30];
	int flag;
}dic[1010];

int cnt;

void str_lower_cpy(char *a,char *b)
{
	int i,l=strlen(b);
	for(i=0;i<l;i++)
		a[i]=tolower(b[i]);
}

int cmp_c(const void *a,const void *b)
{
	return *(char *)a-*(char *)b;
}

int cmp_str(const void *a,const void *b)
{
	return strcmp(((dict *)a)->s,((dict *)b)->s);
}

int cmp_str2(const void *a,const void *b)
{
	return strcmp(((dict *)a)->in,((dict *)b)->in);
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i;
	cnt=0;
	memset(dic,0,sizeof(dic));
	while(cin>>dic[cnt].in)
		if(strcmp(dic[cnt].in,"#"))
			str_lower_cpy(dic[cnt].s,dic[cnt].in),
			qsort(dic[cnt].s,strlen(dic[cnt].s),sizeof(dic[cnt].s[0]),cmp_c),
			cnt++;
		else
			break;
	qsort(dic,cnt,sizeof(dic[0]),cmp_str);

	for(i=1;i<cnt;i++)
	{
		if(!strcmp(dic[i-1].s,dic[i].s))
			dic[i-1].flag=dic[i].flag=1;
	}
	qsort(dic,cnt,sizeof(dic[0]),cmp_str2);
	for(i=0;i<cnt;i++)
		if(!dic[i].flag)
			cout<<dic[i].in<<endl;

return 0;
}
