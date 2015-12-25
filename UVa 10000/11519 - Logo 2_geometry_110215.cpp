/*
 * 11519 - Logo 2
 *
 * geometry...
 * ��Ŀ˵����The distances and angles in all commands are always non-negative integers��
 * ���ǣ�ʵ�������������ǿ���Ϊ�����ġ�����
 *
 * ���ڽǶȣ�ֻ��Ҫö��[0, 360)Ȼ���ж�����ǲ�����(0, 0)�Ϳ�����~
 *
 * ������ƶ�����Ļ��������������ֱ������ģ�⣬���ͣ��(x, y)�����ƶ�����Ϊsqrt(x^2 + y^2)
 * ��Ϊ�𰸿����Ǹ��������Ի�Ҫ�Ѵ𰸴���ȥ��������ǲ�����(0, 0)�����ǵĻ����𰸾��Ǹ�����~
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
