//多倍長整数を(string→vector)に変換
vector<ll> digit(string s) {
    ll n = s.size();
    vector<ll> d(n);
    rep(i, n) {
        d[i] = s[i] - '0';
    }
    return d;
}


//多倍長整数の足し算
vector<ll> adds(vector<ll> s, vector<ll> t) {
    ll n = s.size();
    ll m = t.size();
    if (n > m) { swap(s, t); n = s.size(); m = t.size(); }
    reverse(ALL(s));
    reverse(ALL(t));
    rep(i, m - n) {
        s.pub(0);
    }
    bool kuriage = false;
    rep(i, m) {
        ll a = s[i];
        ll b = t[i];
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
        t[i] = c;
    }
    if (kuriage) {
        t.pub(1);
    }
    reverse(ALL(t));
    return t;
}


vector<ll> carry_and_fix(vector<ll> digit) {
    int N = digit.size();
    
    for (int i = 0; i < N - 1; ++i) {
        // 繰り上がり処理 (K は繰り上がりの回数)
        if (digit[i] >= 10) {
            int K = digit[i] / 10;
            digit[i] -= K * 10;
            digit[i + 1] += K;
        }
        // 繰り下がり処理 (K は繰り下がりの回数)
        if (digit[i] < 0) {
            int K = (-digit[i] - 1) / 10 + 1;
            digit[i] += K * 10;
            digit[i + 1] -= K;
        }
    }
    // 一番上の桁が 10 以上なら、桁数を増やすことを繰り返す
    while (digit.back() >= 10) {
        int K = digit.back() / 10;
        digit.back() -= K * 10;
        digit.push_back(K);
    }
    // 1 桁の「0」以外なら、一番上の桁の 0 (リーディング・ゼロ) を消す
    while (digit.size() >= 2 && digit.back() == 0) {
        digit.pop_back();
    }
    reverse(ALL(digit));
    return digit;
}


//多倍長整数の掛け算(s × t) 計算量は N(|s||t|)?
vector<ll> mul(vector<ll> s, vector<ll> t) {
    reverse(ALL(s));
    reverse(ALL(t));
    ll NA = s.size(); 
    ll NB = t.size(); 
    vector<ll> res(NA + NB - 1);
    for (int i = 0; i < NA; ++i) {
        for (int j = 0; j < NB; ++j) {
            res[i + j] += s[i] * t[j];
        }
    }
    return carry_and_fix(res);
}
