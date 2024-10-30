
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2135: Count Words Obtained After Adding a Letter"
date = "2018-12-27"
description = "Solution to Leetcode 2135"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/description/)

---
{{< youtube nan >}}
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

