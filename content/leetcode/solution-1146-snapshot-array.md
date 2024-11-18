
+++
authors = ["grid47"]
title = "Leetcode 1146: Snapshot Array"
date = "2024-07-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1146: Snapshot Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Design"]
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

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1155: Number of Dice Rolls With Target Sum](https://grid47.xyz/leetcode/solution-1155-number-of-dice-rolls-with-target-sum/) |
| --- |
