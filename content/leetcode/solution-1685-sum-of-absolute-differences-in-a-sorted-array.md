
+++
authors = ["grid47"]
title = "Leetcode 1685: Sum of Absolute Differences in a Sorted Array"
date = "2024-05-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1685: Sum of Absolute Differences in a Sorted Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "WYe644djV30"
youtube_upload_date="2021-01-04"
youtube_thumbnail="https://i.ytimg.com/vi/WYe644djV30/maxresdefault.jpg"
comments = true
+++



---
You are given a sorted integer array `nums`. Build and return an integer array `result` such that for each index `i`, `result[i]` is equal to the summation of absolute differences between `nums[i]` and all other elements in the array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a sorted integer array `nums`.
- **Example:** `nums = [2, 3, 5]`
- **Constraints:**
	- 2 <= nums.length <= 10^5
	- 1 <= nums[i] <= nums[i + 1] <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an integer array `result` where `result[i]` is the summation of the absolute differences between `nums[i]` and all the other elements in `nums`.
- **Example:** `Output: [4, 3, 5]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the summation of absolute differences for each element of the array `nums`.

- Start by calculating the absolute differences for the first element and store it.
- Then, use an iterative approach to build the result array, where each element `i` is calculated using the differences from the previous element and its neighbors.
{{< dots >}}
### Problem Assumptions ✅
- The array `nums` is already sorted in non-decreasing order.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [2, 4, 6]`  \
  **Explanation:** The result for each element is the sum of absolute differences between the element and all other elements in the array.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to compute the absolute differences efficiently. Since the array is sorted, we can make use of this property to minimize redundant calculations.

### Initial Thoughts 💭
- The array is sorted, which means we can calculate the differences incrementally.
- We can calculate the result iteratively by adjusting the previous result for the current element rather than recalculating the entire sum each time.
{{< dots >}}
### Edge Cases 🌐
- The input array `nums` should not be empty, as the problem defines that the array length is at least 2.
- For large arrays (up to 10^5 elements), the solution needs to be efficient.
- All elements in the array are the same, the result will be an array of zeros since there are no differences.
- Ensure that the solution works within the time limits for the largest input size.
{{< dots >}}
## Code 💻
```cpp
vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    int z = 0, n = nums.size();
    for(int i = 0; i < n; i++)
        z += nums[i] - nums[0];
    vector<int> ans(n, 0);
    ans[0] = z;
    for(int i = 1; i < n; i++)
        ans[i] = ans[i-1] + i * (nums[i] - nums[i-1]) - (n - i)* (nums[i] - nums[i-1]);
    
    return ans;
}
```

This function calculates the sum of absolute differences between each element and every other element in the array for each index, returning a vector of results.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
	```
	Define the function 'getSumAbsoluteDifferences' which takes a vector of integers 'nums' and returns a vector of integers containing the sum of absolute differences.

2. **Variable Initialization**
	```cpp
	    int z = 0, n = nums.size();
	```
	Initialize the variable 'z' to 0 to accumulate the sum of differences, and 'n' to store the size of the 'nums' vector.

3. **Loop Through Array**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Start a loop to iterate through each element in the 'nums' array.

4. **Sum Absolute Differences**
	```cpp
	        z += nums[i] - nums[0];
	```
	In each iteration, accumulate the difference between the current element and the first element of the 'nums' array to 'z'.

5. **Array Initialization**
	```cpp
	    vector<int> ans(n, 0);
	```
	Initialize a vector 'ans' of size 'n' with all elements set to 0. This will store the final results.

6. **Set First Element of Result**
	```cpp
	    ans[0] = z;
	```
	Set the first element of the 'ans' vector to 'z', which is the sum of absolute differences calculated for the first element.

7. **Loop Through Remaining Elements**
	```cpp
	    for(int i = 1; i < n; i++)
	```
	Start a loop to process each element in the 'nums' array starting from the second element.

8. **Calculate Differences for Each Element**
	```cpp
	        ans[i] = ans[i-1] + i * (nums[i] - nums[i-1]) - (n - i)* (nums[i] - nums[i-1]);
	```
	Calculate the sum of absolute differences for the current element by adjusting the previous result. This step uses the previously calculated value to efficiently compute the next result.

9. **Return Statement**
	```cpp
	    return ans;
	```
	Return the vector 'ans' containing the sum of absolute differences for each element.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) as we process each element in the array only once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) as we store the result array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/description/)

---
{{< youtube WYe644djV30 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
