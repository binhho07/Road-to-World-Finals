#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int W, H;
    cin >> W >> H;
    int w1, h1, x1, y1, dx1, dy1;
    cin >> w1 >> h1 >> x1 >> y1 >> dx1 >> dy1;
    
    int w2, h2, x2, y2, dx2, dy2;
    cin >> w2 >> h2 >> x2 >> y2 >> dx2 >> dy2;

    int Px = (4 * (W - w1) * (W - w2)) / __gcd(2 * (W - w1), 2 * (W - w2));
    int Py = (4 * (H - h1) * (H - h2)) / __gcd(2 * (H - h1), 2 * (H - h2));

    vector<bool> X(Px), Y(Py);

    for (int t = 0; t < Px; ++t) {
        int L1 = x1;
        int L2 = x2;
        int R1 = x1 + w1;
        int R2 = x2 + w2;
        if (!(R1 <= L2 || R2 <= L1)) {
            X[t] = 1;
        }
        if (L1 == 0) {
            dx1 = 1;
        }
        else if (R1 == W) {
            dx1 = -1;
        }
        if (L2 == 0) {
            dx2 = 1;
        }
        else if (R2 == W) {
            dx2 = -1;
        }

        x1 += dx1;
        x2 += dx2;
    }

    for (int t = 0; t < Py; ++t) {
        int L1 = y1;
        int L2 = y2;
        int R1 = y1 + h1;
        int R2 = y2 + h2;
        if (!(R1 <= L2 || R2 <= L1)) {
            Y[t] = 1;
        }
        if (L1 == 0) {
            dy1 = 1;
        }
        else if (R1 == H) {
            dy1 = -1;
        }
        if (L2 == 0) {
            dy2 = 1;
        }
        else if (R2 == H) {
            dy2 = -1;
        }

        y1 += dy1;
        y2 += dy2;
    }

    int G = __gcd(Px, Py);
    int D = (Px * Py) / G;
    int C = 0;
    vector<int> cntX(G), cntY(G);

    for (int t = 0; t < Px; ++t) {
        cntX[t % G] += X[t];
    }
    for (int t = 0; t < Py; ++t) {
        cntY[t % G] += Y[t];
    }

    for (int i = 0; i < G; ++i) {
        C += cntX[i] * cntY[i];
    }

    cout << C / __gcd(C, D) << '/' << D / __gcd(C, D) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
