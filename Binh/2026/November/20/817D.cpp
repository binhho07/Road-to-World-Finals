// https://codeforces.com/problemset/problem/817/D

#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int maxn = 3e5 + 5, inf = 1e9 + 7;

struct SOLVE{
    int n, m, q, ans = 0;

    void solve(){
        cin >> n;
        vector<int> a(n + 2), l(n + 2);
        for (int i = 1; i <= n; i++) cin >> a[i];
        a[0] = a[n + 1] = inf;
        stack<int> st;
        st.emplace(0);
        for (int i = 1; i <= n; i++){
            while (st.size() && a[st.top()] < a[i])
                st.pop();
            l[i] = st.top() + 1;
            st.emplace(i);
        }
        while (st.size()) st.pop();
        st.emplace(n + 1);
        for (int i = n; i >= 1; i--){
            while (st.size() && a[st.top()] <= a[i])
                st.pop();
            ans += (st.top() - i) * (i - l[i] + 1) * a[i];
            st.emplace(i);
        }
        a[0] = a[n + 1] = 0;
        while (st.size()) st.pop();
        st.emplace(0);
        for (int i = 1; i <= n; i++){
            while (st.size() && a[st.top()] > a[i])
                st.pop();
            l[i] = st.top() + 1;
            st.emplace(i);
        }
        while (st.size()) st.pop();
        st.emplace(n + 1);
        for (int i = n; i >= 1; i--){
            while (st.size() && a[st.top()] >= a[i])
                st.pop();
            ans -= (st.top() - i) * (i - l[i] + 1) * a[i];
            st.emplace(i);
        }
        cout << ans;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.inp", "r", stdin);
    int t = 1;
    //cin >> t;
    while (t--){
        SOLVE x;
        x.solve();
    }
}
