/*
644 - Immediate Decodability
*/

#include<iostream>
#include<cstring>

using namespace std;

char fix[100][100];
int len[100];

int chk(int p)
{
	int i,j;
	char buf[100];
	for(i=0;i<p;i++)
	{
		if(len[i]<len[p])
		{
			strcpy(buf,fix[p]);
			buf[len[i]]='\0';
			if(!strcmp(buf,fix[i]))
				return 0;
		}
		else
		{
			strcpy(buf,fix[i]);
			buf[len[p]]='\0';
			if(!strcmp(buf,fix[p]))
				return 0;
		}
	}
	return 1;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i=0,flag=1,cas=1;
	while(cin>>fix[i])
		if(fix[i][0]!='9')
		{
			len[i]=strlen(fix[i]);
			if(!chk(i))
				flag=0;
			i++;
		}
		else
		{
			if(flag)
				cout<<"Set "<<cas++<<" is immediately decodable"<<endl;
			else
				cout<<"Set "<<cas++<<" is not immediately decodable"<<endl;
			i=0;flag=1;
		}
return 0;
}
