
+++
authors = ["Yasir"]
title = "Leetcode 703: Kth Largest Element in a Stream"
date = "2022-11-24"
description = "Solution to Leetcode 703"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/kth-largest-element-in-a-stream/description/)

---

**Code:**

{{< highlight html >}}
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto x: nums) {
            pq.push(x);
            if(pq.size() > k) {
                cout << pq.top();
                pq.pop();
            }

        }

    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k) {
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
{{< /highlight >}}

