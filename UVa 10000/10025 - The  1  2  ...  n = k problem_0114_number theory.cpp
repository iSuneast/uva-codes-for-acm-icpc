/*
10025 - The ? 1 ? 2 ? ... ? n = k problem
*/

/*
main�����----i---Ϊ�Ӷ��η�������ó�.....
����Ϊ (1+n)*n/2>=i..........

���� (1+i)*i/2......���......�õ�1+...+n�ĺ�����...
��				SUM1=1+2+.....+ANS+.....+i;
��				SUM2=1+2+.....-ANS+.....+i;
����Եõ�.....SUM2-SUM1=2*ANS........

���ݶԳ���....n....��....-n....��ȡֵ��һ����...
*/

#include<iostream>
#include<cmath>

using namespace std;

long n,t,i;

int not_match(int i)
{
	return ((1+i)*i/2-n)%2;
}

int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		n=abs(n);
		i=(long)ceil((-1.0+sqrt(1.0+8*n))/2);
		while(not_match(i))
			i++;
		if(!n)
			i=3;
		cout<<i<<endl;
		if(t)
			cout<<endl;
	}

return 0;
}