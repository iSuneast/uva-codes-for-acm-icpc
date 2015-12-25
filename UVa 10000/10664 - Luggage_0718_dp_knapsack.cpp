/*
10664 - Luggage

dp...
knapsack...
最土的背包...
数据读入问题...
wa了无数次...
*/

#include<iostream>
#include<sstream>
#include<string>
#define MAXN 210
using namespace std;

string s;
bool w[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	getline(cin,s);
	int dataset=atoi(s.c_str());
	while(dataset--)
	{
		getline(cin,s);
		stringstream sin(s);
		int n,tot=0;
		memset(w,0,sizeof(w));
		w[0]=true;

		while(sin>>n)
		{
			for(int i=MAXN-1;i>=0;--i)
				if(w[i])
					w[i+n]=true;
			tot+=n;
		}

		if(tot%2==0 && w[tot/2])
			puts("YES");
		else
			puts("NO");
	}

	return 0;
}

/*
搜索解法...

#include<iostream>
#include<string>
#include<vector>
using namespace std;

string s;
vector<int> w;

bool dp(int dep,int left,int right)
{
	if(dep==w.size())
		return left==right;
	if(dp(dep+1,left+w[dep],right))
		return true;
	if(dp(dep+1,left,right+w[dep]))
		return true;
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	cin>>dataset;getline(cin,s);
	while(dataset--)
	{
		getline(cin,s);
		stringstream sin(s);
		int n;

		w.clear();
		while(sin>>n)
			w.push_back(n);

		if(dp(0,0,0))
			puts("YES");
		else
			puts("NO");
	}

	return 0;
}

*/
