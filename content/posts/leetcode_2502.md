
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2502: Design Memory Allocator"
date = "2017-12-25"
description = "Solution to Leetcode 2502"
tags = [
    
]
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

