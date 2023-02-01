class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
          while (str1 != str2) {
            int size1 = str1.size();
            int size2 = str2.size();
            if (size1 < size2) swap(str1, str2);            
            int i = 0, j = 0;
            while (i < size1 && j < size2) {
                if (str1[i] != str2[j]) return "";
                i++;
                j++;
            }
            str1=str1.substr(i);
        }
        return str1;
    }
};