
+++
authors = ["Yasir"]
title = "Leetcode 784: Letter Case Permutation"
date = "2022-09-04"
description = "Solution to Leetcode 784"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/letter-case-permutation/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        bt(ans, s, 0);
        return ans;
    }
    
    void bt(vector<string> &ans, string &s, int i) {
        if(i== s.size()) {
            ans.push_back(s);
            return;
        }
        
        bt(ans, s, i + 1);
        if(isalpha(s[i])) {
            s[i] ^= 1 << 5;
            bt(ans, s, i+1);
        }
        
    }
};
{{< /highlight >}}

