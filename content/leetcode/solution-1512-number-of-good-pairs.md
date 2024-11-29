
+++
authors = ["grid47"]
title = "Leetcode 1512: Number of Good Pairs"
date = "2024-06-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1512: Number of Good Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "BqhDFUo1rjs"
youtube_upload_date="2023-10-03"
youtube_thumbnail="https://i.ytimg.com/vi_webp/BqhDFUo1rjs/maxresdefault.webp"
comments = true
+++



---
You are given an array of integers. A pair (i, j) is called a good pair if nums[i] == nums[j] and i < j. Your task is to find the number of good pairs in the array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array nums where each element can range from 1 to 100.
- **Example:** `nums = [4, 5, 6, 4, 4, 6]`
- **Constraints:**
	- 1 <= nums.length <= 100
	- 1 <= nums[i] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the total number of good pairs in the array.
- **Example:** `4`
- **Constraints:**
	- Return the result as an integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the number of good pairs by checking all pairs of indices in the array where the elements are equal and the first index is less than the second.

- Step 1: Iterate through the array and store the frequency of each element using a hashmap.
- Step 2: For each element, calculate the number of good pairs that can be formed using the frequency of that element.
- Step 3: Return the total count of good pairs.
{{< dots >}}
### Problem Assumptions ✅
- The array has at least one element.
- The elements are integers between 1 and 100.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [4, 5, 6, 4, 4, 6]`  \
  **Explanation:** In this case, the good pairs are formed by the elements 4 and 6. We can count the pairs by using the frequency of each element.

- **Input:** `nums = [2, 2, 2, 2]`  \
  **Explanation:** Since all elements are equal, every pair is a good pair. The total number of good pairs is calculated by the combination formula C(n, 2), where n is the number of occurrences of the element.

{{< dots >}}
## Approach 🚀
To find the number of good pairs, we use a hashmap to track the frequency of each element. For each element, we calculate how many good pairs can be formed by its frequency.

### Initial Thoughts 💭
- The solution involves calculating combinations from the frequencies of each element.
- Consider using a hashmap to store the frequency of elements, which allows for an efficient calculation of good pairs.
{{< dots >}}
### Edge Cases 🌐
- The array is guaranteed to have at least one element.
- Ensure the solution handles arrays with a length up to 100 efficiently.
- Handle cases where all elements are the same, or where all elements are distinct.
- Ensure that the algorithm is efficient enough to handle the maximum array length of 100.
{{< dots >}}
## Code 💻
```cpp
int numIdenticalPairs(vector<int>& A) {
    int res = 0;
    unordered_map<int, int> count;
    for (int a: A) {
        res += count[a]++;
    }
    return res;   
}
```

This code defines the `numIdenticalPairs` function that calculates the number of good pairs in the input array `A`. A good pair is defined as two indices `i` and `j` where `i < j` and `A[i] == A[j].` The function uses an unordered map to track the frequency of each element and efficiently counts the number of pairs.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int numIdenticalPairs(vector<int>& A) {
	```
	Defines the `numIdenticalPairs` function that takes a vector of integers `A` as input and aims to calculate the number of good pairs in the array.

2. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	Initializes a variable `res` to 0. This will store the count of good pairs found in the array.

3. **Data Structure Initialization**
	```cpp
	    unordered_map<int, int> count;
	```
	Initializes an unordered map `count` that will store the frequency of each element in the array `A`. The map's key is the element, and the value is the count of occurrences.

4. **Loop Start**
	```cpp
	    for (int a: A) {
	```
	Starts a loop that iterates through each element `a` in the array `A`.

5. **Frequency Update**
	```cpp
	        res += count[a]++;
	```
	Increments `res` by the current frequency of element `a` (before it is incremented) and then increases the frequency of `a` in the `count` map. This is how the number of good pairs is calculated.

6. **Return Result**
	```cpp
	    return res;   
	```
	Returns the final count of good pairs stored in `res`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the number of elements in the array. This is because we iterate through the array once to build the hashmap.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n), as we store the frequency of each element in the hashmap.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-good-pairs/description/)

---
{{< youtube BqhDFUo1rjs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
