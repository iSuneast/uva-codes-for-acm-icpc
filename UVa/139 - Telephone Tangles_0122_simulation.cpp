/*
139 - Telephone Tangles
*/

#include<iostream>
#include<cstring>

using namespace std;

char phone[10000][30],area[10000][50],call[500];
int all=0,tim,p,vip;
double mon[10000];

void print()
{
	int i;
	cout<<call;
	for(i=strlen(call)+1;i<17;i++)
		cout<<' ';
	cout<<area[p];
	for(i+=strlen(area[p])+strlen(call)-strlen(phone[p])-1;i<51;i++)
		cout<<' ';
	for(i=strlen(phone[p]);i<strlen(call);i++)
		cout<<call[i];
	printf("%5d%6.2f%7.2f\n",tim,mon[p]/100,tim*mon[p]/100);
}

int find()
{
	int i,j,t;
	for(i=1;i<all;i++)
	{
		t=strlen(phone[i]);
		for(j=0;j<t;j++)
			if(call[j]!=phone[i][j])
				break;
		if(j==t)
		{
			if(((call[0]==call[1])&&(strlen(call)-strlen(phone[i])>3)&&(strlen(call)-strlen(phone[i])<11)))
			return i;
			else if((strlen(call)-strlen(phone[i])<8)&&(strlen(call)-strlen(phone[i])>3))
				return i;
		}
	}
	return -1;
}

void calc()
{
	int i;
	if(call[0]!='0')
	{
		p=0,print();
		return ;
	}
	p=find();
	if((p==-1))
	{
		cout<<call;
		for(i=strlen(call)+1;i<17;i++)
			cout<<' ';
		cout<<"Unknown";
		for(i=23;i<51;i++)
			cout<<' ';
		printf("%5d%13.2f\n",tim,-1.0);
		return ;
	}
	print();
}

void preget()
{
	int i;
	char c;

	memset(phone,0,sizeof(phone));
	memset(area,0,sizeof(area));
	memset(mon,0,sizeof(mon));

	strcpy(phone[all],"");
	strcpy(area[all],"Local");
	mon[all++]=0;

	while(scanf("%s",phone[all]))
		if(strcmp(phone[all],"000000"))
		{
			getchar();
			i=0;
			while((c=getchar())!='$')
				area[all][i++]=c;
			area[all][i]='\0';
			cin>>mon[all++];

		}
		else
			break;
	while(cin>>call)
		if(strcmp(call,"#"))
			cin>>tim,calc();
}

int main()
{
	preget();

return 0;
}
