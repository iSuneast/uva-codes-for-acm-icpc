/*
443 - Humble Numbers

number theory
*/

#include<iostream>

using namespace std;

long long num[5850],t;
int ls[]={2,3,5,7};

int main()
{
//	freopen("in.txt","r",stdin);

	int i,j,k,n;
	num[1]=1;
	for(i=2;i<=5842;i++)
	{
		num[i]=2147483647;
		for(j=1;j<i;j++)
			for(k=0;k<4;k++)
			{
				t=num[j]*ls[k];		//��Ȼ�����Χ��int��,�����м���̿������
				if(t>num[i-1] && t<num[i])
					num[i]=t;
			}
	}
	while(cin>>n && n)
	{
		cout<<"The "<<n;
		if(n%100-n%10 == 10)		//����Ҫ�ر�ע����һ��Ӣ����﷨
			cout<<"th";
		else switch(n%10)
		{
		case 1:	cout<<"st";	break;
		case 2:	cout<<"nd";	break;
		case 3:	cout<<"rd";	break;
		default:	cout<<"th";
		}
		cout<<" humble number is "<<num[n]<<"."<<endl;
	}

return 0;
}
