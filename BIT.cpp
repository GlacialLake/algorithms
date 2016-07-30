#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#define For(i,n) for(int i=0;i<(n);++i)
#define Rint(x) scanf("%d",&(x))
#define R2int(x,y) scanf("%d %d",&(x),&(y))
#define Pint(x) printf("%d",(x))
#define Pintln(x) printf("%d\n",(x))
const int MAXN = 10000;

//This array is indexed from 1 to length.
int tree[MAXN];
int length;
void add(int pos, int val){
    while(pos <= length){
	tree[pos] += val;
	pos += ((pos)&(-pos));
    }
}
int sum(int k){
    int ret = 0;
    while(k >= 1){
	ret += tree[k];
	k -= ((k)&(-k));
    }
    return ret;
}
void init(int* arr, int len){
    memset(tree, 0, sizeof tree);
    length = len;
    for(int i = 0; i < len; ++i)add(i + 1, arr[i]);
}
int main()
{
    int arr[100];
    int n;
    Rint(n);
    For(i,n)Rint(arr[i]);
    init(arr, n);
    int noper;
    Rint(noper);
    For(j,noper){
	int pos, val;
	R2int(pos,val);
	add(pos,val);
    }
    int nq;
    Rint(nq);
    For(k,nq){
	int a, b;
	R2int(a,b);
	Pintln(sum(b)-sum(a-1));
    }
    return 0;
}
