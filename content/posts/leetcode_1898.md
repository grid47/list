
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1898: Maximum Number of Removable Characters"
date = "2019-08-19"
description = "Solution to Leetcode 1898"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-removable-characters/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int isSubseq(string &s, string &p, vector<int>& mp, int k) {
        int i = 0, j = 0;
        while(i < s.size() && j < p.size()) {
            if(mp[i] <= k) {
                i++;
                continue;
            }
            if(s[i] == p[j]) {
                i++;
                j++;
                if(j == p.size()) return true;
            } else i++;
        }
        return false;
    }
    
    int maximumRemovals(string s, string p, vector<int>& rm) {
        vector<int> mp(s.size(), INT_MAX);
        for(int i = 0; i < rm.size(); i++)
            mp[rm[i]] = i;
        int l = 0, r = rm.size() - 1, ans = -1;
        while(l <= r) {
            int mid = l + (r - l + 1) / 2;
            if(isSubseq(s, p, mp, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans + 1;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

