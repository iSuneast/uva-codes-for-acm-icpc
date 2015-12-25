/*
10042 - Smith Numbers

number theory...
WA��ʮ������...
������û�п��ǵ�˵"��nΪ��������ʷ��˹��"...
���Ǳ㻳���Ǿ�������...orz
����long long...��ʵ������û�б�Ҫ...
*/

#include<iostream>
#define MAXN 100000
using namespace std;

int prime[MAXN],cnt=0;

void init()
{
	prime[cnt++]=2;
	for(int i=3;i<MAXN;i+=2)
		if(!prime[i])
		{
			prime[cnt++]=i;
			for(int j=i;j<MAXN;j+=i)
				prime[j]=1;
		}
}

int total(int n)
{
	int s=0;
	while(n)
	{
		s+=n%10;
		n/=10;
	}
	return s;
}

int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
//��nΪ��������ʷ��˹��...
bool calc(int n)
{
	int s=total(n),t=0,tmp=n;
	for(int i=0;i<cnt && n!=1;++i)
		while(n%prime[i]==0)
		{
			n/=prime[i];
			t+=total(prime[i]);
		}
	if(n==tmp)		//n�޷����������������֪����������Ϊ������...
		return false;
	if(n!=1)
		t+=total(n);
	if(t==s)
	{
		int *p=(int*)bsearch(&tmp,prime,cnt,sizeof(prime[0]),cmp);
		if(p==NULL)
			return true;
	}
	return false;
}

int main()
{
//	freopen("in.txt","r",stdin);

	init();
	int dataset;
	int n;
	cin>>dataset;
	while(dataset--)
	{
		cin>>n;
		while(!calc(++n))
			;
		cout<<n<<endl;
	}

	return 0;
}
