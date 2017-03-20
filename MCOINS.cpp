#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
//#include <unordered_map>
#include <utility>
#include <cassert>
#include <iomanip>
#include <ctime>
#include <fstream>

using namespace std;

const int me = 1000025;

static int uget()
{
    int c;
    while(c = getchar(), isspace(c)) {}
    int n = c - '0';
    while(c = getchar(), isdigit(c)) { n = n * 10 + (c - '0'); }
    return n;
}
template<class T> static void uput(T n)
{
    char s[30];
    int x = 0;
    do { s[x ++]=(n % 10) + '0'; n /= 10; } while(n);
    for(int i = x - 1; i >= 0; i --) putchar(s[i]);
    putchar('\n');
}

int k, l, m, x;
int dp[me];

int get(int x){
    if(dp[x] != -1)
        return dp[x];
    int &res = dp[x];
    if(x == 0)
        return res = 2;
    if(x == 1 || x == k || x == l)
        return res = 1;
    if(get(x - 1) == 2 || (x >= k && get(x - k) == 2) || (x >= l && get(x - l) == 2))
        return res = 1;
    return res = 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   
    cin >> k >> l >> m;
    fill(dp, dp + me, -1);
    while(m --){
        cin >> x;
        if(get(x) == 1)
            cout << 'A';
        else cout << 'B';
    }
    cout << endl;
    
    return 0;
}