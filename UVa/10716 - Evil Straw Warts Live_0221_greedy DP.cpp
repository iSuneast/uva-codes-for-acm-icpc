/*
10716 - Evil Straw Warts Live
*/

#include<iostream>

using namespace std;

int l,ans,flag;
char buf[110];

bool chk()
{
	int c[128],i,cnt=0;
	memset(c,0,sizeof(c));
	for(i=0;i<l;i++)
		c[buf[i]]++;
	for(i=0;i<128;i++)
		if(c[i]%2==1)
			cnt++;
	if(cnt>1)
		return false;
	return true;
}

void move(int start,int p)
{
	int i;
	char c=buf[start];
	if(start>p)
		for(i=start;i>p;i--)
			buf[i]=buf[i-1];
	else
		for(i=start;i<p;i++)
			buf[i]=buf[i+1];
	buf[p]=c;
	ans+=abs(start-p);
}

void dp(int start,int end)
{
	int x,y;
	if(start==end || start == end-1)
		return ;
	for(x=start;x<end;x++)
		if(buf[x] == buf[end-1])
			break;
	for(y=end-1;y>=start;y--)
		if(buf[y] == buf[start])
			break;
	if(x-start > end-y-1)
		move(y,end-1);
	else
		move(x,start);
	dp(start+1,end-1);
}

int main()
{
//	freopen("in.txt","r",stdin);

	int n;
	cin>>n;getchar();
	while(n--)
	{
		gets(buf);
		ans=0;
		l=strlen(buf);
		if(!chk())
			cout<<"Impossible"<<endl;
		else
		{
			dp(0,l);
			cout<<ans<<endl;
		}
	}

return 0;
}
