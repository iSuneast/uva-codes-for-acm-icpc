/*
10635 - Prince and Princess

经典的LIS...
Adapted algorithm for finding longest increasing subsequences

Let S={a1,a2,...,an} be a sequence of n real numbers.
The length of the longest increasing subsequence of S is the
number of elements in the list of numbers that the following
procedure generates.
	Let k=1,ans let L be an empty list of numbers.
	while k<=n: 
	Inspect L for numbers greater than or equal to ak.
	If any exist,replace the smallest of them with ak.
	Otherwise (when ak is greater than every number in L),
	insert ak into the list L.Increast k by 1.
*/

#include<iostream>
#include<algorithm>
#define MAXN 62500
using namespace std;

int n,p,q,n1[MAXN+1],n2[MAXN+1],buf[MAXN+1],hash[MAXN+1],key[MAXN+1];

int cmp_1(const int i,const int j)		{	return n2[i]<n2[j];	}		//间接排序
int cmp_2(const void *i,const void *j)	{	return (*(int *)i)-(*(int *)j);	}

int main()
{
//	freopen("in.txt","r",stdin);

	int dataset,cas=1,i,k,ans,*pnt,done;
	cin>>dataset;
	while(dataset--)
	{
		cin>>n>>p>>q;
		for(i=0;i<=p;i++)
			scanf("%d",n1+i);
		for(i=0;i<=q;i++)
		{
			scanf("%d",n2+i);
			hash[i]=i;
		}
		sort(hash,hash+q,cmp_1);
		for(i=0;i<q;i++)
			buf[i]=n2[hash[i]];	//buf保存有序的n2数组.
		ans=0;
		for(k=0;k<p;k++)	//O(NlogN)
		{
			pnt=(int *)bsearch(&n1[k],buf,q,sizeof(buf[0]),cmp_2);	//二分查找
			if(pnt)
			{
				done=false;
				for(i=0;i<ans;i++)	//找到值则修改有序的key表.
					if(key[i]>hash[pnt-buf])
					{
						key[i]=hash[pnt-buf];
						done=true;
						break;
					}
				if(!done)
					key[ans++]=hash[pnt-buf];
			}
		}
		cout<<"Case "<<cas++<<": "<<ans+1<<endl;//信不信由你,在这里我WA了一次..
	}

	return 0;
}
