
+++
authors = ["grid47"]
title = "Leetcode 1865: Finding Pairs With a Certain Sum"
date = "2024-05-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1865: Finding Pairs With a Certain Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Design"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "T4yZIHISIYY"
youtube_upload_date="2021-05-16"
youtube_thumbnail="https://i.ytimg.com/vi_webp/T4yZIHISIYY/maxresdefault.webp"
comments = true
+++



---
You are given two integer arrays nums1 and nums2. Your task is to implement a data structure that supports two types of operations: 1) Add a value to an element in nums2. 2) Count the number of pairs (i, j) such that nums1[i] + nums2[j] equals a given total value.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integer arrays nums1 and nums2. The operations you will perform on these arrays are add(index, val) and count(tot).
- **Example:** `[[2, 2, 3, 3, 3, 4], [2, 5, 6, 3, 6, 5]]`
- **Constraints:**
	- 1 <= nums1.length <= 1000
	- 1 <= nums2.length <= 10^5
	- 1 <= nums1[i], nums2[i] <= 10^9
	- 0 <= index < nums2.length
	- 1 <= val <= 10^5
	- 1 <= tot <= 10^9
	- At most 1000 calls to add and count

{{< dots >}}
### Output Specifications 📤
- **Output:** The output consists of results for each count operation, representing the number of valid pairs where nums1[i] + nums2[j] equals the given total.
- **Example:** `[null, 10, null, 3, 2, null, null, 15]`
- **Constraints:**
	- For each count operation, return the count of valid pairs.

{{< dots >}}
### Core Logic 🔍
**Goal:** Efficiently count pairs for each query and update the nums2 array with add operations.

- Use a hash map to store the frequency of elements in nums2.
- For each count operation, iterate through nums1 and check how many values in nums2 match the required sum.
- For add operations, update the corresponding value in nums2 and adjust the frequency map.
{{< dots >}}
### Problem Assumptions ✅
- The input arrays nums1 and nums2 are valid and within the constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `[[2, 2, 3, 3, 3, 4], [2, 5, 6, 3, 6, 5]]`  \
  **Explanation:** In this example, there are multiple pairs that sum to the target values, and after performing add operations, the pairs change.

{{< dots >}}
## Approach 🚀
The approach involves using a hash map to track the frequencies of elements in nums2 and efficiently counting pairs using this map.

### Initial Thoughts 💭
- We need an efficient way to count pairs where nums1[i] + nums2[j] == tot.
- The add operation needs to efficiently update the frequency map for nums2.
{{< dots >}}
### Edge Cases 🌐
- If nums2 is empty, the count will always return 0.
- For very large arrays, the algorithm needs to efficiently handle updates and counts.
- Handle cases where the sum of nums1[i] and nums2[j] is very large.
- Ensure that the frequency map is updated correctly for each add operation.
{{< dots >}}
## Code 💻
```cpp
vector<int> nums1, nums2;
vector<vector<int>> mtx;
map<int, int> mp;
int m, n;
FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
    this->nums1 = nums1;
    this->nums2 = nums2;
    m = nums2.size(), n = nums1.size();
    for(int i = 0; i < nums2.size(); i++) {
            mp[nums2[i]]++;
    }
}

void add(int index, int val) {
    int key = nums2[index];
    nums2[index] += val;
    mp[key]--;
    mp[nums2[index]]++;
}

int count(int tot) {
    int res = 0;
    for(int i = 0; i < n; i++) {
        res += mp[tot - nums1[i]];
    }
    return res;
}
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
```

This code defines a class `FindSumPairs` that is used to manage two integer vectors `nums1` and `nums2`. The class provides two main operations: adding a value to an element in `nums2` and counting the number of pairs that sum up to a given total. The internal data structure `map<int, int> mp` is used to store the frequency of each number in `nums2`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	vector<int> nums1, nums2;
	```
	Declare two integer vectors `nums1` and `nums2`, which will be used to store the input arrays.

2. **Variable Declaration**
	```cpp
	vector<vector<int>> mtx;
	```
	Declare a 2D vector `mtx`, although it is not used in the current code snippet.

3. **Variable Declaration**
	```cpp
	map<int, int> mp;
	```
	Declare a map `mp` that will store the frequency of each element in `nums2`.

4. **Variable Declaration**
	```cpp
	int m, n;
	```
	Declare two integer variables `m` and `n` to store the sizes of `nums2` and `nums1` respectively.

5. **Constructor Definition**
	```cpp
	FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
	```
	Define the constructor for the `FindSumPairs` class, which initializes the vectors `nums1` and `nums2`, and populates the map `mp` with the frequency of elements in `nums2`.

6. **Member Initialization**
	```cpp
	    this->nums1 = nums1;
	```
	Initialize the member variable `nums1` with the value of the input vector `nums1`.

7. **Member Initialization**
	```cpp
	    this->nums2 = nums2;
	```
	Initialize the member variable `nums2` with the value of the input vector `nums2`.

8. **Size Assignment**
	```cpp
	    m = nums2.size(), n = nums1.size();
	```
	Assign the size of `nums2` to `m` and the size of `nums1` to `n`.

9. **Loop Initialization**
	```cpp
	    for(int i = 0; i < nums2.size(); i++) {
	```
	Start a loop to iterate through the elements of `nums2` to populate the frequency map `mp`.

10. **Map Update**
	```cpp
	            mp[nums2[i]]++;
	```
	For each element in `nums2`, increment its corresponding frequency in the map `mp`.

11. **Function Definition**
	```cpp
	void add(int index, int val) {
	```
	Define the `add` function, which modifies an element in `nums2` at the specified index and updates the frequency map `mp`.

12. **Retrieve Key**
	```cpp
	    int key = nums2[index];
	```
	Retrieve the value at the given index in `nums2` and store it in `key`.

13. **Modify Element**
	```cpp
	    nums2[index] += val;
	```
	Increase the value of the element in `nums2` at the given index by `val`.

14. **Map Update (Decrement)**
	```cpp
	    mp[key]--;
	```
	Decrement the frequency of the old value in the map `mp`.

15. **Map Update (Increment)**
	```cpp
	    mp[nums2[index]]++;
	```
	Increment the frequency of the new value in the map `mp` after the modification.

16. **Function Definition**
	```cpp
	int count(int tot) {
	```
	Define the `count` function, which returns the number of pairs of elements from `nums1` and `nums2` whose sum equals `tot`.

17. **Result Initialization**
	```cpp
	    int res = 0;
	```
	Initialize the result variable `res` to store the number of pairs found.

18. **Loop Through nums1**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Loop through the elements of `nums1` to check for pairs with elements from `nums2`.

19. **Map Lookup**
	```cpp
	        res += mp[tot - nums1[i]];
	```
	For each element in `nums1`, check if the complement (i.e., `tot - nums1[i]`) exists in the map `mp`. If it does, add its frequency to `res`.

20. **Return Result**
	```cpp
	    return res;
	```
	Return the total count of pairs whose sum equals `tot`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) for add operation if no counting is needed.
- **Average Case:** O(n) for count operation, where n is the length of nums1.
- **Worst Case:** O(n) for each count operation, where n is the length of nums1.

The count operation iterates through nums1 to find matching pairs, while the add operation updates nums2 in constant time.

### Space Complexity 💾
- **Best Case:** O(1) if no updates are needed to the frequency map.
- **Worst Case:** O(m) for the frequency map, where m is the length of nums2.

The space complexity depends on the size of nums2 and the number of unique elements in it.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/finding-pairs-with-a-certain-sum/description/)

---
{{< youtube T4yZIHISIYY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
