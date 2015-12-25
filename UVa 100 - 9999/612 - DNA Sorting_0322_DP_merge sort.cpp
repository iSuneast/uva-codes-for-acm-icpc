/*
612 - DNA Sorting

merge_sort...
DP.
*/

#include<iostream>
#include<algorithm>

#define MAXN 105
#define MAXLEN 55
using namespace std;
char str[MAXN][MAXLEN],buf[MAXLEN];
int n,key,cnt[MAXN],fa[MAXN];

void merge_sort(char *a,int x,int y)
{
	if(y-x<=1)
		return ;
	int m=x+(y-x)/2;
	int p=x,q=m,i=x;
	merge_sort(a,x,m);
	merge_sort(a,m,y);
	while(p<m || q<y)
	{
		if(q>=y || (p<m && a[p]<=a[q]))
			buf[i++]=a[p++];
		else
		{
			buf[i++]=a[q++];
			key+=m-p;
		}
	}
	for(i=x;i<y;i++)
		a[i]=buf[i];
}
int cmp(const int a,const int b)
{
	if(cnt[a]==cnt[b])
		return a<b;
	return cnt[a]<cnt[b];
}

int main()
{
//	freopen("in.txt","r",stdin);

	int dataset;
	cin>>dataset;
	while(dataset--)
	{
		int i,m;
		cin>>n>>m;
		char tmp[MAXLEN];
		for(i=0;i<m;i++)
		{
			cin>>str[i];
			strcpy(tmp,str[i]);
			key=0;
			merge_sort(tmp,0,n);
			cnt[i]=key;
			fa[i]=i;
		}
		sort(fa,fa+m,cmp);
		for(i=0;i<m;i++)
			cout<<str[ fa[i] ]<<endl;
		if(dataset)
			cout<<endl;
	}

return 0;
}
