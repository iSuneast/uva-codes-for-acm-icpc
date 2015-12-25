/*
10409 - Die Game
*/

#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	map<string,int> m;
	m["north"]=0;	m["south"]=1;
	m["west"]=2;	m["east"]=3;
	int n;
	while(cin>>n && n)
	{
		int up=1,front=2,left=3,t;
		string dir;
		while(n--)
		{
			cin>>dir;
			t=up;
			switch(m[dir])
			{
			case 0:
				up=7-front;
				front=t;
				break;
			case 1:
				up=front;
				front=7-t;
				break;
			case 2:
				up=7-left;
				left=t;
				break;
			case 3:
				up=left;
				left=7-t;	//果然又是小BUG.left=7-up.亏我写的出来.
				break;
			}
		}
		cout<<up<<endl;
	}

return 0;
}
