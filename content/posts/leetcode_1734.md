
+++
authors = ["Yasir"]
title = "Leetcode 1734: Decode XORed Permutation"
date = "2020-01-29"
description = "Solution to Leetcode 1734"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/decode-xored-permutation/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> decode(vector<int>& enc) {
        int n = enc.size() + 1;
        vector<int> ans(n, 0);
        
        int x = 0;
        for(int i = 1; i < n + 1; i++)
            x ^= i;
        
        ans[0] = x;
        for(int i = 1; i < enc.size(); i += 2)
            ans[0] ^= enc[i];
        
        for(int i = 1; i < n; i++)
            ans[i] = ans[i - 1] ^ enc[i - 1];
        
        return ans;
    }
};
{{< /highlight >}}

