/*
10714 - Ants
...
咬人啊...
看一下Algorithm....
我就晕了...
竟然这么简单...
***********************************
This is one of those great problems, 
which are very easy, 
once you get an insightful idea.

All you need to notice is that the ants are indistinguishable. 
When two ants collide, 
we may simply ignore the fact that they change the directions 
in which they're walking! 
***********************************
*/

#include<iostream>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int cas,mint,maxt,len,n,t;
	cin>>cas;
	while(cas--)
	{
		cin>>len>>n;
		mint=maxt=0;
		while(n--)
		{
			cin>>t;
			maxt=maxt>t?maxt:t;
			maxt=maxt>len-t?maxt:len-t;
			t=t<len-t?t:len-t;
			mint=mint>t?mint:t;
		}
		cout<<mint<<' '<<maxt<<endl;
	}

return 0;
}
