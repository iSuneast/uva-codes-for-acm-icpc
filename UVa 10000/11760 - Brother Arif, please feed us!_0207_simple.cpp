/*
11760 - Brother Arif, please feed us!
....
以后考虑问题要慎重啊...
*/

#include<iostream>

using namespace std;

int row[10001],col[10001];
int R,C,N,i,r,c,cas=1;

int main()
{
//	freopen("in.txt","r",stdin);
	
	while(cin>>R>>C>>N&&(R||C||N))
	{
		memset(row,0,sizeof(row));
		memset(col,0,sizeof(col));
		row[0]=col[0]=row[R+1]=col[C+1]=1;		//边界要封死....

		for(i=0;i<N;i++)
			cin>>r>>c,
			row[r+1]=1,
			col[c+1]=1;
		cin>>r>>c;

		if((row[r+1]||col[c+1]) && ((row[r+1]||col[c])) && ((row[r+1]||col[c+2])) && ((row[r]||col[c+1])) && ((row[r+2]||col[c+1])))
			cout<<"Case "<<cas++<<": Party time! Let's find a restaurant!";
		else
			cout<<"Case "<<cas++<<": Escaped again! More 2D grid problems!";
		cout<<endl;
	}

return 0;
}
