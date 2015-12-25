/*
10785 - The Mad Numerologist
*/

#include<iostream>
#include<algorithm>

using namespace std;

char vow[2][5]={'A','U','E','O','I'};
char con[2][21]={'J','S','B','K','T','C','L','D','M','V','N','W','F','X','G','P','Y','H','Q','Z','R'};
char ansv[200],ansc[200];

int cmp(const char a,const char b)
{
	return a<b;
}

void init()
{
	int i;
	for(i=0;i<5;i++)
		vow[1][i]=21;
	for(i=0;i<21;i++)
		con[1][i]=5;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int n,l,cas=1,flag,cntv,cntc,v,c,t;
	cin>>n;
	while(n--)
	{
		init();
		flag=1;
		cntv=cntc=0;
		v=c=0;
		cin>>l;
		cout<<"Case "<<cas<<": ";
		t=l;
		while(l--)
		{
			if(flag)
			{
				if(!vow[1][cntv])
					cntv++;
				ansv[v++]=vow[0][cntv];
				vow[1][cntv]--;
				flag=0;
			}
			else
			{
				if(!con[1][cntc])
					cntc++;
				ansc[c++]=con[0][cntc];
				con[1][cntc]--;
				flag=1;
			}
		}
		sort(ansc,ansc+c,cmp);
		sort(ansv,ansv+v,cmp);
		c=v=0;
		flag=1;
		while(t--)
		{
			if(flag)
				cout<<ansv[v++],flag=0;
			else
				cout<<ansc[c++],flag=1;
		}
		cout<<endl;
		cas++;
	}

return 0;
}