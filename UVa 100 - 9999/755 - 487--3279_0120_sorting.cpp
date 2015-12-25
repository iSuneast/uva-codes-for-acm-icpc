/*
755 - 487--3279
*/

#include<iostream>
#include<ctype.h>
#include<algorithm>

using namespace std;

char buf[100],tmp[10];
int dif,p[100000];

void format()
{
	int len=strlen(buf),i,j;
	char c;
	for(i=j=0;i<len;i++)
	{
		switch(c=buf[i])
		{
		case 'A':case 'B':case 'C':
			c='2';
			break;
		case 'D':case 'E':case 'F':
			c='3';
			break;
		case 'G':case 'H':case 'I':
			c='4';
			break;
		case 'J':case 'K':case 'L':
			c='5';
			break;
		case 'M':case 'N':case 'O':
			c='6';
			break;
		case 'P':case 'R':case 'S':
			c='7';
			break;
		case 'T':case 'U':case 'V':
			c='8';
			break;
		case 'W':case 'X':case 'Y':
			c='9';
		}
		if(isdigit(c))
			tmp[j++]=c;
	}
	tmp[j]='\0';
	sscanf(tmp,"%d",&p[dif++]);
}

int cmp(const int a,const int b)
{
	return a<b;
}

int main()
{
	int cas,n,i,k,ans;
//	scanf("%d",&cas);
//	while(cas--)
	{
		dif=k=0;
		scanf("%d",&n);getchar();
		for(i=0;i<n;i++)
		{
			gets(buf);
			format();
		}
		sort(p,p+dif,cmp);
		for(i=1;i<dif;i++)
		{
			ans=0;
			while(p[i]==p[i-1]&&i<dif)
				ans++,i++;
			if(ans)
				printf("%03d-%04d %d\n",p[i-1]/10000,p[i-1]%10000,ans+1),k=1;
		}
		if(!k)
			printf("No duplicates.\n");
	//	if(cas)
	//		putchar('\n');
	}

return 0;
}
