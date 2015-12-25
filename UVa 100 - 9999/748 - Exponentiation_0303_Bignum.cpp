/*
748 - Exponentiation
*/

#include<iostream>
#include<cmath>

using namespace std;

double r,n;
char ans[200],key[10];
int buf[200];	//之所以用int,是因为用char的时候中间结果溢出了..

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("748.txt","w",stdout);

	while(cin>>r>>n)
	{
		int la=floor(n*log10(r))+1;
		if(la<0)
			la=0;
		sprintf(key,"%lf",r);
		char *token=strtok(key,".");
		token=strtok(NULL,".");
		int lb=strlen(token);
		while(token[lb-1]=='0')
			lb--;
		token[lb]='\0';
		strcat(key,token);
		lb*=n;
		int i,j,l=strlen(key),carry;
		for(i=0;i<<1 < l;i++)
			swap(key[i]-='0',key[l-i-1]-='0');
		if(l%2)
			key[l/2]+='0';
		while(!key[l-1])
			l--;
		memset(ans,0,sizeof(ans));
		memcpy(ans,key,sizeof(key));
		int lans=l;
		while(--n)
		{
			memset(buf,0,sizeof(buf));
			for(i=0;i<lans;i++)
				for(j=0;j<l;j++)
					buf[i+j]+=ans[i]*key[j];
			lans+=l;
			for(i=carry=0;i<lans;i++)
			{
				ans[i]=(buf[i]+carry)%10;
				carry=(buf[i]+carry)/10;
			}
		}
		while(!ans[lans-1])
			--lans;
		for(i=lans-1;la--;i--,lans--)
			cout<<(int)ans[i];
		cout<<'.';
		for(i=lans;i<lb;i++)
			cout<<0;
		while(lans--)
			cout<<(int)ans[lans];
		cout<<endl;
	}

return 0;
}
