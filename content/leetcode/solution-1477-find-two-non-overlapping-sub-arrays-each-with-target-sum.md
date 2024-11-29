
+++
authors = ["grid47"]
title = "Leetcode 1477: Find Two Non-overlapping Sub-arrays Each With Target Sum"
date = "2024-06-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1477: Find Two Non-overlapping Sub-arrays Each With Target Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Dynamic Programming","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "uV_JsPPLK9o"
youtube_upload_date="2020-07-17"
youtube_thumbnail="https://i.ytimg.com/vi_webp/uV_JsPPLK9o/maxresdefault.webp"
comments = true
+++



---
You are given an array of integers arr and an integer target. You need to find two non-overlapping sub-arrays of arr each with a sum equal target. The goal is to minimize the sum of their lengths, and if no such sub-arrays exist, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array arr and an integer target.
- **Example:** `[1, 1, 1, 2, 3], 2`
- **Constraints:**
	- 1 <= arr.length <= 10^5
	- 1 <= arr[i] <= 1000
	- 1 <= target <= 10^8

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should return the minimum sum of the lengths of the two sub-arrays, or -1 if no such sub-arrays exist.
- **Example:** `2`
- **Constraints:**
	- If no two sub-arrays with sum equal to target exist, return -1.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to efficiently find two non-overlapping sub-arrays that sum to the target and minimize the sum of their lengths.

- Use a sliding window approach to find all sub-arrays that sum to the target.
- Store the lengths of valid sub-arrays and ensure they do not overlap.
- Track the minimum sum of lengths for valid sub-arrays.
{{< dots >}}
### Problem Assumptions ✅
- The array will contain at least one sub-array summing to the target.
{{< dots >}}
## Examples 🧩
- **Input:** `[1, 1, 1, 2, 3], 2`  \
  **Explanation:** Here, two sub-arrays sum to 2: [1, 1] and [2], and the sum of their lengths is 2.

{{< dots >}}
## Approach 🚀
The approach uses a sliding window to efficiently find all sub-arrays that sum to the target and then minimizes the sum of the lengths of non-overlapping sub-arrays.

### Initial Thoughts 💭
- We need to consider non-overlapping sub-arrays, so after finding one, we must avoid overlapping with the second.
- Sliding window is an efficient way to find sub-arrays with a fixed sum.
{{< dots >}}
### Edge Cases 🌐
- Empty arrays should return -1.
- For large arrays, the solution should be optimized for time efficiency.
- Handle cases where no valid sub-arrays exist.
- Ensure the solution handles arrays with up to 10^5 elements.
{{< dots >}}
## Code 💻
```cpp
int minSumOfLengths(vector<int>& arr, int target) {
    unordered_map<int, int> mp;
    int sum = 0, lsize = INT_MAX, result = INT_MAX;
    mp[0] = -1;
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        mp[sum] = i;
    }
    sum = 0;
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if(mp.count(sum - target)) 
        lsize = min(lsize, i - mp[sum-target]);

        if(mp.count(sum + target) && lsize < INT_MAX)
        result = min(result, mp[sum + target] -i +lsize);


    }

    return result == INT_MAX ? -1: result;
}
```

This function `minSumOfLengths` solves the problem of finding the minimum sum of lengths of two non-overlapping subarrays that sum up to a given target. It uses a hash map to store the cumulative sums and the smallest possible subarray lengths to optimize the search.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Method**
	```cpp
	int minSumOfLengths(vector<int>& arr, int target) {
	```
	This is the definition of the function `minSumOfLengths`, which takes an array `arr` and a target sum `target` as parameters.

2. **Declaration**
	```cpp
	    unordered_map<int, int> mp;
	```
	An unordered map `mp` is declared to store cumulative sums and their corresponding indices. This helps to efficiently find subarrays whose sum is equal to a given target.

3. **Initialization**
	```cpp
	    int sum = 0, lsize = INT_MAX, result = INT_MAX;
	```
	The variables are initialized: `sum` stores the cumulative sum of the elements, `lsize` is used to track the smallest subarray length, and `result` will store the minimum sum of lengths of the valid subarrays.

4. **Initialization**
	```cpp
	    mp[0] = -1;
	```
	The hash map `mp` is initialized with a base case where the cumulative sum `0` is mapped to index `-1`. This helps handle edge cases like when a valid subarray starts at the beginning of the array.

5. **Loop**
	```cpp
	    for(int i = 0; i < arr.size(); i++) {
	```
	This is the start of the first loop, which iterates through the array `arr` to calculate cumulative sums.

6. **Update**
	```cpp
	        sum += arr[i];
	```
	In this step, the current element `arr[i]` is added to the cumulative sum `sum`.

7. **Update**
	```cpp
	        mp[sum] = i;
	```
	The current cumulative sum is stored in the map `mp`, with the index `i` as its value.

8. **Initialization**
	```cpp
	    sum = 0;
	```
	The cumulative sum is reset to zero for the second loop to calculate possible valid subarrays.

9. **Loop**
	```cpp
	    for(int i = 0; i < arr.size(); i++) {
	```
	Start of the second loop, which processes the array again to check for subarrays that sum up to the target.

10. **Update**
	```cpp
	        sum += arr[i];
	```
	The current element `arr[i]` is added to the cumulative sum again.

11. **Condition**
	```cpp
	        if(mp.count(sum - target)) 
	```
	This condition checks if there is a subarray in `mp` whose sum is equal to `sum - target`, indicating a valid subarray.

12. **Update**
	```cpp
	        lsize = min(lsize, i - mp[sum-target]);
	```
	If the condition is true, the length of the current subarray is calculated and the smallest subarray length (`lsize`) is updated.

13. **Condition**
	```cpp
	        if(mp.count(sum + target) && lsize < INT_MAX)
	```
	This condition checks if there is another subarray in `mp` whose sum is equal to `sum + target` and ensures that a valid subarray length (`lsize`) has been found.

14. **Update**
	```cpp
	        result = min(result, mp[sum + target] -i +lsize);
	```
	If both conditions are met, the `result` is updated with the minimum sum of lengths of the valid subarrays.

15. **Return**
	```cpp
	    return result == INT_MAX ? -1: result;
	```
	The function returns the minimum sum of lengths of the valid subarrays found. If no valid subarrays exist, `-1` is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n) for the sliding window approach if all sub-arrays are found early.
- **Average Case:** O(n) for iterating through the array and checking sub-array sums.
- **Worst Case:** O(n) in the worst case where we need to examine every element.

Time complexity is linear with respect to the size of the array.

### Space Complexity 💾
- **Best Case:** O(1) if we are able to immediately return the result.
- **Worst Case:** O(n) if we need to store all sub-array sums and lengths.

Space complexity depends on the need to store sub-array lengths, which could scale with the size of the input.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/description/)

---
{{< youtube uV_JsPPLK9o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
