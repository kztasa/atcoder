//‘½”{’·®”‚Ì‘«‚µZ(string‚Å‚â‚Á‚Ä‚éj
string adds(string s, string t) {
    ll n = s.size();
    ll m = t.size();
    if (n > m) { swap(s, t); n = s.size(); m = t.size();}
    reverse(ALL(s));
    reverse(ALL(t));
    rep(i, m - n) {
        s.pub('0');
    }
    bool kuriage = false;
    rep(i, m) {
        ll a = s[i] - '0';
        ll b = t[i] - '0';
        ll c = a + b;
        if (kuriage) {
            c++;
        }
        if (c >= 10) {
            c -= 10; kuriage = true;
        }
        else {
            kuriage = false;
        }
        t[i] = c + '0';
    }
    if (kuriage) {
        t.pub('1');
    }
    reverse(ALL(t));
    return t;
}

//‘½”{’·®”‚ÌŠ|‚¯Z(s ~ a) ŒvZ—Ê‚Í N(a|s|)?
string mul(string s, ll a) {
    string t = s;
    rep(j, a - 1) {
        t = adds(t, s);
    }
    ll n = t.size();
    ll p = 0;
    rep(i, n) {
        p += t[i] - '0';
    }
    return t;
}