/*
10945 - Mother bear

string
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	string talk;
	while(getline(cin,talk) && talk!="DONE")
	{
		int i,p,l=talk.length();
		for(i=p=0;i<l;i++)
			if(isalpha(talk[i]))
				talk[p++]=tolower(talk[i]);
		bool beat=false;
		for(i=0;i<p/2;i++)
			if(talk[i]!=talk[p-1-i])
			{
				beat=true;
				break;
			}
		if(beat)
			cout<<"Uh oh.."<<endl;
		else
			cout<<"You won't be eaten!"<<endl;
	}

return 0;
}
