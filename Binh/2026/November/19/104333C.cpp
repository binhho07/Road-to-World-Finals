// https://codeforces.com/gym/104333/problem/C

#include<bits/stdc++.h>
#define int long long 
#define ia array<int, 2>

using namespace std;
const int maxn = 2e5 + 5;
const ia mod = {2409235909, (int)1e9 + 9}, base = {631, 311};
int N;

ia operator - (ia a, ia b)
{
    ia c;
    for (int i = 0; i < 2; i++)
        c[i] = (a[i] - b[i] + mod[i]) % mod[i];
    return c;
}

ia operator + (ia a, ia b)
{
    ia c;
    for (int i = 0; i < 2; i++)
    {
        c[i] = (a[i] + b[i]);
        if (c[i] >= mod[i])
            c[i] -= mod[i];
    }
    return c;
}
 
ia operator * (ia a, ia b)
{
    ia c;
    for (int i = 0; i < 2; i++)
        c[i] = (a[i] * b[i]) % mod[i];
    return c;
}
 
inline ia makepair(char c)
{
    ia tmp = {c - 'a' + 1, c - 'a' + 1};
    return tmp;
} 

struct HASH{
    vector<ia> mu, h;
    ia get(int l, int r){
        return h[r] - h[l - 1] * mu[r - l + 1];
    }


    HASH(string s){
        mu.resize(s.size() + 1);
        h.resize(s.size() + 1);
        mu[0] = {1, 1};
        for (int i = 1; i <= s.size(); i++)
            mu[i] = mu[i - 1] * base;
        h[0] = {0, 0};
        for (int i = 1; i <= s.size(); i++)
            h[i] = h[i - 1] * base + makepair(s[i - 1]);
    }
};

struct SOLVE{
    int n, m, q;
    string s;

    vector<int> seg;

    void upd(int lx, int rx, int val, int id = 1, int l = 1, int r = N){
        if (lx > r || l > rx) return;
        if (lx <= l && r <= rx) return void(seg[id] = max(seg[id], val));
        int mid = (l + r) / 2;
        upd(lx, rx, val, id * 2, l, mid);
        upd(lx, rx, val, id * 2 + 1, mid + 1, r);
    }

    int get(int pos, int id = 1, int l = 1, int r = N){
        if (l == r) return seg[id];
        int mid = (l + r) / 2;
        if (pos <= mid) return max(seg[id], get(pos, id * 2, l, mid));
        return max(seg[id], get(pos, id * 2 + 1, mid + 1, r));
    }

    void solve(){
        cin >> n >> s;
        N = n;
        string rs = s;
        reverse(rs.begin(), rs.end());
        HASH S(s), RS(rs);
        seg.resize(4 * n + 1, 0);
        for (int i = 1; i <= n; i++){
            // odd
            {
                int l = 1, r = min(i, n - i + 1), ans = 1;
                while (l <= r){
                    int mid = (l + r) / 2;
                    if (S.get(i, i + mid - 1) == RS.get(n - i + 1, n - i + mid)){
                        ans = mid, l = mid + 1;
                    } else r = mid - 1;
                }
                upd(i - ans + 1, i + ans - 1, ans * 2 - 1);
            }
            // even
            {
                int l = 1, r = min(i, n - i), ans = 0;
                while (l <= r){
                    int mid = (l + r) / 2;
                    if (S.get(i + 1, i + mid) == RS.get(n - i + 1, n - i + mid)){
                        ans = mid, l = mid + 1;
                    } else r = mid - 1;
                }
                upd(i - ans + 1, i + ans, ans * 2);
            }
        }
        for (int i = 1; i <= n; i++)
            cout << get(i) << " ";
        cout << "\n";
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.inp", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--){
        SOLVE x;
        x.solve();
    }
}
