/*
324 - Factorial Frequencies
*/

#include<iostream>

using namespace std;

int fac[400][800],lf[400],n,ans[10],p=2;

void calc()
{
	for(;p<=n;p++)
	{
		char buf[32];
		sprintf(buf,"%d",p);
		int carry=0,l=strlen(buf),i,j,tmp[800];
		memset(tmp,0,sizeof(tmp));
		for(i=0;i<l/2;i++)
			swap(buf[i],buf[l-i-1]);
		for(i=0;i<l;i++)
			for(j=0;j<lf[p-1];j++)
			{
				tmp[i+j]+=(buf[i]-'0')*fac[p-1][j];
			}
		lf[p]=l+lf[p-1]-1;
		for(i=0;i<lf[p];i++)
		{
			fac[p][i]=(tmp[i]+carry)%10;
			carry=(tmp[i]+carry)/10;
			
		}
		if(carry)
			fac[p][lf[p]++]=carry;
	}
}

int main()
{
//	freopen("in.txt","r",stdin);

	memset(fac,0,sizeof(fac));
	memset(lf,0,sizeof(lf));
	fac[1][0]=1;lf[1]=1;
	while(cin>>n && n)
	{
		calc();
		memset(ans,0,sizeof(ans));

		for(int i=lf[n]-1;i>=0;i--)
			ans[ fac[n][i] ]++;
		cout<<n<<"! --"<<endl;
		printf("   (0)%5d    (1)%5d    (2)%5d    (3)%5d    (4)%5d\n",ans[0],ans[1],ans[2],ans[3],ans[4]);
		printf("   (5)%5d    (6)%5d    (7)%5d    (8)%5d    (9)%5d\n",ans[5],ans[6],ans[7],ans[8],ans[9]);
	}

return 0;
}
