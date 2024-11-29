
+++
authors = ["grid47"]
title = "Leetcode 2966: Divide Array Into Arrays With Max Difference"
date = "2024-01-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2966: Divide Array Into Arrays With Max Difference in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "XleOio1oJeo"
youtube_upload_date="2024-02-01"
youtube_thumbnail="https://i.ytimg.com/vi/XleOio1oJeo/maxresdefault.jpg"
comments = true
+++



---
You are given an array `nums` of size `n` where `n` is a multiple of 3, and a positive integer `k`. Your task is to divide the array into `n / 3` subarrays, each containing exactly 3 elements, such that the difference between the largest and smallest element in each subarray is less than or equal to `k`. If it's possible to divide the array in this way, return a 2D array containing the subarrays. If it is not possible, return an empty array. If multiple valid divisions exist, return any valid one.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `nums` of size `n` and an integer `k`. The array is divisible by 3 to allow division into valid groups of three elements.
- **Example:** `nums = [1, 3, 4, 8, 7, 9, 3, 5, 1], k = 2`
- **Constraints:**
	- n == nums.length
	- 1 <= n <= 10^5
	- n is a multiple of 3
	- 1 <= nums[i] <= 10^5
	- 1 <= k <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a 2D array containing the subarrays formed by grouping the elements, where each group contains exactly 3 elements, and the difference between the maximum and minimum element in each group is at most `k`. If this is not possible, return an empty array.
- **Example:** `[[1, 1, 3], [3, 4, 5], [7, 8, 9]]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to divide the array into subarrays of size 3 where the difference between the maximum and minimum integers in each group is less than or equal to `k`.

- Sort the array `nums` in ascending order.
- Iterate through the sorted array and try to form subarrays of size 3.
- For each subarray, check if the difference between the largest and smallest element is less than or equal to `k`.
- If all subarrays are valid, return them; otherwise, return an empty array.
{{< dots >}}
### Problem Assumptions ✅
- The array can always be divided into groups of three, as long as the division criteria are met.
- The order of the elements within each subarray can vary, as long as the condition on the difference between the max and min is satisfied.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [1, 3, 4, 8, 7, 9, 3, 5, 1], k = 2`  \
  **Explanation:** The array is first sorted as [1, 1, 3, 3, 4, 5, 7, 8, 9]. The valid subarrays are [[1, 1, 3], [3, 4, 5], [7, 8, 9]]. The difference between the maximum and minimum elements in each subarray is at most 2, so the output is valid.

- **Input:** `Input: nums = [2, 4, 2, 2, 5, 2], k = 2`  \
  **Explanation:** It is impossible to create valid subarrays because one subarray will always have the elements 2 and 5, and 5 - 2 = 3, which is greater than `k = 2`.

{{< dots >}}
## Approach 🚀
Sort the array and check if the difference between the largest and smallest integers in each group is within the allowed limit `k`. If it is, return the groups; otherwise, return an empty array.

### Initial Thoughts 💭
- The array needs to be divided into groups of three integers, which implies that the length of the array is divisible by 3.
- Sorting the array helps ensure that we can check the condition on differences in an ordered manner.
- By sorting the array, we can easily check if any adjacent group of three integers satisfies the condition on the difference.
{{< dots >}}
### Edge Cases 🌐
- The array is guaranteed not to be empty as per the constraints.
- Ensure that the solution efficiently handles the maximum array length (10^5).
- The value of `k` can be large, which may make it difficult to form valid groups, so ensure that this is handled correctly.
- Check if the array length is divisible by 3 and handle cases where it's not.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> divideArray(vector<int>& nums, int k) {
    int size = nums.size();
    if (size % 3 != 0)
        return vector<vector<int>>();

    sort(nums.begin(), nums.end());

    vector<vector<int>> result(size / 3, vector<int>(3));
    int groupIndex = 0;
    for (int i = 0; i < size; i += 3) {
        if (i + 2 < size && nums[i + 2] - nums[i] <= k) {
            result[groupIndex] = { nums[i], nums[i + 1], nums[i + 2] };
            groupIndex++;
        }
        else {
            return vector<vector<int>>();
        }
    }
    return result;
}
```

This code defines a function that divides an array into groups of three integers where the difference between the largest and smallest number in each group does not exceed a given threshold `k`. If such grouping is not possible, it returns an empty vector.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<vector<int>> divideArray(vector<int>& nums, int k) {
	```
	Defines the function `divideArray`, which takes a reference to an array `nums` and an integer `k` as input, returning a 2D vector of integers.

2. **Variable Initialization**
	```cpp
	    int size = nums.size();
	```
	Initializes a variable `size` to store the length of the input array `nums`.

3. **Edge Case Check**
	```cpp
	    if (size % 3 != 0)
	```
	Checks if the size of the array is a multiple of 3. If not, the array cannot be divided into groups of three.

4. **Return Empty Case**
	```cpp
	        return vector<vector<int>>();
	```
	Returns an empty 2D vector if the size of the array is not divisible by 3.

5. **Sorting**
	```cpp
	    sort(nums.begin(), nums.end());
	```
	Sorts the input array `nums` in ascending order to facilitate grouping the numbers.

6. **Result Initialization**
	```cpp
	    vector<vector<int>> result(size / 3, vector<int>(3));
	```
	Initializes the `result` 2D vector, which will hold the groups of three integers.

7. **Group Index Initialization**
	```cpp
	    int groupIndex = 0;
	```
	Initializes a variable `groupIndex` to keep track of the current index in the `result` vector.

8. **Loop Through Elements**
	```cpp
	    for (int i = 0; i < size; i += 3) {
	```
	Begins a loop that iterates through the sorted array, stepping by 3 elements each time to form groups.

9. **Group Validation**
	```cpp
	        if (i + 2 < size && nums[i + 2] - nums[i] <= k) {
	```
	Checks if the group of three consecutive elements has a difference between the largest and smallest element less than or equal to `k`.

10. **Group Assignment**
	```cpp
	            result[groupIndex] = { nums[i], nums[i + 1], nums[i + 2] };
	```
	Assigns the current group of three numbers to the `result` vector at the current `groupIndex`.

11. **Group Index Increment**
	```cpp
	            groupIndex++;
	```
	Increments the `groupIndex` to move to the next position in the `result` vector for the next group.

12. **Return Empty Case**
	```cpp
	        else {
	```
	Handles the case where the group of numbers cannot be formed because the difference between the largest and smallest number is greater than `k`.

13. **Return Empty**
	```cpp
	            return vector<vector<int>>();
	```
	Returns an empty 2D vector if the group is invalid.

14. **Return Result**
	```cpp
	    return result;
	```
	Returns the `result` vector containing all the valid groups formed from the array.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The dominant factor is the sorting operation, which takes O(n log n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

We need extra space to store the subarrays, which in the worst case is proportional to the size of the input.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/)

---
{{< youtube XleOio1oJeo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
