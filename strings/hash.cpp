struct StrHash {
    const long long p = 337, m = 1e9 + 7;
    vector<long long> hash, ppows;

    StrHash(string s) {

        ppows.resize(s.size() + 5);
        ppows[0] = 1;
        for(int i = 1; i < ppows.size(); i++) {
            ppows[i] = (ppows[i - 1] * p) % m;
        }

        hash.resize(s.size());
        hash[0] = s[0] - 'a' + 1;
        for(int i = 1; i < hash.size(); i++) {
            hash[i] = (hash[i - 1] * p) % m;
            hash[i] = (hash[i] + (s[i] - 'a' + 1)) % m;
        }
    }

    ll getHash(int l, int r) {
        if(l == 0) return hash[r];
        ll h = hash[r] - (hash[l - 1] * ppows[r - l + 1]) % m;
        if(h < 0) h += m;
        h %= m;
        return h;
    }
};
