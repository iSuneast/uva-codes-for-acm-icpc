/*
 * 10056 - What is the Probability ?
 *
 * math...
 *
 * n p I
 * when 1->I-1 lose, I win, we got probability = (1-p)^(I-1) * p
 * if no winner in a single round, we'll continuous loop
 *      1->I-1 lose again, I win, we got (1-p)^(I-1+n) * p
 * the same thing happen again and again
 * finally, after INF round, we win
 * and we find the format is  (1-p)^(I-1+INF*n) * p
 * we add all of this
 *    (1-p)^(I-1) * p + (1-p)^(I-1+n) * p + ... + (1-p)^(I-1+INF*n) * p
 *
 * set ai = (1-p)^(I-1) * p
 * set k  = (1-p)^n
 * we got ai + ai*k + ai*k^2 + ai*k^3 + ...
 *       = ai * (1-k^INF) / (1-k)
 * k < 1, so k^INF = 0
 * the format become = ai / (1-k)
 * this is the probability we win
 *
 * but, what about others?
 * p1 = a1 / (1-k)
 * p2 = a2 / (1-k)
 * ...
 * the total enent probability is
 *    p1 + p2 + .. + pn
 *  = (a1 + a2 + ... + an) / (1-k)
 *  = ( (1-p)^(1-1)*p + (1-p)^(2-1)*p + ... + (1-p)^(n-1)*p ) / (1-k)
 *  = ( 1 - (1-p)^n ) / (1-k)
 *  = ( 1-k ) / (1-k)
 *  = 1
 *
 * so, of cause the final answer is
 * ai / (1-k) = (1-p)^(I-1) * p / ( 1 - (1-p)^n )
 *
 * a simple trick: when p=0, the answer should be 0.0000
 *
 * happy coding~
 */

#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <vector>
#include <ctime>
#define MAXN
using namespace std;
const int INF=0x3f3f3f3f;
const double eps=1e-9;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int dataset;
    scanf("%d", &dataset);

    int n, I;
    double p;
    while(dataset--)
    {
    	scanf("%d %lf %d", &n, &p, &I);

    	if(p<eps) {
    		puts("0.0000");
    		continue;
    	}

    	double ap=1-p;
    	double key=p;
    	for(int i=1; i<I; ++i) {
    		key*=ap;
    	}

    	double tot=1.0;
    	for(int i=1; i<=n; ++i) {
    		tot*=ap;
    	}
    	tot=1-tot;

    	printf("%.4lf\n", key/tot);
    }

    return 0;
}

