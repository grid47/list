
+++
authors = ["grid47"]
title = "Leetcode 1052: Grumpy Bookstore Owner"
date = "2024-07-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1052: Grumpy Bookstore Owner in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "pXFbNuEIn8Q"
youtube_upload_date="2024-06-21"
youtube_thumbnail="https://i.ytimg.com/vi_webp/pXFbNuEIn8Q/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/grumpy-bookstore-owner/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxSatisfied(vector<int>& cust, vector<int>& gm, int min) {

        int res = 0;
        int n = cust.size();
        vector<int> mins(n, 0), cs(n, 0);
            
        for(int i = 0; i < n; i++) {
            if(i < min)
            mins[0] += cust[i];
            else
            mins[i - min + 1] = mins[i - min] - cust[i - min] + cust[i];
            
            if(i == 0) cs[i] = gm[i] == 0 ? cust[i]: 0;
            else cs[i] = cs[i - 1] + (gm[i] == 0 ? cust[i]:0);
        }
        // for(int i = 0; i < n; i++)
        //     cout << mins[i] << " ";
        // cout << "\n";
        // for(int i = 0; i < n; i++)
        //     cout << cs[i] << " ";
        for(int i = 0; i <= n - min; i++) {
            int ans = (i > 0? cs[i - 1] : 0) + mins[i] + (cs[n - 1] - cs[i + min - 1]);                
            res = max(res, ans); 
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1052.md" >}}
---
{{< youtube pXFbNuEIn8Q >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1053: Previous Permutation With One Swap](https://grid47.xyz/leetcode/solution-1053-previous-permutation-with-one-swap/) |
| --- |
