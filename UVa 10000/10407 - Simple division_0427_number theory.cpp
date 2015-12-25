/*
10407 - Simple division

number theory...
������...
a=a'*d+c
b=b'*d+c
.....
z=z'*d+c
��dʹ��������ʽ������c�����...
������...
Ȼ�����μ�ȥ��С��...
ʣ�µ�������ʽΪ
a''*d
b''*d
....
z''*d
ֻҪ��һ��������ֵ��gcd����d��...
*/

#include<iostream>
#include<algorithm>
#define MAXN 1010
using namespace std;

int var[MAXN],cnt;

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(cin>>var[0] && var[0])
	{
		cnt=1;
		while(cin>>var[cnt] && var[cnt])
			++cnt;
		sort(var,var+cnt);
		int i;
		for(i=cnt-1;i>=0;--i)
			var[i]-=var[0];
		i=0;
		while(i<cnt && !var[i])
			++i;
		if(i+1==cnt)
			cout<<var[i]<<endl;
		else
		{
			int key=gcd(var[i],var[i+1]);
			for(i+=2;i<cnt;++i)
				key=gcd(key,abs(var[i]));
			cout<<key<<endl;
		}
	}

	return 0;
}
