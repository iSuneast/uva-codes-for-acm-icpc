/*
10783 - Odd Sum
*/

#include<iostream>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	int cas=1,dataset,a,b,i,key[110];

	memset(key,0,sizeof(key));
	key[1]=1;
	for(i=3;i<103;i+=2)
		key[i]+=key[i-2]+i;
	cin>>dataset;
	while(dataset--)
	{
		cin>>a>>b;
		if(a%2==0)
			a--;
		else if(a>1)
			a-=2;
		else
			a=0;
		if(b%2==0)
			b--;
		cout<<"Case "<<cas++<<": "<<key[b]-key[a]<<endl;
	}

return 0;
}
