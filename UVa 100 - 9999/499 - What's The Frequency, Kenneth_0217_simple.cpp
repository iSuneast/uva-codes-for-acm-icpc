/*
499 - What's The Frequency, Kenneth?
*/

#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

struct ASC
{
	int n;
	char c;
}alpha[256];

int cmp(const void *a,const void *b)
{
	struct ASC *x=(struct ASC *)a;
	struct ASC *y=(struct ASC *)b;
	if(x->n == y->n)
		return x->c - y->c;
	return y->n - x->n;
}

int main()
{
//	freopen("in.txt","r",stdin);
	string buf;
	while(getline(cin,buf))
	{
		string::iterator siter=buf.begin();
		memset(alpha,0,sizeof(alpha));


		while(siter!=buf.end())
		{
			if(isalpha(*siter))
				alpha[*siter].c=*siter,alpha[*siter].n++;
			siter++;
		}
		qsort(alpha,256,sizeof(alpha[0]),cmp);
		int i=0;
		do
		cout<<alpha[i++].c;
		while(alpha[i].n == alpha[i-1].n);
		cout<<' '<<alpha[0].n<<endl;
	}
return 0;
}
