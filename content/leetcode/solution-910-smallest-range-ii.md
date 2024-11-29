
+++
authors = ["grid47"]
title = "Leetcode 910: Smallest Range II"
date = "2024-08-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 910: Smallest Range II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
You are given an integer array `nums` and an integer `k`. For each element in `nums`, you can either add or subtract `k`. The score of the array is calculated as the difference between the maximum and minimum elements of the modified array. Your task is to find and return the minimum possible score after modifying the values in the array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `nums` and an integer `k`.
- **Example:** `Input: nums = [5, 8], k = 3`
- **Constraints:**
	- 1 <= nums.length <= 10^4
	- 0 <= nums[i] <= 10^4
	- 0 <= k <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum score of the array after modifying the values of the elements.
- **Example:** `Output: 4`
- **Constraints:**
	- The returned score should be the smallest possible score after modifying the array.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to minimize the score of the array by appropriately modifying each element with either addition or subtraction of `k`.

- Sort the input array `nums` to arrange the elements in ascending order.
- Initialize the left boundary as `nums[0] + k` and the right boundary as `nums[n-1] - k`.
- Iterate through the sorted array and compute the new score by adjusting each element by either adding or subtracting `k`.
- Track the minimum score by updating the result after each modification.
{{< dots >}}
### Problem Assumptions ✅
- The array is non-empty, with at least one element.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [5, 8], k = 3`  \
  **Explanation:** In this case, changing the values of `5` and `8` by adding or subtracting `3` gives [2, 11]. The score is the difference between the maximum and minimum, which is 11 - 2 = 9.

- **Input:** `Input: nums = [2, 4, 7], k = 1`  \
  **Explanation:** Here, changing the values of `2`, `4`, and `7` results in [3, 3, 6]. The score is the difference between the maximum and minimum, which is 6 - 3 = 3.

{{< dots >}}
## Approach 🚀
The strategy is to first sort the array, then evaluate the minimum score by adjusting each element's value with `k` and updating the score based on the adjusted maximum and minimum values.

### Initial Thoughts 💭
- By sorting the array, we can ensure that the largest and smallest elements are easy to access and modify.
- The key observation is that modifying the largest and smallest values with `k` can significantly affect the score.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs in this problem as the length of `nums` is always at least 1.
- For large inputs, the algorithm must handle arrays of length up to 10^4 efficiently.
- If `k` is 0, the array remains unchanged, and the score is simply the difference between the maximum and minimum elements.
- Ensure that the solution handles arrays with values at the upper limit (10^4) correctly.
{{< dots >}}
## Code 💻
```cpp
class Solution {

public:
int smallestRangeII(vector<int>& nums, int k) {
    
    sort(nums.begin(), nums.end());
    int n = nums.size(), left = nums[0] + k, right = nums[n - 1] - k;
    
    int res = nums[n - 1] - nums[0];
    for(int i = 0; i < n - 1; i++) {
        int maxi = max(nums[i] + k, right);
        int mini = min(nums[i + 1] - k, left);
        res = min(res, maxi - mini);
    }
    
    return res;
}

```

This code defines a solution for finding the smallest range after modifying the elements of the input array based on a value `k`. The logic sorts the array, then calculates the minimum difference possible by adjusting the elements using the value of `k`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Code Block**
	```cpp
	class Solution {
	```
	The class definition for `Solution`, which contains the method for solving the problem.

2. **Access Modifier**
	```cpp
	public:
	```
	The access modifier that makes the following method accessible from outside the class.

3. **Function Declaration**
	```cpp
	int smallestRangeII(vector<int>& nums, int k) {
	```
	The declaration of the method `smallestRangeII`, which takes an integer vector `nums` and an integer `k` and returns an integer value.

4. **Sorting**
	```cpp
	    sort(nums.begin(), nums.end());
	```
	Sorts the input vector `nums` to simplify the process of calculating the smallest range after modifying elements.

5. **Variable Initialization**
	```cpp
	    int n = nums.size(), left = nums[0] + k, right = nums[n - 1] - k;
	```
	Initializes variables: `n` (the size of `nums`), `left` (the modified value of the smallest element), and `right` (the modified value of the largest element).

6. **Variable Initialization**
	```cpp
	    int res = nums[n - 1] - nums[0];
	```
	Calculates the initial difference between the largest and smallest elements in the sorted array, which is the starting value for the smallest range.

7. **Loop**
	```cpp
	    for(int i = 0; i < n - 1; i++) {
	```
	A loop to iterate through the array to calculate the smallest possible range by adjusting elements using `k`.

8. **Computation**
	```cpp
	        int maxi = max(nums[i] + k, right);
	```
	Calculates the maximum value for the current range, considering the modified `nums[i]` and `right`.

9. **Computation**
	```cpp
	        int mini = min(nums[i + 1] - k, left);
	```
	Calculates the minimum value for the current range, considering the modified `nums[i + 1]` and `left`.

10. **Computation**
	```cpp
	        res = min(res, maxi - mini);
	```
	Updates the result `res` with the minimum range found between `maxi` and `mini`.

11. **Return Statement**
	```cpp
	    return res;
	```
	Returns the smallest range found after processing the entire array.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting step, which takes O(n log n), where n is the number of elements in the array.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

In the worst case, the space complexity is O(n) due to the sorting operation. However, the space complexity can be reduced to O(1) if sorting is done in-place.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/smallest-range-ii/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
