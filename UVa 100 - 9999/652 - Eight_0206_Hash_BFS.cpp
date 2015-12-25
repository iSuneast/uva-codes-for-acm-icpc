/*
652 - Eight
现在想起来..
觉得说TLE完全是托memcmp的福...
*/

#include<iostream>

using namespace std;

typedef int state[10];			//最后一位存放Z.即0的位置
const int MAXSTATE=1000003;
const int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
state st[MAXSTATE]={1,2,3,4,5,6,7,8,0,8},goal;
int dir[MAXSTATE],fa[MAXSTATE];
char key[]={'d','u','r','l'};
int head[MAXSTATE],next[MAXSTATE],hasht[MAXSTATE];
int front=0,rear=1;

bool issolvable(state &s)
{
	int i,j,sum=0;
	for(i=0;i<9;i++)
		for(j=i+1;j<9;j++)
			if(j==s[9])
				continue;
			else if(s[i]>s[j])
				sum++;
	return sum%2==0;
}

int hash(int s)
{
	hasht[s]=0;
	for(int i=0;i<9;i++)
		hasht[s]=hasht[s]*10+st[s][i];
	return hasht[s]%MAXSTATE;
}

int try_to_insert(int s)
{
	int h=hash(s);
	int u=head[h];
	while(u)
	{
		if(hasht[u]==hasht[s])
			return 0;
		u=next[u];
	}
	next[s]=head[h];
	head[h]=s;
	return 1;
}

int bfs()
{
	int i,hashg=0;

	for(i=0;i<9;i++)			//计算goal的hash
		hashg=hashg*10+goal[i];
	for(i=0;i<front;i++)
		if(hashg==hasht[i])
			return i;

	while(front<rear)
	{
		state &s=st[front];
		if(hashg==hasht[front])
			return front;

		int z=s[9],x=z/3,y=z%3;
		for(int d=0;d<4;d++)
		{
			int newx=x+dx[d],newy=y+dy[d],newz=3*newx+newy;
			int cnt=0;
			if(newx>=0 && newy>=0 && newx<3 && newy<3)
			{
				state &t=st[rear];
				memcpy(t,s,sizeof(s));
				t[newz]=s[z];
				t[z]=s[newz];
				t[9]=newz;
				fa[rear]=front;
				dir[rear]=d;
				if(try_to_insert(rear))
					rear++;
			}
		}
		front++;
	}
	return 0;
}

void print(int ans)
{
	if(!ans)
		return ;
	putchar(key[dir[ans]]);	
	print(fa[ans]);
}

int main()
{
//	freopen("in.txt","r",stdin);
	int dataset;
	cin>>dataset;
	memset(head,0,sizeof(head));
	hasht[0]=hash(0);

	while(dataset--)
	{
		char c;
		for(int i=0;i<9;i++)
		{
			cin>>c;
			if(c=='x')
				goal[i]=0,goal[9]=i;
			else
				goal[i]=c-'0';
		}
		if(issolvable(goal))
			print(bfs()),
			cout<<endl;
		else
			cout<<"unsolvable"<<endl;
		if(dataset)
			cout<<endl;
	}

return 0;
}
