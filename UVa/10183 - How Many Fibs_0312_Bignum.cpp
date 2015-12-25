/*
10183 - How Many Fibs?

又是一道训练class的好题。
*/

#include<iostream>
#define MOD 10
#define MAXLEN 110
#define MAXN 500
using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;

class bign
{
	friend istream &operator >>(istream &,bign &);
	friend ostream &operator <<(ostream &,bign &);
public:
	bign(){memset(n,0,sizeof(n));}
	bign &operator += (bign &);
	void operator = (bign &);
	bool operator <=(bign &);
	int n[MAXLEN];
private:
}fib[MAXN];

istream &operator >>(istream &is,bign &n)
{
	char buf[MAXLEN];
	is>>buf;
	int i,l=strlen(buf);
	memset(n.n,0,sizeof(n.n));
	for(i=l-1;i>=0;i--)
		n.n[l-i-1]=buf[i]-'0';
	return is;
}

ostream &operator <<(ostream &os,bign &n)
{
	int i=MAXLEN-1;
	while(i>=0 && !n.n[i])
		i--;
	for(;i>=0;i--)
		cout<<n.n[i];
	return os;
}

void bign::operator = (bign &a)
{
	memcpy(n,a.n,sizeof(a.n));
}

bign& bign::operator += (bign &a)
{
	int carry=0;
	for(int i=0;i<MAXLEN;i++)
	{
		n[i]+=carry+a.n[i];
		carry=n[i]/MOD;
		n[i]%=MOD;
	}
	return *this;
}

bool bign::operator <=(bign &a)
{
	int l1=MAXLEN-1,l2=MAXLEN-1;
	while(l1 >=0 && !n[l1])
		l1--;
	while(l2>=0 && !a.n[l2])
		l2--;
	if(l2<l1)
		return false;
	else if(l2>l1)
		return true;
	else
	{
		for(;l2>=0;l2--)
			if(n[l2]<a.n[l2])
				return true;
			else if(n[l2]>a.n[l2])
				return false;
		return true;
	}
}

void init()
{
	fib[0].n[0]=1;fib[1].n[0]=2;
	for(int i=2;i<MAXN;i++)
	{
		fib[i]=fib[i-1];
		fib[i]+=fib[i-2];
	}
}

int main()
{
//	freopen("in.txt","r",stdin);

	init();
	bign a,b,e;
	e.n[0]=0;
	int i,cnt;
	while(cin>>a>>b && !(a<=e && b<=e))
	{
		for(i=cnt=0;i<MAXN;i++)
			if(a<=fib[i] && fib[i]<=b)
				cnt++;
		cout<<cnt<<endl;
	}

return 0;
}
