
+++
authors = ["Crafted by Me"]
title = "Leetcode 1465: Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts"
date = "2020-10-28"
description = "Solution to Leetcode 1465"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxArea(int h, int w, vector<int>& hr, vector<int>& vt) {
        
        int mx1 = 0, mx2 = 0;
        sort(hr.begin(), hr.end());
        sort(vt.begin(), vt.end());
        mx1 = h - hr.back();
        mx2 = w - vt.back();
        int prv = 0;
        for(int i = 0; i < hr.size(); i++) {
            mx1 = max(mx1, hr[i] - prv);
            prv = hr[i];
        }
        prv= 0;
        for(int i = 0; i < vt.size(); i++) {
            mx2 = max(mx2, vt[i] - prv);
            prv = vt[i];
        }      
        long long mxa = mx1, mxb = mx2;
        return (mxa * mxb) % 1000000007;
    }
};
{{< /highlight >}}



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

