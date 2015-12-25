/*
10258 - Contest Scoreboard

教你说过多少次了...
题目要认真点看...
*/

#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#define PENALTY 20
#define MAXTEAM 110
#define MAXPROBLEM 15
using namespace std;

struct oj
{
	bool solved[MAXPROBLEM];
	int num,penalty[MAXPROBLEM],final,sloves;
}team[MAXTEAM];

int flag[MAXTEAM];

int cmp(const oj a,const oj b)
{
	if(a.sloves==b.sloves)
	{
		if(a.final==b.final)
			return a.num<b.num;
		return a.final<b.final;
	}
	return a.sloves>b.sloves;
}

int main()
{
//	freopen("in.txt","r",stdin);

	int dataset;
	cin>>dataset;getchar();getchar();
	while(dataset--)
	{
		int i;
		memset(team,0,sizeof(team));
		memset(flag,0,sizeof(flag));
		for(i=0;i<MAXTEAM;++i)
			team[i].num=i;
		string buf;
		int num,quesnum,tim,cnt=0;
		char state;
		while(getline(cin,buf) && buf!="")
		{
			stringstream sin(buf);
			sin>>num>>quesnum>>tim>>state;
			if(!flag[num])
				flag[num]=1;
			switch(state)
			{
			case'C':
				if(team[num].solved[quesnum])
					break;
				team[num].solved[quesnum]=true;
				team[num].final+=team[num].penalty[quesnum]+tim;
				team[num].sloves++;
				break;
			case'I':
				team[num].penalty[quesnum]+=PENALTY;
				break;
			default:
				break;
			}
		}
		sort(team,team+MAXTEAM,cmp);
		for(i=0;i<MAXTEAM;++i)
			if(flag[team[i].num])
				cout<<team[i].num<<' '<<team[i].sloves<<' '<<team[i].final<<endl;
		if(dataset)		//这句话漏了...orz
			cout<<endl;
	}

	return 0;
}
