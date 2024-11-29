
+++
authors = ["grid47"]
title = "Leetcode 954: Array of Doubled Pairs"
date = "2024-08-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 954: Array of Doubled Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Q0WKzdpR74o"
youtube_upload_date="2020-04-27"
youtube_thumbnail="https://i.ytimg.com/vi/Q0WKzdpR74o/maxresdefault.jpg"
comments = true
+++



---
Given an integer array of even length, determine if it is possible to reorder the array such that for every index i, arr[2 * i + 1] = 2 * arr[2 * i] holds true. If it is possible to reorder the array in this way, return true, otherwise return false.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers, arr, with even length.
- **Example:** `Input: arr = [6, 3, 4, 8]`
- **Constraints:**
	- 2 <= arr.length <= 30000
	- arr.length is even.
	- -105 <= arr[i] <= 105

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a boolean value: true if the array can be reordered as described, false otherwise.
- **Example:** `Output: true`
- **Constraints:**
	- The output will be a boolean indicating if the array can be reordered accordingly.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check whether we can reorder the elements in pairs such that each second element is twice the first element.

- 1. Create a frequency map to count occurrences of each element.
- 2. Sort the unique elements by their absolute values.
- 3. For each element, check if the frequency of its double exists. If not, return false.
- 4. Adjust the frequencies accordingly after each pair is formed.
- 5. If all elements are successfully paired, return true; otherwise, return false.
{{< dots >}}
### Problem Assumptions ✅
- The array will always have an even number of elements.
- We assume the input array is non-empty.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: arr = [6, 3, 4, 8]`  \
  **Explanation:** In this case, we cannot reorder the array such that for every i, arr[2 * i + 1] = 2 * arr[2 * i] because the elements do not form valid pairs.

- **Input:** `Input: arr = [4, -2, 2, -4]`  \
  **Explanation:** Here, we can form pairs [-2, -4] and [2, 4], so the array can be reordered to form a valid sequence.

{{< dots >}}
## Approach 🚀
The approach involves sorting the elements of the array based on their absolute values and then checking if we can pair each element with its double while adjusting frequencies.

### Initial Thoughts 💭
- The key observation is that we need to pair each element with its double, so sorting the elements will allow us to efficiently check this condition.
- Using a frequency map to track the occurrences of elements is an efficient way to ensure we can match each element with its double.
{{< dots >}}
### Edge Cases 🌐
- The input will not be empty as the length of the array is guaranteed to be at least 2.
- For large arrays up to the size limit of 30000, the solution should run in linearithmic time due to sorting, followed by linear passes for pairing.
- Special values like 0 and negative numbers are valid as long as they satisfy the pairing condition.
- The algorithm must run efficiently for large input sizes, particularly for arrays of length up to 30000.
{{< dots >}}
## Code 💻
```cpp
bool canReorderDoubled(vector<int>& arr) {
    
    unordered_map<int, int> c;
    for(int i : arr)
        c[i]++;
    
    vector<int> keys;
    for(auto it: c)
        keys.push_back(it.first);
    
    sort(keys.begin(), keys.end(), [&](int a, int b){
        return abs(a) < abs(b);
    });
    
    for(int x: keys) {
        if(c[x] > c[2 * x])
            return false;
        c[2 * x] -= c[x];
    }
    
    return true;
}
```

This function checks if the given array can be reordered to form pairs such that every pair consists of one element and its double. It uses a frequency map and sorts keys by absolute value for correct pairing.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool canReorderDoubled(vector<int>& arr) {
	```
	The function `canReorderDoubled` takes an array and determines if it can be reordered to form valid (x, 2x) pairs.

2. **Map Initialization**
	```cpp
	    unordered_map<int, int> c;
	```
	Create a hash map `c` to count the frequency of each element in the array.

3. **Frequency Calculation**
	```cpp
	    for(int i : arr)
	```
	Iterate through the array to populate the frequency map `c`.

4. **Increment Frequency**
	```cpp
	        c[i]++;
	```
	Increase the count of the current element in the frequency map.

5. **Key Extraction**
	```cpp
	    vector<int> keys;
	```
	Create a vector `keys` to store unique elements from the frequency map.

6. **Iterate Map**
	```cpp
	    for(auto it: c)
	```
	Iterate through the frequency map to extract unique keys.

7. **Push Keys**
	```cpp
	        keys.push_back(it.first);
	```
	Push each unique key into the `keys` vector for further processing.

8. **Sort Keys**
	```cpp
	    sort(keys.begin(), keys.end(), [&](int a, int b){
	```
	Sort the keys in ascending order of their absolute values using a lambda function.

9. **Absolute Value Comparison**
	```cpp
	        return abs(a) < abs(b);
	```
	Compare the absolute values of two elements to determine their order.

10. **Iterate Keys**
	```cpp
	    for(int x: keys) {
	```
	Iterate through the sorted keys to verify the (x, 2x) pairs.

11. **Pair Check**
	```cpp
	        if(c[x] > c[2 * x])
	```
	If there are more occurrences of `x` than `2x`, the pairing is invalid.

12. **Return False**
	```cpp
	            return false;
	```
	Return `false` immediately if a valid pair cannot be formed for the current key.

13. **Adjust Frequency**
	```cpp
	        c[2 * x] -= c[x];
	```
	Adjust the frequency of `2x` by subtracting the count of `x` after pairing.

14. **Return True**
	```cpp
	    return true;
	```
	Return `true` indicating the array can be reordered to form valid pairs.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is O(n log n) due to the sorting step, followed by linear scans to check the pairing conditions.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage required for the frequency map and the sorted keys.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/array-of-doubled-pairs/description/)

---
{{< youtube Q0WKzdpR74o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
