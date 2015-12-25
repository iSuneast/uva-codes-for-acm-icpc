/*
146 - ID Codes
...
感叹于STL的无比强大...
*/

#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	char id[100];
	while(cin>>id&&id[0]!='#')
	{
		if(next_permutation(id,id+strlen(id)))
			cout<<id<<endl;
		else
			cout<<"No Successor"<<endl;
	}

return 0;
}
