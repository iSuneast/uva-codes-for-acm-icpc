/*
 * 11519 - Logo 2
 *
 * geometry...
 * 题目说：“The distances and angles in all commands are always non-negative integers”
 * 但是，实际上数据里面是可以为负数的。。。
 *
 * 对于角度，只需要枚举[0, 360)然后判断最后是不是在(0, 0)就可以了~
 *
 * 如果是移动距离的话，跳过这条语句直接往下模拟，最后停在(x, y)，则移动距离为sqrt(x^2 + y^2)
 * 因为答案可能是负数，所以还要把答案代回去看看最后是不是在(0, 0)，不是的话，答案就是负数了~
 *
 * happy coding~
 */

#include<iostream>
#include<cmath>
#define MAXN 1003
using namespace std;
const double eps=1e-6;

struct CMD {
	char op;
	int d;
};

struct POINT {
	double x,y;
	int d;
	POINT(){}
	POINT(double _x,double _y,int _d):x(_x),y(_y),d(_d){}
};
const double pi=acos(-1.0);

double arc(int d) {
	return d*2*pi/360.0;
}

void run(POINT &s, CMD &cmd) {
	if(cmd.op=='l')
		s.d = (s.d+cmd.d)%360;
	else if(cmd.op=='r')
		s.d = (s.d-cmd.d+360)%360;
	else if(cmd.op=='b') {
		s.x -= cmd.d*cos( arc(s.d) );
		s.y -= cmd.d*sin( arc(s.d) );
	} else {
		s.x += cmd.d*cos( arc(s.d) );
		s.y += cmd.d*sin( arc(s.d) );
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset, n;
	char op[3],buf[10];
	CMD cmd[MAXN];

	scanf("%d", &dataset);
	while( dataset-- ) {
		scanf("%d", &n);

		int bgn=-1;
		bool unknown=false, justDoIt=false;
		POINT s=POINT(0,0,0), stop;
		for(int i=0; i<n; ++i) {
			scanf("%s %s", op, buf);
			cmd[i].op = op[0];
			if(buf[0]=='?') {
				unknown=true;
				if( cmd[i].op=='f' || cmd[i].op=='b')
					justDoIt=true;
				stop=s;
				bgn=i;
			} else {
				cmd[i].d=atol(buf);
				if(!unknown || justDoIt)
					run(s, cmd[i]);
			}
		}

		int key;
		if(justDoIt) {
			key = floor( sqrt( pow(s.x, 2.0) + pow(s.y, 2.0) ) +eps );
			cmd[bgn].d=key;
			for(int i=bgn ; i<n; ++i) {
				run(stop, cmd[i]);
			}

			if( !(abs(stop.x)<eps && abs(stop.y)<eps) )
				key=-key;
		} else {
			for(key=0; key<360; ++key) {
				POINT cur = stop;
				cmd[bgn].d = key;
				for(int i=bgn ; i<n; ++i) {
					run(cur, cmd[i]);
				}

				if(abs(cur.x)<eps && abs(cur.y)<eps)
					break;
			}
		}

		printf("%d\n", key);
	}

	return 0;
}
