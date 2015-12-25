/*
490 - Rotating Sentences

simple
*/

#include<iostream>
#include<string>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	int max,i=0,j,k,cnt=0;
	string msg;
	char sen[100][100];

	memset(sen,' ',sizeof(sen));
	getline(cin,msg);
	max=msg.length();

	while(msg!="\0")
	{
		cnt++;
		for(j=0;j<msg.length()&&j<100;j++)
			sen[i][j]=msg[j];
		max=max>msg.length()?max:msg.length();
		i++;
		getline(cin,msg);
	}
	for(j=0;j<max;j++)
	{
		for(k=cnt-1;k>=0;k--)
			cout<<sen[k][j];
		cout<<endl;
	}

return 0;
}