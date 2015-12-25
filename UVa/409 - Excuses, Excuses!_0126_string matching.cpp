/*
409 - Excuses, Excuses!
...
晕...可能又是数组开得太小了....
RE了两次...
*/

#include<iostream>
#include<cctype>
#include<cstring>

using namespace std;

char key[250][250],exc[250][800];
int cnt[250],k,e,m;

int mat(char *buf)
{
	int i;
	for(i=0;i<k;i++)
		if(!strcmp(key[i],buf))
			return 1;
	return 0;
}

void pick(int p)
{
	char buf[250];
	int i=0,j;
	while(i<strlen(exc[p]))
	{	
		while(exc[p][i]&&!isalpha(exc[p][i]))
			i++;
		j=0;
		while(exc[p][i]&&isalpha(exc[p][i]))
			buf[j++]=tolower(exc[p][i++]);
		buf[j]='\0';
		if(mat(buf))
			cnt[p]++;
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int cas=1,i;
	while(cin>>k>>e)
	{
		getchar();
		memset(cnt,0,sizeof(cnt));
		m=0;
		for(i=0;i<k;i++)
			gets(key[i]);
		for(i=0;i<e;i++)
			gets(exc[i]),pick(i),m=m>cnt[i]?m:cnt[i];
		cout<<"Excuse Set #"<<cas++<<endl;
		for(i=0;i<e;i++)
			if(cnt[i]==m)
				cout<<exc[i]<<endl;
		cout<<endl;
	}

return 0;
}
