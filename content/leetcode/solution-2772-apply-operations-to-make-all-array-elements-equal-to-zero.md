
+++
authors = ["grid47"]
title = "Leetcode 2772: Apply Operations to Make All Array Elements Equal to Zero"
date = "2024-02-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2772: Apply Operations to Make All Array Elements Equal to Zero in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "xpjC9rt9xsM"
youtube_upload_date="2023-07-09"
youtube_thumbnail="https://i.ytimg.com/vi_webp/xpjC9rt9xsM/maxresdefault.webp"
comments = true
+++



---
You are given a 0-indexed integer array nums and a positive integer k. You can repeatedly select a contiguous subarray of size k and decrease all its elements by 1. Determine if it is possible to make all elements in nums equal to 0 using this operation.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A 0-indexed integer array nums and an integer k.
- **Example:** `nums = [3,3,2,1,0], k = 2`
- **Constraints:**
	- 1 <= k <= nums.length <= 100,000
	- 0 <= nums[i] <= 1,000,000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a boolean value: true if all elements can be made 0, and false otherwise.
- **Example:** `Output: true`
- **Constraints:**
	- Output is either true or false.

{{< dots >}}
### Core Logic 🔍
**Goal:** Check if all elements in the array can be reduced to 0 using the specified operation.

- Iterate through the array while keeping track of the cumulative decrease required to meet the operation conditions.
- At each index, ensure the required decrease does not exceed the current element.
- Adjust the cumulative decrease using a sliding window technique to manage subarrays of size k.
- Return true if all elements can be made 0; otherwise, return false.
{{< dots >}}
### Problem Assumptions ✅
- The operation can be performed any number of times.
- The array elements are non-negative.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [3,2,1,0], k = 2`  \
  **Explanation:** Select the subarray [3,2] to reduce it by 1. Repeat until all elements are 0. The output is true.

- **Input:** `nums = [1,3,1,1], k = 3`  \
  **Explanation:** It is not possible to reduce all elements to 0. The output is false.

{{< dots >}}
## Approach 🚀
Use a greedy algorithm combined with a sliding window to manage the operations efficiently.

### Initial Thoughts 💭
- At each step, only subarrays of size k can be reduced.
- The operation is cumulative and impacts the next elements.
- Keep track of the cumulative decrease to efficiently determine if the operation is valid for each index.
{{< dots >}}
### Edge Cases 🌐
- An empty array is invalid as per constraints.
- Test arrays with the maximum size (100,000) and values to ensure efficiency.
- Test arrays with all elements as 0, which should immediately return true.
- Ensure k is less than or equal to the array size.
{{< dots >}}
## Code 💻
```cpp
bool checkArray(vector<int>& A, int k) {
    int cur = 0, n = A.size();
    for (int i = 0; i < n; ++i) {
        if (cur > A[i])
            return false;
        A[i] -= cur;
        cur += A[i];
        if (i >= k - 1)
            cur -= A[i - k + 1];
    }
    return cur == 0;
}
```

The function `checkArray` checks if it is possible to split the given array into subarrays of size `k` such that the sum of elements in each subarray is the same. It uses a greedy approach to check if the transformation is possible by iterating over the array and adjusting the current value by subtracting and adding the elements in a sliding window manner.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	bool checkArray(vector<int>& A, int k) {
	```
	This line declares the function `checkArray` that accepts a reference to an integer vector `A` and an integer `k`, which represents the size of the subarrays we are considering.

2. **Variable Initialization**
	```cpp
	    int cur = 0, n = A.size();
	```
	The variable `cur` is initialized to 0, which will be used to keep track of the sum of the elements in the sliding window. `n` stores the size of the array `A`.

3. **Looping**
	```cpp
	    for (int i = 0; i < n; ++i) {
	```
	A loop is initiated to iterate through the elements of the array `A` from index `0` to `n-1`.

4. **Conditional Function Call**
	```cpp
	        if (cur > A[i])
	```
	This condition checks if the current value `cur` exceeds the current element `A[i]`. If true, it means the transformation is not possible, so the function returns `false`.

5. **Return Statement**
	```cpp
	            return false;
	```
	If the condition `cur > A[i]` is met, the function immediately returns `false`, indicating that the desired transformation is not possible.

6. **Variable Manipulation**
	```cpp
	        A[i] -= cur;
	```
	The current element `A[i]` is adjusted by subtracting the value of `cur`, essentially modifying the array during the iteration.

7. **Variable Manipulation**
	```cpp
	        cur += A[i];
	```
	The modified value of `A[i]` is added to `cur`, updating the sum of the current window.

8. **Conditional Function Call**
	```cpp
	        if (i >= k - 1)
	```
	This condition checks if the index `i` has reached or exceeded `k - 1`, which marks the point where we begin reducing the window size.

9. **Variable Manipulation**
	```cpp
	            cur -= A[i - k + 1];
	```
	When the condition `i >= k - 1` is true, the value at `A[i - k + 1]` is subtracted from `cur` to shrink the sliding window by removing the effect of the element that has moved out of the window.

10. **Return Statement**
	```cpp
	    return cur == 0;
	```
	After completing the loop, the function returns `true` if `cur` is equal to 0, indicating that the transformation is possible, otherwise `false`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The solution involves a single pass through the array, with constant-time operations per index.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The solution uses a constant amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/apply-operations-to-make-all-array-elements-equal-to-zero/description/)

---
{{< youtube xpjC9rt9xsM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
