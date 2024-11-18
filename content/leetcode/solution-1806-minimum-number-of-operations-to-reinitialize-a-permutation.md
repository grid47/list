
+++
authors = ["grid47"]
title = "Leetcode 1806: Minimum Number of Operations to Reinitialize a Permutation"
date = "2024-05-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1806: Minimum Number of Operations to Reinitialize a Permutation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "MT7Qo0LmoFo"
youtube_upload_date="2021-03-28"
youtube_thumbnail="https://i.ytimg.com/vi_webp/MT7Qo0LmoFo/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int reinitializePermutation(int n) {
        
        vector<int> prem(n, 0), arr(n, 0);
        
        for(int i = 0; i < n; i++) {
            prem[i] = i;
        }
        int cnt = 1;
        while(1) {
        
            for(int i = 0; i < n; i++) {
                arr[i] = (i % 2) ? prem[n/2 + (i - 1)/2] : prem[i/2];
            }
            
            bool x = false;
            for(int i= 0; i < n; i++)
                if(arr[i] != i) x = true;
            
            if(!x) break;
            
            prem = arr;
            cnt++;
        }
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1806.md" >}}
---
{{< youtube MT7Qo0LmoFo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1807: Evaluate the Bracket Pairs of a String](https://grid47.xyz/leetcode/solution-1807-evaluate-the-bracket-pairs-of-a-string/) |
| --- |
