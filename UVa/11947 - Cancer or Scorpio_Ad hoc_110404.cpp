/*
 * 11947 - Cancer or Scorpio
 *
 * Ad hoc...
 * the child will born in 40 weeks = 40*7 days
 * so just calculate what date is it after 280 days
 *
 * then just hard coding of the "Sign" part the child belong to
 * notice that
 * "the name (in lowercase) of zodiac sign that correspond according to the date of birth."
 * the Sign should be output in lower case
 *
 * happy coding~
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#define MAXN
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;
typedef long long LL;
typedef pair<int, int> pii;
template<class T>void ChkMin(T &a, const T &b) {if(a>b)    a=b;}
template<class T>void ChkMax(T &a, const T &b) {if(a<b)    a=b;}

int days[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int leap(int y) {
	return ((y%4==0 && y%100!=0) || y%400==0)? 29:28;
}

string process(int m, int d) {
	if((m==1 && d>=21) || (m==2 && d<=19))
		return "aquarius";

	if((m==2 && d>=20) || (m==3 && d<=20))
		return "pisces";

	if((m==3 && d>=21) || (m==4 && d<=20))
		return "aries";

	if((m==4 && d>=21) || (m==5 && d<=21))
		return "taurus";

	if((m==5 && d>=22) || (m==6 && d<=21))
		return "gemini";

	if((m==6 && d>=22) || (m==7 && d<=22))
		return "cancer";

	if((m==7 && d>=23) || (m==8 && d<=21))
		return "leo";

	if((m==8 && d>=22) || (m==9 && d<=23))
		return "virgo";

	if((m==9 && d>=24) || (m==10 && d<=23))
		return "libra";

	if((m==10 && d>=24) || (m==11 && d<=22))
		return "scorpio";

	if((m==11 && d>=23) || (m==12 && d<=22))
		return "sagittarius";

	return "capricorn";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int dataset, date;
    scanf("%d", &dataset);
    for(int cas=1; cas<=dataset; ++cas) {
    	scanf("%d", &date);
    	int m=date/1000000;
    	int d=date/10000%100;
    	int y=date%10000;
    	int k=280;
    	days[2]=leap(y);

    	while(k--) {
    		++d;
    		if(d>days[m]) {
    			d=1;

    			++m;
    			if(m>12) {
    				m=1;

    				++y;
    				days[2]=leap(y);
    			}
    		}
    	}

    	printf("%d %02d/%02d/%04d ", cas, m, d, y);
    	cout<<process(m, d)<<endl;
    }

    return 0;
}

