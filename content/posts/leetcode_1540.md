
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1540: Can Convert String in K Moves"
date = "2020-08-12"
description = "Solution to Leetcode 1540"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/can-convert-string-in-k-moves/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.size() != t.size()) return false;
        int n = s.size();
        vector<int> cnt(n, 0);
        vector<int> frq(26, 0);
        for(int i = 0; i < n; i++) {
            if(t[i] > s[i]) {
                cnt[i] = t[i] - s[i];
            } else if(t[i] < s[i]) {
                cnt[i] = 26 - (s[i] - t[i]);
            }
            // cout << cnt[i] << " ";
            frq[cnt[i] % 26]++;
        }

        for(int i = 1; i < 26; i++) {
            // cout << frq[i] << " ";
            if(frq[i] == 0) continue;
            long net = (long) (i + (frq[i] - 1)  * 26);
            if( net > k) return false;
        }
        
        return true;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
