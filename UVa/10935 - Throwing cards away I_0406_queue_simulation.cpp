/*
10935 - Throwing cards away I

线性表的题...
RE了2次...
主要是没有考虑到n=1的时候队列是空的....
queue就下溢了...
*/

#include<iostream>
#include<queue>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	int n;
	while(cin>>n && n)
	{
		if(n==1)
		{
			cout<<"Discarded cards:"<<endl;
			cout<<"Remaining card: 1"<<endl;
			continue;
		}
		queue<int> q;
		for(int i=1;i<=n;++i)
			q.push(i);
		cout<<"Discarded cards: 1";
		q.pop();
		while(q.size()!=1)
		{
			q.push(q.front());
			q.pop();
			cout<<", "<<q.front();
			q.pop();
		}
		cout<<endl<<"Remaining card: "<<q.front()<<endl;
	}


	return 0;
}
