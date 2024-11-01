
+++
authors = ["Crafted by Me"]
title = "Leetcode 1287: Element Appearing More Than 25% In Sorted Array"
date = "2021-04-25"
description = "Solution to Leetcode 1287"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
	int findSpecialInteger(vector<int>& arr) {
		unordered_map<int, int> m;
		for(int i = 0; i < arr.size(); i++){
			m[arr[i]]++;
		}
		for(auto i : m){
			if(i.second > arr.size() / 4){
				return i.first;
			}
		}
		return arr[0];
	}
};
{{< /highlight >}}


---
{{< youtube G74W8v2yVjY >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

