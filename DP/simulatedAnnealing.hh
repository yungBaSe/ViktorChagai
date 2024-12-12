/**
 * Description: Use it if you chill guy =)
 * 
 * There is solution of a problem of placing
 * 8 queens on a chessboard in a such way that they
 * don't attack each other
 * 
 * $f(p)$ - number of the queens that don't 
 * attack anothers
 */
const int n = 100;
const int k = 1000;

int f(vector<int> &p) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        int d = 1;
        for (int j = 0; j < i; j++)
            if (abs(i - j) == abs(p[i] - p[j]))
                d = 0;
        s += d;
    }
    return s;
}

double rnd() { return double(rand()) / RAND_MAX; }

int main() {
    vector<int> v(n);
    iota(v.begin(), v.end(), 0);
    shuffle(v.begin(), v.end()); // generate initial permutation
    int ans = f(v);

    double t = 1;
    for (int i = 0; i < k && ans < n; i++) {
        t *= 0.99;
        vector<int> u = v;
        swap(u[rand() % n], u[rand() % n]);
        int val = f(u);
        if (val > ans || rnd() < exp((val - ans) / t)) {
            v = u;
            ans = val;
        }
    }

    for (int x : v)
        cout << x + 1 << " ";

    return 0;
}