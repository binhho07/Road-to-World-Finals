#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int maxn = 3e5 + 5;

struct SOLVE{
    int n, m, t, c, ans = 0;

    bool eval(const string& e, int& val){
        val = 0;
        int sign = 1, i = 0, m = e.size();
        while (true){
            int j = i;
            while (j < m && isdigit(e[j])) j++;
            int len = j - i;
            if (len == 0 || len > 10) return false;        
            if (len > 1 && e[i] == '0') return false;      
            val += sign * stoll(e.substr(i, len));
            if (j == m) return true;               
            sign = (e[j] == '+' ? 1 : -1);
            i = j + 1;                                        
        }
    }

    bool good(string& t){
        int eq = -1;
        for (int i = 0; i < t.size(); i++){
            if (t[i] == '='){
                if (eq == -1)
                    eq = i;
                else return false;
            }
        }
        int L, R;
        if (!eval(t.substr(0, eq), L) || !eval(t.substr(eq + 1), R)) return false;
        return L == R;
    }

    void solve(){
        string s;
        cin >> s;
        if (good(s)) return cout << "Correct", void();
        int n = s.size();
        for (int i = 0; i < n; i++){
            if (!isdigit(s[i])) continue;
            string t = s.substr(0, i) + s.substr(i + 1);      
            for (int j = 0; j <= (int)t.size(); j++){
                string u = t.substr(0, j) + s[i] + t.substr(j);
                if (good(u)) return cout << u, void();
            }
        }
        cout << "Impossible";
    }};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef LOCAL
        freopen("test.inp", "r", stdin);
        // freopen("test.out", "w", stdout);
    #endif    
    int t = 1;
    // cin >> t;
    while (t--){
        SOLVE x;
        x.solve();
    }
}
