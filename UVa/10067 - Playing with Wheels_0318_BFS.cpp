#include<iostream>
#include<queue>
#define MAXN 10010
using namespace std;

int hash[MAXN];
const int front[]={9,0,1,2,3,4,5,6,7,8};
const int rear[]={1,2,3,4,5,6,7,8,9,0};

int h(char *s)
{
	return 1000*(s[0]-'0')+100*(s[1]-'0')+10*(s[2]-'0')+(s[3]-'0');
}

int main()
{
//	freopen("in.txt","r",stdin);

	int dataset;
	cin>>dataset;
	while(dataset--)
	{
		int n,start,target,state,i;
		char s[10],buf[10];
		memset(s,0,sizeof(s));
		buf[4]=s[4]=0;
		for(i=0;i<4;i++)
			cin>>s[i];
		start=h(s);
		for(i=0;i<4;i++)
			cin>>s[i];
		target=h(s);
		cin>>n;
		memset(hash,-1,sizeof(hash));
		while(n--)
		{
			for(i=0;i<4;i++)
				cin>>s[i];
			state=h(s);
			hash[state]=0;
		}
		queue<int> q;
		q.push(start);
		hash[start]=0;
		while(!q.empty())
		{
			state=q.front();
			q.pop();
			if(state==target)
				break;
			int dis=hash[state];
			sprintf(s,"%04d",state);
			for(int d=0;d<4;d++)
			{
				memcpy(buf,s,sizeof(s));
				buf[d]=front[s[d]-'0']+'0';
				buf[4]=0;
				sscanf(buf,"%d",&state);
				if(hash[state]==-1)
				{
					hash[state]=dis+1;
					q.push(state);
				}

				memcpy(buf,s,sizeof(s));
				buf[d]=rear[s[d]-'0']+'0';
				buf[4]=0;
				sscanf(buf,"%d",&state);
				if(hash[state]==-1)
				{
					hash[state]=dis+1;
					q.push(state);
				}
			}
		}
		cout<<hash[target]<<endl;
	}

return 0;
}
