/*
10061 - How many zero's and how many digits ?
...
不愧是UVa的神牛....
某牛说...

"
Postby yiuyuho ?? Tue Aug 22, 2006 10:27 pm
change
digit=floor(logarithm/log10(base))+1;
to
digit=floor(logarithm/log10(base)+1e-9)+1;

Yes, watch them floats!
"

然后......
就AC了...
*/

#include<iostream>
#include<cmath>

using namespace std;

long mat[10000],b,n,key[10000][2],k;
double ansb,ans;

void makekey(long t)
{
	int i=2;
	k=0;
	memset(key,0,sizeof(key));
	while(t!=1)
	{
		key[k][0]=i;
		while(!(t%i))
			key[k][1]++,t/=i;
		i++;
		if(key[k][1])
			k++;
	}
}

void makedig(long n)
{
	ansb=0;
	while(n--)
		ansb+=log((double)n+1);
	ansb=floor(ansb/log(b)+1e-9)+1;
}

int main()
{
	long i,t,j;
	while(cin>>n>>b)
	{
		memset(mat,0,sizeof(mat));
		makekey(b);
		if(n==1||n==0)
			ansb=1;
		else
			makedig(n);

		for(i=2;i<=n;i++)
		{
			t=i;
			for(j=0;j<k;j++)
				while(!(t%key[j][0]))
					t/=key[j][0],mat[j]++;
		}
		ans=mat[0]/key[0][1];
		for(j=1;j<k;j++)
			t=mat[j]/key[j][1],ans=ans<t?ans:t;
		printf("%d %d\n",(long)ans,(long)ansb);
	}

return 0;
}
