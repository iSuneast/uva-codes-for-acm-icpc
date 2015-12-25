/*
10670 - Work Reduction
*/

#include<iostream>
#include<cstdlib>

using namespace std;

struct agency
{
	char name[20];
	int a,b,m;
}ag[110];

int cmp(const void *x,const void *y)
{
	agency *a=(agency *)x;
	agency *b=(agency *)y;

	if(a->m==b->m)
		return strcmp(a->name,b->name);
	return a->m > b->m;
}

int main()
{
//	freopen("in.txt","r",stdin);

	int cas=1,dataset,n,m,l,i,t,remain;
	char buf[50];
	cin>>dataset;
	while(dataset--)
	{
		cout<<"Case "<<cas++<<endl;
		cin>>n>>m>>l;getchar();
		for(i=0;i<l;i++)
		{
			gets(buf);
			char *token=strtok(buf,":");
			sscanf(token,"%s",&ag[i].name);
			token=strtok(NULL,":");
			sscanf(token,"%d,%d",&ag[i].a,&ag[i].b);
			ag[i].m=0;
			remain=n;
			while(1)
			{
				t=remain;
				remain/=2;
				if(remain < m)
				{
					ag[i].m+=(t-m)*ag[i].a;
					break;
				}
				else
				{
					t=(t-remain)*ag[i].a;
					ag[i].m+=t<ag[i].b?t:ag[i].b;
				}
			}
		}
		qsort(ag,l,sizeof(ag[0]),cmp);
		for(i=0;i<l;i++)
			cout<<ag[i].name<<' '<<ag[i].m<<endl;
	}

return 0;
}
