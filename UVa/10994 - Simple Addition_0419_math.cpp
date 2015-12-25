/*
10994 - Simple Addition

math...
simple calc...
ÍÆ¹«Ê½...
*/

#include<iostream>
#include<cmath>
using namespace std;

long long hash[10];
void init()
{
	hash[0]=0;
	hash[1]=1;
	hash[2]=3;
	hash[3]=6;
	hash[4]=10;
	hash[5]=15;
	hash[6]=21;
	hash[7]=28;
	hash[8]=36;
	hash[9]=45;
}

long long calc(long long p)
{
	long long key=0,s;
	int pos=0,cur;
	while(p)
	{
		s=0;
		cur=p%10;	p/=10;
		s=cur*5*(pow(10.0,pos)-1)+hash[cur];
		key+=s;	++pos;
	}
	return key;
}

int main()
{
//	freopen("in.txt","r",stdin);

	init();
	long long p,q,key1,key2;
	while(cin>>p>>q && (p>=0 || q>=0))
	{
		if(!p)
			key1=0;
		else
			key1=calc(p-1);
		key2=calc(q);
		cout<<key2-key1<<endl;
	}

	return 0;
}
