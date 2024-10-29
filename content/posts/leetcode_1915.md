
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1915: Number of Wonderful Substrings"
date = "2019-08-03"
description = "Solution to Leetcode 1915"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-wonderful-substrings/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        map<int, int> mp;
        mp[0] = 1;
        int msk = 0;
        long long ans = 0;
        for(int i = 0; i < word.size(); i++) {
            
            int idx = word[i] - 'a';
            msk ^= (1 << idx);
            ans += mp[msk];
            for(int j = 0; j < 10; j++) {
                int lf = msk ^ (1 << j);
                ans += mp[lf];
                }
            mp[msk]++;
            }
        
        return ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

