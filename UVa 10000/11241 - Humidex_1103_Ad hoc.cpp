/*
11241 - Humidex

Ad hoc...
quite a long problem description...
but at the same time, it's quite simple...

read the data, then use the format the problem gives
calculate and finally output
Done!
*/

#include<iostream>
#include<cmath>
using namespace std;
const double EXP=2.718281828;

double T,D,H;
char c[3];
bool isT,isD,isH;

bool input()
{
	isT=false,isD=false,isH=false;

	for(int i=0;i<2;++i)
	{
		scanf("%s",c);

		if(c[0]=='T')
		{
			scanf("%lf",&T);
			isT=true;
		}
		else if(c[0]=='D')
		{
			scanf("%lf",&D);
			isD=true;
		}
		else if(c[0]=='H')
		{
			scanf("%lf",&H);
			isH=true;
		}
		else
			return false;
	}
	return true;
}

void processT()
{
	double e=6.11*
		exp(5417.7530 * ((1/273.16) - (1/(D+273.16))) );
	double h=(0.5555)*(e - 10.0);
	T=H-h;
}

void processD()
{
	double h=H-T;
	double e=h/(0.5555) + 10.0;
	D=(1/273.16) - log(e/6.11)/log(EXP) / 5417.7530;
	D= 1/D - 273.16;
}

void processH()
{
	double e=6.11*
		pow(EXP,5417.7530 * ((1/273.16) - (1/(D+273.16))) );
	double h=(0.5555)*(e - 10.0);
	H=T+h;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	while(input())
	{
		if(!isT)
			processT();
		else if(!isD)
			processD();
		else
			processH();

		printf("T %.1lf D %.1lf H %.1lf\n",T,D,H);
	}

	return 0;
}
