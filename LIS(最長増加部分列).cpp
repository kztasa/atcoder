// �Œ����������� (LIS)  (1.1 �Œ�����������̒����̎擾)
ll LIS(const std::vector<ll>& v)
{
    std::vector<ll> dp;

    for (const auto& elem : v)
    {
        auto it = std::lower_bound(dp.begin(), dp.end(), elem);

        if (it == dp.end())
        {
            dp.push_back(elem);
        }
        else
        {
            *it = elem;
        }
    }

    return dp.size();
}
