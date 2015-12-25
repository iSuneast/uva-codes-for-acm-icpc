/*
10020 - Minimal coverage
....
╮(╯▽╰)╭哎...
做人不能太贪心啊....
.....
....
太贪心的话....
就WA了...
...
特地留了一个sample纪念一下....
....
这题能过这个sample的话....
基本没问题了...
^^^^^^^^^^^^^^^^
1

3
-1 1
1 2
2 3
0 3
*/

#include<iostream>
#include<algorithm>

using namespace std;

struct segment
{
	int l,r;
}s[100010];
int p[100010];

int cmp(const segment a,const segment b)
{
	if(a.l==b.l)
		return a.r > b.r;
	return a.l < b.l;
}

int main()
{
//	freopen("in.txt","r",stdin);

	int cas,i,j,k,n,key,l,r,t;
	cin>>cas;
	while(cas--)
	{
		cin>>r;
		l=n=key=0;
		while(cin>>s[n].l>>s[n].r && (s[n].l||s[n].r))
			n++;
		sort(s,s+n,cmp);

		i=0;
		while(i<n && l<r)
		{
			while(i<n && s[i].r<=l)		//检查左边界
				i++;
			if(i==n)
				break;
			if(s[i].l > l)			//越界
			{
				key=0;
				break;
			}
			j=k=i;t=0;
			while(i<n && s[i].l<=l)
				i++;
			for(;j<i;j++)			//取最右边的那条线段.
				t=s[t].r>s[j].r?t:j;
			p[key++]=t;
			l=s[t].r;
			i=k;
		}
		if(l<r)
			key=0;
		cout<<key<<endl;
		for(i=0;i<key;i++)
			cout<<s[p[i]].l<<' '<<s[p[i]].r<<endl;
		if(cas)
			cout<<endl;
	}

return 0;
}
