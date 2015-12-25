/*
362 - 18,000 Seconds Remaining
*/

#include<iostream>
#include<cmath>

using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int cas=1,buf,sec,byte,t,done;
	while(cin>>byte && byte)
	{
		cout<<"Output for data set "<<cas++<<", "<<byte<<" bytes:"<<endl;
		buf=sec=done=0;
		do
		{
			cin>>t;
			buf+=t;
			sec++;
			if(sec && sec%5==0)
			{
				done+=buf;
				if(!buf)
					cout<<"   Time remaining: stalled"<<endl;
				else
					cout<<"   Time remaining: "<<(int)(ceil((byte-done)*5.0/buf))<<" seconds"<<endl;
				buf=0;
			}
		}while(buf+done<byte);
		cout<<"Total time: "<<sec<<" seconds"<<endl<<endl;
	}

return 0;
}
