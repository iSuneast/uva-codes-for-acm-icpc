/*
130 - Roman Roulette

simulation...
joseph����...
ֱ��ģ�⼴��...
��Ȼ����Сϸ����Ҫע��...
��die��start�������ڵ�ʱ��Ҫ���⴦��...
���ϴ�һ��ֻ��Ҫ�򵥽��������˵�״̬����...
*/

#include<iostream>
#define MAXN 110
using namespace std;

int var[MAXN],front[MAXN],back[MAXN];

void erase(int p)
{
	front[ back[p] ]=front[p];
	back[ front[p] ]=back[p];
}

void insert(int p)
{
	front[ back[p] ]=p;
	back[ front[p] ]=p;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int n,k,i;
	while(cin>>n>>k && (n||k))
	{
		if(n==1)
		{
			cout<<1<<endl;
			continue;
		}
		memset(var,0,sizeof(var));
		memset(front,0,sizeof(front));
		memset(back,0,sizeof(back));
		for(i=0;i<n;++i)
		{
			var[i]=i+1;
			front[i]=(i+1)%n;
			back[i]=(i-1+n)%n;
		}
		int start=n-1,tot=n;
		while(--n)
		{
			int pase=k;		//�����氡...��������������...��Ȼû��TLE...
			while(pase--)
				start=front[start];
			erase(start);
			int die=start;
			pase=k;
			while(pase--)
				start=front[start];
			erase(start);
			var[die]=var[start];
			if(front[die]==start || back[die]==start)
				swap(start,die);
			insert(start=die);
		}
		if(var[start]==1)
			cout<<1<<endl;
		else
			cout<<tot+1-var[start]+1<<endl;
	}

	return 0;
}
