/*
 * 11576 - Scrolling Sign
 *
 * Ad hoc...
 * greedy...
 * ˮ�⡣
 * ÿ��ֻҪ�Ƚ����������ַ����Ϳ�����
 * ������ĺϲ����������ڶ��������ܺϲ��ĳ��ȼӵ���������
 *
 * happy coding~
 */

#include<iostream>
#define MAXN 103
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
#endif

	int dataset, h , w;
	char s[MAXN],buf[MAXN];
	scanf("%d", &dataset);
	while(dataset--) {
		scanf("%d%d", &w, &h);
		s[0]=0;
		int key=0, l=0;

		while(h--) {
			scanf("%s", buf);
			bool got=false;
			for(int i=0; i<l; ++i) {
				bool fade=false;
				for(int k=0; i+k<l; ++k) {
					if(s[i+k]!=buf[k]) {
						fade=true;
						break;
					}
				}
				if(!fade) {
					got=true;
					key+=i;
					break;
				}
			}

			if(!got) {
				key+=w;
			}

			strcpy(s,buf);
			l=w;
		}

		printf("%d\n", key);
	}

	return 0;
}
