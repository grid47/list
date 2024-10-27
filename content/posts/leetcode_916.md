
+++
authors = ["Yasir"]
title = "Leetcode 916: Word Subsets"
date = "2022-04-26"
description = "Solution to Leetcode 916"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/word-subsets/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> frq(26, 0);
        for(auto s: words2) {
            vector<int> tmp(26, 0);
            for(char c: s) {
                tmp[c - 'a']++;
                frq[c - 'a'] = max(frq[c - 'a'], tmp[c-'a']);
            }
        }
        vector<string> res;
        for(auto s: words1) {
            vector<int> tmp(26, 0);
            for(char c: s) tmp[c - 'a']++;
            int flag = true;
            for(int i = 0; i < 26; i++) {
                if(tmp[i] < frq[i]) {
                    flag = false;
                    break;
                }
            }
            if(flag) res.push_back(s);
        }
        return res;
    }
};
{{< /highlight >}}

