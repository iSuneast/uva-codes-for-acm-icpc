/*
10530 - Guessing Game

simulation...
Ä£ÄâÌâ...
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);

	string str1,str2;
	int upper,lower,cur;
	while(cin>>cur && cur)
	{
		upper=20;
		lower=-1;
		while(cin>>str1>>str2 && str2!="on")
		{
			if(str2=="high")
				upper=upper<cur?upper:cur;
			else if(str2=="low")
				lower=lower>cur?lower:cur;
			else
				break;
			cin>>cur;
		}
		if(cur>lower && cur<upper)
			cout<<"Stan may be honest"<<endl;
		else
			cout<<"Stan is dishonest"<<endl;
	}

	return 0;
}
