/*
11860 - Document Analyzer

Ad hoc...
this problem isn't hard...
just be careful about the data input...
no trick exist...

use vector to store the words,
and set to calculate the different numbers of words

we use begin=1, end=1, to simulate a queue
and map to store the word's current position.
for example:

* a case is a case case is not a case
total different = 4
									begin end
   a								
   0								   1   1
   a case
   0   0							   1   2
   a case is
   0   0   0						   1   3
   a case is a
   1   0   0 0						   2   4
   a case is a case
   1   1   0 0	0					   3   5
   a case is a case case
   1   1   0 0	1	  0				   3   6
   a case is a case case is
   1   1   1 0	1	  0	  0			   4   7
   a case is a case case is not
   1   1   1 0	1	  0	  0  0		   4   8 //all is here now {4,8}
   a case is a case case is not a
   1   1   1 1	1	  0	  0  0	0	   6   9 //{6,9}is better.
   ....

quite simple, isn't?
*/

#include<iostream>
#include<string>
#include<map>
#include<set>
#include<vector>
#define MAXN 100003
using namespace std;

vector<string> data;
set<string> ss;
map<string,int> msi;
bool flag[MAXN];
int cnt;
char buf[200];

void input()
{
	ss.clear();
	data.clear();
	cnt=0;
	while(scanf("%s",buf)!=EOF && strcmp(buf,"END"))
	{
		int l=strlen(buf);
		for(int i=0;i<l;++i)
		{
			if(!isalpha(buf[i]))
				continue;
			int j=i;
			while(isalpha(buf[j]))
				++j;
			buf[j]=0;

			data.push_back(buf+i);
			if(ss.find(buf+i)==ss.end())
			{
				ss.insert(buf+i);
				++cnt;
			}
			i=j;
		}
	}
}

void process()
{
	int sz=data.size(),bgn=0,p=0,q=0x3f3f3f3f;
	memset(flag,0,sizeof(flag));
	msi.clear();

	for(int i=0;i<sz;++i)
	{
		if(msi.find(data[i])==msi.end())
		{
			msi[data[i]]=i;
			--cnt;
		}
		else
		{
			flag[ msi[ data[i] ] ]=true;
			msi[ data[i] ]=i;
			while(flag[bgn])
				++bgn;
		}

		if(cnt==0 && q-p>i-bgn)
		{
			p=bgn;
			q=i;
		}
	}

	printf(" %d %d\n",p+1,q+1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		input();
		printf("Document %d:",cas);
		process();
	}

	return 0;
}
