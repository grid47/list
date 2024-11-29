
+++
authors = ["grid47"]
title = "Leetcode 2615: Sum of Distances"
date = "2024-02-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2615: Sum of Distances in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "b620guqinSc"
youtube_upload_date="2023-04-09"
youtube_thumbnail="https://i.ytimg.com/vi_webp/b620guqinSc/maxresdefault.webp"
comments = true
+++



---
You are given a 0-indexed integer array `nums`. For each element `nums[i]`, compute the sum of absolute differences |i - j| for all indices `j` where `nums[j] == nums[i]` and `j != i`. If there are no such indices, set the corresponding value in the result array to 0. Return the resulting array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a 0-indexed integer array `nums` of length `n`. Each element of `nums` is an integer in the range [0, 10^9].
- **Example:** `nums = [1, 3, 1, 1, 2]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 0 <= nums[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array `arr` where for each `i`, `arr[i]` is the sum of absolute differences |i - j| for all `j` such that `nums[j] == nums[i]` and `j != i`. If no such `j` exists, set `arr[i] = 0`.
- **Example:** `Output: [5, 0, 3, 4, 0]`
- **Constraints:**
	- The array `arr` must have the same length as the input array `nums`.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the sum of absolute differences for each element of the array, considering the other elements with the same value and their indices.

- Step 1: Initialize two maps to keep track of the cumulative sum of indices and the count of occurrences for each number.
- Step 2: Iterate through the array from left to right, and for each index, calculate the sum of absolute differences based on previously encountered indices of the same value.
- Step 3: Iterate through the array from right to left to update the result array with the contributions from indices after the current one.
- Step 4: Return the final result array.
{{< dots >}}
### Problem Assumptions ✅
- All elements in the array are non-negative integers.
- If there are multiple occurrences of a number, the distances should be calculated between all pairs of indices with the same value.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [1, 3, 1, 1, 2]`  \
  **Explanation:** For index 0 (value 1), there are two other occurrences of 1 at indices 2 and 3. The absolute differences are |0 - 2| + |0 - 3| = 5, so arr[0] = 5. For index 1 (value 3), there are no other occurrences of 3, so arr[1] = 0. The same logic applies for the other indices.

- **Input:** `nums = [0, 5, 3]`  \
  **Explanation:** Each value in `nums` is distinct, so the sum of absolute differences for all indices is 0. Hence, the result is [0, 0, 0].

{{< dots >}}
## Approach 🚀
The approach involves efficiently calculating the sum of absolute differences for each element by using two passes over the input array. In the first pass, we compute contributions from previous occurrences, and in the second pass, we compute contributions from subsequent occurrences.

### Initial Thoughts 💭
- Using a brute force solution with nested loops would be too slow, especially for large arrays.
- By keeping track of the sum of indices and count of occurrences for each number in a map, we can efficiently compute the result in two passes over the array.
{{< dots >}}
### Edge Cases 🌐
- If the input array is empty, return an empty array.
- The solution should handle arrays of size up to 10^5 efficiently.
- If all elements are distinct, the result should be an array of zeros.
- The solution should work even for very large integers (up to 10^9).
{{< dots >}}
## Code 💻
```cpp
vector<long long> distance(vector<int>& nums) {
    /*
    
    [1,3,1,1,2]
     0,1,2,3,4
    
     0
       0  
     2   2
     5   3 4
             0
    */
    
    unordered_map<int, double> mp, cnt;
    int n = nums.size();
    vector<long long> arr(n, 0);
    for(int i = 0; i < n; i++) {
        arr[i] = cnt[nums[i]] * i - mp[nums[i]];
        mp[nums[i]] += i;
        cnt[nums[i]] += 1;
    }
    mp.clear(), cnt.clear();        
    for(int i = n - 1; i >= 0; i--) {
        arr[i] += mp[nums[i]] - cnt[nums[i]] * i;
        mp[nums[i]] += i;
        cnt[nums[i]] += 1;
    }
    return arr;
}
```

This code calculates the distance between elements in the array `nums` using unordered maps to keep track of counts and sum of indices for each unique value.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Code Start**
	```cpp
	vector<long long> distance(vector<int>& nums) {
	```
	Function definition for calculating distances.

2. **Data Structure Initialization**
	```cpp
	    unordered_map<int, double> mp, cnt;
	```
	Declare unordered maps `mp` and `cnt` for tracking the sum of indices and counts.

3. **Size Calculation**
	```cpp
	    int n = nums.size();
	```
	Store the size of the `nums` array.

4. **Array Initialization**
	```cpp
	    vector<long long> arr(n, 0);
	```
	Initialize an array `arr` of size `n` to store the result.

5. **Loop Start**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Loop through the array `nums` to calculate partial distances.

6. **Update Distance**
	```cpp
	        arr[i] = cnt[nums[i]] * i - mp[nums[i]];
	```
	Calculate and store the partial result in `arr[i]`.

7. **Update Sum Map**
	```cpp
	        mp[nums[i]] += i;
	```
	Update the sum of indices for the current value in `nums`.

8. **Update Count Map**
	```cpp
	        cnt[nums[i]] += 1;
	```
	Increment the count for the current value in `nums`.

9. **Clear Maps**
	```cpp
	    mp.clear(), cnt.clear();        
	```
	Clear the maps `mp` and `cnt` before the reverse pass.

10. **Reverse Loop Start**
	```cpp
	    for(int i = n - 1; i >= 0; i--) {
	```
	Loop through the array `nums` in reverse to complete the calculation.

11. **Update Reverse Distance**
	```cpp
	        arr[i] += mp[nums[i]] - cnt[nums[i]] * i;
	```
	Update the distance for each element in the reverse pass.

12. **Update Reverse Sum Map**
	```cpp
	        mp[nums[i]] += i;
	```
	Update the sum of indices for the current value in the reverse pass.

13. **Update Reverse Count Map**
	```cpp
	        cnt[nums[i]] += 1;
	```
	Increment the count for the current value in the reverse pass.

14. **Return Result**
	```cpp
	    return arr;
	```
	Return the final calculated array `arr`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because the algorithm makes two passes through the array, each requiring O(n) time, where `n` is the length of the array.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) because the algorithm uses hash maps to store the cumulative sum and counts of occurrences for each unique value in the array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/sum-of-distances/description/)

---
{{< youtube b620guqinSc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
