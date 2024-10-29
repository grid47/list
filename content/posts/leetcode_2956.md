
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2956: Find Common Elements Between Two Arrays"
date = "2016-09-26"
description = "Solution to Leetcode 2956"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-common-elements-between-two-arrays/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        set<int> n1, n2;
        for(int x: nums1) n1.insert(x);
        for(int x: nums2) n2.insert(x);
        int cnt1 = 0;
        for(int x: nums1) if(n2.count(x)) cnt1++;
        int cnt2 = 0;
        for(int x: nums2) if(n1.count(x)) cnt2++;        
        return vector<int>{cnt1, cnt2};
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

