/*
 * 790 - Head Judge Headache
 *
 * Ad hoc...
 * there are so many tricks in this problem...
 *
 * @ the input SUBMIT time isn't always increasing...
 *      so we should sort the input data according to submit time
 *      if two submit have a same time, we should consider the return valur "N" at first
 * @ in the input, if maximum id number is n
 *    we should output n teams. even they may not even exist
 * @ if the problem is already "Y", we should never consider "N" again...
*/

#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define MAXN 30
#define SZ 100003
using namespace std;

struct ACM
{
	int penalty,problem[7],solved,id;
	bool operator<(const ACM &t)const
	{
		if(solved==t.solved)
		{
			if(penalty==t.penalty)
				return id<t.id;
			return penalty<t.penalty;
		}
		return solved>t.solved;
	}
}team[MAXN];

struct INPUT
{
	int team_id,m,problem;
	bool yes;
	bool operator<(const INPUT &t)const
	{
		if(m==t.m)
			return yes<t.yes;
		return m<t.m;
	}
}input[SZ];
char s[100];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("314","w",stdout);
#endif

	int dataset;
	scanf("%d",&dataset);	gets(s);	gets(s);
	while(dataset--)
	{
		memset(team,0,sizeof(team));
		int n=0,cnt=0,id,h,m,p;
		char pro[3],state[3];
		for(;gets(s) && s[0];++cnt)
		{
			sscanf(s,"%d%s%d%*c%d%s",&id,pro,&h,&m,state);
			input[cnt].team_id=id;
			input[cnt].m=h*60+m;
			input[cnt].problem=pro[0]-'A';
			input[cnt].yes=(state[0]=='Y');

			n=max(n,id);
		}
		sort(input,input+cnt);

		for(int i=0;i<cnt;++i)
		{
			id=input[i].team_id;
			m=input[i].m;
			p=input[i].problem;

			if(!input[i].yes)
			{
				if(team[id].problem[p]!=-1)
					team[id].problem[p]+=20;
			}
			else if(team[id].problem[p]!=-1)
			{
				team[id].penalty+=m+team[id].problem[p];
				team[id].solved++;
				team[id].problem[p]=-1;
			}
		}

		for(int i=1;i<=n;++i)
			team[i].id=i;
		sort(team+1,team+1+n);

		int rank=1,jmp=0;
		puts("RANK TEAM PRO/SOLVED TIME");
		for(int i=1;i<=n;++i)
		{
			if(team[i-1].solved!=team[i].solved || team[i-1].penalty!=team[i].penalty)
			{
				rank+=jmp;
				jmp=1;
			}
			else
				++jmp;

			printf("%4d%5d",rank ,team[i].id);
			if(team[i].solved)
				printf("%5d%11d",team[i].solved ,team[i].penalty);
			putchar(10);
		}

		if(dataset)
			putchar(10);
	}

	return 0;
}

