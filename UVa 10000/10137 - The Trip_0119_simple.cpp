/*
10137 - The Trip

题目不难,
注意一下精度就可以了.
*/

#include<iostream>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	double mon[1000],avg,ans,ans1;
	int n,i,t;
	while(cin>>n && n)
	{
		avg=ans=ans1=0.00;
		for(i=0;i<n;i++)
		{
//			cin>>mon[i],avg+=mon[i];
				//用逗号表达式可以省略括号,但是增加了代码出错的风险
			cin>>mon[i];
			avg+=mon[i];
		}
		avg/=n;
		t=((long)(avg*1000))%10;
		avg=((long)(avg*100))/100.0;
		if(t>4)
			avg+=0.01;
		for(i=0;i<n;i++)
			if(avg>mon[i])
				ans+=avg-mon[i];
			else
				ans1+=mon[i]-avg;
		printf("$%.2lf\n",ans<ans1?ans:ans1);
	}

return 0;
}
