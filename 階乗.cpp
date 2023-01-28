ll fac(ll n) {
    ll now = 1;
    rep(i, n + 1) {
        if (i == 0) {
            continue;
        }
        now *= i;
    }
    return now;
}