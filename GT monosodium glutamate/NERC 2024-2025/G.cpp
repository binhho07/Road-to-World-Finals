#include <iostream>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <algorithm>
#include <random>
#include <complex>
#include <bitset>
#include <queue>
#include <unordered_set>
#include <chrono>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

using ll = long long;

#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ff first
#define ss second
#define ordered_set tree < int ,  null_type ,  less<int>,  rb_tree_tag ,  tree_order_statistics_node_update >
// #define double long double
#define endl "\n"

const ll INF = 1e18;

const int MOD = 1000'000'000 + 7;

struct Coord {
    int x, y;

    Coord(int _x, int _y): x(_x), y(_y) {
    }

    bool operator <(const Coord &other) const {
        int left = x - other.x;
        int right = other.y - y;
        if (left < 0) {
            if (right >= 0) {
                return true;
            }
            return __int128(2) * __int128(left) * __int128(left) > __int128(right) * __int128(right);
        } else {
            if (right < 0) {
                return false;
            }
            return __int128(2) * __int128(left) * __int128(left) < __int128(right) * __int128(right);
        }
    }

    bool operator ==(const Coord &other) const {
        return x == other.x && y == other.y;
    }

    Coord operator +(const Coord &other) {
        return Coord(x + other.x, y + other.y);
    }

    Coord operator -(const Coord &other) {
        return Coord(x - other.x, y - other.y);
    }

    Coord div_sq2() {
        return Coord(y / 2, x);
    }

    void print() {
        cout << x << "+" << y << "√2";
    }
};

struct Point {
    Coord x, y;

    Point(Coord _x, Coord _y): x(_x), y(_y) {
    }

    bool operator <(const Point &other) const {
        if (x != other.x) {
            return x < other.x;
        }
        return y < other.y;
    }

    bool operator ==(const Point &other) const {
        return x == other.x && y == other.y;
    }

    Point operator +(const Point &other) {
        return Point(x + other.x, y + other.y);
    }

    Point operator -(const Point &other) {
        return Point(x - other.x, y - other.y);
    }

    Point rotate() {
        Coord nx = x - y;
        Coord ny = x + y;
        return Point(nx.div_sq2(), ny.div_sq2());
    }

    void print() {
        cout << "(";
        x.print();
        cout << ",";
        y.print();
        cout << ")";
    }
};

struct Segment {
    Point start, end;

    Segment(Point _start, Point _end): start(_start), end(_end) {
        if (end < start) {
            swap(start, end);
        }
    }

    bool operator <(const Segment &other) const {
        if (start != other.start) {
            return start < other.start;
        }
        return end < other.end;
    }

    void print() {
        start.print();
        cout << " ";
        end.print();
        cout << endl;
    }
};

vector<Segment> sl(vector<Segment> a) {
    vector<pair<Point, int> > dt;

    for (auto it: a) {
        dt.push_back({it.start, -1});
        dt.push_back({it.end, 1});
    }

    sort(all(dt));

    int bal = 0;
    Point start = {{0, 0}, {0, 0}};

    vector<Segment> ans;

    for (auto [pt, tp]: dt) {
        if (bal == 0) {
            start = pt;
        }
        bal -= tp;
        if (bal == 0) {
            ans.push_back(Segment(start, pt));
        }
    }

    return ans;
}

void solve() {
    int n;
    cin >> n;

    Point curr = {{0, 0}, {0, 0}};

    int ang = 0;

    map<Coord, vector<Segment> > horiz;
    map<Coord, vector<Segment> > vert;
    map<Coord, vector<Segment> > diag1;
    map<Coord, vector<Segment> > diag2;

    for (int i = 0; i < n; i++) {
        string com;
        cin >> com;
        int num;
        cin >> num;

        if (com == "rotate") {
            ang += num;
            ang %= 360;
        } else {
            num *= 1024;
            Point d = {{0, 0}, {0, 0}};
            int tp = (ang / 45) % 2;
            if (tp == 0) {
                if ((ang / 90) % 2 == 0) {
                    d = {{0, 0}, {num, 0}};
                } else {
                    d = {{num, 0}, {0, 0}};
                }
            } else {
                d = {{0, num}, {0, num}};
            }
            if (90 <= ang && ang <= 270) {
                d.y = {-d.y.x, -d.y.y};
            }
            if (ang <= 180) {
                d.x = {-d.x.x, -d.x.y};
            }
            Point nxt = curr + d;
            if (com == "move") {
                curr = nxt;
            } else {
                if (ang == 0 || ang == 180) {
                    vert[curr.x].push_back(Segment(curr, nxt));
                } else if (ang == 90 || ang == 270) {
                    horiz[curr.y].push_back(Segment(curr, nxt));
                } else if (ang == 45 || ang == 225) {
                    diag1[curr.x + curr.y].push_back(Segment(curr, nxt));
                } else {
                    diag2[curr.x - curr.y].push_back(Segment(curr, nxt));
                }
                curr = nxt;
            }
        }
    }

    vector<Segment> obj;

    for (auto it: horiz) {
        auto curr = sl(it.ss);
        for (auto it2: curr) {
            obj.push_back(it2);
        }
    }

    for (auto it: vert) {
        auto curr = sl(it.ss);
        for (auto it2: curr) {
            obj.push_back(it2);
        }
    }

    for (auto it: diag1) {
        auto curr = sl(it.ss);
        for (auto it2: curr) {
            obj.push_back(it2);
        }
    }

    for (auto it: diag2) {
        auto curr = sl(it.ss);
        for (auto it2: curr) {
            obj.push_back(it2);
        }
    }

    auto nw = obj;

    int ans = 360;

    int rot = 0;

    for (int iii = 0; iii < 7; iii++) {
        rot += 45;
        rot %= 360;
        for (int i = 0; i < nw.size(); i++) {
            Segment upd = Segment(nw[i].start.rotate(), nw[i].end.rotate());
            nw[i] = upd;
        }
        map<Point, int> mp;
        for (auto seg: nw) {
            set<Point> can;
            for (auto goal: obj) {
                Point p1 = goal.start - seg.start;
                Point p2 = goal.end - seg.end;
                // cout << rot << endl;
                // goal.print();
                // seg.print();
                if (p1 == p2) {
                    can.insert(p1);
                }
            }
            for (auto it: can) {
                mp[it]++;
            }
        }
        for (auto it: mp) {
            if (it.ss == obj.size()) {
                ans = min(ans, rot);
            }
        }
    }

    cout << ans << endl;
}


signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }
}
