/*
10550 - Combination Lock

虽然是简单的模拟题...
但是模拟了半天就是不出结果 = =)
看了phbb..才知道自己把顺时针和逆时针搞反了...
*/

#include<iostream>
using namespace std;

void calc(int &key,int s,int e)
{
	if(s>e)
		key+=40-s+e;
	else
		key+=e-s;
}

int main()
{
//	freopen("in.txt","r",stdin);

	int p,a,b,c,ans;

	while(cin>>p>>a>>b>>c && (p||a||b||c))
	{
		ans=120;
		calc(ans,a,p);
		calc(ans,a,b);
		calc(ans,c,b);
		cout<<ans*9<<endl;
	}

	return 0;
}
