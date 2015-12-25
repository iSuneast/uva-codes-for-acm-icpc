/*
11356 - Dates

Ad hoc...
date calculate...
just simulate
no trick...
*/

#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#define MAXN 3030
using namespace std;

map<string,int> msi;
char dic[13][20];
int days[MAXN],months[13];

bool isleap(int year)
{
	return year%4==0 && year%100 || year%400==0;
}

void init()
{
	days[0]=0;
	for(int i=1;i<MAXN;++i)
	{
		days[i]+=days[i-1]+365;
		if(isleap(i))
			++days[i];
	}

	months[0]=0;
	months[1]=months[3]=months[5]=months[7]=months[8]=months[10]=months[12]=31;
	months[2]=28;
	months[4]=months[6]=months[9]=months[11]=30;

	msi["January"]=1;
	msi["February"]=2;
	msi["March"]=3;
	msi["April"]=4;
	msi["May"]=5;
	msi["June"]=6;
	msi["July"]=7;
	msi["August"]=8;
	msi["September"]=9;
	msi["October"]=10;
	msi["November"]=11;
	msi["December"]=12;

	strcpy(dic[1],"January");
	strcpy(dic[2],"February");
	strcpy(dic[3],"March");
	strcpy(dic[4],"April");
	strcpy(dic[5],"May");
	strcpy(dic[6],"June");
	strcpy(dic[7],"July");
	strcpy(dic[8],"August");
	strcpy(dic[9],"September");
	strcpy(dic[10],"October");
	strcpy(dic[11],"November");
	strcpy(dic[12],"December");
}

int trans(int year,int month,int day)
{
	int key=days[year-1]+day;
	for(int i=1;i<month;++i)
		key+=months[i];
	if(month>2 && isleap(year))
		++key;
	return key;
}

void output(int cas,int cur)
{
	int year=lower_bound(days,days+MAXN,cur)-days;
	cur-=days[year-1];

	int month=1;
	if(isleap(year))
		months[2]=29;

	while(cur>months[month])
	{
		cur-=months[month++];
	}

	months[2]=28;

	printf("Case %d: %d-%s-%02d\n",cas,year,dic[month],cur);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif
	
	int dataset,year,day,d;
	char date[30],month[20];

	init();
	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		scanf("%s",date);
		for(int i=0;date[i];++i)
		{
			if(date[i]=='-')
				date[i]=' ';
		}

		sscanf(date,"%d %s %d",&year,month,&day);
		scanf("%d",&d);
		output(cas,trans(year,msi[month],day)+d);
	}

	return 0;
}
