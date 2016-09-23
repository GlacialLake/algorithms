#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN = 1000;
vector<int> G[MAXN];
int n;
int vis[MAXN];
int topo[MAXN], top;
bool dfs(int u)
{
    vis[u] = -1;
    int sz = G[u].size();
    vector<int>& curv = G[u];
    for (int i = 0; i < sz; ++i) {
        if (vis[curv[i]] < 0) return false;
        else if (!vis[curv[i]] && !dfs(curv[i])) return false;
    }
    vis[u] = 1;
    topo[--top] = u;
    return true;
}
bool toposort()
{
    top = n;
    memset(vis, 0, sizeof vis);
    for (int u = 0; u < n; ++u) if (!vis[u])
        if (!dfs(u)) return false;
    return true;
}
int main()
{
    scanf("%d", &n);
    int m;
    scanf("%d", &m);
    int a, b;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
    }
    toposort();
    for (int i = 0; i < n - 1; ++i) {
        printf("%d ", topo[i]);
    }
    printf("%d\n", topo[n - 1]);
    return 0;
}
