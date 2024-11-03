
+++
authors = ["Crafted by Me"]
title = "Leetcode 1095: Find in Mountain Array"
date = "2021-11-03"
description = "In-depth solution and explanation for Leetcode 1095: Find in Mountain Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-in-mountain-array/description/)

---

**Code:**

{{< highlight cpp >}}
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int len;
    map<int, int> mp;
    
    int get(int idx, MountainArray &arr) {
        if(idx < 0 || idx == len) return INT_MIN;
        if(mp.count(idx)) return mp[idx];
        return mp[idx] = arr.get(idx);
    }
    
    int search(int l, int r, int hit, MountainArray &arr, bool inc) {
        int ans = -1;
        while(l <= r) {
            int mid = l + (r - l + 1) / 2;
            int val = get(mid, arr);
            if(val == hit) return mid;
            if(val < hit) {
                if(inc) {
                    l = mid + 1;
                } else r = mid - 1;
            } else {
                if(inc) r = mid - 1;
                else l = mid + 1;
            }
        }
        return ans;
    }
    
    int findInMountainArray(int hit, MountainArray &arr) {
        int l = 0, r = arr.length();
        len = r;
        int peak = -1;
        while(l <= r) {
            int mid = l + (r - l + 1) / 2;
            int val = get(mid, arr);
            int left  = get(mid - 1, arr);
            int right = get(mid + 1, arr);            
            if(val > left && val > right) {
                peak = mid;
                break;
            }
            if(left < val && val < right) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        int r1 = search(0, peak, hit, arr, true);
        int r2 = search(peak, len - 1, hit, arr, false);
        if(r1 != -1) return r1;
        if(r2 != -1) return r2;
        return -1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1095.md" >}}
---


"| 1096: Brace Expansion II |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

