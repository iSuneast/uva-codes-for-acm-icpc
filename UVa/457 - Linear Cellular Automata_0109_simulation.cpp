/*
457 - Linear Cellular Automata

simulation
*/

#include<iostream>

using namespace std;

int k,t,pro[15],dna[55];

void init()
{
	memset(dna,0,sizeof(dna));
	dna[19]=1;
}

void print()
{
	for(int i=0;i<40;i++)
		if(dna[i]==0)
			cout<<' ';
		else if(dna[i]==1)
			cout<<'.';
		else if(dna[i]==2)
			cout<<'x';
		else
			cout<<'W';
	cout<<endl;
}

void grow()
{
	int t0,t1;
	t0=dna[0];
	dna[0]+=dna[1];
	for(int i=1;i<40;i++)
	{
		t1=dna[i];
		dna[i]+=t0+dna[i+1];
		t0=t1;
	}
}

void format()
{
	for(int i=0;i<40;i++)
		dna[i]=pro[dna[i]];
}

int main()
{
	int i;
	freopen("in.txt","r",stdin);
	cin>>t;
	while(t--)
	{
		init();
		for(i=0;i<10;i++)
			cin>>pro[i];
		for(i=0;i<50;i++)
		{
			print();
			grow();
			format();
		}
		if(t)
			cout<<endl;
	}

return 0;
}