/*
10620 - A Flea on a Chessboard

simulation...
ֱ������Ŀ��˼ģ��...
��ϸ�۲���Է���,��Ч��״̬��ʵ������[0-2s,0-2s]����
��x,y��2sȡģ��,��set����...
�������ֵ�ظ�����,���޽�
�ǽ���������������[0-s,s-2s],[s-2s,0-s].
����ע��,���ж���ת��...
�����Ͳ�Ҫ���⿼����0���˳��������
*/

#include<iostream>
#include<set>
using namespace std;

set<int> si;

int hash(int x,int y)
{
	return x*10000+y;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif

	int s,x,y,dx,dy,h,mod;
	while(scanf("%d%d%d%d%d",&s,&x,&y,&dx,&dy)!=EOF && (s||x||y||dx||dy))
	{
		mod=2*s;
		si.clear();
		int jump=0;
		while(true)
		{
			if(si.find( h=hash(x%mod,y%mod) )==si.end())
			{
				int tx=x%mod,ty=y%mod;
				if((0<tx && tx<s && s<ty && ty<mod) || (s<tx && tx<mod && 0<ty && ty<s))
					break;
				si.insert(h);
			}
			else
			{
				jump=-1;
				break;
			}
			x+=dx,y+=dy;
			++jump;
		}

		if(jump==-1)
			puts("The flea cannot escape from black squares.");
		else
			printf("After %d jumps the flea lands at (%d, %d).\n",jump,x,y);
	}

	return 0;
}
