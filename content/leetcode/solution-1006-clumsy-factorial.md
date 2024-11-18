
+++
authors = ["grid47"]
title = "Leetcode 1006: Clumsy Factorial"
date = "2024-07-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1006: Clumsy Factorial in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Stack","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "DxcqMnUON_I"
youtube_upload_date="2019-07-23"
youtube_thumbnail="https://i.ytimg.com/vi_webp/DxcqMnUON_I/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/clumsy-factorial/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int clumsy(int n) {
        
        int ans = n;
        int j = n - 1;
        vector<int> stk;
        
        for(int i = 1; i < n; i++) {
            
                 if(i % 4 == 1) ans *= j--;
            else if(i % 4 == 2) ans /= j--;
            else {
                
                stk.push_back(ans);
                
                if(i % 4 == 3) ans = j--;
                        else   ans = (-1 * j--);
                
            }
            
        }
        
        int sum = 0;
        for(int i = 0; i < stk.size(); i++)
            sum += stk[i];
        
        return sum + ans;
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1006.md" >}}
---
{{< youtube DxcqMnUON_I >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1007: Minimum Domino Rotations For Equal Row](https://grid47.xyz/leetcode/solution-1007-minimum-domino-rotations-for-equal-row/) |
| --- |
