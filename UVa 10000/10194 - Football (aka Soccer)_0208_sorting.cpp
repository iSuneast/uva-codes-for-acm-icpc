/*
10194 - Football (aka Soccer)
*/

#include<iostream>

using namespace std;

struct football
{
	char l_name[35],name[35];
	int point,win,tie,loss,games,score,against;
}team[35];

char buf[256],name1[100],name2[100];
int team_num,game_num,scr1,scr2;

int cmp(const void *a,const void *b)
{
	return strcmp(((football *)a)->l_name,((football *)b)->l_name);
}

int cmp_final(const void *a,const void *b)
{
	football *x=(football *)a;
	football *y=(football *)b;

	if(x->point != y->point)
		return x->point < y->point;
	else if(x->win != y->win)
		return x->win < y->win;
	else if(x->score-x->against != y->score-y->against)
		return x->score-x->against < y->score-y->against;
	else if(x->score != y->score)
		return x->score < y->score;
	else if(x->games != y->games)
		return x->games > y->games;
	else
		return strcmp(x->l_name,y->l_name);
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("10194.txt","w",stdout);

	int n,i,j,k;
	football *p1,*p2;
	cin>>n;getchar();
	while(n--)
	{
		memset(team,0,sizeof(team));

		gets(buf);puts(buf);

		cin>>team_num;getchar();
		for(i=0;i<team_num;i++)
		{
			gets(team[i].name);
			k=strlen(team[i].name);
			for(j=0;j<k;j++)
				team[i].l_name[j]=tolower(team[i].name[j]);
			team[i].l_name[j]='\0';
		}
		qsort(team,team_num,sizeof(team[0]),cmp);
		cin>>game_num;getchar();
		for(i=0;i<game_num;i++)
		{
			j=0;
			gets(buf);

			while(buf[j]!='#')
				name1[j]=tolower(buf[j]),j++;
			name1[j++]='\0';
			sscanf(buf+j,"%d@%d",&scr1,&scr2);
			while(buf[j++]!='#')
				;
			k=0;
			while(buf[j])
				name2[k++]=tolower(buf[j]),j++;
			name2[k]='\0';

			p1=(football *)bsearch(name1,team,team_num,sizeof(team[0]),cmp);
			p2=(football *)bsearch(name2,team,team_num,sizeof(team[0]),cmp);

			p1->score+=scr1;p1->against+=scr2;p1->games++;
			p2->score+=scr2;p2->against+=scr1;p2->games++;
			if(scr1>scr2)
				p1->win++,	p1->point+=3,
				p2->loss++;
			else if(scr1==scr2)
				p1->tie++,	p1->point+=1,
				p2->tie++,	p2->point+=1;
			else
				p1->loss++,
				p2->win++,	p2->point+=3;
		}
		qsort(team,team_num,sizeof(team[0]),cmp_final);

		for(i=0;i<team_num;i++)
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
				i+1,team[i].name,team[i].point,team[i].games,team[i].win,team[i].tie,team[i].loss,
				team[i].score-team[i].against,team[i].score,team[i].against);

		if(n)
			cout<<endl;
	}

return 0;
}
