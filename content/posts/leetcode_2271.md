
+++
authors = ["Yasir"]
title = "Leetcode 2271: Maximum White Tiles Covered by a Carpet"
date = "2018-08-11"
description = "Solution to Leetcode 2271"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-white-tiles-covered-by-a-carpet/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& t, int len) {
        
        int n = t.size(), res = 0,
            cover = 0, j = 0, partial = 0;

        sort(t.begin(), t.end());
        
        for(int i = 0; i < n && res < len ; ) {
            if(t[j][0] + len > t[i][1]) {
                cover += t[i][1] - t[i][0] + 1;
                res = max(res, cover);               
                i++;
            } else {
                partial = max(0, t[j][0] + len - t[i][0]);
                res = max(res, cover + partial);
                cover -= (t[j][1] - t[j][0] + 1);
                j++;
            }            
        }
        
        return res;        
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

