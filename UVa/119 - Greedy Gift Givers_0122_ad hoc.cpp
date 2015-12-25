/*
119 - Greedy Gift Givers
*/

//rem	remain
//recn	receive number

#include<iostream>
#include<cstring>

using namespace std;

char nam[100][120],man[120];
int res[100],num;

void print()
{
	int i;
	for(i=0;i<num;i++)
		cout<<nam[i]<<' '<<res[i]<<endl;
}

void giveto(int mon,char *man)
{
	int i;
	for(i=0;i<num;i++)
		if(!strcmp(man,nam[i]))
		{
			res[i]+=mon;
			return ;
		}
}

int main()
{
	int i,j,mon,recn,rem,flag=0;
	while(cin>>num)
	{
		if(flag)
			cout<<endl;
		memset(nam,0,sizeof(nam));
		memset(man,0,sizeof(man));
		memset(res,0,sizeof(res));

		for(i=0;i<num;i++)
			cin>>nam[i];
		for(i=0;i<num;i++)
		{
			cin>>man>>mon>>recn;
			if(recn)
			{
				rem=mon%recn;
				giveto(rem-mon,man);
				mon=(mon-rem)/recn;
				for(j=0;j<recn;j++)
					cin>>man,giveto(mon,man);
			}
		}
		print();
		flag=1;
	}

return 0;
}
