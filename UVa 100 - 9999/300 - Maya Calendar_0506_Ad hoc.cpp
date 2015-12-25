/*
300 - Maya Calendar

Ad hoc...
做这种题...
一句话....
一定要有耐心...
that's all...
*/

#include<iostream>
#include<map>
#include<string>
using namespace std;

map<string,int> msi;
map<int,string> mis;

void init()
{
	msi["pop"]=1;
	msi["no"]=2;
	msi["zip"]=3;
	msi["zotz"]=4;
	msi["tzec"]=5;
	msi["xul"]=6;
	msi["yoxkin"]=7;
	msi["mol"]=8;
	msi["chen"]=9;
	msi["yax"]=10;
	msi["zac"]=11;
	msi["ceh"]=12;
	msi["mac"]=13;
	msi["kankin"]=14;
	msi["muan"]=15;
	msi["pax"]=16;
	msi["koyab"]=17;
	msi["cumhu"]=18;
	msi["uayet"]=19;

	mis[1]="imix";
	mis[2]="ik";
	mis[3]="akbal";
	mis[4]="kan";
	mis[5]="chicchan";
	mis[6]="cimi";
	mis[7]="manik";
	mis[8]="lamat";
	mis[9]="muluk";
	mis[10]="ok";
	mis[11]="chuen";
	mis[12]="eb";
	mis[13]="ben";
	mis[14]="ix";
	mis[15]="mem";
	mis[16]="cib";
	mis[17]="caban";
	mis[18]="eznab";
	mis[19]="canac";
	mis[20]="ahau";
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	init();
	int dataset;
	char buf[10];
	int year,month,day,tot;
	scanf("%d",&dataset);
	printf("%d\n",dataset);
	while(dataset--)
	{
		scanf("%d%*c%s%d",&day,buf,&year);
		tot=year*365+(msi[buf]-1)*20+day;
		year=tot/260;
		month=tot%20+1;
		day=tot%13+1;
		cout<<day<<" "<<mis[month]<<" "<<year<<endl;
	}

	return 0;
}
