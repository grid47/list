
+++
authors = ["grid47"]
title = "Leetcode 1648: Sell Diminishing-Valued Colored Balls"
date = "2024-05-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1648: Sell Diminishing-Valued Colored Balls in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Binary Search","Greedy","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "oj7Rxz1r70g"
youtube_upload_date="2021-02-13"
youtube_thumbnail="https://i.ytimg.com/vi/oj7Rxz1r70g/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/sell-diminishing-valued-colored-balls/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mod = (int) 1e9 + 7;
    int maxProfit(vector<int>& inv, int orders) {
        
        
        long n = inv.size(), res = 0;
        
        sort(inv.rbegin(), inv.rend());
        
        for(int i = 0, col = 1; i < n && orders > 0; i++, col++) {
            long cur = inv[i], prv = i + 1 < n? inv[i + 1]: 0;
            long depth = min((long)orders/col, (long)cur - prv);
            orders -= depth * col;
            
        res = (res + ((cur * (cur + 1) - (cur - depth) * (cur - depth + 1)) / 2 * col)) % mod;
                  
            if(cur - prv > depth) {
                res = (res + orders * (cur - depth)) % mod;
                break;
            }
        }
        
        /*
            There is a value k, for which all the balls above this value are sold.
            
        */
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1648.md" >}}
---
{{< youtube oj7Rxz1r70g >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1652: Defuse the Bomb](https://grid47.xyz/leetcode/solution-1652-defuse-the-bomb/) |
| --- |
