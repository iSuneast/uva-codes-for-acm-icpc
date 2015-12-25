/*
10391 - Compound Words
*/

#include<iostream>
#include<algorithm>

using namespace std;

char dic[120010][30],l[120010];

int cmp(const void *a,const void *b)
{
	return strcmp(((char *)a),((char *)b));
}

int main()
{
//	freopen("in.txt","r",stdin);

	int cnt=0;
	while(gets(dic[cnt]))
	{
		l[cnt]=strlen(dic[cnt]);
		cnt++;
	}
	char buf[30];
	for(int i=1;i<cnt;i++)
	{
		strcpy(buf,dic[i]);
		for(int j=1;j<l[i];j++)
		{
			char t=buf[j];
			buf[j]='\0';
			char *p=(char *)bsearch(buf,dic,cnt,sizeof(dic[0]),cmp);
			if(p)
			{
				p=(char *)bsearch(dic[i]+j,dic,cnt,sizeof(dic[0]),cmp);
				if(p)
				{
					cout<<dic[i]<<endl;
					break;
				}
			}
			buf[j]=t;
		}
	}

return 0;
}
