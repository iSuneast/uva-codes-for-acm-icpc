/*
10344 - 23 out of 5

backtracking...
�������ΪUVa������һֱ�ı��...
�տ�ʼ���˵ÿ��'o'Ӧ����ֻ����һ����������...
����WA...(�����������ط�)
��BBS��֪��˵���ݵ�˳���ǿ��Ե�����...
��next_permutation����ȫ����ȴ����WA...

�������ڿ���������..
'o'ֻ��һ��������...
�����������a*(-b)�������...
���ݵ�˳���ǿ������⽻����...
a,b,c,d,e -> ȫ���ж��п���...
*/

#include<iostream>
using namespace std;

int num[5],flag[5];

bool dfs(int var,int cur)
{
	if(cur==5)
	{
		if(var==23)		//����varֻ����23,������-23����,Ҳ����˵,ÿ��'o'ֻ��һ��������
			return true;
		else
			return false;
	}
	for(int i=0;i<5;++i)
		if(!flag[i])
		{
			flag[i]=1;
			if(dfs(var+num[i],cur+1)
			|| dfs(var-num[i],cur+1)
			|| dfs(var*num[i],cur+1))
				return true;
			flag[i]=0;
		}
	return false;
}

int main()
{
//	freopen("in.txt","r",stdin);

	while(true)
	{
		bool bk=true;
		int i;
		for(i=0;i<5;++i)
		{
			cin>>num[i];
			if(num[i])
				bk=false;
			flag[i]=0;
		}
		if(bk)
			break;
		bool got=false;
		for(i=0;i<5;++i)
		{
			flag[i]=1;
			if(dfs(num[i],1))
			{
				cout<<"Possible"<<endl;
				got=true;
				break;
			}
			flag[i]=0;
		}
		if(!got)
			cout<<"Impossible"<<endl;
	}

	return 0;
}
