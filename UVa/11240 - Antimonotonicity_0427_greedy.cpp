/*
11240 - Antimonotonicity

greedy...
̰���㷨...

ԭ��ܼ�...
ÿ�ζ�Ѱ�������������е����ƥ��...
�����������½�...
*/

#include<iostream>
#define MAXN 30010
using namespace std;

int var[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int dataset;
	cin>>dataset;
	while(dataset--)
	{
		int n,i;
		cin>>n;
		for(i=0;i<n;++i)
			scanf("%d",var+i);
		int cur=var[0],key=1;
		bool bigger=true;
		for(i=1;i<n;++i)
		{
			if(cur>var[i] && !bigger)		//�����ֵ�ȵ�ǰ�Ĵ�,���Ǵ�ʱ��ȷ������ֵӦ�ñȽ�С
				cur=var[i];
			else if(cur<var[i] && bigger)	//�����ֵ�ȵ�ǰ��С,���Ǵ�ʱ��ȷ������ֵӦ�ñȽϴ�
				cur=var[i];
			if( (cur>var[i] && bigger)
				|| (cur<var[i] && !bigger) )	//�����������������ֵ�Ļ�.�ۼ�.���Ҹ���bigger.
			{
				cur=var[i];
				bigger=!bigger;
				++key;
			}
		}
		cout<<key<<endl;
	}

	return 0;
}
