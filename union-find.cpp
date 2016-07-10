#include<cstdio>
const int MAXN = 1000;
int pre[MAXN];
void init(int n)
{
    for(int i = 0; i < n; ++i){
	pre[i] = i;
    }
}
int find(int x)
{
    int r = x;
    while(pre[r] != r)
	r = pre[r];
    int i = x, j;
    while(pre[i] != r){
	j = pre[i];
	pre[i] = r;
	i = j;
    }
    return r;
}
void join(int a, int b)
{
    pre[find(a)] = find(b);
}
int main()
{
    int n;
    scanf("%d", &n);
    init(n);
    int a, b;
    while(scanf("%d %d", &a, &b)){
	if(a == n)
	    break;
	join(a, b);
    }
    while(scanf("%d %d", &a, &b)){
	if(a == n)
	    break;
	if(find(a) == find(b)){
	    printf("Yes\n");
	}else{
	    printf("No\n");
	}
    }
    return 0;
}
