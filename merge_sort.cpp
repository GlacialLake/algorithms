#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
void merge_sort(int* A, int l, int r, int* R)
{
    if(r <= l + 1)return;
    int mid = r + ((l - r) >> 1);
    merge_sort(A, l, mid, R);
    merge_sort(A, mid, r, R);
    int p = l, q = mid, rp = l;
    while(p < mid || q < r)
	if(q == r || (p < mid && A[p] <= A[q]))R[rp++] = A[p++];
	else R[rp++] = A[q++];
    for(int i = l; i < r; ++i)A[i] = R[i];
}
int main()
{
    int a[1000], r[1000];
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)scanf("%d", &a[i]);
    merge_sort(a, 0, N, r);
    for(int j = 0; j < N; ++j)printf("%d\n", a[j]);
    return 0;
}

