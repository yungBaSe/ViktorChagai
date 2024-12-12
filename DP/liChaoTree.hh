/**
 * Description: good with lazySegmentTree.hh idea sometimes.
 * It's just got to be here. Don't touch it.
 */
struct LiChaoTree{
    struct line {
        int k = 0, m = 0;
        line() {}
        line(int k, int m): k(k), m(m) {}
        int get(int x) {
            return k * x + m;
        }
    };
public:
    LiChaoTree (int _maxn) : maxn(_maxn) {
        t.assign(4 * maxn);
    }
    void upd(int v = 1, int tl = 0, int tr = maxn - 1, line L) {
        if (tl > tr) {
            return;
        }
        int tm = (tl + tr) / 2;
        bool l = L.get(tl) > t[v].get(tl);
        bool mid = L.get(tm) > t[v].get(tm);
        if (mid) {
            swap(L, t[v]);
        }
        if (l != mid) {
            upd(2 * v, tl, tm - 1, L);
        }
        else {
            upd(2 * v + 1, tm + 1, tr, L);
        }
    }
    int get(int v = 1, int tl = 0, int tr = maxn - 1, int x) {
        if (tl > tr) {
            return 0;
        }
        int tm = (tl + tr) / 2;
        if (x == tm) {
            return t[v].get(x);
        }	
        if (x < tm) {
            return max(t[v].get(x), get(2 * v, tl, tm - 1, x));
        }
        else {
            return max(t[v].get(x), get(2 * v + 1, tm + 1, tr, x));
        }
    }
private:
    int maxn;
    vector <line> t;
}