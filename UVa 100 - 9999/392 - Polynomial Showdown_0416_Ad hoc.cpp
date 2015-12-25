/*
392 - Polynomial Showdown

ad hoc...
WA�˺ü���...
�����Ǳ߽�����û�и����...
�ر���"1"��"-1"�����������Ϊ����...
һ��Ҫ���濼��..��ȻWA�ĺܲ�...
*/

#include<iostream>
#include<string>
#define MAXN 10
using namespace std;

string hash[MAXN];

void init()
{
	hash[0]="";
	hash[1]="x";
	hash[2]="x^2";
	hash[3]="x^3";
	hash[4]="x^4";
	hash[5]="x^5";
	hash[6]="x^6";
	hash[7]="x^7";
	hash[8]="x^8";
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("392.txt","w",stdout);

	init();
	int var[10],i;
	while(cin>>var[8])
	{
		for(i=7;i>=0;--i)
			cin>>var[i];
		bool first=true;
		for(i=8;i>=0;--i)
			if(var[i])
			{
				if(first)
				{
					first=false;
					if(var[i]<0)
					{
						cout<<"-";
						var[i]=-var[i];
					}
				}
				else if(var[i]<0)
					cout<<" - ",var[i]=-var[i];
				else
					cout<<" + ";
				if(var[i]!=1 || !i)
					cout<<var[i];
				cout<<hash[i];
			}
		if(first)
			cout<<0;
		cout<<endl;
	}


	return 0;
}
