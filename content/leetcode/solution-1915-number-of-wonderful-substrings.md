
+++
authors = ["grid47"]
title = "Leetcode 1915: Number of Wonderful Substrings"
date = "2024-04-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1915: Number of Wonderful Substrings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Bit Manipulation","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "P6i1qj8DMZk"
youtube_upload_date="2021-06-27"
youtube_thumbnail="https://i.ytimg.com/vi/P6i1qj8DMZk/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/number-of-wonderful-substrings/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        map<int, int> mp;
        mp[0] = 1;
        int msk = 0;
        long long ans = 0;
        for(int i = 0; i < word.size(); i++) {
            
            int idx = word[i] - 'a';
            msk ^= (1 << idx);
            ans += mp[msk];
            for(int j = 0; j < 10; j++) {
                int lf = msk ^ (1 << j);
                ans += mp[lf];
                }
            mp[msk]++;
            }
        
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1915.md" >}}
---
{{< youtube P6i1qj8DMZk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1920: Build Array from Permutation](https://grid47.xyz/leetcode/solution-1920-build-array-from-permutation/) |
| --- |