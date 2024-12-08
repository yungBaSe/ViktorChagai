namespace SparseTable{

template <typename T>
struct SparseTable{
public:

    SparseTable (vector <T> &_a) : n(_a.size()), a(_a) {
        init(n);
    }
    
    T rmq(T l, T r) {
        T t = __lg(r - l);
        return min(g[t][l], g[t][r - (1 << t)]);
    }


private:
    int n;
    vector <T> &a;
    vector <vector <T>> g; 

    void init(int n) {
        int logn = __lg(n);

        g.assign(logn + 1, vector <T>(n));

        for (int i = 0; i < n; ++i) {
            g[0][i] = a[i];
        }
        
        for (int l = 0; l <= logn - 1; l++) {
            for (int i = 0; i + (2 << l) <= n; i++) {
                g[l + 1][i] = min(g[l][i], g[l][i + (1 << l)]);
            }
        }
    }
};
};