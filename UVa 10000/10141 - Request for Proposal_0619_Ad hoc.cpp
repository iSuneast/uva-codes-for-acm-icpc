/*
10141 - Request for Proposal

Ad hoc...
水题...
题目比较长而已..
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n,p,cas=1;
	bool first=true;
	while(cin>>n>>p && (n||p))
	{
		if(cas!=1)
			cout<<endl;

		string key,buf;
		pair<double,int> best,cur;
		best.second=-1;

		getline(cin,buf);
		for(int i=0;i<n;++i)
			getline(cin,buf);
		
		while(p--)
		{
			getline(cin,buf);
			cin>>cur.first>>cur.second;
			if(cur.second>best.second
				|| (cur.second==best.second 
					&& cur.first<best.first) )
			{
				best=cur;
				key=buf;
			}

			getline(cin,buf);
			while(cur.second--)
				getline(cin,buf);
		}

		cout<<"RFP #"<<cas++<<endl;
		cout<<key<<endl;
	}

	return 0;
}
