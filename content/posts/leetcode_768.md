
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 768: Max Chunks To Make Sorted II"
date = "2022-09-22"
description = "Solution to Leetcode 768"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/max-chunks-to-make-sorted-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<pair<int,int>> tmp;
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            tmp.push_back({arr[i], i});
        }
        sort(tmp.begin(), tmp.end());
        int res = 0, mx = -1;
        for(int i = 0; i < n; i++) {
            mx = max(mx, tmp[i].second);
            if(mx == i){
                res++;
            }
        }
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

