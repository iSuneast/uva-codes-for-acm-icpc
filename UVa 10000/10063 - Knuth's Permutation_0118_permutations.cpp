/*
10063 - Knuth's Permutation
*/

#include<iostream>
#include<string>

using namespace std;

void perm(string buf,string str)
{
	if(buf=="")
		cout<<str<<endl;
	else
		for(int i=0;i<str.length()+1;i++)
			perm(buf.substr(1,buf.length()-1),str.substr(0,i)+buf[0]+str.substr(i,str.length()-i));
}

int main()
{
	string str,buf;
	int flag=0;
	while(getline(cin,str))
	{
		if(flag)
			cout<<endl;
		perm(str,"");
		flag=1;
	}

return 0;
}