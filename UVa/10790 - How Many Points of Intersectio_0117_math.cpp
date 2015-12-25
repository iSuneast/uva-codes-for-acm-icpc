/*
10790 - How Many Points of Intersection?
*/

#include<iostream>

using namespace std;

int main()
{
	long long n,m,cas=1;
	while(cin>>n>>m&&(n||m))
		cout<<"Case "<<cas++<<": "<<n*m*(n-1)*(m-1)/4<<endl;

return 0;
}