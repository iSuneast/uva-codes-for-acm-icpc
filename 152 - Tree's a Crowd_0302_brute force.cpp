/*
152 - Tree's a Crowd
*/

#include<iostream>
#include<cmath>

using namespace std;

double pnt[5005][3];

int main()
{
//	freopen("in.txt","r",stdin);

	int tree[11],num,i,j,d,m;
	num=0;
	while(cin>>pnt[num][0]>>pnt[num][1]>>pnt[num][2]
		&& (pnt[num][0]||pnt[num][1]||pnt[num][2]) )
		num++;
	double dx,dy,dz;
	memset(tree,0,sizeof(tree));
	for(i=0;i<num;i++)
	{
		m=20;
		for(j=0;j<num;j++)
			if(j!=i)
			{
				dx=pnt[i][0]-pnt[j][0];
				dy=pnt[i][1]-pnt[j][1];
				dz=pnt[i][2]-pnt[j][2];
				d=(int)floor(sqrt(dx*dx+dy*dy+dz*dz));
				m=m<d?m:d;
			}
			if(m<=10)
				tree[m]++;
	}
	for(i=0;i<10;i++)
		printf("%4d",tree[i]);
	cout<<endl;

return 0;
}
