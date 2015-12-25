/*
10701 - Pre, in and post

graph theory...
tree build...
递归建树...
越来越熟练了...
*/

#include<iostream>
#include<string>
#define MAXN 60
using namespace std;
int nodes,pos;
string po,io;
char node[MAXN];

void build(int pstart,int pend,int istart,int iend)
{
	if(istart>=iend || pstart>=pend)
		return ;
	int i;
	for(i=istart;i<iend;++i)
		if(io[i]==po[pstart])
			break;
	node[--pos]=po[pstart];
	if(i==istart)
		build(pstart+1,pend,i+1,iend);
	else if(i==iend-1)
		build(pstart+1,pend,istart,i);
	else
	{
		build(pstart+(i-istart)+1,pend,i+1,iend);
		build(pstart+1,pstart+(i-istart)+1,istart,i);
	}
}

int main()
{
//	freopen("in.txt","r",stdin);

	int dataset;
	cin>>dataset;
	while(dataset--)
	{
		cin>>nodes>>po>>io;
		build(0,pos=nodes,0,nodes);
		node[nodes]=0;
		cout<<node<<endl;
	}

	return 0;
}
