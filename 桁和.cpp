ll sumofdigit(ll p) {
    string s = to_string(p);
    ll n = s.size();
    ll ans = 0;
    rep(i, n) {
        ans += s[i] - '0';
    }
    return ans;
}