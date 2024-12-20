/*
11500 - Vampires

game theory...
博弈论的题...
只需对题目做点稍微的转化就可以转化为经典的概率取子模型.

令n1,n2为两种物品的数量
每次从中取1
有p的概率从n1中取,q=1-p的概率从n2中取
则n1先取完的概率ans=(1-pow(q/p,n1))/(1-pow(q/p,n1+n2))
特殊情况是p=q时,公式无解,而此时ans=n1/(n1+n2)

本题有点不同
===============================1===============================
从ev1和ev2中取,每次取d
并且有如下的转化
state1:	ev1		ev2		从1中取d
state2:	ev1-d	ev2+d	从2中取d
state3：ev1		ev2		从?中取d
state.......
可以观察说无论从那堆取,都是要一次性全部取完
如果说先取1,再取2,就会出现循环.此时问题变成无解
所以,可以推得只有两种情况:
	case1：全部取1,直至取完
	case2：全部取2,直至取完
===============================2===============================
从ev1和ev2中取,每次取d
而概率公式只能对应于取1的情况
只需令n1=ev1/d,n2=ev2/d即可...
*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	double ev1,ev2,v,d;
	while(scanf("%lf%lf%lf%lf",&ev1,&ev2,&v,&d)!=EOF && (ev1||ev2||v||d))
	{
		double n1=ceil(ev1/d),n2=ceil(ev2/d);
		double p=v/6.0,q=1-p;
		if(v==3)
			printf("%.1lf\n",100*n1/(n1+n2));
		else
			printf("%.1lf\n",100*(1-pow(q/p,n1))/(1-pow(q/p,n1+n2)));
	}

	return 0;
}
