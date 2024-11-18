
+++
authors = ["grid47"]
title = "Leetcode 2844: Minimum Operations to Make a Special Number"
date = "2024-01-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2844: Minimum Operations to Make a Special Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Greedy","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "xFshDEg_Ul4"
youtube_upload_date="2023-09-03"
youtube_thumbnail="https://i.ytimg.com/vi/xFshDEg_Ul4/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/minimum-operations-to-make-a-special-number/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumOperations(string num) {
        bool fivefound = false;
        bool zerofound = false;
        for (int i =num.size()-1; i >=0;i--) {
            
            if (zerofound && num[i]=='0') return num.size()-2-i;
            if (zerofound && num[i]=='5') return num.size()-2-i;
            if (fivefound && num[i]=='2') return num.size()-2-i;
            if (fivefound && num[i]=='7') return num.size()-2-i;
            if (num[i]=='5') fivefound = true;
            if (num[i]=='0') zerofound = true;
            
        }
        if (zerofound) return num.size()-1;
        return num.size();
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2844.md" >}}
---
{{< youtube xFshDEg_Ul4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2845: Count of Interesting Subarrays](https://grid47.xyz/leetcode/solution-2845-count-of-interesting-subarrays/) |
| --- |
