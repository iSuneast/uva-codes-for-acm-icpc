/*
440 - Eeny Meeny Moo
...
��������Ү....
��ϧ...
ֱ�ӽ���һ��TLE...(����̫С...���Ƴ�����ѭ��)
�ڶ���WA....(������ʵ������ͬ...)
orz...
*/

#include<iostream>

using namespace std;

int region[160],n,key;

bool accept()
{
	int cnt=n,i,p=1;
	memset(region,0,sizeof(region));
	while(--cnt)
	{
		region[p]=1;
		i=key;
		while(i--)
		{
			p=(p+1)%n;
			if(region[p])
				while(region[p])
					p=(p+1)%n;
		}
		if(region[2])
			return false;
	}
	return true;
}

int main()
{
//	freopen("in.txt","r",stdin);
	while(cin>>n && n)
	{
		key=1;
		while(!accept())
			key++;
		cout<<key<<endl;
	}

return 0;
}
