/*
187 - Transaction Processing

simulation...
杂题...
慢慢模拟即可...
输入那边的处理有点麻烦...
不会出现非法数据..
*/

#include<iostream>
#include<string>
#include<map>
#include<vector>
#define MAXN 1010
using namespace std;

struct DATA
{
	int num,mon;
};
map<int,string> mis;
string s;
vector<DATA> vd[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int var;
	while(getline(cin,s))
	{
		var=atoi(s.substr(0,3).c_str());
		if(!var)
			break;
		mis[var]=s.substr(3,s.length()-3);
	}

	DATA tmp;
	while(getline(cin,s) && s.substr(0,6)!="000000")
	{
		int p=atoi(s.substr(0,3).c_str());
		tmp.num=atoi(s.substr(3,3).c_str());
		tmp.mon=atoi(s.substr(6,s.length()-6).c_str());
		vd[p].push_back(tmp);
	}

	for(int i=0;i<MAXN;++i)
		if(vd[i].size())
		{
			int sz=vd[i].size(),sum=0;
			for(int j=0;j<sz;++j)
				sum+=vd[i][j].mon;

			if(sum!=0)
			{
				cout<<"*** Transaction ";
				printf("%03d",i);
				cout<<" is out of balance ***"<<endl;
				int sz=vd[i].size();
				for(int j=0;j<sz;++j)
				{
					printf("%3d ",vd[i][j].num);
					cout<<mis[ vd[i][j].num ];
					int l=30-mis[ vd[i][j].num ].length();
					while(l--)
						putchar(' ');

					printf(" %10.02lf\n",vd[i][j].mon/100.0);
				}
				sum*=-1;
				printf("999 Out of Balance                 %10.02lf\n\n",sum/100.0);
			}

		}

		return 0;
}
