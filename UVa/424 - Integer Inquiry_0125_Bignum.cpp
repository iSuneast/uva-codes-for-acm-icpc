/*
424 - Integer Inquiry
...
这题好悲剧啊...
....
竟然忘了进位....
*/

#include<iostream>
#include<cstring>

using namespace std;

int num[110][110],cnt=0;
char buf[110];

void rev()
{
	int len=strlen(buf),i;
	for(i=0;i<len;i++)
		num[cnt][i]=buf[len-1-i]-'0';
}

int main()
{
//	freopen("in.txt","r",stdin);
	int up=0,i,j;
	memset(num,0,sizeof(num));
	while(gets(buf)&&strcmp(buf,"0"))
		rev(),cnt++;
	for(i=0;i<110;i++)
	{	
		for(j=1;j<cnt;j++)
			num[0][i]+=num[j][i];
		num[0][i]+=up;
		up=num[0][i]/10;
		num[0][i]%=10;
	}
	i--;
	while(!num[0][i])
		i--;
	for(;i>=0;i--)
		cout<<num[0][i];
	cout<<endl;

return 0;
}
