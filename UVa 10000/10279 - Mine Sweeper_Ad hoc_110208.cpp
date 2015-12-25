/*
 * 10279 - Mine Sweeper
 *
 * Ad hoc...
 * a simple problem...
 *
 * happy coding~
 */

#include <cstring>
#include <cstdio>
#define MAXN 13
using namespace std;

char g[MAXN][MAXN], key[MAXN][MAXN];
int mine[MAXN][MAXN];

const int dx[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
const int dy[] = { 1, 0, -1, 1, -1, 1, 0, -1 };

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	int dataset, n;
	scanf("%d", &dataset);
	while (dataset--)
	{
		scanf("%d", &n);
		memset(g, 0, sizeof(g));
		memset(mine, 0, sizeof(mine));
		memset(key, 0, sizeof(key));

		for (int i = 1; i <= n; ++i)
		{
			scanf("%s", g[i] + 1);
			for (int j = 1; j <= n; ++j)
			{
				if (g[i][j] == '*')
				{
					for (int d = 0; d < 8; ++d)
					{
						int tx = i + dx[d];
						int ty = j + dy[d];
						++mine[tx][ty];
					}
				}
			}
		}

		bool fade = false;
		for (int i = 1; i <= n; ++i)
		{
			scanf("%s", key[i] + 1);
			for (int j = 1; j <= n; ++j)
			{
				if (key[i][j] == 'x')
				{
					key[i][j] = mine[i][j] + '0';
					if (g[i][j] == '*')
						fade = true;
				}
			}
		}

		if (fade)
		{
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
					if (g[i][j] == '*')
						key[i][j] = '*';
		}

		for (int i = 1; i <= n; ++i)
			puts(key[i] + 1);

		if (dataset)
			putchar(10);
	}

	return 0;
}
