
+++
authors = ["grid47"]
title = "Leetcode 2817: Minimum Absolute Difference Between Elements With Constraint"
date = "2024-01-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2817: Minimum Absolute Difference Between Elements With Constraint in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Ordered Set"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "iZkBnYIJ9Qc"
youtube_upload_date="2023-08-13"
youtube_thumbnail="https://i.ytimg.com/vi/iZkBnYIJ9Qc/maxresdefault.jpg"
comments = true
+++



---
You are given a 0-indexed integer array nums and an integer x. Find the minimum absolute difference between two elements in the array such that their indices are at least x apart.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array nums and an integer x. The array nums has length n, and the integer x satisfies 0 <= x < n.
- **Example:** `nums = [7, 9, 5, 3], x = 2`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^9
	- 0 <= x < nums.length

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum absolute difference between two elements that are at least x indices apart.
- **Example:** `Output: 0`
- **Constraints:**
	- The output should be a single integer representing the minimum absolute difference.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find two elements in the array that are at least x indices apart and minimize the absolute difference between them.

- 1. Iterate through the array starting from index x.
- 2. Maintain a sorted set of elements within the range of x indices apart.
- 3. For each new element, calculate the absolute difference with the closest elements in the sorted set.
- 4. Keep track of the minimum absolute difference.
{{< dots >}}
### Problem Assumptions ✅
- The array is not empty, and the integer x is valid as per the constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [7, 9, 5, 3], x = 2`  \
  **Explanation:** The minimum absolute difference occurs between nums[0] = 7 and nums[3] = 7, both of which are at least 2 indices apart. The absolute difference is 0, which is the minimum.

{{< dots >}}
## Approach 🚀
We can use a sorted set to efficiently compute the minimum absolute difference between elements that are at least x indices apart.

### Initial Thoughts 💭
- The problem requires checking the difference between elements that are at least x indices apart.
- A sorted set or tree can help efficiently find the minimum difference.
{{< dots >}}
### Edge Cases 🌐
- The input will never be empty as per the constraints.
- For large arrays, the algorithm should efficiently handle up to 10^5 elements.
- When all elements in the array are identical, the minimum difference is 0.
- The algorithm should handle arrays with up to 10^5 elements efficiently.
{{< dots >}}
## Code 💻
```cpp
int minAbsoluteDifference(vector<int>& nums, int x) {
set<int> s;
int res = INT_MAX;
for (int i = x; i < nums.size() && res > 0; ++i) {
    s.insert(nums[i - x]);
    auto it = s.upper_bound(nums[i]);
    if (it != begin(s))
        res = min(res, nums[i] - *prev(it));
    if (it != end(s))
        res = min(res, *it - nums[i]);
}
    return res;
}
```

This function calculates the minimum absolute difference between an element at index 'i' in the array 'nums' and any element at index 'i-x' to 'i'. It utilizes a set to find the closest values efficiently.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Code Block**
	```cpp
	int minAbsoluteDifference(vector<int>& nums, int x) {
	```
	The function definition begins, accepting a vector of integers and an integer 'x' as parameters.

2. **Variable Declaration**
	```cpp
	set<int> s;
	```
	A set 's' is declared to store unique integers encountered during the loop, which will help in efficiently finding the closest values.

3. **Variable Initialization**
	```cpp
	int res = INT_MAX;
	```
	The variable 'res' is initialized to the maximum integer value to track the minimum absolute difference found during the loop.

4. **Loop**
	```cpp
	for (int i = x; i < nums.size() && res > 0; ++i) {
	```
	A loop starts from index 'x' to the end of the 'nums' vector. The loop continues as long as the 'res' is greater than 0, ensuring that the minimum difference will always decrease.

5. **Set Insertion**
	```cpp
	    s.insert(nums[i - x]);
	```
	Insert the element at index 'i-x' into the set 's' to keep track of previous elements within the range of 'x'.

6. **Upper Bound Search**
	```cpp
	    auto it = s.upper_bound(nums[i]);
	```
	The function 'upper_bound' is used to find the first element in the set 's' that is greater than 'nums[i]'.

7. **Condition Check**
	```cpp
	    if (it != begin(s))
	```
	Check if the iterator 'it' is not pointing to the first element in the set, indicating that a smaller element exists.

8. **Minimum Difference Update**
	```cpp
	        res = min(res, nums[i] - *prev(it));
	```
	If a smaller element exists, update 'res' with the minimum of the current 'res' and the absolute difference between 'nums[i]' and the largest smaller element.

9. **Condition Check**
	```cpp
	    if (it != end(s))
	```
	Check if 'it' is not pointing to the end of the set, indicating that a larger element exists.

10. **Minimum Difference Update**
	```cpp
	        res = min(res, *it - nums[i]);
	```
	If a larger element exists, update 'res' with the minimum of the current 'res' and the absolute difference between the larger element and 'nums[i]'.

11. **Return Statement**
	```cpp
	    return res;
	```
	Return the final minimum absolute difference found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The algorithm requires sorting and binary search, making the time complexity O(n log n), where n is the size of the input array.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of the elements in the set or map.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-absolute-difference-between-elements-with-constraint/description/)

---
{{< youtube iZkBnYIJ9Qc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
