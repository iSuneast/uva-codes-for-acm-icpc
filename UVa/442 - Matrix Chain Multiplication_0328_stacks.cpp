/*
442 - Matrix Chain Multiplication

stack...
*/

#include<iostream>
#include<string>
#include<stack>
#define MAXN 30
using namespace std;
typedef pair<int,int> pii;

int main()
{
//	freopen("in.txt","r",stdin);

	int n,c,r,i,key,mat[2][MAXN];;
	char cur,none='T';
	cin>>n;
	for(i=0;i<n;++i)
	{
		cin>>cur>>c>>r;
		mat[0][cur-'A']=c;
		mat[1][cur-'A']=r;
	}
	string buf;
	while(cin>>buf)
	{
		key=0;
		int len=buf.length(),tc,tr;
		stack<char> sc;
		stack<pii> tmp,_t;
		bool error=false;
		pii a,b;
		for(int i=0;i<len && !error;++i)
		{
			switch(buf[i])
			{
			case '(':
				sc.push('(');
				break;
			case ')':
				while(sc.top()!='(')
				{
					sc.pop();
					_t.push(tmp.top());
					tmp.pop();
				}
				sc.pop();	sc.push(none);
				a=_t.top();	_t.pop();
				while(!_t.empty())
				{
					b=_t.top();	_t.pop();
					if(a.second!=b.first)
					{
						error=true;
						break;
					}
					key+=a.first*a.second*b.second;
					a.second=b.second;
				}
				tmp.push(a);
				break;
			default:
				if(!sc.empty() && sc.top()!='(')
				{
					a=tmp.top();	tmp.pop();
					b=make_pair(mat[0][buf[i]-'A'],mat[1][buf[i]-'A']);
					if(a.second!=b.first)
					{
						error=true;
						break;
					}
					key+=a.first*a.second*b.second;
					tmp.push(make_pair(a.first,b.second));
				}
				else
				{
					sc.push(none);
					tmp.push(make_pair(mat[0][buf[i]-'A'],mat[1][buf[i]-'A']));
				}
			}
		}
		if(error)
			cout<<"error"<<endl;
		else
			cout<<key<<endl;
	}

	return 0;
}
