
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1146: Snapshot Array"
date = "2021-09-09"
description = "Solution to Leetcode 1146"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

