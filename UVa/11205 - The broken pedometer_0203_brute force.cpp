/*
11205 - The broken pedometer_0203_brute force

Theory Difficulty:easy
Coding Difficulty:easy
Algorithms Used:brute force
Solution Description: 
	There are up to 15 different LEDs,
so there are 2^15 different ways in which they might be active/broken. 
We can easily test all 100 * 2^15 possibilities.
Represent each symbol as an integer in binary. 
So, 1 1 0 1 0 is stored as 26
(or 11 if you start from the left; doesn't matter which way you do it).
For i from 1 to 2^p, AND together each symbol with i. 
Then, check if every symbol is unique under this bitmask.
We can't afford to do an O(N^2) comparison, 
so make a boolean array of 2^p cells, b[], and set b[j] to true if j is some symbol under the bitmask i. 
If the cell is already set to true, then you don't have a unique representation.
Take the minimum number of LEDs needed across all unique representations, 
and output it.
*/

#include<iostream>

using namespace std;

int light[150],flag[32800],ans;

void calc(int n)
{
	int t=0;
	do
	if(n%2)
		t++;
	while(n/=2);
	ans=ans>t?ans:t;
}

int main()
{
//	freopen("in.txt","r",stdin);

	int cas,i,j,t,ok,p,n;

	cin>>cas;
	while(cas--)
	{
		cin>>p>>n;
		memset(light,0,sizeof(light));
		for(i=0;i<n;i++)
			for(j=0;j<p;j++)
				cin>>t,
				light[i]|=(t<<j);
		ans=0;
		for(i=1;i<(1<<p);i++)
		{
			memset(flag,0,sizeof(flag));
			ok=1;
			for(j=0;j<n;j++)
				if(!flag[light[j]|i])
					flag[light[j]|i]=1;
				else
				{	ok=0;	break;	}
			if(ok)
				calc(i);
		}
		cout<<p-ans<<endl;
	}

return 0;
}


/*
BackTracking....WA...Can't figure out why...

#include<iostream>

using namespace std;

int p,n,ans;
char light[150][20],buf[150][20];

void calc(int cur,int key)
{
	int i,j,k,ok,flag;

	ans=ans>key?ans:key;

	for(k=cur;k<p;k++)
	{
		memcpy(buf,light,sizeof(light));
		for(i=0;i<n;i++)
			light[i][k]='0';
		ok=1;flag=0;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
				if(!strcmp(light[i],light[j]))
				{	ok=0;	break;	}
			if(!ok)
			{	flag=1;	break;	}
		}
		if(!flag)
			calc(k+1,key+1);
		memcpy(light,buf,sizeof(buf));
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	int cas,i,j;
	cin>>cas;
	while(cas--)
	{
		memset(light,0,sizeof(light));
		cin>>p>>n;
		for(i=0;i<n;i++)
			for(j=0;j<p;j++)
				cin>>light[i][j];
		ans=0;
		calc(0,0);

		cout<<p-ans<<endl;
	}

return 0;
}


*/