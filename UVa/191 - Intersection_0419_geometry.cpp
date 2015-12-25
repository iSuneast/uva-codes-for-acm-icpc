/*
191 - Intersection

geometry...
*/

#include<iostream>
using namespace std;

int xstart,ystart,xend,yend;
int xleft,ytop,xright,ybottom;

int outerproduct(int x,int y)	//���,���Ϊ0��ʱ������ر��ж�..
{
	return xstart*yend+xend*y+x*ystart-xstart*y-xend*ystart-x*yend;
}

bool inside(int x,int y)	//�жϵ��Ƿ��ھ����ڲ�
{
	return between(xleft,xright,x) && between(ytop,ybottom,y);
}

bool between(int s,int e,int p)	//�ж��Ƿ���м�
{
	return (p>=s && p<=e) || (p>=e && p<=s);
}

bool shadow(int ps,int pe,int ts,int te)	//��x,yͶӰ�Ƿ��н���
{
	return between(ps,pe,ts) || between(ps,pe,te)
		|| between(ts,te,ps) || between(ts,te,pe);
}

bool calc()
{
	if(inside(xstart,ystart) || inside(xend,yend))
		return true;
	int flag=0,t;
	t=outerproduct(xleft,ytop);
	if(t!=0)	flag+=t>0?1:-1;
	t=outerproduct(xleft,ybottom);
	if(t!=0)	flag+=t>0?1:-1;
	t=outerproduct(xright,ytop);
	if(t!=0)	flag+=t>0?1:-1;
	t=outerproduct(xright,ybottom);
	if(t!=0)	flag+=t>0?1:-1;
	if(flag==4 || flag==-4)
		return false;
	return shadow(xleft,xright,xstart,xend)
		&& shadow(ystart,yend,ytop,ybottom);
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("191.txt","w",stdout);

	int dataset;
	cin>>dataset;
	while(dataset--)
	{
		cin>>xstart>>ystart>>xend>>yend
			>>xleft>>ytop>>xright>>ybottom;
		cout<<(calc()?'T':'F')<<endl;
	}

	return 0;
}
