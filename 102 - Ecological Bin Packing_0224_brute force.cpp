/*
102 - Ecological Bin Packing
....
明显状态量很少...
直接枚举
*/

#include<iostream>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("102.txt","w",stdout);

	char key[6][4]={"BCG","BGC","CBG","CGB","GBC","GCB"};

	int bin1[3],bin2[3],bin3[3],b[6];
	while(cin>>bin1[0]>>bin1[1]>>bin1[2]
		>>bin2[0]>>bin2[1]>>bin2[2]
		>>bin3[0]>>bin3[1]>>bin3[2])
	{
		b[0]=bin1[1]+bin1[2]+bin2[0]+bin2[1]+bin3[0]+bin3[2];
		b[1]=bin1[1]+bin1[2]+bin2[0]+bin2[2]+bin3[0]+bin3[1];

		b[2]=bin1[0]+bin1[1]+bin2[1]+bin2[2]+bin3[0]+bin3[2];
		b[3]=bin1[0]+bin1[1]+bin2[0]+bin2[2]+bin3[1]+bin3[2];

		b[4]=bin1[0]+bin1[2]+bin2[1]+bin2[2]+bin3[0]+bin3[1];
		b[5]=bin1[0]+bin1[2]+bin2[0]+bin2[1]+bin3[1]+bin3[2];

		int m=0;
		for(int i=1;i<6;i++)
			if(b[i] < b[m])
				m=i;
		cout<<key[m]<<' '<<b[m]<<endl;
	}
return 0;
}
