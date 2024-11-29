
+++
authors = ["grid47"]
title = "Leetcode 1800: Maximum Ascending Subarray Sum"
date = "2024-05-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1800: Maximum Ascending Subarray Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "uiCLUTepEJA"
youtube_upload_date="2021-03-21"
youtube_thumbnail="https://i.ytimg.com/vi/uiCLUTepEJA/maxresdefault.jpg"
comments = true
+++



---
Given an array of positive integers 'nums', return the maximum possible sum of an ascending subarray. A subarray is ascending if for each i, num[i] < num[i+1].
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array 'nums' of positive integers. Your task is to find the maximum sum of a strictly ascending subarray.
- **Example:** `nums = [5, 10, 15, 2, 8, 30]`
- **Constraints:**
	- 1 <= nums.length <= 100
	- 1 <= nums[i] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum sum of any strictly ascending subarray.
- **Example:** `For nums = [5, 10, 15, 2, 8, 30], the output will be 55.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the sum of the maximum ascending subarray in 'nums'.

- 1. Iterate through the array 'nums'.
- 2. Track the sum of the current ascending subarray. Reset the sum whenever the sequence stops being strictly ascending.
- 3. Keep a variable to track the maximum sum found.
{{< dots >}}
### Problem Assumptions ✅
- The array will contain at least one number.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [5, 10, 15, 2, 8, 30]`  \
  **Explanation:** In this example, the ascending subarrays are [5, 10, 15] and [2, 8, 30]. The maximum sum is 5 + 10 + 15 + 30 = 55.

{{< dots >}}
## Approach 🚀
We will iterate through the array and calculate the sum of all strictly ascending subarrays while updating the maximum sum whenever needed.

### Initial Thoughts 💭
- An ascending subarray is defined by consecutive elements where each element is greater than the previous one.
- We need to check each subarray's sum and compare it with the maximum sum so far.
{{< dots >}}
### Edge Cases 🌐
- If the array is empty, return 0.
- Ensure that the solution can handle arrays with up to 100 elements.
- For arrays with only one element, the maximum sum is the value of that element.
- Make sure the solution runs efficiently within the given constraints.
{{< dots >}}
## Code 💻
```cpp
int maxAscendingSum(vector<int>& nums) {
    int sum = nums[0];
    int maxi = sum;
    if(nums.size() == 1) return nums[0];
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] <= nums[i-1]){
            sum = 0;
        }
            sum += nums[i];
            maxi = max(sum,maxi);
    }
        return maxi;
    }

```

The function `maxAscendingSum` calculates the maximum sum of a strictly increasing contiguous subarray from a given list of integers.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maxAscendingSum(vector<int>& nums) {
	```
	This is the function definition. The input is a vector of integers, `nums`, and the output is an integer representing the maximum sum of an ascending subarray.

2. **Variable Initialization**
	```cpp
	    int sum = nums[0];
	```
	Initialize `sum` to the first element of the `nums` array. This variable tracks the sum of the current ascending subarray.

3. **Variable Initialization**
	```cpp
	    int maxi = sum;
	```
	Initialize `maxi` to the value of `sum`. This will track the maximum sum encountered during the iteration.

4. **Edge Case Handling**
	```cpp
	    if(nums.size() == 1) return nums[0];
	```
	Handle the edge case where the input list has only one element. In this case, the only possible sum is the element itself.

5. **Loop Start**
	```cpp
	    for(int i = 1; i < nums.size(); i++){
	```
	Start a loop from the second element to the last element of the `nums` array to evaluate each element in relation to its predecessor.

6. **Condition Check**
	```cpp
	        if(nums[i] <= nums[i-1]){
	```
	Check if the current element is less than or equal to the previous element. If so, the ascending subarray has ended.

7. **Reset Sum**
	```cpp
	            sum = 0;
	```
	Reset `sum` to 0 since the current subarray is no longer strictly increasing.

8. **Sum Update**
	```cpp
	            sum += nums[i];
	```
	Add the current element to `sum` as part of the current ascending subarray.

9. **Maximum Update**
	```cpp
	            maxi = max(sum,maxi);
	```
	Update `maxi` with the larger of the current sum (`sum`) or the previous maximum (`maxi`).

10. **Return Statement**
	```cpp
	        return maxi;
	```
	Return the maximum sum of the strictly increasing subarray found during the iteration.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) where n is the length of the array, as we only iterate through the array once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we only need a few variables to track the current sum and the maximum sum.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-ascending-subarray-sum/description/)

---
{{< youtube uiCLUTepEJA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
