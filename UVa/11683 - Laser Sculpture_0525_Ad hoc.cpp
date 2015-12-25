/*
11683 - Laser Sculpture

Ad hoc...
直接暴力果然超时啊...
首先感叹一下日本人的聪明头脑吧...(或者是我太笨了?)

感觉说规律其实还是很明显的...
每次都看一下下降多少
累加起来就是解了
        #
      ###
  #  ####
 ### ####
#### ####
*/

#include<iostream>
#define MAXN 10010
using namespace std;

int block[MAXN],height,lengh;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	while(scanf("%d%d",&height,&lengh)!=EOF && height)
	{
		for(int i=1;i<=lengh;++i)
			scanf("%d",block+i);
		int key=0;
		for(int i=1;i<=lengh;++i)
		{
			if(block[i]<height)
				key+=height-block[i];
			height=block[i];
		}
		printf("%d\n",key);
	}

	return 0;
}
