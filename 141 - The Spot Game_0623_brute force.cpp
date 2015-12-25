/*
141 - The Spot Game

simulation...
brute force..
ֱ��ģ����ת
Ȼ����ƥ�伴��

��ת:�Ե�ǰ״̬˳ʱ��90����ת3�μ��ɵõ����н�
�۲�ɵ�
��(x0,y0)Ϊԭ״̬a0[x0][y0]
  (x1,y1)Ϊ˳ʱ��90����ת״̬a1[x1][y1]
��	x0+y1=n+1,x1=y0
����a1[x1][y1]=a0[x0][y0]
			  =a0[ n+1-y1 ][ x1 ]
Ȼ������о�����ƥ�伴��
*/

#include<iostream>
#define MAXN 51
using namespace std;

bool state[MAXN*8][MAXN][MAXN];
int n;

void rotate_mat(int s,int e)
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			state[e][i][j]=state[s][n+1-j][i];
}

bool cmp(int a,int b)
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(state[a][i][j]!=state[b][i][j])
				return false;
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(cin>>n && n)
	{
		memset(state[0],0,sizeof(state[0]));
		int x,y,win=0;
		char c;
		for(int i=0;i<2*n;++i)
		{
			cin>>x>>y>>c;
			if(!win)
			{
				int cur=i*4;
				if(i)
					memcpy(state[cur],state[(i-1)*4],sizeof(state[0]));
				if(c=='+')
					state[cur][x][y]=true;
				else
					state[cur][x][y]=false;

				for(int j=0;j<cur;++j)
					if(cmp(cur,j))
					{
						win=i+1;
						break;
					}
				if(!win)
					for(int j=cur;j<cur+3;++j)
						rotate_mat(j,j+1);
			}
		}
		if(!win)
			cout<<"Draw"<<endl;
		else
			cout<<"Player "<<(win&1?2:1)<<" wins on move "<<win<<endl;
	}

	return 0;
}
