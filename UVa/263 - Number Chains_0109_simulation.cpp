/*
263 - Number Chains
*/

#include<iostream>
#include<algorithm>

using namespace std;

long h,l,n,buf[1000],cnt;;

int cmp(const long a,const long b)
{
	return a<b;
}

int cmp_h(const long a,const long b)
{
	return a>b;
}

void sep()
{
	char num[13]={0};
	sprintf(num,"%d",n);
	sort(num,num+strlen(num),cmp);
	sscanf(num,"%d",&l);
	sort(num,num+strlen(num),cmp_h);
	sscanf(num,"%d",&h);
}

int exist()
{
	int i;
	for(i=0;i<cnt-1;i++)
		if(buf[i]==n)
			return 1;
	return 0;
}

int main()
{
//	freopen("in.txt","r",stdin);
	while(cin>>n&&n)
	{
		cnt=0;
		printf("Original number was %d\n",n);
		sep();
		do
		{
			buf[cnt]=n=h-l;
			cout<<h<<" - "<<l<<" = "<<n<<endl;
			sep();
			cnt++;
		}while(!exist());
		printf("Chain length %d\n\n",cnt);
	}

return 0;
}