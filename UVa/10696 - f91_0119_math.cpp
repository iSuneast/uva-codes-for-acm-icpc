/*
10696 - f91
....µÚ50Ìâ....
*/

#include<iostream>

using namespace std;

int ans[1000000]={0};

int f91(int n)
{
	if(ans[n])
		return ans[n];
	else if(n<=100)
		return ans[n]=f91(f91(n+11));
	return ans[n]=n-10;
}

int main()
{
	int n;
	while(cin>>n&&n)
		cout<<"f91("<<n<<") = "<<f91(n)<<endl;

return 0;
}
