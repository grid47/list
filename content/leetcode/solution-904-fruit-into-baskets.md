
+++
authors = ["grid47"]
title = "Leetcode 904: Fruit Into Baskets"
date = "2024-08-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 904: Fruit Into Baskets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "GVecnelW8mA"
youtube_upload_date="2020-12-28"
youtube_thumbnail="https://i.ytimg.com/vi_webp/GVecnelW8mA/maxresdefault.webp"
comments = true
+++



---
You are visiting a farm where fruit trees are planted in a single row from left to right. Each tree produces one type of fruit, represented by an integer array `fruits`, where `fruits[i]` is the type of fruit the ith tree produces. You have two baskets, and each basket can hold an unlimited amount of one type of fruit. Starting from any tree, you must pick exactly one fruit from each tree while moving to the right until the fruits cannot fit into your baskets. Determine the maximum number of fruits you can collect.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** An integer array `fruits` representing the types of fruits on trees in a row.
- **Example:** `Input: fruits = [3, 3, 1, 2, 3]`
- **Constraints:**
	- 1 <= fruits.length <= 10^5
	- 0 <= fruits[i] < fruits.length

{{< dots >}}
### Output Specifications 📤
- **Output:** An integer representing the maximum number of fruits you can collect.
- **Example:** `Output: 4`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Calculate the longest subarray containing at most two unique numbers, representing the fruit types that fit into two baskets.

- Use a sliding window to maintain the current subarray of fruit types.
- Keep track of the frequency of each fruit type in the window.
- If the number of unique fruit types exceeds two, adjust the window size by incrementing the starting index.
- Update the maximum length of the window whenever it contains at most two unique fruit types.
{{< dots >}}
### Problem Assumptions ✅
- The fruit array is non-empty.
- Each fruit type is represented by a non-negative integer.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: fruits = [3, 3, 1, 2, 3]`  \
  **Explanation:** Start picking fruits at index 0. Collect fruits from trees [3, 3, 1, 2] before encountering the third type of fruit. Maximum fruits collected: 4.

- **Input:** `Input: fruits = [1, 2, 2, 3]`  \
  **Explanation:** Start picking fruits at index 1. Collect fruits from trees [2, 2, 3]. Maximum fruits collected: 3.

{{< dots >}}
## Approach 🚀
Use a sliding window and hash map to track fruit types and their frequencies. Adjust the window to maintain at most two types of fruits while maximizing the collected count.

### Initial Thoughts 💭
- This problem can be solved using the sliding window technique.
- We need to track the fruit types and their counts in the current window.
- The key is to maintain a window of at most two unique fruit types.
{{< dots >}}
### Edge Cases 🌐
- Input array has only one tree.
- Input array is of length 100,000 with alternating fruit types.
- All trees produce the same type of fruit.
- Large arrays with more than two unique fruit types repeated frequently.
{{< dots >}}
## Code 💻
```cpp
int totalFruit(vector<int>& fruits) {
    // longest len of sub arr with at most two elements
    map<int, int> mp;
    int j = 0, res = 0, dst = 0;
    
    for(int i = 0; i < fruits.size(); i++) {
        mp[fruits[i]]++;
        if(mp[fruits[i]] == 1) dst++;

        if(dst <= 2) res = max(res, i - j + 1);

        while(dst > 2 && j < i) {
            mp[fruits[j]]--;
            if(mp[fruits[j]] == 0) dst--;
            j++;
        }
    }
    return res;
}
```

This function calculates the longest length of a contiguous subarray with at most two distinct elements using a sliding window approach.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int totalFruit(vector<int>& fruits) {
	```
	Define the function 'totalFruit' which takes a vector of integers representing fruits as input and returns an integer representing the longest subarray with at most two distinct elements.

2. **Variable Declaration**
	```cpp
	    map<int, int> mp;
	```
	A map 'mp' is used to store the count of each fruit in the current sliding window.

3. **Variable Initialization**
	```cpp
	    int j = 0, res = 0, dst = 0;
	```
	Initialize variables: 'j' for the left boundary of the window, 'res' for storing the maximum length of the subarray, and 'dst' for tracking the number of distinct fruits in the window.

4. **Loop**
	```cpp
	    for(int i = 0; i < fruits.size(); i++) {
	```
	Iterate through the 'fruits' array using 'i' as the right boundary of the sliding window.

5. **Map Update**
	```cpp
	        mp[fruits[i]]++;
	```
	Increment the count of the current fruit in the map.

6. **Distinct Count Update**
	```cpp
	        if(mp[fruits[i]] == 1) dst++;
	```
	If the count of the current fruit becomes 1 (i.e., it is newly added to the window), increment the distinct fruit count ('dst').

7. **Subarray Update**
	```cpp
	        if(dst <= 2) res = max(res, i - j + 1);
	```
	If the window contains at most two distinct fruits, update the result with the maximum length of the subarray (i - j + 1).

8. **Inner While Loop**
	```cpp
	        while(dst > 2 && j < i) {
	```
	If the window contains more than two distinct fruits, move the left boundary 'j' to shrink the window until it contains at most two distinct fruits.

9. **Map Update**
	```cpp
	            mp[fruits[j]]--;
	```
	Decrement the count of the fruit at the left boundary 'j' to reduce its frequency in the window.

10. **Distinct Count Update**
	```cpp
	            if(mp[fruits[j]] == 0) dst--;
	```
	If the count of the fruit at 'j' becomes 0, decrement the distinct fruit count ('dst').

11. **Left Boundary Update**
	```cpp
	            j++;
	```
	Increment 'j' to shrink the left boundary of the window.

12. **Return Statement**
	```cpp
	    return res;
	```
	Return the result, which is the length of the longest subarray with at most two distinct elements.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

Each fruit is processed at most twice—once when added to the window and once when removed.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The hash map stores at most two unique keys at any time.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/fruit-into-baskets/description/)

---
{{< youtube GVecnelW8mA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
