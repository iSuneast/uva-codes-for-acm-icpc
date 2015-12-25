/*
408 - Uniform Generator
....����....
..
������˵��ô�����ⶼ������....��AC��...
*/

#include<iostream>

using namespace std;

int euler(int a,int b)
{
	if(a%b==0)
		return b;
	return euler(b,a%b);
}

int main()
{
	int step,mod;
	while(cin>>step>>mod)
	{
		printf("%10d%10d",step,mod);
		if(euler(step,mod)==1)
			cout<<"    Good Choice"<<endl<<endl;
		else
			cout<<"    Bad Choice"<<endl<<endl;
	}

return 0;
}
