#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const int MAXN = 1000;
const int INF = 0x3f3f3f3f;

struct edge{
    int from, to, dist;
    edge(int f, int t, int d):from(f),to(t),dist(d){}
};
struct heapnode{
    int d, u;
    bool operator < (const heapnode& hn) const {
	return d > hn.d;
    }
};
struct dijkstra{
    int n, m;
    vector<edge> e;
    vector<int> v[MAXN];
    bool vis[MAXN];
    int d[MAXN];
    int fa[MAXN];
    void init(int _n){
	n = _n;
	m = 0;
	e.clear();
	for(int i = 0; i < n; ++i)v[i].clear();
    }
    void adde(int from, int to, int dist){
	e.push_back(edge(from, to, dist));
	//++m;
	v[from].push_back(m++);
    }
    void dijk(int src, int dest = -1){
	priority_queue<heapnode> pq;
	for(int i = 0; i < n; ++i)d[i] = INF; d[src] = 0;
	memset(vis, 0, sizeof vis);
	pq.push((heapnode){0, src});
	heapnode x;
	int u;
	//int i = 0;
	while(!pq.empty()){
	    //printf("#\n");
	    //++i;
	    //printf("%d", ++i);
	    x = pq.top(); pq.pop();
	    if(vis[u = x.u])continue; vis[u] = 1;
#define SPECIAL
#ifdef SPECIAL
	    //printf("%d\n", u);
	    //printf("%d\n", dest);
	    if(u == dest)break;
#endif
#undef SPECIAL
	    int sz = v[u].size();
	    //printf("%d\n", sz);
	    for(int i = 0; i < sz; ++i){
		edge& cur_e = e[v[u][i]];
		//printf("%d %d\n", d[cur_e.to], d[u] + cur_e.dist);
		//printf("%d\n", cur_e.to);
		if(d[cur_e.to] > d[u] + cur_e.dist){
		    d[cur_e.to] = d[u] + cur_e.dist;
		    fa[cur_e.to] = u;
		    pq.push((heapnode){d[cur_e.to], cur_e.to});
		    //printf("%d %d\n", d[cur_e.to], cur_e.to);
		}
	    }
	}
    }
};

int chain[MAXN];
int p = 0;

int main()
{
    dijkstra D;
    int n;
    scanf("%d", &n);
    D.init(n);
    int m;
    scanf("%d", &m);
    int f, t, d;
    for(int i = 0; i < m; ++i){
	scanf("%d %d %d", &f, &t, &d);
	D.adde(f, t, d);
    }
    int F, T;
    scanf("%d %d", &F, &T);
    D.dijk(F, T);
    //printf("#\n");
    int x = T;
    //printf("%d %d\n",F,T);
    while(x != F){
	//printf("%d\n",x);
	//printf("#\n");
	chain[p++] = x;
	x = D.fa[x];
    }
    chain[p++] = F;
    printf("%d", F);
    for(int i = p - 2; i >= 0; --i){
	printf(" -> %d", chain[i]);
    }
    printf("\n");
    return 0;
}
