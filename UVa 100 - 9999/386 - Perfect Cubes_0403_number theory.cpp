/*
386 - Perfect Cubes

number theory...
求满足a^3=b^3+c^3+d^3的所有数对...
明显应该从b,c,d开始枚举,然后求a...
可以用bsearch优化...
所以,整体时间复杂度由O(n^4)降到O(n^3log n)..
*/

#include<iostream>
#include<algorithm>
#define MAXN 200
using namespace std;

int tab[MAXN+1];
struct point
{
	int a,b,c,d;
}pnt[MAXN];

int cmp2(const point a,const point b)
{
	if(a.a==b.a)
		return a.b<b.b;
	return a.a<b.a;
}

int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}

int main()
{
//	freopen("in.txt","r",stdin);

	int i,j,k,*p,var,cnt=0;
	for(i=1;i<=MAXN;++i)
		tab[i]=i*i*i;
	for(i=2;i<=MAXN;++i)
		for(j=i;j<=MAXN;++j)
			for(k=j;k<=MAXN;++k)
			{
				var=tab[i]+tab[j]+tab[k];
				p=(int *)bsearch(&var,tab,MAXN+1,sizeof(int),cmp);
				if(p)
				{
					pnt[cnt].a=p-tab;
					pnt[cnt].b=i;
					pnt[cnt].c=j;
					pnt[cnt].d=k;
					++cnt;
				}
			}
	sort(pnt,pnt+cnt,cmp2);
	for(i=0;i<cnt;++i)
		printf("Cube = %d, Triple = (%d,%d,%d)\n",pnt[i].a,pnt[i].b,pnt[i].c,pnt[i].d);


	return 0;
}
