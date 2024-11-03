
+++
authors = ["Crafted by Me"]
title = "Leetcode 1146: Snapshot Array"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1146: Snapshot Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/snapshot-array/description/)

---

**Code:**

{{< highlight cpp >}}
class SnapshotArray {
public:

    unordered_map<int, map<int, int>> snaps;
    int snap_id = 0;

    SnapshotArray(int length) {
        for(int i = 0; i < length; i++) {
            map<int, int> mp;
            mp[0] = 0;
            snaps[i] = mp;
        }
    }
    
    void set(int index, int val) {
        snaps[index][snap_id] = val;
    }
    
    int snap() {
        snap_id++;
        return snap_id - 1;
    }
    
    int get(int index, int snid) {
        auto it = snaps[index].upper_bound(snid);
        it--;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1146.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1147: Longest Chunked Palindrome Decomposition](https://grid47.xyz/posts/leetcode_1147) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

