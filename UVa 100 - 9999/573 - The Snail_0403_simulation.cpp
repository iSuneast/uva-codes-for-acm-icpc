/*
573 - The Snail

simulation.
�Ժ���Ŀһ��Ҫ�����...
*/

#include<iostream>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	double h,u,d,f,cur;
	while(cin>>h>>u>>d>>f && h)
	{
		int day=1;
		cur=u;
		f=u*f/100;
		if(cur<=h)
			while(true)
			{
				cur=cur-d;
				if(cur<0)		//���߶ȵ�ʱ��failed
					break;
				++day;
				u-=f;
				if(u<0)			//���ĸ߶ȷǸ�,Ҳ����˵��СΪ0.
					u=0;
				cur+=u;
				if(cur>h)		//�߶�>h(û�еȺ�)��succeed.
					break;
			}
		if(cur<0)
			cout<<"failure on day "<<day<<endl;
		else
			cout<<"success on day "<<day<<endl;
	}

	return 0;
}
