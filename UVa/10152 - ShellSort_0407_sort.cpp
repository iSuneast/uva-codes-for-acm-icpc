/*
10152 - ShellSort

��BT���㷨��...
����n����Ŀ,++n����ⱨ��...
����Ū��ʲô��˼...

��ʵ���������е���Ч��λ...
�ӵ�����ɨ��...
��һ����Ч��λ������ȷ��λ�ò�ֵ����Ϊ1...
ͬ��...
��i����Ч��λ������ȷ��λ�ò�ֵΪi...
����,ɨ��һ���...
���䷢�ֵ���Чλ�õ��������...

��Ȼ,����ֱ�Ӵ���,���ɨ��һ��ó����..
*/

#include<iostream>
#include<string>
#include<map>
#define MAXN 210
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	int dataset;
	scanf("%d",&dataset);
	while(dataset--)
	{
		int n,i,flag[MAXN];
		scanf("%d",&n);getchar();
		string s[MAXN],t[MAXN];
		for(i=0;i<n;++i)
		{
			getline(cin,s[i]);
			flag[i]=0;
		}
		map<string,int> e;
		for(i=0;i<n;++i)
		{
			getline(cin,t[i]);
			e[t[i]]=i;
		}
		int cnt=0;
		for(i=n-1;i>=0;--i)
			if(e[s[i]]-i!=cnt)
			{
				++cnt;
				flag[e[s[i]]]=1;
			}
		for(i=n-1;i>=0;--i)
			if(flag[i])
				cout<<t[i]<<endl;
		cout<<endl;
	}

	return 0;
}
