/*
10550 - Combination Lock

��Ȼ�Ǽ򵥵�ģ����...
����ģ���˰�����ǲ������ = =)
����phbb..��֪���Լ���˳ʱ�����ʱ��㷴��...
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
