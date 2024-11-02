
+++
authors = ["Crafted by Me"]
title = "Leetcode 2424: Longest Uploaded Prefix"
date = "2018-03-15"
description = "Solution to Leetcode 2424"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-uploaded-prefix/description/)

---

**Code:**

{{< highlight cpp >}}
class LUPrefix {
public:
    int i;
    vector<bool> arr;
    LUPrefix(int n) {
        arr.resize(n + 1);
        i = 1;
    }
    
    void upload(int vid) {
        arr[vid] = true;
        while(i < arr.size() && arr[i]) i++;
    }
    
    int longest() {
        return i - 1;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

