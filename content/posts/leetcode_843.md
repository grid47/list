
+++
authors = ["Yasir"]
title = "Leetcode 843: Guess the Word"
date = "2022-07-07"
description = "Solution to Leetcode 843"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/guess-the-word/description/)

---

**Code:**

{{< highlight html >}}
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    
    int overlap(vector<string> &words) {
        vector<vector<int>> prob(6, vector<int>(26, 0));
        for(int i = 0; i < words.size(); i++)
            for(int j = 0; j < 6; j++)
                prob[j][words[i][j] - 'a']++;
        
        int idx = -1;
        long long mx = -1;
        for(int i = 0; i < words.size(); i++) {
            long long cur = 0;
            for(int j = 0; j < 6; j++)
                cur += prob[j][words[i][j] - 'a'];
            
            if(cur > mx) {
                idx = i;
                mx = cur;
            }
        }
        return idx;
    }
    
    int tally(string &a, string &b) {
        int res = 0;
        for(int i = 0;i < 6; i++)
            res += (a[i] == b[i]);
        return res;
    }
    
    void findSecretWord(vector<string>& words, Master& master) {
        int match = 0, j = 0;
        while(match != 6) {
            j++;
            int i = overlap(words);
            match = master.guess(words[i]);
            vector<string> tmp;
            for(auto it: words)
                if(match == tally(it, words[i])) {
                    tmp.push_back(it);
                }
            words = tmp;
        }
    }
};
{{< /highlight >}}

