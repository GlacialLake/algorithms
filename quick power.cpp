#include<iostream>
using namespace std;
int pw(int a,int n)
{
    int ret = 1;
    for(; n; n >>= 1){
        if(n & 1)ret *= a;
        a *= a;
    }
    return ret;
}
int main()
{
    int a, n;
    cin >> a >> n;
    cout << pw(a, n) << endl;
    return 0;
}