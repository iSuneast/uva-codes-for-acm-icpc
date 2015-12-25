/*
11345 - Rectangles

geometry...
I think maybe something wrong with judge's data
*
* Each rectangle is described by 2 points:
* lower left and upper right corners
*
if any rectangle is illegal we should output 0 instead
*/

#include<iostream>
#include<algorithm>
#include<ctime>
using namespace std;

struct Rectangles
{
	int x1,y1,x2,y2;
}key,t;

bool chk(Rectangles a,Rectangles b)
{
	return 
		max(a.x1,a.x2)>min(b.x1,b.x2) &&
		max(b.x1,b.x2)>min(a.x1,a.x2) &&
		max(a.y1,a.y2)>min(b.y1,b.y2) &&
		max(b.y1,b.y2)>min(a.y1,a.y2) ;
}

bool nice(Rectangles &t)
{
	return t.x1<t.x2 && t.y1<t.y2;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset,n;
	int buf[4];

	scanf("%d",&dataset);
	for(int cas=1;cas<=dataset;++cas)
	{
		bool fade=false;

		scanf("%d",&n);
		scanf("%d%d%d%d",&key.x1,&key.y1,&key.x2,&key.y2);
		if(!nice(key))
			fade=true;

		while(--n)
		{
			scanf("%d%d%d%d",&t.x1,&t.y1,&t.x2,&t.y2);
			if(!nice(t))
				fade=true;

			if(fade)
				continue;
			if(!chk(t,key))
				fade=true;
			else
			{
				buf[0]=key.x1;	buf[1]=key.x2;
				buf[2]=t.x1;	buf[3]=t.x2;
				sort(buf,buf+4);
				key.x1=buf[1];	key.x2=buf[2];

				buf[0]=key.y1;	buf[1]=key.y2;
				buf[2]=t.y1;	buf[3]=t.y2;
				sort(buf,buf+4);
				key.y1=buf[1];	key.y2=buf[2];
			}
		}

		if(fade)
			printf("Case %d: 0\n",cas);
		else
			printf("Case %d: %d\n",cas,abs(key.x2-key.x1)*abs(key.y2-key.y1));
	}

	return 0;
}

void random_data()
{
	freopen("in","w",stdout);
	srand((unsigned)time(NULL));

	int dataset=1000;
	cout<<dataset<<endl;
	while(dataset--)
	{
		int n=rand()%30+1;cout<<n<<endl;
		while(n--)
		{
			t.x1=rand()%20000-10000;
			t.x2=rand()%20000-10000;
			t.y1=rand()%20000-10000;
			t.y2=rand()%20000-10000;
			cout<<t.x1<<" "<<t.y1<<" "<<t.x2<<" "<<t.y2<<endl;
		}
		cout<<endl;
	}

}
