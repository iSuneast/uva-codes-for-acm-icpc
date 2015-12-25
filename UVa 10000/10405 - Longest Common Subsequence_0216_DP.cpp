/*
10405 - Longest Common Subsequence
*/

#include<iostream>

using namespace std;

char a[1010],b[1010];
int d[1010][1010],la,lb;	//d要弄成二维数组,不然无法保证所有情况都会算到

int dp(int cura,int curb)
{
	if(cura>=la || curb>=lb)
		return 0;
	if(d[cura][curb]>0)
		return d[cura][curb];
	for(int i=cura;i<la;i++)
		for(int j=curb;j<lb;j++)
			if(a[i]==b[j])
			{
				int max=dp(i+1,j+1)+1;
				d[cura][curb]=d[cura][curb]>max?d[cura][curb]:max;
			}
	return d[cura][curb];
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("10405.txt","w",stdout);

	while(gets(a) && gets(b))
	{
		memset(d,0,sizeof(d));
		la=strlen(a);lb=strlen(b);
		cout<<dp(0,0)<<endl;
	}

return 0;
}
/*
make.cpp

//最后其实还是要靠这个啊....

#include<iostream>
#include<ctime>

using namespace std;

int main()
{
	freopen("in.txt","w",stdout);
	srand(time(NULL));
	int n=1000,i,c;
	while(n--)
	{
		int i=2;
		while(i--)
		{
			while(c--)
			{
				cout<<(char)((rand()%26)+'a');
			}
			cout<<endl;
		}
	}

return 0;
}

*/