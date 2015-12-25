/*
10252 - Common Permutation

������,
һ��ҪС�ĵ��...
����ʱ��ע��߽��ж�...
*/

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	char a[1010],b[1010];
	while(gets(a) && gets(b))
	{
		int la=strlen(a),lb=strlen(b),pa=0,pb=0;
		sort(a,a+la);
		sort(b,b+lb);
		while(pa<la && pb<lb)
		{
			while(pb<lb && b[pb]<a[pa])
				pb++;
			while(pb<lb && pa<la && b[pb]==a[pa])	//�����������ӱ߽��жϵĻ�...
			{
				cout<<b[pb];
				pb++;pa++;
			}
			while(pa<la && a[pa]<b[pb])
				pa++;
		}
		cout<<endl;
	}

return 0;
}
