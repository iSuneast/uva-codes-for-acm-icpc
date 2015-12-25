/*
127 - "Accordian" Patience
*/

#include<iostream>
#include<stack>

using namespace std;

char buf[100];
int n,p,hash[60],hashp=0;

int format(stack<int> card[])
{
	int i,j;
	for(i=j=p;i<hashp;i++)
		if(!card[hash[i]].empty())
			hash[j++]=hash[i];
	return j;
}

bool try_to_insert(int p0,int p1,stack<int> card[])
{
	if(p0<0)
		return false;
	else if(card[hash[p0]].top()%100==card[hash[p1]].top()%100
			|| card[hash[p0]].top()/100==card[hash[p1]].top()/100)
		return true;
	else
		return false;
}

void make(stack<int> card[])
{
	char *token=strtok(buf," "),rank,suit;
	int gap,t;
	while(token!=NULL)
	{
		sscanf(token,"%c%c",&rank,&suit);
		card[n].push(rank*100+suit);
		hash[hashp++]=n++;
		p=t=hashp-1;
		while(p<hashp)
		{
			gap=0;
			while(!card[hash[p]].empty())
				if(try_to_insert(p-3,p,card))
					card[hash[p-3]].push(card[hash[p]].top()),
					card[hash[p]].pop(),
					p-=3,gap++;
				else if(try_to_insert(p-1,p,card))
					card[hash[p-1]].push(card[hash[p]].top()),
					card[hash[p]].pop(),
					p--,gap++;
				else
					break;
			if(!gap && p==t)			//新节点没有移动.
				break;
			if(gap)
				hashp=format(card);
			p++;
		}
		token=strtok(NULL," ");
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
	while(gets(buf) && buf[0]!='#')
	{
//		memset(card,0,sizeof(card));		//这句话导致RE....
		stack<int> card[60];
		n=hashp=0;

		make(card);
		gets(buf);
		make(card);
		if(hashp==1)
			cout<<"1 pile remaining: 52"<<endl;
		else
		{
			cout<<hashp<<" piles remaining:";
			for(int i=0;i<hashp;i++)
				cout<<' '<<card[hash[i]].size();
			cout<<endl;
		}
	}

return 0;
}
