
// 文字列Sの各index について
//「文字 i を中心とする最長の回文の半径」
// を記録した配列 R を O(|S|) で構築するアルゴリズム

vector<ll> Manacher(string S) {
    vector<ll> R(S.size());
    int i = 0, j = 0;
    while (i < S.size()) {
        while (i - j >= 0 && i + j < S.size() && S[i - j] == S[i + j]) ++j;
        R[i] = j;
        int k = 1;
        while (i - k >= 0 && k + R[i - k] < j) R[i + k] = R[i - k], ++k;
        i += k; j -= k;
    }
    return R;
}