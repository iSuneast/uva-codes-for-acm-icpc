/*
10191 - Longest Nap
*/

#include<iostream>
#include<cstdlib>

using namespace std;

class tim	//那个英语单词貌似确实很丰富.没有必要把class 名定义为time吧.(CE)
{
public:
	char start[10],end[10];
	long operator - (tim &b) const
	{
		int e=(b.end[0]-'0')*10+b.end[1]-'0';
		e*=60;
		e+=(b.end[3]-'0')*10+b.end[4]-'0';	//有时候粗心很恐怖,而且难以追踪发现
		int	s=(start[0]-'0')*10+start[1]-'0';
		s*=60;
		s+=(start[3]-'0')*10+start[4]-'0';
		return s-e;
	}
}t[110];

int cmp(const void *a,const void *b)
{
	return strcmp(((tim *)a)->start,((tim *)b)->start);
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("10191.txt","w",stdout);

	int n,i,maxt,p,tmp,cas=1;
	strcpy(t[0].end,"10:00");
	while(cin>>n)
	{
		char buf[300];
		for(i=1;i<=n;i++)
		{
			cin>>t[i].start>>t[i].end;
			gets(buf);
		}
		qsort(t+1,n,sizeof(t[0]),cmp);
		strcpy(t[n+1].start,"18:00");
		maxt=0;
		for(i=1;i<=n+1;i++)
		{
			tmp=t[i]-t[i-1];
			if(maxt<tmp)
			{
				maxt=tmp;
				p=i-1;
			}
		}
		cout<<"Day #"<<cas++<<": the longest nap starts at "<<t[p].end<<" and will last for ";
		if(maxt<60)
			cout<<maxt<<" minutes."<<endl;
		else
			cout<<maxt/60<<" hours and "<<maxt%60<<" minutes."<<endl;
	}

return 0;
}
