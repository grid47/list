
+++
authors = ["grid47"]
title = "Leetcode 2261: K Divisible Elements Subarrays"
date = "2024-03-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2261: K Divisible Elements Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Trie","Rolling Hash","Hash Function","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "BZdbRvIM-js"
youtube_upload_date="2022-05-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/BZdbRvIM-js/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/k-divisible-elements-subarrays/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        
        int res = 0, n = nums.size();
        vector<int> cnt(201, 0); vector<long long> hash(201, 0);
        for (int sz = 0; sz < n; sz++) {
            unordered_set<int> s;
            for(int i = 0; i + sz < n; i++){

cnt[i] += ((nums[i + sz] % p) == 0);
            if(cnt[i] <= k) {
hash[i] = (hash[i] * 200 + nums[i + sz]) % 1000000007;
                res += s.insert(hash[i]).second;
            }
        }
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2261.md" >}}
---
{{< youtube BZdbRvIM-js >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2264: Largest 3-Same-Digit Number in String](https://grid47.xyz/leetcode/solution-2264-largest-3-same-digit-number-in-string/) |
| --- |
