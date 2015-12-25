/*
573 - The Snail

simulation.
以后看题目一定要认真点...
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
				if(cur<0)		//负高度的时候failed
					break;
				++day;
				u-=f;
				if(u<0)			//爬的高度非负,也就是说最小为0.
					u=0;
				cur+=u;
				if(cur>h)		//高度>h(没有等号)是succeed.
					break;
			}
		if(cur<0)
			cout<<"failure on day "<<day<<endl;
		else
			cout<<"success on day "<<day<<endl;
	}

	return 0;
}
