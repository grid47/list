
+++
authors = ["grid47"]
title = "Leetcode 1620: Coordinate With Maximum Network Quality"
date = "2024-05-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1620: Coordinate With Maximum Network Quality in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "TqKDnzkRsh0"
youtube_upload_date="2020-11-30"
youtube_thumbnail="https://i.ytimg.com/vi/TqKDnzkRsh0/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/coordinate-with-maximum-network-quality/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& tow, int rad) {
        
        int n = tow.size();
    
        int mx = INT_MIN;
        vector<vector<int>> res;
        
        for(int i = 0; i <= 50; i++)
        for(int j = 0; j <= 50; j++) {
            
            int sum = 0;
            for(int k = 0; k < n; k++) {
                int x = tow[k][0], y = tow[k][1];
                float r = sqrt((x - i) * (x - i) + (y - j) * (y - j));
                int ss = 0;
                if(r <= rad) {
                    ss = tow[k][2]/(1 + r);
                }
                sum += ss;
            }
            if(mx < sum) {
                mx = sum;
                res = {{i, j}};
            } else if(mx == sum) {
                res.push_back({i, j});
            }
        }
        sort(res.begin(), res.end());
        return res[0];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1620.md" >}}
---
{{< youtube TqKDnzkRsh0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1621: Number of Sets of K Non-Overlapping Line Segments](https://grid47.xyz/leetcode/solution-1621-number-of-sets-of-k-non-overlapping-line-segments/) |
| --- |