/*
10131 - Is Bigger Smarter?

At first, sort by their IQ in decreasing order.
If there are same IQ and different weights,
then sort by their weights in decreasing order.
  
Second, LIS by their weight.
In this case, LIS try to find n maximum lengths.
Each of the i-th maximum lengths contains i-th elephant.
Refer here -> Method to solve http://www.comp.nus.edu.sg/~stevenha/programming/prog_dynamicprogramming.html#5._Longest_Inc/Dec-reasing_Subsequence_(LIS/LDS).
After this step, we can find the longest length of n maximum lengths by a single-loop. I call the longest length 'LL' for my explanation.
	
Finally, try to find the concrete order of elephants.
Make a single-loop (n to 1), and search each of the minimum weights of LL-th to 1-th longest length.
Although N to 1 loop can keep the sorted data consistency, 1 to N loop will failed.

*/

#include<iostream>
#include<algorithm>

using namespace std;

struct elephant
{
	int w,iq,cnt2;
}e[1010];
int buf[1010],flag[1010][1010],fa[1010][1010];

int cmp(const elephant a,const elephant b)
{
	if(a.iq==b.iq)
		return a.w>b.w;
	return a.iq>b.iq;
}
int cmp_2(const int a,const int b)	{	return a<b;	}

void print(int p1,int p2)
{
	if(!p1 || !p2)
		return ;
	else if(fa[p1][p2]==0)
	{
		print(p1-1,p2-1);
		cout<<e[p1].cnt2<<endl;
	}
	else if(fa[p1][p2]==1)
		print(p1-1,p2);
	else
		print(p1,p2-1);
}

int main()
{
//	freopen("in.txt","r",stdin);

	int cnt=1,cnt2,i,j;
	while(cin>>e[cnt].w>>e[cnt].iq)
	{
		buf[cnt]=e[cnt].w;
		e[cnt].cnt2=cnt;
		cnt++;
	}
	sort(e+1,e+cnt,cmp);
	sort(buf+1,buf+cnt,cmp_2);
	cnt2=1;
	for(i=1;i<cnt;i++)		//这一步很关键
		if(buf[i]!=buf[cnt2])
			buf[++cnt2]=buf[i];
	cnt2++;
	memset(flag,0,sizeof(flag));
	memset(fa,0,sizeof(fa));
	for(i=1;i<cnt;i++)
		for(j=1;j<cnt2;j++)
			if(e[i].w==buf[j])
			{
				flag[i][j]=flag[i-1][j-1]+1;
				fa[i][j]=0;
			}
			else if(flag[i-1][j]>=flag[i][j-1])
			{
				flag[i][j]=flag[i-1][j];
				fa[i][j]=1;
			}
			else
			{
				flag[i][j]=flag[i][j-1];
				fa[i][j]=2;
			}
	cout<<flag[cnt-1][cnt2-1]<<endl;
	print(cnt-1,cnt2-1);
return 0;
}
