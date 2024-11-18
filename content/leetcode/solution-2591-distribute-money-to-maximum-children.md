
+++
authors = ["grid47"]
title = "Leetcode 2591: Distribute Money to Maximum Children"
date = "2024-02-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2591: Distribute Money to Maximum Children in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "rCLdAlt05XE"
youtube_upload_date="2023-03-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/rCLdAlt05XE/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/distribute-money-to-maximum-children/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int distMoney(int num, int kid) {
        if(num < kid) return -1;
        int avg = num / kid;
        if(avg > 8) return kid - 1;
        if(avg == 8) {
            if(num % kid == 0) return kid;
            return kid - 1;
        }
        if(avg > 4) {
            num -= kid;
            int sol = num / 7;
            if(num % 7 == 3 && sol == kid - 1) sol--;
            return sol;
        }
        
        if(avg == 4) {
            num -= kid;
            int sol = num / 7;
            if(num % 7 == 3 && sol == kid - 1) sol--;
            return sol;
        }
        
        if(avg < 4) {
            num -= kid;
            int sol = num / 7;
            if(num % 7 == 3 && sol == kid - 1) sol--;
            return sol;            
        }
        
        return -1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2591.md" >}}
---
{{< youtube rCLdAlt05XE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2592: Maximize Greatness of an Array](https://grid47.xyz/leetcode/solution-2592-maximize-greatness-of-an-array/) |
| --- |
