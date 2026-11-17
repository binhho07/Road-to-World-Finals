#include <bits/stdc++.h>
#define int long long

using namespace std;
const int maxn = 2e5 + 5;
int n, q, sum;

struct Tree {
    int mx[4 * maxn], lz[4 * maxn], ra[4 * maxn];

    void build(const vector<int>& a) {
        build(1, 1, n, a);
    }

    void merge(int id, int l, int r) {
        int mid = (l + r) / 2;
        mx[id] = max(mx[id * 2], mx[id * 2 + 1]);
        ra[id] = calc(id * 2 + 1, mid + 1, r, mx[id * 2]);
    }

    void build(int id, int l, int r, const vector<int>& a) {
        if (l == r) 
            return mx[id] = a[l - 1], void();
        int mid = (l + r) / 2;
        build(id * 2, l, mid, a); 
        build(id * 2 + 1, mid + 1, r, a); 
        merge(id, l, r);
    }

    void apply(int id, int l, int r, int val) {
        mx[id] += val; 
        lz[id] += val;
        if (l < r) 
            ra[id] += val * (r - (l + r) / 2);
    }

    void down(int id, int l, int r) {
        if (!lz[id]) return;
        int mid = (l + r) / 2; 
        apply(id * 2, l, mid, lz[id]); 
        apply(id * 2 + 1, mid + 1, r, lz[id]); 
        lz[id] = 0; 
    }

    int calc(int id, int l, int r, int v) {
        if (l == r) return max(v, mx[id]);
        down(id, l, r);
        int mid = (l + r) / 2;
        if (v >= mx[id * 2]) 
            return v * (mid - l + 1) + calc(id * 2 + 1, mid + 1, r, v);
        return calc(id * 2, l, mid, v) + ra[id];
    }

    
    void upd(int id, int l, int r, int lx, int rx) {
        if (lx > r || l > rx) return;
        if (lx <= l && r <= rx) 
            return apply(id, l, r, 1);
        down(id, l, r);
        int mid = (l + r) / 2;
        upd(id * 2, l, mid, lx, rx);
        upd(id * 2 + 1, mid + 1, r, lx, rx); 
        merge(id, l, r);
    }

    int qry(int id, int l, int r, int lx, int rx, int& MX) {
        if (lx > r || l > rx) return 0;
        if (lx <= l && r <= rx) { 
            int s = calc(id, l, r, MX); 
            MX = max(MX, mx[id]); 
            return s; 
        }
        down(id, l, r);
        int mid = (l + r) / 2;
        int s = qry(id * 2, l, mid, lx, rx, MX);
        return s + qry(id * 2 + 1, mid + 1, r, lx, rx, MX);
    }

    int getMax(int id = 1, int l = 1, int r = n) {
        if (l == r) return l;
        down(id, l, r); 
        int mid = (l + r) / 2;
        if (mx[id * 2] == mx[id]) 
            return getMax(id * 2, l, mid);
        return getMax(id * 2 + 1, mid + 1, r);
    }
} L, R;

int getAns(){
    int p = L.getMax();
    int v = 0, s = L.qry(1, 1, n, 1, p, v);
    v = 0;
    if (p + 1 <= n) s += R.qry(1, 1, n, 1, n - p, v);
    return s - sum;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.inp", "r", stdin);
    cin >> n >> q;
    vector<int> a(n); 
    for (auto& x : a) cin >> x, sum += x; 
    vector<int> b(a.rbegin(), a.rend());
    L.build(a);
    R.build(b); 

    cout << getAns() << "\n";
    while (q--) {
        int l, r; cin >> l >> r;
        L.upd(1, 1, n, l, r);
        R.upd(1, 1, n, n - r + 1, n - l + 1);
        sum += r - l + 1;
        cout << getAns() << "\n";
    }
}

