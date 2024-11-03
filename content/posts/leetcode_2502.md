
+++
authors = ["Crafted by Me"]
title = "Leetcode 2502: Design Memory Allocator"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2502: Design Memory Allocator in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/design-memory-allocator/description/)

---

**Code:**

{{< highlight cpp >}}
class Allocator {
public:
    vector<int> mem;
    map<int, vector<vector<int>>> mp;
    Allocator(int n) {
        mem.resize(n, 0);
        
    }
    
    int allocate(int size, int mID) {
        int idx = 0;
        int cnt = 0;
        while(idx < mem.size()) {
            int j = idx;
            while(j < mem.size() && mem[j] == 0 && cnt < size) {
                cnt++;
                j++;
            }
            if(cnt == size) {
                for(int i = idx; i < idx + size; i++)
                    mem[i] = 1;
                mp[mID].push_back({idx, size});
                return idx;
            }
            while(j < mem.size() && mem[j] == 1) j++;
            cnt = 0;
            idx = j;
        }
        return -1;
    }
    
    int free(int mID) {
        int cnt = 0;
        for(int i = 0; i < mp[mID].size(); i++) {
            auto it = mp[mID][i];
            for(int j = it[0]; j < it[0] + it[1]; j++) {
                mem[j] = 0;                
                cnt++;
            }
        }
        mp.erase(mID);
        return cnt;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */
{{< /highlight >}}


---
{{< youtube ARhX-jazvSY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2503: Maximum Number of Points From Grid Queries](https://grid47.xyz/posts/leetcode_2503) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

