/*
11732 - strcmp() Anyone?

̫�ж���...
����AC��...
ͬʱ����cpp��Ч�ʲ������C���Եͺܶ�...
ֻ������������Ǳ��е���¶���...
�������ֶ��ǲ���...
*/

#include<iostream>
using namespace std;

char str[4010][1010];
int mat[4010][4010],mem[4010];

int cmp(char *a,char *b)
{
	char *s=a;
	while(*s==*b && *s)
	{
		++s;++b;
	}
//	return (s-a+1)*2-(*s+*b)?1:0;
//��,��Ȼ�����ɵ������,Ȼ��һֱTLE...
	return (s-a+1)*2-((*s+*b)?1:0);
}

int main()
{
//	freopen("in.txt","r",stdin);

	int j,k,l,cnt,m,n,s,cas=1;
	long ans;
	while(cin>>cnt && cnt)
	{
		getchar();
		memset(mat,0,sizeof(mat));
		memset(mem,0,sizeof(mem));
		ans=0;
		gets(str[0]);
		for(j=1;j<cnt;j++)
		{
			gets(str[j]);
			mat[0][j]=cmp(str[0],str[j]);
			ans+=mat[0][j];
			for(k=1;k<j;k++)
			{
				l=mem[k];
				m=mat[l][j];
				n=mat[l][k];
				if(m!=n)		//ȡС...
					mat[k][j]=m<n?m:n;
				else if(m%2)	//���m�Ƿ�Ϊ����.
				{
					s=(m-1)>>1;	//��s��ʼ�Ƚ�
					mat[k][j]=m-1+cmp(str[k]+s,str[j]+s);
				}
				else
					mat[k][j]=m;
				if(mat[mem[j]][j]<mat[k][j])
					mem[j]=k;
				ans+=mat[k][j];
			}
		}
		cout<<"Case "<<cas++<<": "<<ans<<endl;
	}

return 0;
}
