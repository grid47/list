
+++
authors = ["grid47"]
title = "Leetcode 532: K-diff Pairs in an Array"
date = "2024-09-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 532: K-diff Pairs in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Two Pointers","Binary Search","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/532.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/532.webp" 
    alt="An array where each valid pair with a difference of `k` is softly illuminated."
    caption="Solution to LeetCode 532: K-diff Pairs in an Array Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array. A k-diff pair is a pair of integers (nums[i], nums[j]) where the absolute difference between the values of the pair is k, and i != j.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers nums and an integer k. The array can have up to 10^4 elements, and k is a non-negative integer.
- **Example:** `Input: nums = [5, 1, 6, 1, 8], k = 3`
- **Constraints:**
	- 1 <= nums.length <= 10^4
	- -10^7 <= nums[i] <= 10^7
	- 0 <= k <= 10^7

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of unique k-diff pairs in the array.
- **Example:** `Output: 2`
- **Constraints:**
	- The output should be the number of unique pairs with the specified absolute difference.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find all unique pairs (i, j) such that the absolute difference between nums[i] and nums[j] equals k.

- Count the occurrences of each number in the array using a hashmap.
- For each number in the hashmap, check if a pair exists that satisfies the absolute difference of k.
- If k is greater than 0, check if nums[i] - k exists in the map.
- If k is equal to 0, check if a number appears more than once in the map.
{{< dots >}}
### Problem Assumptions ✅
- The array contains at least one number.
- The input value k is a valid non-negative integer.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [5, 1, 6, 1, 8], k = 3`  \
  **Explanation:** There are two pairs with a difference of 3: (1, 4) and (5, 8). Since the pairs are unique, the output is 2.

{{< dots >}}
## Approach 🚀
To solve this problem efficiently, we will use a hashmap to store the frequency of each element in the array and check for the existence of the required pairs.

### Initial Thoughts 💭
- Using a hashmap to count occurrences of numbers allows for efficient lookups when checking for pairs.
- If k is 0, we need to check for duplicates, while for k > 0, we need to find numbers that differ by k.
{{< dots >}}
### Edge Cases 🌐
- If the input array is empty, return 0.
- Handle cases with the maximum number of elements efficiently using a hashmap.
- Consider the case when k = 0, where the only valid pairs are those that have duplicates.
- Ensure that pairs are counted uniquely and that duplicates are handled correctly.
{{< dots >}}
## Code 💻
```cpp
int findPairs(vector<int>& nums, int k) {
    map<int, int> mp;
    for(int i : nums)
        mp[i]++;
    int res = 0;
    for(auto const &[i, j] : mp)
        if((k > 0 && mp.count(i - k)) ||
          (k == 0 && (j > 1)) )
            res++;
    return res;
}
```

This function counts the number of unique pairs in the array `nums` such that their absolute difference is equal to `k`. It uses a hash map to store the frequency of each element and checks the conditions based on the value of `k`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition, Hash Map Usage**
	```cpp
	int findPairs(vector<int>& nums, int k) {
	```
	Defines the `findPairs` function, which takes an integer array `nums` and an integer `k` as input and returns the number of unique pairs with the absolute difference equal to `k`.

2. **Map Initialization**
	```cpp
	    map<int, int> mp;
	```
	Initializes a hash map `mp` where the keys are the elements of the array `nums`, and the values are the frequency of those elements.

3. **Loop, Array Traversal**
	```cpp
	    for(int i : nums)
	```
	Iterates through each element `i` in the array `nums`.

4. **Count Elements**
	```cpp
	        mp[i]++;
	```
	Increments the count of the current element `i` in the map `mp`. This stores the frequency of each element in the array.

5. **Initialize Result**
	```cpp
	    int res = 0;
	```
	Initializes the variable `res` to store the result, i.e., the number of pairs with the required absolute difference.

6. **Iterate over Map**
	```cpp
	    for(auto const &[i, j] : mp)
	```
	Iterates through the map `mp`, where `i` is the key (the element of the array) and `j` is the value (the frequency of that element).

7. **Condition for k > 0**
	```cpp
	        if((k > 0 && mp.count(i - k)) ||
	```
	Checks if `k > 0` and if the map contains an element `i - k` (the complement of the current element `i` that would form a pair with the absolute difference `k`).

8. **Condition for k == 0**
	```cpp
	          (k == 0 && (j > 1)) )
	```
	Checks if `k == 0` and the frequency of the current element `i` is greater than 1, indicating that there is at least one duplicate, forming a valid pair.

9. **Increment Result**
	```cpp
	            res++;
	```
	Increments the result `res` if the conditions for a valid pair are met.

10. **Return Result**
	```cpp
	    return res;
	```
	Returns the final count of valid pairs.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the number of elements in the input array. This is due to the hashmap creation and lookups.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n), as we use a hashmap to store the frequency of each element in the array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/k-diff-pairs-in-an-array/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
