
+++
authors = ["grid47"]
title = "Leetcode 1186: Maximum Subarray Sum with One Deletion"
date = "2024-07-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1186: Maximum Subarray Sum with One Deletion in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "EWCdm1cKtrA"
youtube_upload_date="2024-07-02"
youtube_thumbnail="https://i.ytimg.com/vi/EWCdm1cKtrA/maxresdefault.jpg"
comments = true
+++



---
Given an array of integers, determine the maximum sum of a non-empty contiguous subarray where you are allowed to optionally delete at most one element. The subarray must remain non-empty after any deletion.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array representing the values of elements.
- **Example:** `Input: arr = [2, -4, 3, 7]`
- **Constraints:**
	- 1 <= arr.length <= 10^5
	- -10^4 <= arr[i] <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a single integer representing the maximum sum of the subarray with at most one optional deletion.
- **Example:** `Output: 9`
- **Constraints:**
	- The subarray must remain non-empty.

{{< dots >}}
### Core Logic 🔍
**Goal:** To calculate the maximum sum of a contiguous subarray with the option to delete one element.

- Use dynamic programming to calculate forward maximum sums.
- Compute backward maximum sums for the array.
- Combine results to evaluate maximum sums with one deletion allowed.
{{< dots >}}
### Problem Assumptions ✅
- The input array always contains at least one element.
- Subarray sums may be negative.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: arr = [3, -1, 5, -2]`  \
  **Explanation:** You can choose [3, -1, 5] and optionally remove -1 to maximize the sum to 8.

- **Input:** `Input: arr = [-3, -1, -4]`  \
  **Explanation:** Since all elements are negative, the best subarray is [-1] for a maximum sum of -1.

{{< dots >}}
## Approach 🚀
Use a dynamic programming approach to efficiently compute the maximum subarray sums with and without one deletion.

### Initial Thoughts 💭
- If no deletion is allowed, it reduces to the classic maximum subarray problem.
- To handle one deletion, we need a way to evaluate the subarray sum excluding one element.
- Using forward and backward maximum sums allows us to efficiently compute the result for each potential deletion point.
{{< dots >}}
### Edge Cases 🌐
- N/A - The input is guaranteed to have at least one element.
- An array of length 10^5 with alternating large positive and negative values.
- An array of all negative values.
- An array of all positive values.
- Handling edge cases where the deletion might lead to the highest result.
{{< dots >}}
## Code 💻
```cpp
int maximumSum(vector<int>& arr) {
    int res = 0, n = arr.size();
    int curr_mx = arr[0], overall_mx = arr[0];
    vector<int> f(n), b(n);
    f[0] = arr[0];
    for(int i = 1; i < n; i++) {
        curr_mx = max(arr[i], curr_mx + arr[i]);
        overall_mx = max(curr_mx, overall_mx);
        f[i] = curr_mx;
    }
    
    curr_mx = overall_mx = b[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--){
        curr_mx = max(arr[i], curr_mx + arr[i]);
        overall_mx = max(overall_mx, curr_mx);
        b[i] = curr_mx;
    }
    
    res = overall_mx;
    for(int i = 1; i < n-1; i++) {
        res = max(res, f[i-1]+b[i+1]);
    }
    return res;
}
```

This function calculates the maximum sum of a subarray in the given array `arr` by considering at most one removal of an element. The approach uses dynamic programming to track the maximum sums from both ends of the array and combines them to find the optimal solution.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maximumSum(vector<int>& arr) {
	```
	Define the function `maximumSum` which takes an integer array `arr` as input and returns the maximum sum after removing one element, or keeping the array unchanged.

2. **Variable Initialization**
	```cpp
	    int res = 0, n = arr.size();
	```
	Initialize `res` to store the result and `n` to store the size of the array.

3. **Variable Initialization**
	```cpp
	    int curr_mx = arr[0], overall_mx = arr[0];
	```
	Initialize `curr_mx` and `overall_mx` to the first element of the array. These will track the current and overall maximum sums, respectively.

4. **Array Initialization**
	```cpp
	    vector<int> f(n), b(n);
	```
	Initialize two vectors `f` and `b` to store the maximum sums for each index from the left and right sides, respectively.

5. **Array Assignment**
	```cpp
	    f[0] = arr[0];
	```
	Set the first element of `f` to be the same as the first element of the array `arr`.

6. **Loop**
	```cpp
	    for(int i = 1; i < n; i++) {
	```
	Loop through the array starting from the second element to calculate the maximum subarray sum from the left.

7. **Max Function**
	```cpp
	        curr_mx = max(arr[i], curr_mx + arr[i]);
	```
	Update `curr_mx` to be the maximum of the current element `arr[i]` and the sum of the current element with the previous subarray sum.

8. **Max Function**
	```cpp
	        overall_mx = max(curr_mx, overall_mx);
	```
	Update `overall_mx` to be the maximum of the current subarray sum (`curr_mx`) and the overall maximum sum so far.

9. **Array Assignment**
	```cpp
	        f[i] = curr_mx;
	```
	Assign the current maximum sum `curr_mx` to the `f` vector at index `i`.

10. **Variable Assignment**
	```cpp
	    curr_mx = overall_mx = b[n-1] = arr[n-1];
	```
	Initialize `curr_mx`, `overall_mx`, and `b[n-1]` to the last element of the array `arr`.

11. **Loop**
	```cpp
	    for(int i = n-2; i >= 0; i--){
	```
	Loop through the array starting from the second last element to calculate the maximum subarray sum from the right.

12. **Max Function**
	```cpp
	        curr_mx = max(arr[i], curr_mx + arr[i]);
	```
	Update `curr_mx` to be the maximum of the current element `arr[i]` and the sum of the current element with the previous subarray sum.

13. **Max Function**
	```cpp
	        overall_mx = max(overall_mx, curr_mx);
	```
	Update `overall_mx` to be the maximum of the current subarray sum (`curr_mx`) and the overall maximum sum so far.

14. **Array Assignment**
	```cpp
	        b[i] = curr_mx;
	```
	Assign the current maximum sum `curr_mx` to the `b` vector at index `i`.

15. **Variable Assignment**
	```cpp
	    res = overall_mx;
	```
	Assign the overall maximum sum to `res`.

16. **Loop**
	```cpp
	    for(int i = 1; i < n-1; i++) {
	```
	Loop through the array, skipping the first and last element, to calculate the maximum possible sum by removing one element.

17. **Max Function**
	```cpp
	        res = max(res, f[i-1]+b[i+1]);
	```
	Update `res` to the maximum of the current result and the sum of the left and right maximum sums from vectors `f` and `b`.

18. **Return Statement**
	```cpp
	    return res;
	```
	Return the maximum sum `res`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

Iterating over the array multiple times for forward and backward passes.

### Space Complexity 💾
- **Best Case:** O(1) if the backward pass is combined with a single array.
- **Worst Case:** O(n)

Space can be reduced by combining computations in a single loop.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/description/)

---
{{< youtube EWCdm1cKtrA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
