
+++
authors = ["Crafted by Me"]
title = "Leetcode 911: Online Election"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 911: Online Election in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["Array","Hash Table","Binary Search","Design"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/online-election/description/)

---

**Code:**

{{< highlight cpp >}}
class TopVotedCandidate {
public:
    map<int, int> mp;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = persons.size(), lead = -1;
        unordered_map<int, int> cnt;
        for(int i = 0; i < n; i++) {
            lead = ++cnt[persons[i]] >= cnt[lead]? persons[i] : lead;
            mp[times[i]] = lead;
        }
            
    }
    
    int q(int t) {
        return (--mp.upper_bound(t))->second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/911.md" >}}
---
{{< youtube 6lmMcTr9gbo >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #912: Sort an Array](https://grid47.xyz/posts/leetcode_912) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

