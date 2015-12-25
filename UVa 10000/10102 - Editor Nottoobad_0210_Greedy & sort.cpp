/*
10102 - Editor Nottoobad
*/

#include<iostream>
#include<cstdlib>

using namespace std;

struct words
{
	char word[110];
	int common;
}w[110];

int cmp(const void *a,const void *b)
{
	words *x=(words *)a;
	words *y=(words *)b;
	if(x->common == y->common)
		return strcmp(y->word,x->word);
	return x->common < y->common;
}

int str_cmp(char *a,char *b)
{
	int i=0;
	while(i<strlen(a))
		if(a[i]==b[i])
			i++;
		else
			break;
	return i;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int cas,n,i,ans;
	cin>>cas;
	while(cas--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>w[i].word,
			w[i].common=str_cmp(w[0].word,w[i].word);

		ans=w[0].common;
		qsort(w+1,n-1,sizeof(w[0]),cmp);

		for(i=1;i<n;i++)
			ans+=strlen(w[i].word)-str_cmp(w[i].word,w[i-1].word);

		cout<<ans<<endl;
		for(i=0;i<n;i++)
			cout<<w[i].word<<endl;
	}

return 0;
}
