
+++
authors = ["grid47"]
title = "Leetcode 525: Contiguous Array"
date = "2024-09-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 525: Contiguous Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/525.webp"
youtube = "3dRoRxipjhY"
youtube_upload_date="2020-04-13"
youtube_thumbnail="https://i.ytimg.com/vi_webp/3dRoRxipjhY/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/525.webp" 
    alt="A sequence where the contiguous subarrays that sum to zero are softly highlighted, glowing as they are identified."
    caption="Solution to LeetCode 525: Contiguous Array Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a binary array of integers nums, where each element is either 0 or 1.
- **Example:** `nums = [1, 0, 1, 0]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- nums[i] is either 0 or 1.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum length of a contiguous subarray with an equal number of 0s and 1s.
- **Example:** `4`
- **Constraints:**
	- The output is an integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the length of the longest contiguous subarray that has an equal number of 0s and 1s.

- 1. Use a score to track the difference between the count of 1s and 0s.
- 2. If the score is zero at any point, it means that the subarray from the start to the current index has an equal number of 1s and 0s.
- 3. Use a hash map to store the first occurrence of each score, and calculate the length of the subarray whenever the score is repeated.
{{< dots >}}
### Problem Assumptions ✅
- The input array nums contains only 0s and 1s.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [1, 0, 1, 0]`  \
  **Explanation:** The entire array is a contiguous subarray with an equal number of 0s and 1s, so the answer is 4.

- **Input:** `nums = [1, 1, 0, 0, 1, 0]`  \
  **Explanation:** The longest contiguous subarray with an equal number of 0s and 1s is the entire array itself, so the answer is 6.

{{< dots >}}
## Approach 🚀
The approach involves using a score to track the difference between the counts of 1s and 0s in the array, and using a hash map to efficiently calculate the longest subarray with an equal number of 0s and 1s.

### Initial Thoughts 💭
- This problem can be solved using a technique based on prefix sums or difference arrays.
- By treating 1 as +1 and 0 as -1, we can use a cumulative sum to track the difference.
{{< dots >}}
### Edge Cases 🌐
- The solution should handle the edge case of an empty array.
- The solution should efficiently handle large arrays with a length up to 10^5.
- If the array contains only 0s or only 1s, the result should be 0 since no subarray with an equal number of 0s and 1s exists.
- The solution must handle arrays of length up to 10^5 in O(n) time complexity.
{{< dots >}}
## Code 💻
```cpp
int findMaxLength(vector<int>& nums) {

    int n = nums.size();
    int score = 0, res = 0;
    map<int, int> mp;

    for(int i = 0; i < n; i++) {
        score += nums[i]? 1: -1;

        if(score == 0) res = i + 1;
        else {

            if(mp.count(score))
            res = max(res, i - mp[score]);

            if(!mp.count(score)) mp[score] = i;
        }
    }
    return res;
}
```

This function finds the maximum length of a contiguous subarray in which the number of 1s and 0s are equal. It uses a prefix sum technique with a hash map to track the balance of 1s and 0s as it iterates through the array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int findMaxLength(vector<int>& nums) {
	```
	Defines the function `findMaxLength` that takes a vector `nums` of 1s and 0s, and returns the maximum length of a contiguous subarray where the number of 1s equals the number of 0s.

2. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	Initializes the variable `n` to store the size of the input array `nums`.

3. **Variable Initialization**
	```cpp
	    int score = 0, res = 0;
	```
	Initializes two variables: `score` to track the current balance of 1s and 0s, and `res` to store the maximum length of the valid subarray found so far.

4. **Hash Map Initialization**
	```cpp
	    map<int, int> mp;
	```
	Initializes a hash map `mp` that will store the first occurrence of each balance (`score`). This helps in finding the longest subarray with a sum of zero.

5. **Main Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Starts a loop to iterate through the array `nums`, updating the `score` and checking for the longest valid subarray.

6. **Balance Calculation**
	```cpp
	        score += nums[i]? 1: -1;
	```
	Updates the `score` by adding 1 if `nums[i]` is 1, or subtracting 1 if it is 0. This represents the balance of 1s and 0s.

7. **Check for Zero Balance**
	```cpp
	        if(score == 0) res = i + 1;
	```
	Checks if the `score` is zero, which means the subarray from the beginning to the current index has an equal number of 1s and 0s. If so, it updates `res` to be the length of this subarray.

8. **Handle Non-Zero Balance**
	```cpp
	        else {
	```
	If `score` is not zero, it checks the hash map `mp` to determine the longest valid subarray.

9. **Check Map for Existing Balance**
	```cpp
	            if(mp.count(score))
	```
	Checks if the `score` has been encountered before in the hash map `mp`. If it has, it means there exists a subarray that sums to zero between the previous occurrence of this balance and the current index.

10. **Update Result**
	```cpp
	            res = max(res, i - mp[score]);
	```
	Updates `res` to the maximum length of the subarray found so far. This is done by comparing the current length (`i - mp[score]`) with the previous maximum length stored in `res`.

11. **Insert Score into Map**
	```cpp
	            if(!mp.count(score)) mp[score] = i;
	```
	If the `score` has not been encountered before, it is added to the hash map `mp` with its index `i` as the value.

12. **Return Result**
	```cpp
	    return res;
	```
	Returns the maximum length of a subarray with an equal number of 1s and 0s.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the array.
- **Average Case:** O(n)
- **Worst Case:** O(n)

In all cases, the time complexity is O(n) since we traverse the array once.

### Space Complexity 💾
- **Best Case:** O(1), if the score repeats immediately.
- **Worst Case:** O(n), where n is the number of distinct scores encountered.

The space complexity is O(n) due to the hash map storing the first occurrence of each score.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/contiguous-array/description/)

---
{{< youtube 3dRoRxipjhY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
