
+++
authors = ["Crafted by Me"]
title = "Leetcode 2135: Count Words Obtained After Adding a Letter"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2135: Count Words Obtained After Adding a Letter in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2136: Earliest Possible Day of Full Bloom](https://grid47.xyz/posts/leetcode_2136) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

