/*
10158 - War

Union find set..
��Ŀ�е㸴��...
main logical:
	���˵ĵ������ҵ�����,���ѵ����ѻ����ҵ�����.
*/

#include<iostream>
#define MAXN 20010	//����һ������������洢����.
using namespace std;
int fa[MAXN],n;

int find(int p)
{
	return p==fa[p]?p:fa[p]=find(fa[p]);
}

int enemy(int p)	//��������������߼���������.
{
	return p+n;
}

void friends(int a,int b)	//union...
{
	a=find(a);
	b=find(b);
	fa[a]=b;
}

int main()
{
//	freopen("in.txt","r",stdin);

	int i,c,x,y,a,b,enemy_a,enemy_b;
	scanf("%d",&n);
	for(i=0;i<2*n;++i)
		fa[i]=i;

	while(scanf("%d %d %d",&c,&x,&y)!=EOF && (c||x||y))
	{
		a=find(x);	enemy_a=find(enemy(x));
		b=find(y);	enemy_b=find(enemy(y));
		switch(c)
		{
		case 1:
			if(a!=enemy_b || b!=enemy_a)
			{
				friends(a,b);
				friends(enemy_a,enemy_b);
			}
			else
				cout<<-1<<endl;
			break;
		case 2:
			if(a!=b || enemy_a!=enemy_b)
			{
				friends(a,enemy_b);
				friends(b,enemy_a);
			}
			else
				cout<<-1<<endl;
			break;
		case 3:
			if(a==b || enemy_a==enemy_b)
				cout<<1<<endl;
			else
				cout<<0<<endl;
			break;
		case 4:
			if(a==enemy_b || b==enemy_a)
				cout<<1<<endl;
			else
				cout<<0<<endl;
			break;
		}
	}


return 0;
}
