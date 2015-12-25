/*
10132 - File Fragmentation
*/

#include<iostream>
#include<cstring>

using namespace std;

int cnt,len[200],total;
char file[200][300],ans[200];

void recover()
{
	char buf[200][2];
	memset(buf,0,sizeof(buf));
	int i,j;
	for(i=0;i<cnt;i++)
		for(j=0;j<len[i];j++)
		{
			++buf[j][file[i][j]-'0'];
			++buf[total-len[i]+j][file[i][j]-'0'];
		}
	for(i=0;i<total;i++)
		ans[i]=buf[i][0]>buf[i][1]?'0':'1';
}

int main()
{
//	freopen("in.txt","r",stdin);
	int cas;
	cin>>cas;getchar();getchar();
	while(cas--)
	{
		cnt=total=0;
		memset(ans,0,sizeof(ans));
		while(gets(file[cnt])&&strcmp(file[cnt],""))
			len[cnt]=strlen(file[cnt]),total+=len[cnt],++cnt;
		total=total*2/cnt;
		recover();
		cout<<ans<<endl;
		if(cas)
			cout<<endl;
	}

return 0;
}
