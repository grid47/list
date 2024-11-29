
+++
authors = ["grid47"]
title = "Leetcode 1480: Running Sum of 1d Array"
date = "2024-06-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1480: Running Sum of 1d Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "qNbwIHhMOr8"
youtube_upload_date="2020-06-14"
youtube_thumbnail="https://i.ytimg.com/vi_webp/qNbwIHhMOr8/maxresdefault.webp"
comments = true
+++



---
You are given an array of integers nums. Your task is to calculate the running sum of the array, where each element at index i represents the sum of all elements from index 0 to index i in the original array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single array of integers nums.
- **Example:** `[4, 3, 2, 1]`
- **Constraints:**
	- 1 <= nums.length <= 1000
	- -10^6 <= nums[i] <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an array of integers representing the running sum of the input array.
- **Example:** `[4, 7, 9, 10]`
- **Constraints:**
	- The length of the output array will be the same as the input array.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the running sum by iterating through the input array and adding each element to the sum of previous elements.

- Start by setting the running sum to the first element.
- Iterate through the rest of the elements, adding each element to the previous sum and storing the result at the current index.
{{< dots >}}
### Problem Assumptions ✅
- The array will always have at least one element.
- The values in the array can be both positive and negative.
{{< dots >}}
## Examples 🧩
- **Input:** `[4, 3, 2, 1]`  \
  **Explanation:** Here, the running sum is calculated as follows: [4, 7, 9, 10].

{{< dots >}}
## Approach 🚀
To compute the running sum, iterate through the array, updating the current element by adding it to the sum of previous elements.

### Initial Thoughts 💭
- The problem requires an efficient solution since the array size can be as large as 1000.
- We can solve the problem in linear time by modifying the array in place.
{{< dots >}}
### Edge Cases 🌐
- If the array is empty, return an empty array.
- The solution should handle arrays of length up to 1000 efficiently.
- Handle cases where the array contains negative values.
- Ensure that the array length does not exceed the given limit.
{{< dots >}}
## Code 💻
```cpp
vector<int> runningSum(vector<int>& nums) {
    for(int i = 1; i < nums.size(); i++)
        nums[i] += nums[i - 1];
    return nums;
}
```

The function `runningSum` takes an input array `nums` and modifies it by replacing each element with the sum of all previous elements, including itself. This results in an array where each element is the running total up to that point.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Method**
	```cpp
	vector<int> runningSum(vector<int>& nums) {
	```
	This is the definition of the function `runningSum`, which takes an array `nums` by reference and returns an array of running sums.

2. **Loop**
	```cpp
	    for(int i = 1; i < nums.size(); i++)
	```
	This for loop starts from index 1 and iterates through the `nums` array to compute the running sum for each element.

3. **Update**
	```cpp
	        nums[i] += nums[i - 1];
	```
	In each iteration, the current element `nums[i]` is updated by adding the value of the previous element `nums[i - 1]` to it, thus building the running sum.

4. **Return**
	```cpp
	    return nums;
	```
	Once the loop completes, the modified `nums` array, which now contains the running sums, is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n) where n is the length of the array.
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) since we only need to iterate over the array once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1) if we modify the array in place.

The space complexity is O(1) since we modify the array in place and do not require extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/running-sum-of-1d-array/description/)

---
{{< youtube qNbwIHhMOr8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
