/*
10763 - Foreign Exchange
....
想开大数组...
明显异想天开....
*/

#include<iostream>

using namespace std;

int flag[2][5000001];
int n;

int chk()
{
	int i;
	for(i=0;i<n;i++)
		if(flag[1][i])
				return 1;
	return 0;
}

int main()
{
//	freopen("in.txt","r",stdin);

	int i,a,b;
	while(cin>>n&&n)
	{
		memset(flag,0,sizeof(flag));
		for(i=0;i<n;i++)
		{
			cin>>a>>b;
			if(a>b)
				flag[0][b]=a,flag[1][b]++;
			else
				flag[0][a]=b,flag[1][a]--;
		}
		if(chk())
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}

return 0;
}
