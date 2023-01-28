//‰ñ•¶‚©‚Ç‚¤‚©
bool pal(string s) {
    ll n = s.size();
    rep(i, n) {
        if (s[i] != s[n - 1 - i]) {
            return false;
        }
    }
    return true;
}