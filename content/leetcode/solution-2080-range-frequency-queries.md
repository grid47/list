
+++
authors = ["grid47"]
title = "Leetcode 2080: Range Frequency Queries"
date = "2024-04-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2080: Range Frequency Queries in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Design","Segment Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "1gZinwGx3lk"
youtube_upload_date="2021-11-21"
youtube_thumbnail="https://i.ytimg.com/vi/1gZinwGx3lk/maxresdefault.jpg"
comments = true
+++



---
Design a data structure that allows you to efficiently find the frequency of a given value in a subarray. Implement the class `RangeFreqQuery` with the following methods:

- `RangeFreqQuery(int[] arr)` initializes the data structure.
- `int query(int left, int right, int value)` returns the frequency of `value` in the subarray from `left` to `right`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the following:

- `arr`: a 0-indexed integer array.
- `query`: a list of queries where each query is represented by three integers: `left`, `right`, and `value`.
- **Example:** `[[1, 2, 3, 4, 2, 5, 3, 2], [2, 4, 2], [1, 6, 3]]`
- **Constraints:**
	- 1 <= arr.length <= 10^5
	- 1 <= arr[i], value <= 10^4
	- 0 <= left <= right < arr.length
	- At most 10^5 calls will be made to query.

{{< dots >}}
### Output Specifications 📤
- **Output:** For each query, return the frequency of `value` in the subarray `arr[left...right]`.
- **Example:** `[null, 2, 2]`
- **Constraints:**
	- The result for each query should be an integer representing the frequency of `value` in the subarray.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to efficiently find the frequency of a specific value in a given subarray.

- Create a map to store the indices of each value in the array.
- For each query, use binary search to find the range of indices where the value appears in the subarray.
{{< dots >}}
### Problem Assumptions ✅
- The array is 0-indexed and the queries are based on 0-indexed positions.
{{< dots >}}
## Examples 🧩
- **Input:** `[[1, 2, 3, 4, 2, 5, 3, 2], [2, 4, 2], [1, 6, 3]]`  \
  **Explanation:** The first query returns `2` because the value `2` appears twice in the subarray [3, 4, 2]. The second query returns `2` because the value `3` appears twice in the subarray [2, 3, 4, 2, 5, 3].

{{< dots >}}
## Approach 🚀
To solve the problem efficiently, we store the indices of each element in the array. For each query, we perform binary search to find the range of indices where the element occurs, then count the number of occurrences in the given subarray.

### Initial Thoughts 💭
- Storing indices of each value allows us to quickly look up occurrences within a specific range.
- We need to handle multiple queries efficiently by preprocessing the array.
{{< dots >}}
### Edge Cases 🌐
- If the array is empty, no queries should be processed.
- Handle large arrays efficiently by using binary search for each query.
- If the value does not appear in the subarray, return 0.
- Ensure the solution can handle up to 10^5 queries efficiently.
{{< dots >}}
## Code 💻
```cpp
map<int, vector<int>> mp;
RangeFreqQuery(vector<int>& arr) {
    for(int i = 0; i < arr.size(); i++) {
        mp[arr[i]].push_back(i);
    }
}

int query(int left, int right, int value) {
    return upper_bound(mp[value].begin(), mp[value].end(), right) -             
        lower_bound(mp[value].begin(), mp[value].end(), left);
}
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
```

This code defines a class for range frequency queries. It stores the indices of each element in a map for efficient range queries and implements a `query` function to return the frequency of a given value within a specific range.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	map<int, vector<int>> mp;
	```
	This line declares a map `mp` where each key is an integer and its value is a vector of integers, used to store the indices of occurrences of each number in the input array.

2. **Constructor Definition**
	```cpp
	RangeFreqQuery(vector<int>& arr) {
	```
	This is the constructor for the `RangeFreqQuery` class, which initializes the map `mp` by iterating over the input array `arr`.

3. **For Loop**
	```cpp
	    for(int i = 0; i < arr.size(); i++) {
	```
	This `for` loop iterates through the input array `arr` to populate the map `mp` with the indices of each element in the array.

4. **Map Update**
	```cpp
	        mp[arr[i]].push_back(i);
	```
	This line adds the current index `i` to the vector corresponding to the element `arr[i]` in the map `mp`. This helps track the positions where each value occurs in the array.

5. **Method Definition**
	```cpp
	int query(int left, int right, int value) {
	```
	This is the definition of the `query` method, which takes a range `[left, right]` and a target `value`, and returns the frequency of `value` within the specified range.

6. **Range Query Logic**
	```cpp
	    return upper_bound(mp[value].begin(), mp[value].end(), right) -             
	```
	This line uses `upper_bound` to find the first index greater than `right` for the target `value` in the map. It calculates the number of occurrences of `value` up to `right`.

7. **Range Query Logic**
	```cpp
	        lower_bound(mp[value].begin(), mp[value].end(), left);
	```
	This line uses `lower_bound` to find the first index greater than or equal to `left`. The difference between the results of `upper_bound` and `lower_bound` gives the number of occurrences of `value` within the range `[left, right]`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) if the value does not appear in the array.
- **Average Case:** O(log n) per query due to binary search.
- **Worst Case:** O(log n) per query, where n is the number of occurrences of the value.

The time complexity is dominated by the binary search operations on the indices.

### Space Complexity 💾
- **Best Case:** O(n) if all values are unique and stored separately.
- **Worst Case:** O(n) for storing the indices of each value in the map.

Space complexity depends on the size of the input array and the number of distinct values.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/range-frequency-queries/description/)

---
{{< youtube 1gZinwGx3lk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
