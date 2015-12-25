/*
10260 - Soundex
*/

#include<iostream>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	char sound[30];
	while(cin>>sound)
	{
		int l=strlen(sound),t=0;
		for(int i=0;i<l;i++)
			switch(sound[i])
			{
			case 'B' :case 'F' :case 'P' :case 'V' :
				if(t!=1)
					t=1,cout<<t;
				break;

			case 'C' :case 'G' :case 'J' :case 'K' :
			case 'Q' :case 'S' :case 'X' :case 'Z' :
				if(t!=2)
					t=2,cout<<t;
				break;
			case 'D' :case 'T' :
				if(t!=3)
					t=3,cout<<t;
				break;
			case 'L' :
				if(t!=4)
					t=4,cout<<t;
				break;
			case 'M' :case 'N' :
				if(t!=5)
					t=5,cout<<t;
				break;
			case 'R' :
				if(t!=6)
					t=6,cout<<t;
				break;
			default :
				t=0;
				break;
			}
		cout<<endl;
	}

return 0;
}
