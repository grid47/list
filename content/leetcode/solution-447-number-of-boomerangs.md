
+++
authors = ["grid47"]
title = "Leetcode 447: Number of Boomerangs"
date = "2024-09-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 447: Number of Boomerangs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/447.webp"
youtube = "QPsEA1Ls3jQ"
youtube_upload_date="2019-11-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/QPsEA1Ls3jQ/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/number-of-boomerangs/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/447.webp" 
    alt="A series of points where boomerangs are formed, glowing as each boomerang path is traced."
    caption="Solution to LeetCode 447: Number of Boomerangs Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        map<int, int> mp;
        int res = 0;
        for(int i = 0; i < points.size(); i++) {
            for(int j = 0; j < points.size(); j++) {
                int d = getDist(points[i], points[j]);
                mp[d]++;
            }
            for(auto [_, val]: mp)
            res += val * (val - 1);
            mp.clear();
        }
        return res;
    }

    int getDist(vector<int> a, vector<int> b) {
        int x = a[0] - b[0];
        int y = a[1] - b[1];
        return x * x + y * y;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/447.md" >}}
---
{{< youtube QPsEA1Ls3jQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #449: Serialize and Deserialize BST](https://grid47.xyz/leetcode/solution-449-serialize-and-deserialize-bst/) |
| --- |