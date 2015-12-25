/*
642 - Word Amalgamation
...
字典...
...
说明我对qsort用的还不是很熟练哈....
*/

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

char dic[110][10],mirror[110][10],key[10];
int dicn;

int cmp_str(const void *a,const void *b)
{
	return strcmp((char*)a,(char*)b);
}

int cmp_c(const char a,const char b)
{
	return a<b;
}

int main()
{
	freopen("in.txt","r",stdin);
	int i,flag;
	dicn=0;
	while(cin>>dic[dicn])
		if(strcmp(dic[dicn],"XXXXXX"))
			dicn++;
		else
			break;
	qsort(dic,dicn,sizeof(dic[0]),cmp_str);
	for(i=0;i<dicn;i++)
	{
		strcpy(mirror[i],dic[i]);
		sort(mirror[i],mirror[i]+strlen(mirror[i]),cmp_c);
	}
	while(cin>>key)
		if(strcmp(key,"XXXXXX"))
		{
			flag=0;
			sort(key,key+strlen(key),cmp_c);
			for(i=0;i<dicn;i++)
				if(!strcmp(key,mirror[i]))
					cout<<dic[i]<<endl,flag=1;
			if(!flag)
				cout<<"NOT A VALID WORD"<<endl;
			cout<<"******"<<endl;
		}
		else
			break;

return 0;
}
