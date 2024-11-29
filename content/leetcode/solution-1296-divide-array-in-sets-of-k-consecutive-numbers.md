
+++
authors = ["grid47"]
title = "Leetcode 1296: Divide Array in Sets of K Consecutive Numbers"
date = "2024-06-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1296: Divide Array in Sets of K Consecutive Numbers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
Given an array of integers `nums` and a positive integer `k`, check if it is possible to divide the array into sets of `k` consecutive numbers.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `nums` and a positive integer `k`.
- **Example:** `Input: nums = [5, 1, 2, 3, 4, 3, 6, 4], k = 4`
- **Constraints:**
	- 1 <= k <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** The function should return `true` if it's possible to divide the array into sets of `k` consecutive numbers, and `false` otherwise.
- **Example:** `Output: true`
- **Constraints:**
	- Return a boolean value.

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine if it is possible to divide the array into sets of `k` consecutive numbers.

- Count the frequency of each number in the array using a map.
- For each number, check if a consecutive sequence starting from that number can be formed by checking its next `k-1` consecutive elements.
- If a number is used in a valid sequence, reduce its frequency in the map.
- Return `true` if all numbers are successfully grouped into sets of `k` consecutive numbers, otherwise return `false`.
{{< dots >}}
### Problem Assumptions ✅
- The array `nums` contains integers and is not empty.
- The value of `k` is positive and less than or equal to the size of the array.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [5, 1, 2, 3, 4, 3, 6, 4], k = 4`  \
  **Explanation:** The array can be grouped into the sets [1, 2, 3, 4] and [3, 4, 5, 6], so the output is `true`.

- **Input:** `Input: nums = [2, 3, 4, 1], k = 3`  \
  **Explanation:** It's not possible to divide the array into sets of 3 consecutive numbers, so the output is `false`.

{{< dots >}}
## Approach 🚀
This problem can be solved by using a frequency map and trying to form consecutive sequences starting from the smallest available number.

### Initial Thoughts 💭
- We need to efficiently count and group elements to form consecutive sequences.
- Using a map to track element frequencies will help us in forming the sets.
- By reducing the frequency of elements as we use them to form sets, we ensure that each number is part of exactly one set.
{{< dots >}}
### Edge Cases 🌐
- The input array is never empty according to the constraints.
- Ensure the solution is optimized for large arrays of size up to 10^5.
- If the number of elements in the array is less than `k`, it's impossible to form a valid set.
- The solution must handle large input sizes efficiently, with time complexity ideally around O(n log n).
{{< dots >}}
## Code 💻
```cpp
bool isPossibleDivide(vector<int>& nums, int k) {

    map<int, int> cnt;
    int n = nums.size();
    for(int num : nums)
        cnt[num]++;
    
    for(auto it : cnt) {
        int frq = it.second;
        if(frq > 0)
        for(int i = 0; i < k; i++) {

              if(cnt[it.first + i] < frq) return false;
            else cnt[it.first + i] -= frq;

        }
    }
    
    return true;
}
```

This function checks if the array can be divided into groups of consecutive numbers of size 'k' using a greedy approach.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool isPossibleDivide(vector<int>& nums, int k) {
	```
	Defines a function that checks if it is possible to divide the input array into groups of 'k' consecutive integers.

2. **Frequency Calculation**
	```cpp
	    map<int, int> cnt;
	```
	Creates a map to store the frequency of each integer in the array.

3. **Array Length**
	```cpp
	    int n = nums.size();
	```
	Stores the size of the input array.

4. **For Each Element**
	```cpp
	    for(int num : nums)
	```
	Iterates through each element of the input array.

5. **Frequency Update**
	```cpp
	        cnt[num]++;
	```
	Increments the frequency count for each number in the map.

6. **For Each Frequency**
	```cpp
	    for(auto it : cnt) {
	```
	Iterates through each number and its frequency in the map.

7. **Get Frequency**
	```cpp
	        int frq = it.second;
	```
	Extracts the frequency of the current number.

8. **Check Frequency**
	```cpp
	        if(frq > 0)
	```
	Checks if the frequency of the current number is greater than zero.

9. **Loop for Consecutive Numbers**
	```cpp
	        for(int i = 0; i < k; i++) {
	```
	Iterates through the next 'k' consecutive numbers.

10. **Return False if Not Enough Numbers**
	```cpp
	              if(cnt[it.first + i] < frq) return false;
	```
	If the frequency of any consecutive number is less than the required, returns false.

11. **Update Frequency**
	```cpp
	            else cnt[it.first + i] -= frq;
	```
	Decreases the frequency of the current consecutive number as it is used in the group.

12. **Return True**
	```cpp
	    return true;
	```
	Returns true if it is possible to divide the numbers into consecutive groups of size 'k'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n) - The best case occurs when the elements are already in the correct order and can be grouped quickly.
- **Average Case:** O(n log n) - Sorting and grouping elements dominate the time complexity.
- **Worst Case:** O(n log n) - The worst case is when sorting and grouping take the longest time.

The time complexity is O(n log n) due to sorting the keys of the frequency map.

### Space Complexity 💾
- **Best Case:** O(n) - The space complexity remains O(n) even in the best case.
- **Worst Case:** O(n) - The space complexity is O(n) because of the frequency map storing all elements.

The space complexity is O(n) due to the frequency map used to track the elements.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
