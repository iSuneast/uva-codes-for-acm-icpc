/*
10371 - Time Zones

Ad hoc...
这题做得无语...
对着bbs那边抠来的数据一组一组改过去的...
题目的时间表示有点不合常理
所以在转换的时候弄得有点乱...

先转换为通常理解的24小时制
然后再转回去就可以了...
注意细节...
*/

#include<iostream>
#include<map>
using namespace std;
typedef pair<int,int> pii;
map<string,pii> mst;

void init();
char buf[10];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	init();
	int h,m,dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		scanf("%s",buf);
		if(buf[0]=='n')
			h=12,m=0;
		else if(buf[0]=='m')
			h=24,m=0;
		else
		{
			sscanf(buf,"%d:%d",&h,&m);
			scanf("%s",buf);
			if(buf[0]=='p' && h<12)
				h+=12;
			else if(buf[0]=='a' && h>=12)
				h-=12;
		}

		scanf("%s",buf);
		h-=mst[buf].first;
		m-=mst[buf].second;

		scanf("%s",buf);
		h+=mst[buf].first;
		m+=mst[buf].second;

		while(m<0)
			m+=60,h--;
		while(m>=60)
			m-=60,h++;

		while(h<0)
			h+=24;
		while(h>=24)
			h-=24;

		if(!m && h==12)
			puts("noon");
		else if(!m && h==0)
			puts("midnight");
		else
		{
			if(h<12)
			{
				if(h<1)
					h+=12;
				printf("%d:%02d a.m.\n",h,m);
			}
			else
			{
				if(h>=13)
					h-=12;
				printf("%d:%02d p.m.\n",h,m);
			}
		}
	}

	return 0;
}

void init()
{
	mst["UTC"]=make_pair(0,0);
	mst["GMT"]=make_pair(0,0);
	mst["BST"]=make_pair(1,0);
	mst["IST"]=make_pair(1,0);
	mst["WET"]=make_pair(0,0);
	mst["WEST"]=make_pair(1,0);
	mst["CET"]=make_pair(1,0);
	mst["CEST"]=make_pair(2,0);
	mst["EET"]=make_pair(2,0);
	mst["EEST"]=make_pair(3,0);
	mst["MSK"]=make_pair(3,0);
	mst["MSD"]=make_pair(4,0);
	mst["AST"]=make_pair(-4,0);
	mst["ADT"]=make_pair(-3,0);
	mst["NST"]=make_pair(-3,-30);
	mst["NDT"]=make_pair(-2,-30);
	mst["EST"]=make_pair(-5,0);
	mst["EDT"]=make_pair(-4,0);
	mst["CST"]=make_pair(-6,0);
	mst["CDT"]=make_pair(-5,0);
	mst["MST"]=make_pair(-7,0);
	mst["MDT"]=make_pair(-6,0);
	mst["PST"]=make_pair(-8,0);
	mst["PDT"]=make_pair(-7,0);
	mst["HST"]=make_pair(-10,0);
	mst["AKST"]=make_pair(-9,0);
	mst["AKDT"]=make_pair(-8,0);
	mst["AEST"]=make_pair(10,0);
	mst["AEDT"]=make_pair(11,0);
	mst["ACST"]=make_pair(9,30);
	mst["ACDT"]=make_pair(10,30);
	mst["AWST"]=make_pair(8,0);
}
