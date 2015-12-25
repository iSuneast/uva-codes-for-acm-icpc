/*
482 - Permutation Arrays

sorting
*/

#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#define MAXN 1000000
using namespace std;
string buf1,buf2[MAXN];
int idx[MAXN],p[MAXN];

int cmp(const int a,const int b)	//间接排序,用的还不是很熟.所以WA了几次.
{	return idx[a]<idx[b];	}

int main()
{
//	freopen("in.txt","r",stdin);

	int dataset,i;
	cin>>dataset;
	while(dataset--)
	{
		getchar();getchar();
		getline(cin,buf1);
		istringstream stream(buf1);
		string num;
		int cnt=0;
		while(stream>>num)
			idx[cnt++]=atoi(num.c_str());
		for(i=0;i<cnt;i++)
		{
			p[i]=i;
			cin>>buf2[i];
		}
		sort(p,p+cnt,cmp);
		for(i=0;i<cnt;i++)
			cout<<buf2[ p[i] ]<<endl;
		if(dataset)
			cout<<endl;
	}

return 0;
}
