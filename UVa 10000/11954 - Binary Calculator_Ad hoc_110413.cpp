/*
 * 11954 - Binary Calculator
 *
 * Ad hoc...
 * calculate the answer of an expression
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

vector<string> vs;

bool isUnary(char c) {
	return c=='n' || c=='s';
}

string format(string str) {
	int l=str.length(), p=0;
	while(p<l && str[p]=='0')
		++p;
	if(p==l)
		return "0";
	return str.substr(p, l-p);
}

string unary(string op, string cur) {
	cur=format(cur);
	if(op[0]=='n') {
		for(int i=cur.length()-1; i>=0; --i ) {
			cur[i]=1-(cur[i]-'0')+'0';
		}
		return cur;
	} else if(op[2]=='r') {
		if(cur.length()==1) {
			return "0";
		} else {
			return cur.substr(0, cur.length()-1);
		}
	} else {
		return cur+"0";
	}
}

string expand(string str, int len) {
	string key="";
	for(int i=len-str.length(); i>0; --i) {
		key+="0";
	}
	return key + str;
}

string process() {
	string key=vs[0];
	for(int i=1; i<vs.size(); i+=2) {
		int len=max(key.length(), vs[i+1].length());
		key=expand(key, len);
		vs[i+1]=expand(vs[i+1], len);

		if(vs[i][0]=='a') {
			for(int j=0; j<len; ++j) {
				if(vs[i+1][j]==key[j] && key[j]=='1') {
					key[j]='1';
				} else
					key[j]='0';
			}
		} else if(vs[i][0]=='x') {
			for(int j=0; j<len; ++j) {
				if(vs[i+1][j]!=key[j]) {
					key[j]='1';
				} else
					key[j]='0';
			}
		} else {
			for(int j=0; j<len; ++j) {
				if(vs[i+1][j]=='1' || key[j]=='1') {
					key[j]='1';
				} else
					key[j]='0';
			}
		}

		key=format(key);
	}

	return key;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    int dataset;
    char buf[1003];
    scanf("%d", &dataset);	gets(buf);
    for(int cas=1; cas<=dataset; ++cas) {
    	gets(buf);
    	vs.clear();

    	for(char *token=strtok(buf," "); token; token=strtok(NULL," ")) {
    		if( isUnary(token[0]) ) {
    			vs.push_back((string)token);
    		} else if(token[0]=='1' || token[0]=='0') {
    			string cur=token;

    			while(!vs.empty()) {
    				string top=*vs.rbegin();
    				if(!isUnary(top[0]))
    					break;
					vs.pop_back();
					cur=unary(top, cur);
    			}

    			vs.push_back(format(cur));

    		} else {
    			vs.push_back((string)token);
    		}
    	}

    	process();
    	cout<<"Case "<< cas <<": "<<process()<<endl;
    }

    return 0;
}

