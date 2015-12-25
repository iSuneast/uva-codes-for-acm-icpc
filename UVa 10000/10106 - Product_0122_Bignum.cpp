/*
10106 - Product
*/

#include<iostream>
#include<cstring>

using namespace std;

char a[300],b[300];
int la,lb,ans[1000];

void rev(char * a,int l)
{
	int i,t;
	for(i=0;i<l/2;i++)
	{
		t=a[i];
		a[i]=a[l-i-1];
		a[l-i-1]=t;
	}
}

int main()
{
	int i,j;
	freopen("in.txt","r",stdin);
	while(gets(a)&&gets(b))
	{
		memset(ans,0,sizeof(ans));
		if(!strcmp(a,"0")||!strcmp(b,"0"))
		{
			cout<<0<<endl;
			continue;
		}
		la=strlen(a);
		lb=strlen(b);
		rev(a,la);
		rev(b,lb);
		for(i=0;i<la;i++)
			for(j=0;j<lb;j++)
				ans[i+j]+=(a[i]-'0')*(b[j]-'0');
		i=la+lb+1;
		for(j=0;j<=i;j++)
			if(ans[j]>=10)
				ans[j+1]+=ans[j]/10,ans[j]%=10;
		while(!ans[i])
			i--;
		for(j=i;j>=0;j--)
			cout<<ans[j];
		cout<<endl;
	}

return 0;
}
