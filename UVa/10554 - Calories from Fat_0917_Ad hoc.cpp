/*
10554 - Calories from Fat

Ad hoc...
sum percent and calories (transform 'g' into C)
then we'll easy got the total Calories from one record,
	and also the fat calories
output fat/total...
*/

#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	string buf;
	const int Calories[]={9,4,4,4,7};
	double record,percent,var,fat,tot;
	char c;

	while(getline(cin,buf) && buf!="-")
	{
		fat=0,tot=0;
		do
		{
			stringstream sin(buf);
			percent=100;
			record=0;
			bool done=false;
			double rem;
			for(int i=0;i<5;++i)
			{
				sin>>var>>c;
				if(c=='%')
					percent-=var;
				else if(c=='g')
					record+=var*Calories[i];
				else
					record+=var;

				if(!i)
				{
					if(c=='%')
						rem=var;
					else
					{
						fat+=record;
						done=true;
					}
				}
			}

			if(!done)
				fat+=rem*record/percent;
			tot+=record*100/percent;

		}while(getline(cin,buf) && buf!="-");

		printf("%.0lf%%\n",fat*100/tot);
	}

	return 0;
}
