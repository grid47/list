
+++
authors = ["Yasir"]
title = "Leetcode 318: Maximum Product of Word Lengths"
date = "2023-12-15"
description = "Solution to Leetcode 318"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-product-of-word-lengths/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int maxProduct(vector<string>& words) {

        int len = words.size();
        vector<int> mask(len, 0);

        int res = 0;
        for(int i = 0; i < len; i++) {
            string word = words[i];
            int sz = word.size();
            for(int j = 0; j < sz; j++)
            mask[i] |= (1 << (word[j] - 'a'));

            for(int j = 0; j < i; j++) {
                if((mask[i] & mask[j]) == 0)
                res = max(res, int (words[i].size() * words[j].size() ));
            }
        }
        return res;
    }
};
{{< /highlight >}}

