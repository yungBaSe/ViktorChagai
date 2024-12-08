namespace SegmentTree{

template <typename T>
struct SegmentTree{

    SegmentTree(vector <T>& _a) : n(_a.size()), a(_a) : {
        t.assign(4 * n, 0);
        mod.assign(4 * n, 0);
        build(1, 0, n);
    } 
    
    void update(int v = 1, int tl = 0, int tr = n, int l, int r, T x){
        if (l >= r || tl >= tr) return;
        if (l == tl && r == tr){
            apply(v, l, r, x);
        }
        else {
            push(v, tl, tr);
            int mid = (tl + tr) >> 1;
            update(2 * v, tl, mid, l, min(r, mid), x);
            update(2 * v + 1, mid, tr, max(l, mid), r, x);
            t[v] = min(t[2 * v], t[2 * v + 1]); 
        }
    }
    
    ll get_min(int v = 1, int tl = 0, int tr = n, int l, int r){
        if (l >= r || tl >= tr) return INFLL;
        if (l == tl && r == tr){
            return t[v];
        }
        else {
            push(v, tl, tr);
            int mid = (tl + tr) >> 1;
            return min(get_min(2 * v, tl, mid, l, min(r, mid)), get_min(2 * v + 1, mid, tr, max(l, mid), r));
        }
    }

private:
    int n;
    vector <T> &a;
    vector <T> t, mod;

    void build(int v, int l, int r){
        if (l == r - 1) {
            t[v] = a[l];
        }
        else {
            int mid = (l + r) >> 1;
            build(2 * v, l, mid);
            build(2 * v + 1, mid, r);
            t[v] = min(t[2 * v], t[2 * v + 1]);
        }
    }

    void apply (int v, int l, int r, ll x){
        t[v] += x;
        mod[v] += x;
    }
    
    void push (int v, int l, int r){
        int mid = (l + r) >> 1;
        apply(2*v, l, mid, mod[v]);
        apply(2*v + 1, mid, r, mod[v]);
        mod[v] = 0;
    }
};
};