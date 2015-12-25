/*
673 - Parentheses Balance
...
感叹于string的无比强大...
*/

#include<iostream>
#include<string>

using namespace std;

int main()
{
	freopen("in.txt","r",stdin);

	int n,flag;
	string buf,key1="()",key2="[]";
	string::size_type p;
	cin>>n;getchar();

	while(n--)
	{
		flag=1;
		getline(cin,buf);
		while((p=buf.find(key1))<buf.length()||(p=buf.find(key2))<buf.length())
			buf.erase(p,2);
		if(buf.empty())
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}

return 0;
}
