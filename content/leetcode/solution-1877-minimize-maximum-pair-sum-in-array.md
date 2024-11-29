
+++
authors = ["grid47"]
title = "Leetcode 1877: Minimize Maximum Pair Sum in Array"
date = "2024-05-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1877: Minimize Maximum Pair Sum in Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "gAzUiJ1ylQc"
youtube_upload_date="2021-05-29"
youtube_thumbnail="https://i.ytimg.com/vi_webp/gAzUiJ1ylQc/maxresdefault.webp"
comments = true
+++



---
Given an array `nums` of even length `n`, your task is to pair up the elements of the array into `n / 2` pairs such that the maximum pair sum is minimized. A pair sum is defined as the sum of two elements in a pair. The goal is to minimize the largest of these pair sums.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array `nums` consisting of `n` integers.
- **Example:** `For nums = [1, 9, 2, 8].`
- **Constraints:**
	- 2 <= n <= 10^5
	- n is even.
	- 1 <= nums[i] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimized maximum pair sum after optimally pairing up the elements.
- **Example:** `For nums = [1, 9, 2, 8], the output is 9.`
- **Constraints:**
	- The output should be an integer representing the minimized maximum pair sum.

{{< dots >}}
### Core Logic 🔍
**Goal:** To minimize the maximum pair sum, the array should be sorted, and pairs should be formed from the smallest and largest elements.

- Sort the array in non-decreasing order.
- Pair the smallest element with the largest element, the second smallest with the second largest, and so on.
- Compute the sum of each pair, and track the maximum sum.
- Return the maximum pair sum.
{{< dots >}}
### Problem Assumptions ✅
- The array contains at least two elements.
- The array length is even, and pairing is always possible.
{{< dots >}}
## Examples 🧩
- **Input:** `For nums = [1, 9, 2, 8].`  \
  **Explanation:** The sorted array is [1, 2, 8, 9]. The optimal pairings are (1, 9) and (2, 8), resulting in pair sums of 10 and 10. The minimized maximum pair sum is 9.

- **Input:** `For nums = [3, 4, 6, 7, 2, 5].`  \
  **Explanation:** The sorted array is [2, 3, 4, 5, 6, 7]. The optimal pairings are (2, 7), (3, 6), and (4, 5), resulting in pair sums of 9, 9, and 8. The minimized maximum pair sum is 8.

{{< dots >}}
## Approach 🚀
To solve this problem, we first sort the array in ascending order and then pair the smallest elements with the largest ones. This minimizes the maximum sum of any pair.

### Initial Thoughts 💭
- Sorting the array ensures that pairing the smallest and largest elements minimizes the maximum sum.
- By pairing extreme values, we balance the sums to reduce the largest possible pair sum.
{{< dots >}}
### Edge Cases 🌐
- Not applicable, as the input array is guaranteed to have an even length and at least two elements.
- The algorithm should efficiently handle arrays with up to 100,000 elements.
- Arrays where all elements are the same value.
- Ensure the array length is even.
{{< dots >}}
## Code 💻
```cpp
int minPairSum(vector<int>& A) {
    sort(A.begin(), A.end());
    int res = 0, n = A.size();
    for (int i = 0; i < n / 2; ++i)
        res = max(res, A[i] + A[n - i - 1]);
    return res;        
}
```

This code calculates the minimum possible value of the maximum pair sum for a vector of integers by sorting the array and pairing the smallest and largest elements.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minPairSum(vector<int>& A) {
	```
	Define a function to compute the minimum possible maximum pair sum of an array.

2. **Sort**
	```cpp
	    sort(A.begin(), A.end());
	```
	Sort the array to enable pairing of smallest and largest elements.

3. **Initialization**
	```cpp
	    int res = 0, n = A.size();
	```
	Initialize the result variable and store the size of the array.

4. **Loop**
	```cpp
	    for (int i = 0; i < n / 2; ++i)
	```
	Iterate through the first half of the array to form pairs with elements from the end.

5. **Update Result**
	```cpp
	        res = max(res, A[i] + A[n - i - 1]);
	```
	Calculate the pair sum and update the result with the maximum pair sum encountered so far.

6. **Return**
	```cpp
	    return res;        
	```
	Return the minimum possible value of the maximum pair sum.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is O(n log n) due to the sorting step.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) for storing the sorted array, or O(1) if sorting in place.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/description/)

---
{{< youtube gAzUiJ1ylQc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
