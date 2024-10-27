
+++
authors = ["Yasir"]
title = "Leetcode 2424: Longest Uploaded Prefix"
date = "2018-03-10"
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

{{< highlight html >}}
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

