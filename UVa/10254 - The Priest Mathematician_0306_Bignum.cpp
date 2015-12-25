/*
10254 - The Priest Mathematician

算是当做class的一个练习吧...
*/

#include<iostream>
#define MAXN 160
#define MAXLEN 10
#define MOD 100000

using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;

class bign
{
	friend ostream& operator<< (ostream& ,bign& );
public:
	bign& operator+= (bign &);
	bign& operator= (bign &);
	bign(){memset(num,0,sizeof(num));}
	int num[MAXLEN];
};

ostream& operator<< (ostream& os,bign& n)
{
	int i=MAXLEN-1;
	while(i && !n.num[i])
		--i;
	cout<<n.num[i--];
	while(i>=0)
		printf("%05d",n.num[i--]);
	return os;
}

bign& bign::operator= (bign &a)
{
	memcpy(num,a.num,sizeof(a.num));
	return *this;
}

bign& bign::operator+= (bign &a)
{
	int carry=0;
	for(int i=0;i<MAXLEN;i++)
	{
		num[i]+=a.num[i]+carry;
		carry=num[i]/MOD;
		num[i]%=MOD;
	}
	return *this;
}

bign buf[MAXN];

void init()
{
	int carry;
	buf[0].num[0]=1;
	for(int i=1;i<MAXN;i++)
	{
		carry=0;
		for(int j=0;j<MAXLEN;j++)
		{
			buf[i].num[j]=buf[i-1].num[j]*2+carry;
			carry=buf[i].num[j]/MOD;
			buf[i].num[j]%=MOD;
		}
	}
}

void calc(int n) 
{
	if(n<=1)		//还有n==0这种极端...
	{
		cout<<n<<endl;
		return ;
	}
	bign key;
	key.num[0]=1;
	int p=0,cnt=1;
	for(int j=2;j<=n;j++)
	{
		key+=buf[cnt];
		if(p++==cnt)
		{
			++cnt;
			p=0;
		}
	}
	cout<<key<<endl;
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("10254.txt","w",stdout);

	init();
	int n;
	while(cin>>n)
		calc(n);

return 0;
}
