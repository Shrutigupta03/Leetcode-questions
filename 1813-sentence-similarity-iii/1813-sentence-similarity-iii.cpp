class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        auto splitWords = [](const string& sentence) {
            vector<string> words;
            string word = "";
            for (char c : sentence) {
                if (c == ' ') {
                    if (!word.empty()) {
                        words.push_back(word);
                        word = "";
                    }
                } else {
                    word += c;
                }
            }
            if (!word.empty()) words.push_back(word);
            return words;
        };

        vector<string> words1 = splitWords(sentence1);
        vector<string> words2 = splitWords(sentence2);
        
        if (words1.size() < words2.size()) swap(words1, words2);
        
        int start = 0, end = 0;
        int n1 = words1.size(), n2 = words2.size();
        
        while (start < n2 && words1[start] == words2[start]) start++;
        
        while (end < n2 && words1[n1 - end - 1] == words2[n2 - end - 1]) end++;
        
        return start + end >= n2;
    }
};