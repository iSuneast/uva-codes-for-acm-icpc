/*
10747 - Maximum Subsequence

Ad hoc..
�Ȱ����ִ�С�ľ���ֵ����
����ֵһ����Ԫ�ذ���С����

���Ӿ���ֵ���Ԫ�ؿ�ʼһ��̰�ļ���
���̰�ĵõ��ĸ��������������Ļ���취ͨ������Ԫ����ȡ���������˻�
	@�ӽ�����������һ������,Ȼ���ʣ���Ԫ��������һ������
	@�ӽ�����������һ������,Ȼ���ʣ���Ԫ��������һ������
�������,���Խ���Ԫ��,ȡ������˻���һ��.�˻�һ��ȡ������һ��

������������û�г���,��˵�����������Ԫ��<=0
ֻ�谴ֵ��С����.Ȼ��ȡǰk�����ֵ��ͼ���...
*/

#include<iostream>
#include<algorithm>
#define MAXN 10010
using namespace std;
typedef pair<int,int> pii;

int n,k,var[MAXN];

int cmp(const int a,const int b)
{
	if(abs(a)!=abs(b))
		return abs(a)>abs(b);
	else
		return a>b;
}

int s;

pii process1()
{
	for(int i=k;i<n;++i)
	{
		if(var[i]<0)
			for(int j=k-1;j>=0;--j)
				if(var[j]>0)
					return make_pair(j,i);
	}
	return make_pair(-1,-1);
}

pii process2()
{
	for(int i=k;i<n;++i)
	{
		if(var[i]>0)
			for(int j=k-1;j>=0;--j)
				if(var[j]<0)
					return make_pair(j,i);
	}
	return make_pair(-1,-1);
}

int sum()
{
	sort(var,var+n);
	int s=0;
	for(int i=n-1;i>=n-k;--i)
		s+=var[i];
	return s;
}

int calc()
{
	s=0;
	bool negetive=false;
	sort(var,var+n,cmp);
	for(int i=0;i<k;++i)
	{
		if(var[i]<0)
			negetive=!negetive;
		s+=var[i];
		if(!var[i])
			return sum();
	}

	if(!negetive)
		return s;

	pii a=process1();
	pii b=process2();
	if(a.first!=-1 && b.first!=-1)
	{
		if(var[a.second]*var[b.first] > var[b.second]*var[a.first])
			return s-var[a.first]+var[a.second];
		else if(var[a.second]*var[b.first]  < var[b.second]*var[a.first])
			return s-var[b.first]+var[b.second];
		else
			return max(s-var[a.first]+var[a.second],s-var[b.first]+var[b.second]);
	}
	else if(a.first!=-1)
		return s-var[a.first]+var[a.second];
	else if(b.first!=-1)
		return s-var[b.first]+var[b.second];
	else
		return max(s,sum());
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d%d",&n,&k)!=EOF && (n||k))
	{
		for(int i=0;i<n;++i)
			scanf("%d",&var[i]);

		printf("%d\n",calc());
	}

	return 0;
}

/*�������������

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","w",stdout);
#endif

	srand((unsigned)time(NULL));
	int dataset=100;
	while(dataset--)
	{
		int n=rand()%10+1,k=rand()%n+1;
		cout<<n<<" "<<k<<endl;
		while(n--)
			cout<<rand()%10-5<<" ";
		cout<<endl;
	}
	cout<<"0 0"<<endl;

	return 0;
}

*/