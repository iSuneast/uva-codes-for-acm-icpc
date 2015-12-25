/*
10100 - Longest Match

LCS.
最好不要用递归版本的LCS.会TLE.
*/

#include<iostream>
#include<cstring>
using namespace std;

char buf[1010],s1[1010][25],s2[1010][25];
int cnt1,cnt2,flag[1010][1010];

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("10100.txt","w",stdout);

	int cas=1;
	while(gets(buf))
	{
		bool blank=false;
		if(!strlen(buf))
			blank=true;
		cnt1=cnt2=1;
		char *p=buf;
		while(*p)
			if(isalnum(*p))
				p++;
			else
				*p++=' ';
		char *token=strtok(buf," ");
		while(token!=NULL)
		{
			strcpy(s1[cnt1++],token);
			token=strtok(NULL," ");
		}
		gets(buf);
		if(!strlen(buf))
			blank=true;
		if(blank)
		{
			printf("%2d",cas++);
			cout<<". Blank!"<<endl;
			continue;
		}
		p=buf;
		while(*p)
			if(isalnum(*p))
				p++;
			else
				*p++=' ';
			token=strtok(buf," ");
		while(token!=NULL)
		{
			strcpy(s2[cnt2++],token);
			token=strtok(NULL," ");
		}
		memset(flag,0,sizeof(flag));
		for(int i=1;i<cnt1;i++)
			for(int j=1;j<cnt2;j++)
				if(!strcmp(s1[i],s2[j]))
					flag[i][j]=flag[i-1][j-1]+1;
				else if(flag[i-1][j]>=flag[i][j-1])
					flag[i][j]=flag[i-1][j];
				else
					flag[i][j]=flag[i][j-1];
		printf("%2d",cas++);
		cout<<". Length of longest match: "<<flag[cnt1-1][cnt2-1]<<endl;
	}

return 0;
}
