
+++
authors = ["grid47"]
title = "Leetcode 823: Binary Trees With Factors"
date = "2024-08-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 823: Binary Trees With Factors in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Dynamic Programming","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "vzjMGYUG7qY"
youtube_upload_date="2021-03-13"
youtube_thumbnail="https://i.ytimg.com/vi/vzjMGYUG7qY/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/binary-trees-with-factors/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, long> rootWithCount;
        rootWithCount[arr[0]] = 1;
        for(int i = 0; i < arr.size(); i++) {
            long count = 1;
            for(auto j : rootWithCount) {
                int root = j.first;
                if((arr[i] % root == 0) && (rootWithCount.find(arr[i]/root) != rootWithCount.end())) {
                    count += rootWithCount[root] * rootWithCount[arr[i]/root];
                }
            }
            rootWithCount[arr[i]] = count;
        }
        int no = 0;
        for(auto it: rootWithCount) no = (no + it.second) % (int)(1e9+7);
        return no;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/823.md" >}}
---
{{< youtube vzjMGYUG7qY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #824: Goat Latin](https://grid47.xyz/leetcode/solution-824-goat-latin/) |
| --- |