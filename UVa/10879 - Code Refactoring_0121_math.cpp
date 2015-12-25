/*
10879 - Code Refactoring
*/

#include<stdio.h>
#include<math.h>

int main()
{
	int n,k,cas=1,flag,i,a,b,t,tmp;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&k);
		printf("Case #%d: %d",cas,k);
		cas++;
		flag=2;
		tmp=(int)sqrt(k)+1;
		for(i=2;i<tmp;i++)
			if(!(k%i)&&((t=k/i)!=i))
			{
				if(flag==2)
					a=i,b=t,printf(" = %d * %d",a,b),flag--;
				else if(flag==1)
				{
					if((b!=i)&&(a!=i)&&(b!=t)&&(a!=t))
						printf(" = %d * %d",i,t),flag--;
				}
				else
					break;
			}
			if(n)
			putchar('\n');
	}

return 0;
}
