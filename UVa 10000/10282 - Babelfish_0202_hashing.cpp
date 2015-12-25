/*
10282 - Babelfish
*/

#include<iostream>
#include<cstdlib>

using namespace std;

struct dictionary
{
	char foreign[20],en[20];
}dic[100010],*p;

int cmp(const void *a,const void *b)
{
	return strcmp(((dictionary *)a)->foreign,((dictionary *)b)->foreign);
}

int main()
{
//	freopen("in.txt","r",stdin);
	long cnt=0;
	char buf[300];
	while(gets(buf))
		if(strlen(buf))
			sscanf(buf,"%s %s",dic[cnt].en,dic[cnt].foreign),cnt++;
		else
			break;

	qsort(dic,cnt,sizeof(dic[0]),cmp);

	while(gets(buf))
	{
		p=(dictionary *)bsearch(buf,dic,cnt,sizeof(dic[0]),cmp);
		if(p)
			cout<<(*p).en<<endl;
		else
			cout<<"eh"<<endl;
	}
	return 0;
}
