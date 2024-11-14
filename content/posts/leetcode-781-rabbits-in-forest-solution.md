
+++
authors = ["grid47"]
title = "Leetcode 781: Rabbits in Forest"
date = "2024-08-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 781: Rabbits in Forest in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/rabbits-in-forest/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/781.webp" 
    alt="A forest where rabbits are hiding, with each rabbit's position glowing softly as it’s found."
    caption="Solution to LeetCode 781: Rabbits in Forest Problem"
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
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> c;
        for(int i: answers)
        c[i]++;
        int res = 0;
        for(auto i : c) res += (i.second + i.first) / (i.first + 1) * (i.first + 1);
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/781.md" >}}
---
{{< youtube leiSa1i-QrI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #784: Letter Case Permutation](https://grid47.xyz/posts/leetcode-784-letter-case-permutation-solution/) |
| --- |
