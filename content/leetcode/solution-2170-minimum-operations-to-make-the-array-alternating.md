
+++
authors = ["grid47"]
title = "Leetcode 2170: Minimum Operations to Make the Array Alternating"
date = "2024-04-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2170: Minimum Operations to Make the Array Alternating in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "LkSQby_5YMg"
youtube_upload_date="2022-02-13"
youtube_thumbnail="https://i.ytimg.com/vi_webp/LkSQby_5YMg/maxresdefault.webp"
comments = true
+++



---
You are given a 0-indexed array nums consisting of n positive integers. The array nums is called alternating if nums[i - 2] == nums[i] and nums[i - 1] != nums[i] for all valid i. In one operation, you can choose an index i and change nums[i] into any positive integer. Your task is to return the minimum number of operations required to make the array alternating.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer array nums containing positive integers.
- **Example:** `[4, 1, 4, 2, 3, 4]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a single integer, which represents the minimum number of operations required to make the array alternating.
- **Example:** `3`
- **Constraints:**
	- The output must be an integer value representing the number of operations.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to minimize the number of operations required to make the array alternate by modifying its elements.

- Find the most frequent elements at even and odd indices separately.
- Determine the number of operations based on the most frequent elements and the number of required changes.
{{< dots >}}
### Problem Assumptions ✅
- The array contains only positive integers.
{{< dots >}}
## Examples 🧩
- **Input:** `[4, 1, 4, 2, 3, 4]`  \
  **Explanation:** In this example, to make the array alternating, we change the numbers at the odd indices to match the most frequent numbers at the even indices. This requires 3 operations.

{{< dots >}}
## Approach 🚀
The approach is to count the most frequent elements at the even and odd indexed positions and minimize the number of changes required to make the array alternating.

### Initial Thoughts 💭
- By focusing on the most frequent elements at even and odd indices, we can minimize the number of changes needed.
- We need to handle two cases: when the most frequent elements at even and odd indices are the same, and when they are different.
{{< dots >}}
### Edge Cases 🌐
- The input will not be empty as per the constraints.
- Ensure the solution handles large arrays efficiently, with lengths up to 10^5.
- Handle cases where all elements in the array are the same.
- Make sure the solution works within the provided input constraints.
{{< dots >}}
## Code 💻
```cpp

array<int, 3> top2Freq(vector<int>& nums, int start) {
    int first = 0, second = 0, cnt[100001] = {};
    for(int i = start; i < nums.size(); i += 2) {
        if(++cnt[nums[i]] >= cnt[first]) {
            if(nums[i] != first)
                second = first;
            first = nums[i];
        } else if(cnt[nums[i]] > cnt[second]) second = nums[i];
    }
    return {first, cnt[first], cnt[second] };
}

int minimumOperations(vector<int>& nums) {
    auto ev = top2Freq(nums, 0), od = top2Freq(nums, 1);
    return nums.size() - (ev[0] != od[0]? ev[1] + od[1] : max(ev[1]+ od[2], ev[2] + od[1]));
}
```

This code defines two functions: `top2Freq`, which finds the two most frequent elements in even and odd indexed positions of a vector, and `minimumOperations`, which calculates the minimum number of operations required to make the two most frequent elements equal across the entire array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	array<int, 3> top2Freq(vector<int>& nums, int start) {
	```
	This defines the function `top2Freq`, which takes a vector of integers and an integer `start` as input and returns an array of three integers: the two most frequent elements and their respective counts.

2. **Variable Initialization**
	```cpp
	    int first = 0, second = 0, cnt[100001] = {};
	```
	Here, two variables `first` and `second` are initialized to 0, and an array `cnt` is created to store the frequency of elements up to index 100000.

3. **For Loop**
	```cpp
	    for(int i = start; i < nums.size(); i += 2) {
	```
	The `for` loop iterates through the `nums` array, starting from the given `start` index and moving in steps of 2, to handle either even or odd indexed positions.

4. **Frequency Count Update**
	```cpp
	        if(++cnt[nums[i]] >= cnt[first]) {
	```
	The count of the current element `nums[i]` is incremented, and if its frequency is greater than or equal to the frequency of `first`, the element is considered for the top two frequent elements.

5. **First Element Assignment**
	```cpp
	            if(nums[i] != first)
	```
	If the current element is not the same as the most frequent element (`first`), the previous `first` becomes `second`.

6. **Second Element Assignment**
	```cpp
	                second = first;
	```
	The previous `first` value is now assigned to `second`, since we have found a new most frequent element.

7. **First Element Update**
	```cpp
	            first = nums[i];
	```
	The current element `nums[i]` becomes the new most frequent element (`first`).

8. **Else Condition**
	```cpp
	        } else if(cnt[nums[i]] > cnt[second]) second = nums[i];
	```
	If the current element's frequency is greater than that of `second`, then `second` is updated with the current element.

9. **Return Statement**
	```cpp
	    return {first, cnt[first], cnt[second] };
	```
	The function returns an array containing the most frequent element `first`, its frequency `cnt[first]`, and the second most frequent element `second`.

10. **Function Definition**
	```cpp
	int minimumOperations(vector<int>& nums) {
	```
	This defines the function `minimumOperations`, which calculates the minimum number of operations required to make the two most frequent elements equal across the entire array.

11. **Calling top2Freq**
	```cpp
	    auto ev = top2Freq(nums, 0), od = top2Freq(nums, 1);
	```
	The function calls `top2Freq` twice, once for even indexed positions (`ev`) and once for odd indexed positions (`od`), storing the results in `ev` and `od` respectively.

12. **Return Statement**
	```cpp
	    return nums.size() - (ev[0] != od[0]? ev[1] + od[1] : max(ev[1]+ od[2], ev[2] + od[1]));
	```
	The function calculates the minimum operations needed by checking if the most frequent elements of even and odd indexed positions are the same or different, and returns the calculated number of operations.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) as we are scanning through the array and calculating frequencies.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) because we need to store the frequency counts of the elements in the array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-operations-to-make-the-array-alternating/description/)

---
{{< youtube LkSQby_5YMg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
