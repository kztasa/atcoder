
// ������S�̊eindex �ɂ���
//�u���� i �𒆐S�Ƃ���Œ��̉񕶂̔��a�v
// ���L�^�����z�� R �� O(|S|) �ō\�z����A���S���Y��

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