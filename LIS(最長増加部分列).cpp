// Å’·‘‰Á•”•ª—ñ (LIS)  (1.1 Å’·‘‰Á•”•ª—ñ‚Ì’·‚³‚Ìæ“¾)
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
