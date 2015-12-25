/*
10420 - List of Conquests
*/

#include<iostream>
#include<cstring>
#include<string>

using namespace std;

int main()
{
	int n,i,j,num[2000],cnt,flag,t;
	char count[2000][75],tmp[75];

	while(cin>>n)
	{
		getchar();
		cnt=0;
		memset(num,0,sizeof(num));
		memset(count,0,sizeof(count));
		for(i=0;i<n;i++)
		{
			gets(tmp);
			flag=0;				//这个地方时杯具的源泉....
			for(j=0;j<strlen(tmp);j++)
				if(tmp[j]==' ')
				{
					tmp[j]='\0';
					break;
				}
			for(j=0;j<cnt;j++)
				if(!strcmp(count[j],tmp))
				{
					num[j]++;
					flag=1;
					break;
				}
			if(!flag)
			{
				j=0;
				while(count[cnt][j]=tmp[j])
					j++;
				num[cnt++]++;
			}
		}
		for(i=0;i<cnt;i++)
		{
			t=i;
			for(j=i+1;j<cnt;j++)
				if(strcmp(count[t],count[j])>0)
					t=j;
			if(t!=i)
			{
				cout<<count[t]<<' '<<num[t]<<endl;
				strcpy(count[t],count[i]);
				num[t]=num[i];
			}
			else
				cout<<count[t]<<' '<<num[t]<<endl;
		}
	}

return 0;
}