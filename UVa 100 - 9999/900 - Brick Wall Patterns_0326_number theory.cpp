/*
900 - Brick Wall Patterns

ÔÎ,ì³²¨ÄÇÆõÊı...
*/

#include<iostream>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	int key[60],i;
	key[0]=key[1]=1;
	for(i=2;i<=50;++i)
		key[i]=key[i-1]+key[i-2];
	while(cin>>i && i)
		cout<<key[i]<<endl;

return 0;
}
