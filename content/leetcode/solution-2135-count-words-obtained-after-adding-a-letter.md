
+++
authors = ["grid47"]
title = "Leetcode 2135: Count Words Obtained After Adding a Letter"
date = "2024-04-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2135: Count Words Obtained After Adding a Letter in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Bit Manipulation","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int wordCount(vector<string>& start, vector<string>& end) {
        set<int> bit;
        for(auto it: start) {
            int mask = 0;
            for(char x: it)
                mask |= 1 << (x - 'a');
            bit.insert(mask);
        }
        
        int cnt = 0;
        
        for(auto it: end) {
            int mask = 0;
            for(char x: it)
                mask |= 1 << (x - 'a');
            
            for(int i = 0; i < 26; i++) {
                if(((mask >> i) & 1) == 0) continue;
                int tmp = (mask ^ (1 << i));
                if(bit.count(tmp)) {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2135.md" >}}
---
{{< youtube Ag3bur1amBs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2138: Divide a String Into Groups of Size k](https://grid47.xyz/leetcode/solution-2138-divide-a-string-into-groups-of-size-k/) |
| --- |
