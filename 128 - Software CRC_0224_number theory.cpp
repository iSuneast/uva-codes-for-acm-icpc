/*
128 - Software CRC
*/

#include<iostream>
#include<string>

using namespace std;

#define g 34943

int main()
{
//	freopen("in.txt","r",stdin);
	string buf;
	while(getline(cin,buf) && buf[0]!='#')
	{
		string::iterator si=buf.begin();
		unsigned ans=0;		//±ÿ–Î”√unsigned
		while(si!=buf.end())
			ans=((ans<<8)+*si++)%g;
		ans=(ans<<16)%g;
		ans=ans==0?0:g-ans;
		printf("%02X %02X\n",ans>>8,ans-((ans>>8)<<8));
	}

return 0;
}
