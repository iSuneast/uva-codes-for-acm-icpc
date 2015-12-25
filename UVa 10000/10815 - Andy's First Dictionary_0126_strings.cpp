/*
10815 - Andy's First Dictionary
*/

#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

char dic[1000000][20];
int cnt=0;

int cmp(const void *a,const void *b)
{
	return strcmp((char *)a,(char *)b);
}

void pick(char *p)
{
	char buf[250];
	int i=0,j,l=strlen(p);
	while(i<l)
	{
		while(p[i]&&!isalpha(p[i]))
			i++;
		j=0;
		while(p[i]&&isalpha(p[i]))
			buf[j++]=tolower(p[i++]);
		buf[j]='\0';
		if(strcmp(buf,""))
			strcpy(dic[cnt++],buf);
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	char buf[250];
	int i;
	while(gets(buf))
		pick(buf);
	qsort(dic,cnt,sizeof(dic[0]),cmp);
	puts(dic[0]);
	for(i=1;i<cnt;i++)
		if(strcmp(dic[i],dic[i-1]))
			puts(dic[i]);

return 0;
}
