/*
489 - Hangman Judge

simulation
*/

#include<iostream>
#include<string>

using namespace std;

int main()
{
	int rnd,i,j,la,lk,r,w;
	string ans,key;
	int flag[128],tflag;

	while(cin>>rnd&&rnd!=-1)
	{
		memset(flag,0,sizeof(flag));
		r=w=0;
		cin>>key>>ans;
		la=ans.length();
		lk=key.length();
		for(i=0;i<la;i++)
		{
			tflag=0;
			if(r==lk||w==7)
				break;
			for(j=0;j<lk;j++)
			{
				if(flag[ans[i]])
					break;
				if(ans[i]==key[j])
					tflag=1,r++;
			}
			if(!tflag)
				w++;
			flag[ans[i]]=1;
		}
		if(w==7)
				printf("Round %d\nYou lose.\n",rnd);
		else if(r==lk)
				printf("Round %d\nYou win.\n",rnd);
		else
			printf("Round %d\nYou chickened out.\n",rnd);
	}

return 0;
}