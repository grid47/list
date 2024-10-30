
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1562: Find Latest Group of Size M"
date = "2020-07-22"
description = "Solution to Leetcode 1562"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-latest-group-of-size-m/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {

        int n = arr.size();
        vector<int> len(n + 2, 0), cnt(n + 1, 0);
        
        int res = -1;
        
        for(int i = 0; i < n; i++) {
            
            int a = arr[i];
            int ll = len[a - 1];
            int rl = len[a + 1];
            len[a] = len[a - ll] = len[a + rl] = ll + rl + 1;
            
            cnt[ll]--;
            cnt[rl]--;
            
            cnt[len[a]]++;
            
            if(cnt[m] > 0) res = i + 1;
            
        }
        
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

