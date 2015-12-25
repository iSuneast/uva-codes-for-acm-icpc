/*
541 - Error Correction
*/

#include<iostream>

using namespace std;

int mat[100][100],c[100],l[100],i,j,failedi,failedj,keyi,keyj;
int n;

int chk()
{
	failedi=failedj=0;
	for(i=0;i<n;i++)			
		if(c[i]%2)
			failedi++,keyi=i;
	if(failedi>1)
		return 2;
	for(j=0;j<n;j++)
		if(l[j]%2)
			failedj++,keyj=j;
		if(failedj>1)
			return 2;
	if(failedi==failedj)
		return failedi;
		else
			return 2;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int ans;
	while(cin>>n&&n)
	{
		memset(mat,0,sizeof(mat));
		memset(c,0,sizeof(c));
		memset(l,0,sizeof(l));

		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				cin>>mat[i][j],c[i]+=mat[i][j],l[j]+=mat[i][j];
		ans=chk();
		if(ans==0)
			cout<<"OK"<<endl;
		else if(ans==1)
			cout<<"Change bit ("<<keyi+1<<','<<keyj+1<<')'<<endl;
		else
			cout<<"Corrupt"<<endl;
	}

return 0;
}