
+++
authors = ["grid47"]
title = "Leetcode 2870: Minimum Number of Operations to Make Array Empty"
date = "2024-01-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2870: Minimum Number of Operations to Make Array Empty in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "_AcO35R0fss"
youtube_upload_date="2024-01-04"
youtube_thumbnail="https://i.ytimg.com/vi/_AcO35R0fss/maxresdefault.jpg"
comments = true
+++



---
You are given an array nums consisting of positive integers. You are allowed to perform two types of operations on the array any number of times: (1) Choose two elements that are the same and remove them from the array. (2) Choose three elements that are the same and remove them from the array. Your task is to return the minimum number of operations required to empty the array, or return -1 if it is not possible to empty the array using these operations.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of positive integers nums. You need to apply operations to empty the array.
- **Example:** `nums = [3, 1, 3, 3, 2, 2, 1, 2, 1]`
- **Constraints:**
	- 2 <= nums.length <= 105
	- 1 <= nums[i] <= 106

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of operations required to empty the array, or return -1 if it is not possible to empty the array.
- **Example:** `For input nums = [3, 1, 3, 3, 2, 2, 1, 2, 1], the output is 4.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to minimize the number of operations required to remove all elements from the array, using the two defined operations.

- Count the frequency of each element in the array.
- For each element, check if its count can be divided into valid pairs or triples for removal.
- If any element has a count of 1, return -1 since it can't be removed.
- For other elements, calculate the number of operations required by grouping them in pairs or triples.
{{< dots >}}
### Problem Assumptions ✅
- The array is non-empty and contains only positive integers.
{{< dots >}}
## Examples 🧩
- **Input:** `For input nums = [3, 1, 3, 3, 2, 2, 1, 2, 1], the output is 4.`  \
  **Explanation:** We can apply the operations in sequence to remove the elements and make the array empty in 4 operations.

{{< dots >}}
## Approach 🚀
The solution involves counting the frequency of each element in the array and then applying the operations as efficiently as possible to minimize the number of operations.

### Initial Thoughts 💭
- We need to group elements in pairs or triples to remove them efficiently.
- A simple approach is to count the frequency of each element and then determine how many operations are needed to remove all occurrences of that element.
{{< dots >}}
### Edge Cases 🌐
- The array will always have at least two elements.
- The algorithm should handle large arrays efficiently (up to 100,000 elements).
- If an element appears only once, it is impossible to remove it.
- The solution must account for arrays containing large numbers of repeated elements.
{{< dots >}}
## Code 💻
```cpp
int minOperations(vector<int>& nums) {
    unordered_map<int, int> m;
    for (int n : nums)
        ++m[n];
    int res = 0;
    for (auto [_, cnt] : m) {
        if (cnt == 1)
            return -1;
        res += cnt / 3 + (cnt % 3 > 0);
    }
    return res;
}
```

This function calculates the minimum number of operations required to group elements in the array into groups of 3, returning -1 if any element appears only once.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Code Declaration**
	```cpp
	int minOperations(vector<int>& nums) {
	```
	Function declaration that takes a vector of integers as input, returning an integer result.

2. **Variable Initialization**
	```cpp
	    unordered_map<int, int> m;
	```
	Initialize an unordered map to store the frequency of each element in the nums vector.

3. **Loop Setup**
	```cpp
	    for (int n : nums)
	```
	Start a for-each loop to iterate over each element in the nums vector.

4. **Frequency Count**
	```cpp
	        ++m[n];
	```
	Increment the count for the current element in the unordered map m.

5. **Result Initialization**
	```cpp
	    int res = 0;
	```
	Initialize the result variable to 0, which will hold the total number of operations.

6. **Map Iteration**
	```cpp
	    for (auto [_, cnt] : m) {
	```
	Iterate through the unordered map, where _ represents the element (not used) and cnt represents its frequency.

7. **Condition Check**
	```cpp
	        if (cnt == 1)
	```
	Check if the current frequency of the element is 1.

8. **Early Return**
	```cpp
	            return -1;
	```
	If an element appears only once, return -1, as grouping is not possible.

9. **Result Calculation**
	```cpp
	        res += cnt / 3 + (cnt % 3 > 0);
	```
	Calculate the number of operations for the current element by dividing its frequency by 3 and adding 1 if there is a remainder.

10. **Return Result**
	```cpp
	    return res;
	```
	Return the final result, which is the total number of operations.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we only need to traverse the array once to count element frequencies.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) for storing the frequency counts of each element.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/description/)

---
{{< youtube _AcO35R0fss >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
