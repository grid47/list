class Solution {
public:
    long long countVowels(string word) {
        long long res = 0, n = word.size();
        for(int i = 0; i < n; i++)
        if(string("aeiou").find(word[i]) != string::npos)
        res += (i + 1) * (n - i);
        return res;
    }
};