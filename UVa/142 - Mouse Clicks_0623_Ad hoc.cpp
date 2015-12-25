/*
142 - Mouse Clicks

Ad hoc...
*/

#include<iostream>
#define MAXN 66
#define INF 0x7f7f7f7f
using namespace std;

struct POINT
{
	int x,y;
}icon[MAXN];

struct WINDOW
{
	POINT a,b;
}window[MAXN>>1];

int icnt,wcnt;
int x,y;

bool inside(POINT a,POINT b)
{
	return x>=a.x && x<=b.x
		&& y>=a.y && y<=b.y;
}

bool chk_window()
{
	int key=-1;
	for(int i=0;i<wcnt;++i)
		if(inside(window[i].a,window[i].b))
			key=i;
	if(key==-1)
		return false;
	printf("%c\n",key+'A');
	return true;
}

int dist(POINT a)
{
	int dx=a.x-x;
	int dy=a.y-y;
	return dx*dx+dy*dy;
}

void chk_icon()
{
	int dis[MAXN],key=INF;
	for(int i=0;i<icnt;++i)
		if(icon[i].x!=-1)
		{
			dis[i]=dist(icon[i]);
			key=min(key,dis[i]);
		}
		else
			dis[i]=-1;
	for(int i=0;i<icnt;++i)
		if(key==dis[i])
			printf("%3d",i+1);
	cout<<endl;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	char c;

	icnt=wcnt=0;
	while(cin>>c && c!='#')
	{
		if(c=='I')
		{
			cin>>icon[icnt].x>>icon[icnt].y;
			++icnt;
		}
		else if(c=='R')
		{
			cin>>window[wcnt].a.x>>window[wcnt].a.y
				>>window[wcnt].b.x>>window[wcnt].b.y;
			if(window[wcnt].a.x>window[wcnt].b.x)
				swap(window[wcnt].a.x,window[wcnt].b.x);
			if(window[wcnt].a.y>window[wcnt].b.y)
				swap(window[wcnt].a.y,window[wcnt].b.y);
			++wcnt;
		}
		else
		{
			for(int i=0;i<icnt;++i)
				for(int j=0;j<wcnt;++j)
				{
					x=icon[i].x;	y=icon[i].y;
					if(inside(window[j].a,window[j].b))
					{
						icon[i].x=-1;
						break;
					}
				}

				cin>>x>>y;
				if(!chk_window())
					chk_icon();
		}
	}


	return 0;
}
