
+++
authors = ["Crafted by Me"]
title = "Leetcode 1540: Can Convert String in K Moves"
date = "2020-08-15"
description = "In-depth solution and explanation for Leetcode 1540: Can Convert String in K Moves in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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


---


"| 1541: Minimum Insertions to Balance a Parentheses String |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

