class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
      std::unordered_map<char, std::set<std::string_view>> firstChar2Suffix;
      for (std::string_view idea : ideas) {
          firstChar2Suffix[idea[0]].insert(idea.substr(1));
      }
      std::vector<char> keys;
      const int groupSz = firstChar2Suffix.size();
      keys.reserve(groupSz);
      for (const auto& p : firstChar2Suffix) {
          keys.push_back(p.first);
      }
      long long res = 0;
      for (int i = 0; i < groupSz; ++i) {
          for (int j = i + 1; j < groupSz; ++j) {
              const auto& set1 = firstChar2Suffix[keys[i]];
              const auto& set2 = firstChar2Suffix[keys[j]];
              std::vector<std::string_view> unionSet;
              std::set_union(set1.begin(), set1.end(), set2.begin(), set2.end(),
                  std::back_inserter(unionSet));
              res += (set1.size() - unionSet.size()) * (set2.size() -
  unionSet.size()) * 2;
          }
      }
      return res;
        
    }
};