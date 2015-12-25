/*
400 - Unix ls
*/

#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>

using namespace std;

char file[102][62];
int n,i,j,k,maxlen,c,l;
int p;

int cmp_str(const void *a,const void *b)
{
	return strcmp((char *)a,(char *)b);
}

void print()
{
	cout<<"------------------------------------------------------------"<<endl;
	for(i=0;i<l;i++)
		for(j=0;j<c;j++)
		{
			p=j*l+i;
			if(p<n)
			{
			cout<<file[p];
			if(p<n-l)
			{
				for(k=0;k<maxlen-strlen(file[p]);k++)
					cout<<' ';				
			}
			else
				cout<<endl;
			}
		}
}

int main()
{
	while(scanf("%d",&n)==1)
	{
		memset(file,0,sizeof(file));
		maxlen=0;
		for(i=0;i<n;i++)
			scanf("%s",file+i),maxlen=maxlen>strlen(file[i])?maxlen:strlen(file[i]);
		maxlen+=2;
		c=62/maxlen;
		l=(int)ceil((double)n/c);
		qsort(file,n,sizeof(file[0]),cmp_str);
		print();
	}

return 0;
}