class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        int totalSkill = 0;
        unordered_map<int, int> skillMap;

        for (int s : skill) {
            totalSkill += s;
            skillMap[s]++;
        }

        if (totalSkill % (n / 2) != 0) {
            return -1;
        }

        int targetSkill = totalSkill / (n / 2);
        long long totalChemistry = 0;

        for (auto& [currSkill, currFreq] : skillMap) {
            int partnerSkill = targetSkill - currSkill;

            if (skillMap.find(partnerSkill) == skillMap.end() ||
                currFreq != skillMap[partnerSkill]) {
                return -1;
            }

            totalChemistry += (long long)currSkill * (long long)partnerSkill *                                             (long long)currFreq;
        }

        return totalChemistry / 2;
    }
};