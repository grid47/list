
+++
authors = ["Crafted by Me"]
title = "Leetcode 784: Letter Case Permutation"
date = "2022-09-10"
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

{{< highlight cpp >}}
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


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/784.md" >}}
- by gpt
        
---
{{< youtube qcWClV0FRTs >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

