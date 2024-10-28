
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1156: Swap For Longest Repeated Character Substring"
date = "2021-08-30"
description = "Solution to Leetcode 1156"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

