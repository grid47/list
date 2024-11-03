
+++
authors = ["Crafted by Me"]
title = "Leetcode 1156: Swap For Longest Repeated Character Substring"
date = "2021-09-03"
description = "In-depth solution and explanation for Leetcode 1156: Swap For Longest Repeated Character Substring in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/swap-for-longest-repeated-character-substring/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxRepOpt1(string text, int res = 1) {
        vector<vector<int>> idx(26);
        for(int i = 0; i < text.size(); i++)
            idx[text[i] - 'a'].push_back(i);

        for(int n = 0; n < 26; n++) {
            auto cnt = 1, cnt1 = 0, mx = 0;
            for(auto i = 1; i < idx[n].size(); i++) {
                if(idx[n][i] == idx[n][i - 1]+ 1) ++cnt;
                else {
                    cnt1 = idx[n][i] == idx[n][i-1] + 2? cnt:0;
                    cnt = 1;
                }
                mx = max(mx, cnt + cnt1);
            }
            res = max(res, mx + ( idx[n].size() > mx ? 1 : 0) );
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1156.md" >}}
---


"| 1157: Online Majority Element In Subarray |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

