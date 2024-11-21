/// @brief 最長増加部分列（LIS）のインデックスを返します
/// @tparam Strict 狭義単調増加の場合 true, 広義単調増加の場合 false
/// @tparam Type 数列の要素の型
/// @param v 数列
/// @return 最長増加部分列（LIS）のインデックス
/// @note 1.4 最長増加部分列の復元
template <bool Strict, class Type>
vector<int> LIS(const std::vector<Type>& v){
	vector<Type> dp;
	auto it = dp.begin();
	vector<int> positions;
	for (const auto& elem : v){
		if constexpr (Strict){
			it = std::lower_bound(dp.begin(), dp.end(), elem);
		}
		else{
			it = std::upper_bound(dp.begin(), dp.end(), elem);
		}
		positions.push_back(static_cast<int>(it - dp.begin()));
		if (it == dp.end())	{
			dp.push_back(elem);
		}
		else{
			*it = elem;
		}
	}
	vector<int> subseq(dp.size());
	int si = static_cast<int>(subseq.size()) - 1;
	int pi = static_cast<int>(positions.size()) - 1;
	while ((0 <= si) && (0 <= pi)){
		if (positions[pi] == si){
			subseq[si] = pi;
			--si;
		}
		--pi;
	}
	return subseq;
}
