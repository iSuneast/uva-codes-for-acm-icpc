/*
608 - Counterfeit Dollar

enum...
因为题目描述说.必存在解...
直接枚举即可...
*/

#include<stdio.h>
#include<string.h>

char left[3][7],right[3][7],res[3][5];

bool heavy(char x )
{
    int i;
    for(i=0;i<3;i++)
        switch(res[i][0])
        {
        case 'u':if(strchr(left[i],x)==NULL)return false;break;
        case 'e':if(strchr(left[i],x)!=NULL||strchr(right[i],x)!=NULL)return false;break;
        case 'd':if(strchr(right[i],x)==NULL)return false;break;
        }
    return true;
}

bool light(char x )
{
    int i;
    for(i=0;i<3;i++)
        switch(res[i][0])
        {
        case 'u':if(strchr(right[i],x)==NULL)return false;break;
        case 'e':if(strchr(left[i],x)!=NULL||strchr(right[i],x)!=NULL)return false;break;
        case 'd':if(strchr(left[i],x)==NULL)return false;break;
        }
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	
	int n;
	scanf("%d",&n);
	while(n--)
	{
		for(int i=0;i<3;i++)
			scanf("%s%s%s",left[i],right[i],res[i]);
		for(char c='A';c<='L';c++)
			if(light(c))
				printf("%c is the counterfeit coin and it is light.\n",c);
			else if(heavy(c))
				printf("%c is the counterfeit coin and it is heavy.\n",c);
	}

return 0;
}