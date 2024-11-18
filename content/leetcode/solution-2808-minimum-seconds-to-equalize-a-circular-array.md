
+++
authors = ["grid47"]
title = "Leetcode 2808: Minimum Seconds to Equalize a Circular Array"
date = "2024-01-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2808: Minimum Seconds to Equalize a Circular Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "NgWw6HIyCWE"
youtube_upload_date="2023-08-06"
youtube_thumbnail="https://i.ytimg.com/vi/NgWw6HIyCWE/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/minimum-seconds-to-equalize-a-circular-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        
        int n = nums.size();
        map<int, vector<int>> pos;
        
        for(int i = 0; i < n; i++)
            pos[nums[i]].push_back(i);
        
        int res = INT_MAX;
        
        for(auto [key, val]: pos) {
            int sec = 0;
            val.push_back(val[0] + n);
            
            for(int i = 1; i < val.size(); i++) {
                sec = max(sec, (val[i] - val[i - 1])/ 2);
            }
            
            res = min(res, sec);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2808.md" >}}
---
{{< youtube NgWw6HIyCWE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2810: Faulty Keyboard](https://grid47.xyz/leetcode/solution-2810-faulty-keyboard/) |
| --- |
