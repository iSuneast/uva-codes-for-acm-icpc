/*
123 - Searching Quickly
*/

#include<iostream>
#include<cstring>
#include<ctype.h>

using namespace std;

char ign[50][10],tit[1000];
int ig=0,n=0,len;

struct result
{
	char key[20];
	char ans[1000];
	int flag;
}res[3000];

int exist(char * buf)
{
	int i;
	for(i=0;i<ig;i++)
		if(!strcmp(buf,ign[i]))
			return 1;
	return 0;
}

void format()
{
	int i,j,k;
	len=strlen(tit);
	for(i=0;i<len;i++)
		if(isalpha(tit[i]))
		{
			tolower(tit[i]);j=0;
			while(isalpha(tit[i]))
				res[n].key[j++]=tolower(tit[i++]);
			res[n].key[j]='\0';
			if(exist(res[n].key))
				continue;
			for(k=0;k<i-j;k++)
				res[n].ans[k]=tolower(tit[k]);
			for(;k<i;k++)
				res[n].ans[k]=toupper(tit[k]);
			for(;k<len;k++)
				res[n].ans[k]=tolower(tit[k]);
			res[n].flag=1;
			n++;
		}
}

void sort()
{
	int i,j,cas=n;
	while(cas--)
	{
		i=0;
		while(!res[i].flag)
			i++;
		for(j=i+1;j<n;j++)
			if(res[j].flag&&strcmp(res[i].key,res[j].key)>0)
				i=j;
		cout<<res[i].ans<<endl;
		res[i].flag=0;
	}
}

int main()
{
	while(cin>>ign[ig]&&strcmp(ign[ig],"::"))
		ig++;
	getchar();
	while(gets(tit))
		format();
	sort();

return 0;
}
