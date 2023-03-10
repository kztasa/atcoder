// 最長増加部分列 (LIS)  (1.1 最長増加部分列の長さの取得)
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
