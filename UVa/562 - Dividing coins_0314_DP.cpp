/*
562 - Dividing coins
*/

#include<iostream>
#define MAXN 101
using namespace std;

int flag[500*MAXN];
int main()
{
//	freopen("in.txt","r",stdin);

	int dataset,m,i,j,sum,coin;
	cin>>dataset;
	while(dataset--)
	{
		cin>>m;
		sum=0;
		memset(flag,0,sizeof(flag));
		flag[0]=1;
		for(i=0;i<m;i++)
		{
			cin>>coin;
			for(j=sum;j>=0;j--)	//ע��,�����������ö��,��Ȼ�����
				if(flag[j])
					flag[j+coin]=1;
			sum+=coin;
		}
		for(i=sum/2;i>=0;i--)
			if(flag[i] || flag[sum-i])
				break;
		cout<<sum-2*i<<endl;
	}

return 0;
}
