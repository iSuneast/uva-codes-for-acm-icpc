/*
 * 245 - Uncompress
 *
 * simulation...
 * just code as the problem description~
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

struct LIST {
	string s;
	LIST *next, *pre;
}head;

set<string> setStr;

void insert(string s) {
	LIST *cur=new LIST, *h=&head;

	if(h->next) {
		cur->next=h->next;
		cur->next->pre=cur;
	}

	cur->pre=h;
	h->next=cur;

	cur->s=s;
}

void erase(LIST *cur) {
	if(cur->next)
		cur->next->pre=cur->pre;
	cur->pre->next=cur->next;

	LIST *h=&head;
	if(h->next) {
		cur->next=h->next;
		cur->next->pre=cur;
	}

	cur->pre=h;
	h->next=cur;
}

void output(int p) {
	LIST *cur=head.next;
	for(int i=1; i<p; ++i) {
		cur=cur->next;
	}
	cout<<cur->s;

	erase(cur);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    head.next=NULL;
    string str;
    while(getline(cin, str) && str!="0") {
    	int len=str.length();
    	for(int i=0; i<len; ) {
    		if(isalpha(str[i])) {
    			int p=i;
    			while(p<len && isalpha(str[p]))
    				++p;
    			string sub=str.substr(i, p-i);
    			i=p;

    			if(setStr.find(sub)==setStr.end()) {
    				setStr.insert(sub);
    				insert(sub);
    			}
    			cout<< sub;
    		} else if(isdigit(str[i])){
    			int p=i;
    			while(p<len && isdigit(str[p]))
    				++p;
    			output(atoi(str.substr(i, p-i).c_str()));
    			i=p;
    		} else {
    			putchar(str[i]);
    			++i;
    		}
    	}
    	putchar(10);
    }

    return 0;
}

