
+++
authors = ["Yasir"]
title = "Leetcode 131: Palindrome Partitioning"
date = "2024-06-19"
description = "Solution to Leetcode 131"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/palindrome-partitioning/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> tmp;
        bt(ans, tmp, s, 0);
        return ans;
    }
    
    void bt(vector<vector<string>> &ans, vector<string> &tmp, string s, int idx) {
        if(idx == s.size()) {
            ans.push_back(tmp);
            return;
        }
        
        for(int i = idx; i < s.size(); i++) {
            if(isPal(s, idx, i)) {
              
                tmp.push_back(s.substr(idx, i - idx + 1));
                bt(ans, tmp, s, i + 1);
                tmp.pop_back();
            }
        }
    }
    
    bool isPal(string s, int i, int j) {
        while(i <= j) {
            if(s[i] != s[j])
                return false;
            i++, j--;
        }
        return true;
    }
};
{{< /highlight >}}

