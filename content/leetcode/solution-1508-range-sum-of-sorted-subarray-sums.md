
+++
authors = ["grid47"]
title = "Leetcode 1508: Range Sum of Sorted Subarray Sums"
date = "2024-06-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1508: Range Sum of Sorted Subarray Sums in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "7XTGlO6b16A"
youtube_upload_date="2024-08-04"
youtube_thumbnail="https://i.ytimg.com/vi/7XTGlO6b16A/maxresdefault.jpg"
comments = true
+++



---
You are given an array of positive integers. Compute all possible subarray sums, sort them in non-decreasing order, and return the sum of elements from index left to right in the sorted array modulo 10^9 + 7.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array of size n, and you are asked to compute the sum of all non-empty subarrays, sort them, and then return a specific sum from the sorted array.
- **Example:** `nums = [1, 2, 3, 4], n = 4, left = 1, right = 5`
- **Constraints:**
	- 1 <= nums.length <= 1000
	- 1 <= nums[i] <= 100
	- 1 <= left <= right <= n * (n + 1) / 2

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a single integer, which is the sum of the elements from index left to right in the sorted list of all subarray sums, modulo 10^9 + 7.
- **Example:** `13`
- **Constraints:**
	- The output should be returned modulo 10^9 + 7.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the sum of all subarrays, sort them, and compute the sum of the elements within the specified range.

- Step 1: Generate all subarray sums by iterating over all pairs of indices in the array.
- Step 2: Sort the subarray sums in non-decreasing order.
- Step 3: Return the sum of the elements from index left to right in the sorted list, modulo 10^9 + 7.
{{< dots >}}
### Problem Assumptions ✅
- The input array will always be non-empty and consist of positive integers.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [1, 2, 3, 4], n = 4, left = 1, right = 5`  \
  **Explanation:** After sorting the subarray sums, the sum of elements from index 1 to 5 is 13.

- **Input:** `nums = [1, 2, 3, 4], n = 4, left = 3, right = 4`  \
  **Explanation:** After sorting the subarray sums, the sum of elements from index 3 to 4 is 6.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to calculate all subarray sums, sort them, and then compute the sum of the elements in the sorted array for the specified range.

### Initial Thoughts 💭
- Sorting all subarray sums can be time-consuming, especially with large input sizes.
- Efficiently compute the subarray sums and handle sorting to avoid excessive time complexity.
{{< dots >}}
### Edge Cases 🌐
- If the input array is empty, the result should be 0.
- Ensure the solution can handle the maximum array size efficiently.
- Consider cases where the array contains identical elements or where there are small subarrays.
- The input array should respect the given constraints.
{{< dots >}}
## Code 💻
```cpp
int mod = (int) 1e9 + 7;
int rangeSum(vector<int>& nums, int n, int left, int right) {
    // binary search
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum = (sum + nums[j]) % mod;                
            ans.push_back(sum);
        }
    }
    
    sort(ans.begin(), ans.end());
    
    int res = 0;
    for(int i = left - 1; i < right; i++)
        res = (res + ans[i]) % mod;
    
    return res;
    
}
```

This code defines the `rangeSum` function, which calculates the sum of subarrays within a specified range [left, right] after sorting all possible subarray sums. The sum is computed modulo 1e9 + 7 to prevent overflow.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Constant Initialization**
	```cpp
	int mod = (int) 1e9 + 7;
	```
	Initializes the constant `mod` with the value 1e9 + 7, which is used to take the modulo of the sums to avoid overflow.

2. **Function Definition**
	```cpp
	int rangeSum(vector<int>& nums, int n, int left, int right) {
	```
	Defines the `rangeSum` function which takes a vector `nums`, its size `n`, and two integers `left` and `right` to calculate the sum of subarrays between indices `left` and `right`.

3. **Variable Initialization**
	```cpp
	    vector<int> ans;
	```
	Initializes an empty vector `ans` that will store the sums of all possible subarrays.

4. **Loop Initialization**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Starts a loop that iterates over all the elements of the input array `nums`.

5. **Variable Initialization**
	```cpp
	        int sum = 0;
	```
	Initializes a variable `sum` to 0, which will store the sum of the current subarray.

6. **Nested Loop**
	```cpp
	        for(int j = i; j < n; j++) {
	```
	Starts a nested loop that iterates through the elements of `nums`, starting from index `i`.

7. **Subarray Sum Calculation**
	```cpp
	            sum = (sum + nums[j]) % mod;                
	```
	Calculates the sum of the current subarray by adding `nums[j]` and taking the result modulo `mod`.

8. **Vector Update**
	```cpp
	            ans.push_back(sum);
	```
	Pushes the current subarray sum to the vector `ans`.

9. **Sorting**
	```cpp
	    sort(ans.begin(), ans.end());
	```
	Sorts the vector `ans` containing the subarray sums in ascending order.

10. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	Initializes `res` to 0, which will store the sum of the subarray sums in the specified range.

11. **Loop**
	```cpp
	    for(int i = left - 1; i < right; i++)
	```
	Iterates over the sorted vector `ans` from the `left - 1` to `right - 1` to select the required subarray sums.

12. **Sum Calculation**
	```cpp
	        res = (res + ans[i]) % mod;
	```
	Adds the current subarray sum to `res` and takes the result modulo `mod` to prevent overflow.

13. **Return**
	```cpp
	    return res;
	```
	Returns the final result, which is the sum of subarray sums in the specified range [left, right], modulo 1e9 + 7.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2 log n)
- **Average Case:** O(n^2 log n)
- **Worst Case:** O(n^2 log n)

The time complexity is dominated by the sorting step, which is O(n^2 log n).

### Space Complexity 💾
- **Best Case:** O(n^2)
- **Worst Case:** O(n^2)

The space complexity is O(n^2) because we store all subarray sums.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/description/)

---
{{< youtube 7XTGlO6b16A >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
