/*
10107 - What is the Median?
*/

#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	int num[10010],cnt=0;
	while(cin>>num[cnt++])
	{
		sort(num,num+cnt);
		if(cnt%2==0)
			cout<<(num[cnt/2]+num[cnt/2-1])/2<<endl;
		else
			cout<<num[cnt/2]<<endl;
	}

return 0;
}
