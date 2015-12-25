/*
344 - Roman Digititis
*/

#include<iostream>

using namespace std;

char *table[10][2]={"",		"",
					"i",	"x",	//1
					"ii",	"xx",
					"iii",	"xxx",
					"iv",	"xl",
					"v",	"l",		//5
					"vi",	"lx",
					"vii",	"lxx",
					"viii",	"lxxx",
					"ix",	"xc"};
int main()
{
//	freopen("in.txt","r",stdin);
	
	int n,i=1,j,key[110][128];
	memset(key,0,sizeof(key));
	key[100]['c']=1;

	while(cin>>n && n)
	{
		for(;i<=n;i++)
		{
			if(i==100)
			{
				key[i]['i']+=key[i-1]['i'];
				key[i]['v']+=key[i-1]['v'];
				key[i]['x']+=key[i-1]['x'];
				key[i]['l']+=key[i-1]['l'];
				key[i]['c']+=key[i-1]['c'];
				break;
			}
			char *t=table[i%10][0];
			while(*t)
				key[i][*t++]++;
			t=table[i/10][1];
			while(*t)
				key[i][*t++]++;
			key[i]['i']+=key[i-1]['i'];
			key[i]['v']+=key[i-1]['v'];
			key[i]['x']+=key[i-1]['x'];
			key[i]['l']+=key[i-1]['l'];
			key[i]['c']+=key[i-1]['c'];
		}
		cout<<n<<": "<<key[n]['i']<<" i, "<<key[n]['v']<<" v, "
			<<key[n]['x']<<" x, "<<key[n]['l']<<" l, "<<key[n]['c']<<" c"<<endl;
	}

return 0;
}
