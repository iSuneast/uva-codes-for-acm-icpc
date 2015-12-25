/*
10250 - The Other Two Trees

geometry...
��Ĳ�֪�������˷����Ҷ���ʱ����...

��ʵ������֪�����εĶԽ��ߵ���������
����������...
�����Ǽ�����...
����Ҫ�����Ǳ���̬��...
����...

(x1,y1) (x2,y2)
��	mx=(x1+x2)/2
	my=(y1+y2)/2
	dx=mx-x1
	dy=my-y1(��Ҫ�Ӿ���ֵ)
���Ϊ
(mx-dy,my+dx)
(mx+dy,my-dx)
*/

#include<iostream>
#include<iomanip>
#include<cmath>
#define eps 1e-15
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	long double x1,y1,x2,y2;
	while(cin>>x1>>y1>>x2>>y2)
		if(fabs(x1-x2)<eps && fabs(y1-y2)<eps)
			puts("Impossible.");
		else
		{
			long double mx=(x1+x2)/2;
			long double my=(y1+y2)/2;
			long double dx=mx-x1;
			long double dy=my-y1;

			cout.precision(10);

			cout<<fixed<<showpoint<<mx-dy<<" "<<my+dx<<" "<<mx+dy<<" "<<my-dx<<endl;
		}

	return 0;
}
