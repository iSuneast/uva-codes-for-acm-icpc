/*
10070 - Leap Year or Not Leap Year and ...

Ad hoc...
date...
bign...
好猥琐的题目啊....
明明就是简单的日期计算.却偏偏要弄个bign...
*/

#include<iostream>
#include<string>
using namespace std;

class bign
{
public:
	string var;
	int operator %(int n)
	{
		int l=var.length(),carry=0;
		for(int i=0;i<l;++i)
			carry=(carry*10+var[i]-'0')%n;
		return carry;
	}
};

bign year;

bool isleap()
{
	return ( (year%4==0 && year%100) || year%400==0 );
}

void judge()
{
	bool done=false,leap=false;
	if(isleap())
		cout<<"This is leap year."<<endl,done=true,leap=true;
	if(year%15==0)
		cout<<"This is huluculu festival year."<<endl,done=true;
	if(leap && year%55==0)
		cout<<"This is bulukulu festival year."<<endl;
	if(!done)
		cout<<"This is an ordinary year."<<endl;
}

int main()
{
//	freopen("in.txt","r",stdin);

	bool first=true;
	while(cin>>year.var)
	{
		if(first)
			first=false;
		else
			cout<<endl;
		judge();
	}

	return 0;
}
