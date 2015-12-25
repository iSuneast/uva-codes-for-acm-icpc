/*
 * 941 - Permutations
 *
 * Ad hoc...
 * 其实是一道水题的。。。
 * 以前竟然不敢做。。。
 * stO，，，
 *
 * 就是求len个字符串的第n+1个排列
 * 直接枚举即可～
 *
 * happy coding～
 */

#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 21
using namespace std;
typedef long long LL;

char str[MAXN], key[MAXN];
LL n;
int len, alpha[26];

LL c(int a,int b) {
	LL key=1;
	for(int i=a-b+1; i<=a; ++i) {
		key*=i;
	}

	for(int i=2; i<=b; ++i) {
		key/=i;
	}

	return key;
}

LL permutation(int tot) {
	LL key=1;
	for(int i=0; i<26; ++i) {
		if(alpha[i]) {
			key*=c(tot, alpha[i]);
			tot-=alpha[i];
		}
	}

	return key;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int dataset;
    scanf("%d", &dataset);
    while(dataset--) {
    	scanf("%s%lld", str, &n);

    	++n;
    	len=strlen(str);

    	sort(str, str+len);
    	for(int i=0; i<len; ++i) {
    		LL pre=0, add;
    		for(int j=0; j<len; ++j) {
    			if(!str[j])
    				continue;

    			memset(alpha, 0, sizeof(alpha));
    			for(int k=0; k<len; ++k) {
    				if(str[k] && k!=j) {
    					++alpha[ str[k]-'a' ];
    				}
    			}

    			key[i] = str[j];
    			add = permutation(len-1-i);

    			if(pre + add>=n) {
    				n-=pre;
    				str[j]=0;
    				break;
    			}

    			pre+=add;
    		}
    	}

    	key[len]=0;
    	puts(key);
    }

    return 0;
}

