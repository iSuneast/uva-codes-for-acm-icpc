/*
630 - Anagrams (II)

string...
对读入的所有字符串排序,映射后
二分查找.输出原值即可
*/

#include<iostream>
#include<string>
#include<algorithm>
#define MAXN 1010
using namespace std;
typedef pair<string,int> psi;

string dic[MAXN];
psi hash[MAXN],cur;
int n;

int cmp(psi a,psi b)
{
	if(a.first==b.first)
		return a.second<b.second;
	else
		return a.first<b.first;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			cin>>dic[i];
			hash[i].first=dic[i];
			hash[i].second=i;
			sort(hash[i].first.begin(),hash[i].first.end());
		}
		sort(hash,hash+n,cmp);
		while(cin>>cur.first && cur.first!="END")
		{
			string t=cur.first;
			cout<<"Anagrams for: "<<cur.first<<endl;
			cur.second=0;
			sort(cur.first.begin(),cur.first.end());
			int p=lower_bound(hash,hash+n,cur)-hash;
			int cnt=1;
			while(p<n && hash[p].first==cur.first)
			{
				printf("%3d) ",cnt++);
				cout<<dic[ hash[p++].second ]<<endl;
			}
			if(cnt==1)
				cout<<"No anagrams for: "<<t<<endl;
		}
		if(dataset)
			cout<<endl;
	}

	return 0;
}
