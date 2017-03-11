#include<iostream>
#include<algorithm>

template<class T> void qs(T *l, T *r)
{
	if (r - l <= 1)
		return;
	T *pivot = l, *iter = l;
	while (++iter < r)
		if (*iter < *l)
			std::swap(*++pivot, *iter);
	std::swap(*l, *pivot);
	qs(l, pivot);
	qs(pivot + 1, r);
}

int seq[1001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cin >> seq[i];
	qs(seq, seq + n);
	for (int i = 0; i < n; ++i)
		std::cout << seq[i] << ' ';
	std::cout << '\n';
	return 0;
}
