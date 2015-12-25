/*
340 - Master-Mind Hints
*/

#include<iostream>
#include<algorithm>

using namespace std;

int n,key[1000],gus[1000];

void match()
{
	int a,b,i,j,ans[1000];
	memcpy(ans,key,sizeof(key));
	a=b=0;
	for(i=0;i<n;i++)
		if(gus[i]==key[i])
			a++,gus[i]=ans[i]=0;
	for(i=0;i<n;i++)
		if(gus[i])
			for(j=0;j<n;j++)
				if(gus[i]==ans[j])
				{
					ans[j]=0,b++;
					break;
				}
	cout<<"    ("<<a<<','<<b<<')'<<endl;
}

int main()
{
	int i,cas=1;

	while(cin>>n&&n)
	{
		cout<<"Game "<<cas<<":"<<endl;
		for(i=0;i<n;i++)
			cin>>key[i];
		while(1)
		{
			for(i=0;i<n;i++)
				cin>>gus[i];
			if(gus[0]==0)
				break;
			match();
		}
		cas++;
	}

return 0;
}