/*
10069 - Distinct Subsequences

DP...
�����WA��һ��...
Ȼ���������CE��һ��...

ò�Ʋ��Ǻ��ѵ���...
��ϧ���˸߾��Ƚ�ȥ�е㲻ˬ��...
����������java͵��һ�µ�...
����ʵ���ǲ���java...
���ַ�������������...
�����...

����״̬ת�Ʒ���...
��xj=yi�Ļ�dp[i][j]=dp[i-1][j-1]+dp[i][j-1]
����dp[i][j]=dp[i][j-1]...ֱ��copy����õ���ֵ...

      r  a  b  b  b  i  t
   1  1  1  1  1  1  1  1   --->�߽�
r  0  1  1  1  1  1  1  1
a  0  0  1  1  1  1  1  1
b  0  0  0  1  2  3  3  3
b  0  0  0  0  1  3  3  3
i  0  0  0  0  0  0  3  3
t  0  0  0  0  0  0  0  3
  ^
 �߽�
*/

#include<iostream>
#define MAXN 10010
#define MAXLEN 110
using namespace std;

class bign
{
	friend ostream &operator<<(ostream &,bign &);
public:
	bign &operator+=(bign &);
	bign &operator=(bign &);
	bign(){memset(var,0,sizeof(var));}
	short var[MAXLEN];		//��short,��Ȼimage̫��,��CE...
};

bign &bign::operator=(bign &b)
{
	memcpy(var,b.var,sizeof(var));
	return *this;
}

bign &bign::operator+=(bign &b)
{
	int i,carry=0;
	for(i=0;i<MAXLEN;++i)
		var[i]+=b.var[i];
	for(i=0;i<MAXLEN;++i)
	{
		var[i]=var[i]+carry;
		carry=var[i]/10;
		var[i]%=10;
	}
	return *this;
}

ostream & operator<<(ostream &os,bign &a)
{
	int i=MAXLEN-1;
	while(i>=0 && !a.var[i])
		--i;
	if(i<0)
		putchar('0');
	else for(;i>=0;--i)
		cout<<a.var[i];
	return os;
}

bign dp[MAXLEN][MAXN];		//���������һ��ά����Ū��...
char x[MAXN],y[MAXLEN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset,i,j,l1,l2;
	cin>>dataset;
	while(dataset--)
	{
		cin>>x>>y;
		l1=strlen(x);
		l2=strlen(y);
		for(j=0;j<=l1;++j)
			dp[0][j].var[0]=1;
		for(i=1;i<=l2;++i)
			for(j=1;j<=l1;++j)
				if(y[i-1]==x[j-1])
					dp[i][j]=dp[i-1][j-1],
					dp[i][j]+=dp[i][j-1];
				else
					dp[i][j]=dp[i][j-1];
		cout<<dp[l2][l1]<<endl;
	}

	return 0;
}
