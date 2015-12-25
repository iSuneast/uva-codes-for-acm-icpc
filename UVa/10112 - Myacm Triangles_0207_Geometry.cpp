/*
10112 - Myacm Triangles
*/

#include<iostream>

using namespace std;

struct Myacm
{
	char label;
	int x,y;
}co[20];

int hash[20][20][20];


int square(int x1,int y1,int x2,int y2,int x3,int y3)
{
	return abs((y3-y1)*(x2-x1)-(x3-x1)*(y2-y1));
}

int main()
{
//	freopen("in.txt","r",stdin);
	int n,i,j,k,l,flag,px,py,pz;
	while(cin>>n&&n)
	{
		memset(hash,0,sizeof(hash));
		for(i=0;i<n;i++)
			cin>>co[i].label>>co[i].x>>co[i].y;
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				for(k=j+1;k<n;k++)
					hash[i][j][k]
					=square(co[i].x,co[i].y,co[j].x,co[j].y,co[k].x,co[k].y);

		px=py=pz=0;
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				for(k=j+1;k<n;k++)
					if(hash[px][py][pz]<hash[i][j][k])
					{
						flag=0;
						for(l=0;l<n;l++)
							if(l<i)
							{
								if(hash[l][i][j]+hash[l][i][k]+hash[l][j][k]
									==hash[i][j][k])
								{	 flag=1;		break;	}
							}
							else if(i<l&&l<j)
							{
								if(hash[i][l][j]+hash[i][l][k]+hash[l][j][k]
									==hash[i][j][k])
								{	 flag=1;		break;	}
							}
							else if(j<l&&l<k)
							{
								if(hash[i][j][l]+hash[i][l][k]+hash[j][l][k]
									==hash[i][j][k])
								{	 flag=1;		break;	}
							}
							else if(k<l)
							{
								if(hash[i][j][l]+hash[i][k][l]+hash[j][k][l]
									==hash[i][j][k])
								{	 flag=1;		break;	}
							}
						if(!flag)
							px=i,py=j,pz=k;
					}
		cout<<co[px].label<<co[py].label<<co[pz].label<<endl;
	}

return 0;
}
