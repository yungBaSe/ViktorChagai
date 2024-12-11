namespace Hashes {
struct HashedString {
    HashedString(string &_s) : s(_s) {
        init(s);
        calcHashes(s);
    }
    pair <ll, ll> getHash(int l, int r) {
        ll h1 = (prefixHash[r + 1].first - (prefixHash[l].first * A1pwrs[r + 1 - l]) % B1 + B1) % B1;
        ll h2 = (prefixHash[r + 1].second - (prefixHash[l].second * A2pwrs[r + 1 - l]) % B2 + B2) % B2;

        return {h1, h2};
    }
private:
    string &s;
    const ll A1 = 999999929, B1 = 1000000009, A2 = 1000000087, B2 = 1000000097;
    vector <ll> A1pwrs, A2pwrs;
    vector <pair <ll, ll>> prefixHash;
    void init() {
        ll a1 = 1;
        ll a2 = 1;
        for (int i = 0; i <= s.size(); ++i) {
            A1pwrs.push_back(a1);
            A2pwrs.push_back(a2);
            a1 = (a1 * A1) % B1;
            a2 = (a2 * A2) % B2;
        }
    }
    void calcHashes() {
        pair <ll, ll> h = {0, 0};
        prefixHash.push_back(h);
        for (char c : s) {
            ll h1 = (prefixHash.back().first * A1 + c) % B1;
            ll h2 = (prefixHash.back().second * A2 + c) % B2;
            prefixHash.emplace_back(h1, h2);
        }
    }
};
};