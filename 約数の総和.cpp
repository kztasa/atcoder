
template<typename T = int>
std::map<T, int> factorize(T n) {
    std::map<T, int> factor_map;
    for (T i = 2; i * i <= n; i++) {
        while (!(n % i)) {
            factor_map[i]++; n /= i;
        }
    }
    if (n > 1) factor_map[n]++;
    return factor_map;
}

//dependent on :factorize 
//–ñ”‚Ì‘˜a@©g‚Íœ‚­
ll sod(int n) {
    map<int, int> f = factorize(n);
    ll sum = 1;
    for (auto a : f) {
        ll s = 1, t = 1;
        rep(i, a.second) {
            t *= a.first;
            s += t;
        }
        sum *= s;
    }
    return sum - n;
}