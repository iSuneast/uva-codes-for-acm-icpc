/*
10018 - Reverse and Add
....
托溢出的福。。
狂WA。。。
试一下sample 1 4000000000
*/

#include<iostream>

using namespace std;

long long l,n,t;
char buf[38];

void rev(char *buf)
{
	for(int i=0;i<l/2;i++)
		swap(buf[i],buf[l-i-1]);
}

bool palindrome()
{
	sprintf(buf,"%u",n);
	l=strlen(buf);
	for(int i=0;i<l/2;i++)
		if(buf[i]!=buf[l-i-1])
			return false;
	return true;
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);

	int dataset,cnt;
	cin>>dataset;
	while(dataset--)
	{
		cin>>n;
		cnt=0;
		while(!palindrome())
		{
			rev(buf);
			sscanf(buf,"%u",&t);
			n+=t;
			cnt++;
		}
		cout<<cnt<<' '<<n<<endl;
	}

return 0;
}
