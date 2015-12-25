/*
10078 - The Art Gallery
..
我简直就是天才的说...
...
股娃娃...
竟然还WA了一次....
....
打错了一行代码....
*/

#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	int i,rev,al,n,p[55][2];
	int tmp;
	while(cin>>n&&n)
	{
		rev=al=0;
		memset(p,0,sizeof(p));
		for(i=0;i<n;i++)
			cin>>p[i][0]>>p[i][1];
		p[n][0]=p[0][0];p[n][1]=p[0][1];
		p[n+1][0]=p[1][0];p[n+1][1]=p[1][1];
		for(i=0;i<n;i++)
		{
			tmp=p[i][0]*p[i+1][1]+p[i+1][0]*p[i+2][1]+p[i+2][0]*p[i][1]-p[i][0]*p[i+2][1]-p[i+1][0]*p[i][1]-p[i+2][0]*p[i+1][1];
			if(tmp>0)
				rev++;
			else if(tmp<0)
				al++;
		}
		if(rev&&al)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}

return 0;
}