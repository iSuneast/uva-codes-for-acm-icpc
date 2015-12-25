/*
10382 - Watering Grass
*/

#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

struct sprinkler
{
	double s,e;
}spr[10010];

int cmp(const sprinkler a,const sprinkler b)
{
	if(a.s==b.s)
		return a.e > b.e;
	return a.s < b.s;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int n,i,cnt,key,s;
	double l,w,p,r,cur;
	while(cin>>n>>l>>w)
	{
		cnt=0;
		for(i=0;i<n;i++)
		{
			cin>>p>>r;
			if(r <= w/2)
				continue;
			spr[cnt].s=p-sqrt(r*r-w*w/4);
			spr[cnt].e=p+p-spr[cnt].s;
			cnt++;
		}
		sort(spr,spr+cnt,cmp);

		key=cur=s=i=0;
		while(s<cnt && cur<l)
		{
			while(s<cnt && spr[s].e <= cur)		//右边够不着界的去掉
				s++;
			if(s==cnt)
				break;
			if(spr[i].s > cur)
				break;
			while(s<cnt && spr[s].s<=cur)
				s++;
			for(;i<s;i++)
				cur=cur>spr[i].e?cur:spr[i].e;
			key++;
		}
		if(cur<l)
			key=-1;
		cout<<key<<endl;
	}

return 0;
}
