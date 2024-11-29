
+++
authors = ["grid47"]
title = "Leetcode 2750: Ways to Split Array Into Good Subarrays"
date = "2024-02-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2750: Ways to Split Array Into Good Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "T8f9ppAJHbY"
youtube_upload_date="2023-07-01"
youtube_thumbnail="https://i.ytimg.com/vi/T8f9ppAJHbY/maxresdefault.jpg"
comments = true
+++



---
You are given a binary array 'nums' containing only 0s and 1s. A good subarray is defined as a contiguous subarray that contains exactly one 1. Your task is to find the number of ways to split the array into good subarrays. Return the result modulo (10^9 + 7).
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You will be given a binary array 'nums' where each element is either 0 or 1.
- **Example:** `nums = [0, 1, 0, 0, 1]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 0 <= nums[i] <= 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of ways to split the array 'nums' into good subarrays, modulo (10^9 + 7).
- **Example:** `For nums = [0, 1, 0, 0, 1], the output is 4.`
- **Constraints:**
	- The result should be returned modulo (10^9 + 7).

{{< dots >}}
### Core Logic 🔍
**Goal:** Count the number of ways to split 'nums' into good subarrays where each subarray contains exactly one 1.

- Iterate through the array and count contiguous zeros between 1s.
- For each segment of zeros, calculate the number of ways to split the segment into good subarrays.
- Multiply the results for all segments together to get the final answer.
{{< dots >}}
### Problem Assumptions ✅
- The array 'nums' will always contain at least one element.
{{< dots >}}
## Examples 🧩
- **Input:** `For nums = [0, 1, 0, 0, 1]`  \
  **Explanation:** You need to count how many ways you can split the array into subarrays where each subarray contains exactly one 1. In this case, there are 4 ways.

{{< dots >}}
## Approach 🚀
We need to find contiguous segments of zeros between the ones and calculate the number of possible ways to split those segments into subarrays containing exactly one 1.

### Initial Thoughts 💭
- The problem involves finding segments of zeros between ones in the array.
- For each segment of zeros, the number of ways to split it depends on the length of the segment.
- We can iterate through the array, identify the segments between 1s, and count the number of ways to split them.
{{< dots >}}
### Edge Cases 🌐
- The input will always have at least one element, so no empty input case.
- If the array is large (close to 100,000 elements), the solution needs to be efficient enough to handle this within the time limit.
- If the array only contains 1s or only 0s, no valid splits are possible.
- Ensure that the result is computed modulo (10^9 + 7).
{{< dots >}}
## Code 💻
```cpp
int numberOfGoodSubarraySplits(vector<int>& nums) {

    int mod = (int) 1e9 + 7;
    long ans = 1, cnt = 0;
    int i = 0, n = nums.size();
    while(i < n && nums[i] == 0) cnt++, i++;
    if(cnt == n) return 0;
    cnt = 0;

    for(; i < n; i++) {
        if(nums[i]) {
            ans = (ans * (cnt + 1)) % mod;
            cnt = 0;
        } else cnt++;
    }
    return ans;
}
```

This function calculates the number of 'good' subarray splits in an array of integers, where each subarray split contains at least one non-zero element. The result is computed using a modular arithmetic approach to avoid overflow.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int numberOfGoodSubarraySplits(vector<int>& nums) {
	```
	Defines the function `numberOfGoodSubarraySplits` which takes a vector `nums` containing integers and returns the number of good subarray splits.

2. **Modular Arithmetic**
	```cpp
	    int mod = (int) 1e9 + 7;
	```
	Defines the modulus `mod` as (10^9 + 7), which is commonly used in competitive programming to prevent integer overflow.

3. **Variable Initialization**
	```cpp
	    long ans = 1, cnt = 0;
	```
	Initializes the result variable `ans` to 1, and the counter `cnt` to 0. `cnt` will track the number of consecutive zeroes in the array.

4. **Size Calculation**
	```cpp
	    int i = 0, n = nums.size();
	```
	Initializes the index `i` to 0, and `n` to the size of the `nums` array. These will be used to traverse the array.

5. **Count Leading Zeroes**
	```cpp
	    while(i < n && nums[i] == 0) cnt++, i++;
	```
	Counts the number of leading zeroes in the array by iterating through the array until a non-zero element is found.

6. **Edge Case Check**
	```cpp
	    if(cnt == n) return 0;
	```
	If the entire array consists of zeroes, there are no valid subarray splits, so the function returns 0.

7. **Reset Counter**
	```cpp
	    cnt = 0;
	```
	Resets the `cnt` variable to 0, as we are starting to process non-zero elements in the array.

8. **Iterate Through Array**
	```cpp
	    for(; i < n; i++) {
	```
	Starts a loop to iterate over the remaining elements in the `nums` array, starting from the first non-zero element.

9. **Non-zero Element Check**
	```cpp
	        if(nums[i]) {
	```
	Checks if the current element `nums[i]` is non-zero.

10. **Update Result**
	```cpp
	            ans = (ans * (cnt + 1)) % mod;
	```
	If the current element is non-zero, the result `ans` is updated by multiplying it with `cnt + 1` (the number of subarrays that can be formed from the zeroes), then taking the result modulo `mod`.

11. **Reset Counter After Non-zero Element**
	```cpp
	            cnt = 0;
	```
	Resets the counter `cnt` to 0 after processing a non-zero element.

12. **Increment Zero Counter**
	```cpp
	        } else cnt++;
	```
	If the current element is zero, the counter `cnt` is incremented to track the consecutive zeroes.

13. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the result `ans`, which represents the total number of good subarray splits modulo (10^9 + 7).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n) where n is the length of nums.
- **Average Case:** O(n).
- **Worst Case:** O(n).

We iterate through the array once to find the segments and compute the result, which is linear in time complexity.

### Space Complexity 💾
- **Best Case:** O(1).
- **Worst Case:** O(1).

We only use a few variables to store intermediate results, so the space complexity is constant.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/ways-to-split-array-into-good-subarrays/description/)

---
{{< youtube T8f9ppAJHbY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
