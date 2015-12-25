#include<iostream>

using namespace std;

int c[100],vis[3][100],set,column,row;

void print()
{
	int i;
	printf("%2d     ",set++);
	for(i=1;i<=8;i++)
		cout<<' '<<c[i];
	cout<<endl;
}

void search(int cur)
{
	int i;
	if(cur>8)
		print();
	else if(cur==row)
		search(cur+1);
	else for(i=1;i<=8;i++)
		if(!vis[0][i]&&!vis[1][i+cur]&&!vis[2][8+cur-i])
		{
			c[cur]=i;
			vis[0][i]=vis[1][i+cur]=vis[2][8+cur-i]=1;
			search(cur+1);
			vis[0][i]=vis[1][i+cur]=vis[2][8+cur-i]=0;
		}
}

int main()
{
///	freopen("in.txt","r",stdin);////////////////////////
//	freopen("750.txt","w",stdout);////////////////////////

	int cas,end=0,endall=0;
	
	while(cin>>cas)
	{
		end=0;
		if(endall)
			cout<<endl;
		while(cas--)
		{
			if(end)
				cout<<endl;
			cin>>column>>row;
			memset(vis,0,sizeof(vis));
			memset(c,0,sizeof(c));
			vis[0][column]=vis[1][row+column]=vis[2][8+row-column]=1;
			c[row]=column;
			set=1;
			cout<<"SOLN       COLUMN\n"
				  " #      1 2 3 4 5 6 7 8\n\n";
			search(1);
			end=1;
		}
		endall=1;
	}

return 0;
}
