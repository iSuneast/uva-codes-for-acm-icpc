/*
679 - Dropping Balls

��ȫ��������ģ����...
����d�ε���...dΪ����...
�ж�p����ż��...
pΪ��...��С������...��ʱans��Ϊ��ǰλ�õ������...
pΪż...��С������...��ʱans��Ϊ��ǰλ�õ��Ҷ���...
�ı�p��ֵ...
*/

#include<iostream>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	int dataset;
	cin>>dataset;
	while(dataset--)
	{
		int d,p,ans=1;
		cin>>d>>p;
		while(d--)
		{
			ans=ans<<1;
			if(p%2)
				p=(p+1)/2;
			else
				p/=2,++ans;
		}
		cout<<(ans>>1)<<endl;
	}
	cin>>dataset;	//�������������Ү...

	return 0;
}
