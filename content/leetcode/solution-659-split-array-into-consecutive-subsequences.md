
+++
authors = ["grid47"]
title = "Leetcode 659: Split Array into Consecutive Subsequences"
date = "2024-09-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 659: Split Array into Consecutive Subsequences in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/659.webp"
youtube = "hbNUEvWyiFU"
youtube_upload_date="2020-07-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/hbNUEvWyiFU/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/659.webp" 
    alt="An array where consecutive subsequences are split and highlighted with glowing sections."
    caption="Solution to LeetCode 659: Split Array into Consecutive Subsequences Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a sorted integer array nums. Determine if it is possible to split nums into one or more subsequences such that each subsequence is a consecutive increasing sequence and each subsequence has a length of 3 or more.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a sorted integer array nums.
- **Example:** `nums = [1, 2, 3, 3, 4, 5]`
- **Constraints:**
	- 1 <= nums.length <= 10^4
	- -1000 <= nums[i] <= 1000
	- nums is sorted in non-decreasing order.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if it is possible to split nums into valid subsequences, otherwise return false.
- **Example:** `true`
- **Constraints:**
	- The output is a boolean value indicating whether the split is possible.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check if it is possible to form valid subsequences of length 3 or more, where each subsequence is a consecutive increasing sequence.

- 1. Use a map to count occurrences of each number in the array.
- 2. Track the subsequences that can be extended with the current number.
- 3. Ensure that each number is either added to an existing subsequence or starts a new valid subsequence of at least length 3.
{{< dots >}}
### Problem Assumptions ✅
- The input array is always sorted in non-decreasing order.
- The length of the array is within the specified limits.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [1, 2, 3, 3, 4, 5]`  \
  **Explanation:** The array can be split into two subsequences: [1, 2, 3] and [3, 4, 5], both of which are valid.

- **Input:** `nums = [1, 2, 3, 4, 4, 5]`  \
  **Explanation:** It is impossible to split this array into valid subsequences, as the subsequence starting with the second 4 cannot be extended to form a valid sequence.

{{< dots >}}
## Approach 🚀
This problem can be solved by tracking the frequency of each element and ensuring that each number is placed in an appropriate subsequence.

### Initial Thoughts 💭
- We can use a frequency map to keep track of the remaining numbers.
- Subsequences should only be extended if the previous number is part of a valid subsequence.
- We need to carefully manage how we form and extend subsequences to meet the requirement that all subsequences have at least 3 elements.
{{< dots >}}
### Edge Cases 🌐
- There will be no empty arrays, as per the constraints.
- The solution should handle arrays of size up to 10^4 efficiently.
- Arrays where consecutive numbers repeat can be tricky, but the solution will handle them by extending or starting new subsequences.
- Ensure the number of subsequences is managed correctly to meet the length 3 constraint.
{{< dots >}}
## Code 💻
```cpp
bool isPossible(vector<int>& nums) {
    unordered_map<int, int> left, end;
    
    for(int num: nums)
        left[num]++;

    for(int num: nums) { // nums is in increasing order
        if(left[num] == 0) continue;
        
        left[num]--;
        
        if(end[num - 1] > 0) {
            end[num - 1]--;
            end[num]++;
        }
        else if(left[num + 1] > 0 && left[num + 2] > 0) {
            left[num + 1]--;
            left[num + 2]--;
            end [num + 2]++;
        } else return false;
    }
    return true;
}
```

This function checks whether it's possible to split an array of numbers into consecutive subsequences. It uses two hash maps (`left` and `end`) to track the counts of elements available for subsequences and the ending elements of subsequences, respectively.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool isPossible(vector<int>& nums) {
	```
	This is the function definition for `isPossible`, which takes a vector of integers `nums` and returns a boolean value indicating whether it's possible to split the array into consecutive subsequences.

2. **Variable Initialization**
	```cpp
	    unordered_map<int, int> left, end;
	```
	Two hash maps `left` and `end` are initialized. `left` tracks the count of available elements, and `end` tracks the number of subsequences ending at a specific number.

3. **Loop Initialization**
	```cpp
	    for(int num: nums)
	```
	Iterate over each number in the `nums` array.

4. **Left Count Update**
	```cpp
	        left[num]++;
	```
	For each number, increment the count in the `left` map to indicate that this number is available for building subsequences.

5. **Loop Start**
	```cpp
	    for(int num: nums) { // nums is in increasing order
	```
	This is the second loop that iterates through the numbers in `nums`. It processes each number in increasing order to check if it can be added to a subsequence.

6. **Skip Processed Numbers**
	```cpp
	        if(left[num] == 0) continue;
	```
	If the number has already been used in a subsequence (i.e., `left[num] == 0`), skip processing it.

7. **Left Count Decrement**
	```cpp
	        left[num]--;
	```
	Decrement the count of the current number in `left` because it is being used to form a subsequence.

8. **Check Existing Subsequence**
	```cpp
	        if(end[num - 1] > 0) {
	```
	If there is a subsequence ending with `num - 1`, extend that subsequence by adding the current `num` to it.

9. **Extend Subsequence**
	```cpp
	            end[num - 1]--;
	```
	Decrement the count of subsequences ending with `num - 1` since we are now using `num` to extend it.

10. **End Subsequence with Current Number**
	```cpp
	            end[num]++;
	```
	Increment the count of subsequences ending with `num` after adding it to an existing subsequence.

11. **Check for New Subsequence**
	```cpp
	        } else if(left[num + 1] > 0 && left[num + 2] > 0) {
	```
	If no subsequence can be extended with the current number, check if we can start a new subsequence with `num`, `num + 1`, and `num + 2`.

12. **Start New Subsequence**
	```cpp
	            left[num + 1]--;
	```
	Decrement the count of `num + 1` in `left` as it's being used to start a new subsequence.

13. **New Subsequence Continuation**
	```cpp
	            left[num + 2]--;
	```
	Decrement the count of `num + 2` in `left` as it's also being used to continue the new subsequence.

14. **End New Subsequence**
	```cpp
	            end [num + 2]++;
	```
	Increment the count of subsequences ending with `num + 2` to mark the successful creation of a new subsequence.

15. **Return False**
	```cpp
	        } else return false;
	```
	If neither extending an existing subsequence nor starting a new one is possible, return `false` to indicate that it's not possible to split the array into consecutive subsequences.

16. **Return True**
	```cpp
	    return true;
	```
	If the loop completes without returning `false`, return `true`, indicating that the array can be split into consecutive subsequences.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) as we process each element in the array once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage needed for the frequency and subsequence maps.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/split-array-into-consecutive-subsequences/description/)

---
{{< youtube hbNUEvWyiFU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
