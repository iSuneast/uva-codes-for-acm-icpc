/*
639 - Don't Get Rooked
*/

#include<iostream>

using namespace std;

int n,ans;
char flag[6][6];

//�տ�ʼ,һֱWA....��Ȼ��mark�����и��ش��bug...

void mark(int x,int y,int k)
{
	int i;
	char c=flag[x][y];	//���뱣��ԭֵ,�����ñ��,�����Щ��ǰδ���ʹ��ĵ�.
	flag[x][y]=k;
	for(i=x+1;i<=n;i++)
		if(flag[i][y]=='X')
			break;
		else if(flag[i][y]==c)
			flag[i][y]=k;
	for(i=y+1;i<=n;i++)
		if(flag[x][i]=='X')
			break;
		else if(flag[x][i]==c)
			flag[x][i]=k;
	for(i=x-1;i;i--)
		if(flag[i][y]=='X')
			break;
		else if(flag[i][y]==c)
			flag[i][y]=k;
	for(i=y-1;i;i--)
		if(flag[x][i]=='X')
			break;
		else if(flag[x][i]==c)
			flag[x][i]=k;
}

void dfs(int x,int y,int key)
{
	for(int k=y;k<=n;k++)		//��ɨ���x��
		if(flag[x][k]=='.')
		{
			mark(x,k,key+1);
			dfs(x,k,key+1);
			mark(x,k,'.');
		}
	for(int i=x+1;i<=n;i++)		//��x+1��,y=1�п�ʼɨ��.
		for(int j=1;j<=n;j++)
			if(flag[i][j]=='.')
			{
				mark(i,j,key+1);
				dfs(i,j,key+1);
				mark(i,j,'.');
			}
	ans=ans>key?ans:key;
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("639.txt","w",stdout);

	while(cin>>n && n)
	{
		int i,j;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				cin>>flag[i][j];
		ans=0;
		dfs(1,1,0);
		cout<<ans<<endl;
	}

return 0;
}

/*
void out()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			if(flag[i][j]>10)
				cout<<flag[i][j];
			else
				cout<<(int)flag[i][j];
		cout<<endl;
	}
	cout<<"_____________________"<<endl;
}
*/

/*
��ʵ����ǿ�make.exe�ҵ�bug��...
�m �� �� .o�� �m  �m.. ��
�m���m ��  �� .�m �mo�y�z�|�}
�� �� /��\/��\ �m �� �m�m �� �m 
�|�}�~�����������~�}�|�z�y���m

#include<iostream>
#include<ctime>

using namespace std;

int main()
{
	freopen("in.txt","w",stdout);
	srand(time(NULL));
	int n=100;
	while(n--)
	{
		int r=rand()%4+1,i,j;
		cout<<r<<endl;
			for(i=0;i<r;i++)
			{
				for(j=0;j<r;j++)
					if(rand()%2)
						cout<<'.';
					else
						cout<<'X';
				cout<<endl;
			}
	}

return 0;
}

*/