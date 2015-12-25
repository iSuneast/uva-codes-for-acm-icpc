/*
485 - Pascal's Triangle of Death

又是一道Bignum...
本害怕会TLE...
不过还好除了AC.什么也没有发生...
*/

#include<iostream>
#define MAXLEN 62
using namespace std;

class bign
{
	friend ostream& operator<<(ostream &,bign &);
public:
	bign(){	memset(n,0,sizeof(n));	}
	bign &operator =(bign &);
	bign &operator +=(bign &);
	short n[MAXLEN];
};

bign &bign::operator =(bign &t)
{
	memcpy(n,t.n,sizeof(n));
	return *this;
}

bign &bign::operator +=(bign &t)
{
	int carry=0;
	for(int i=0;i<MAXLEN;i++)
	{
		n[i]+=t.n[i]+carry;
		carry=n[i]/10;
		n[i]%=10;
	}
	return *this;
}

ostream& operator<<(ostream &os,bign &t)
{
	int p=MAXLEN-1;
	while(!t.n[p])
		--p;
	for(;p>=0;p--)
		os<<t.n[p];
	return os;
}

bign num[210];

void print()
{
	int i=0,j;
	bool done=false;
	cout<<1<<endl;
	while(++i)
	{
		for(j=i;j>0;j--)
		{
			num[j]+=num[j-1];
			if(num[j].n[60])
				done=true;
			cout<<num[j]<<' ';
		}
		cout<<1<<endl;
		if(done)
			return ;
	}
}

int main()
{
//	freopen("485.txt","w",stdout);

	num[0].n[0]=1;
	print();

return 0;
}
