/*
129 - Krypton Factor
*/

#include<iostream>

using namespace std;

int n,l,cnt;
char ans[100];

int dfs(int cur)
{
	int i,j,k,ok,equal;
	if(cnt++==n)		//��������е�������ƶ������������Ľ���,����cnt++
	{
		for(i=0;i<cur;i++)
			if(i&&i%64==0)
				putchar('\n'),putchar(ans[i]+'A');
			else if(i&&i%4==0)
				putchar(' '),putchar(ans[i]+'A');
			else
				putchar(ans[i]+'A');
		cout<<endl<<cur<<endl;
		return 0;
	}
	for(i=0;i<l;i++)
	{
		ans[cur]=i;				//������ַ����ĳ��ȱ�Ϊ(cur+1)+1
		ok=1;
		for(j=1;j*2<=cur+1;j++)	//�Ӻ�����ִ���ʼ���
		{
			equal=1;
			for(k=0;k<j;k++)	//�ִ��ĳ���Ϊż��,���Կ�����k,j����۰�Ա�.
				if(ans[cur-k]!=ans[cur-k-j])
				{
					equal=0;
					break;
				}
			if(equal)
			{
				ok=0;
				break;
			}
		}
		if(ok)
			if(!dfs(cur+1))
				return 0;		//�������dfs����0��ʱ������Ѿ��ҵ�����...�ݹ����
	}
	return 1;
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);

	while(cin>>n>>l&&(n||l))
		cnt=0,dfs(0);

return 0;
}
