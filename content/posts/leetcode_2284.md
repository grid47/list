
+++
authors = ["Crafted by Me"]
title = "Leetcode 2284: Sender With Largest Word Count"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2284: Sender With Largest Word Count in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sender-with-largest-word-count/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {

        unordered_map<string, int> cnt;
        string res;
        int max_cnt = 0;
        for(int i = 0; i < senders.size(); i++) {
            int words = count(begin(messages[i]), end(messages[i]), ' ') + 1;
            int cur = cnt[senders[i]] += words;
            if((cur > max_cnt) || (cur == max_cnt && senders[i] > res)) {
                res = senders[i];
                max_cnt = cur;
            }
        }

        return res;
    }
};
{{< /highlight >}}


---
{{< youtube j5BlwSyz3F8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2285: Maximum Total Importance of Roads](https://grid47.xyz/posts/leetcode_2285) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

