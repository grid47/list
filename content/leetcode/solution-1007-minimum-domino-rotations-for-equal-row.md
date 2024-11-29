
+++
authors = ["grid47"]
title = "Leetcode 1007: Minimum Domino Rotations For Equal Row"
date = "2024-07-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1007: Minimum Domino Rotations For Equal Row in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
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
You are given two arrays, tops and bottoms, where each array represents the top and bottom halves of a series of dominoes. A domino can be rotated, which means swapping its top and bottom halves. The task is to determine the minimum number of rotations required to make either the entire top row or the bottom row consist of the same value. If it is not possible to achieve this, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two arrays of integers, tops and bottoms, where 1 <= tops.length == bottoms.length <= 2 * 10^4 and 1 <= tops[i], bottoms[i] <= 6.
- **Example:** `tops = [2, 1, 3, 4], bottoms = [4, 1, 2, 3]`
- **Constraints:**
	- 1 <= tops.length == bottoms.length <= 2 * 10^4
	- 1 <= tops[i], bottoms[i] <= 6

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of rotations required to make all elements in either the top or bottom row equal. If it is not possible, return -1.
- **Example:** `Output: 1`
- **Constraints:**
	- If no rotations can achieve a uniform row, return -1.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine the minimum number of rotations needed to make all elements in either the top or bottom row the same. If not possible, return -1.

- Count the frequency of each value in both the top and bottom rows.
- For each value that appears in both rows, check if rotating dominoes can make either row uniform with that value.
- Keep track of the minimum number of rotations required and return the result.
{{< dots >}}
### Problem Assumptions ✅
- The values in the tops and bottoms arrays are between 1 and 6.
- The dominoes can be rotated to swap the top and bottom values.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: tops = [2, 1, 2, 4, 2, 2], bottoms = [5, 2, 6, 2, 3, 2]`  \
  **Explanation:** In this case, rotating the second and fourth dominoes will make the top row equal to 2 with only 2 rotations.

- **Input:** `Input: tops = [3, 5, 1, 2, 3], bottoms = [3, 6, 3, 3, 4]`  \
  **Explanation:** In this case, it is impossible to make either row uniform with the same value, so the output is -1.

{{< dots >}}
## Approach 🚀
The approach is to check if we can achieve a uniform row by rotating dominoes. We will consider each value that appears in both rows and calculate the number of rotations needed to make all elements in either the top or bottom row the same value.

### Initial Thoughts 💭
- We need to ensure that we can align all values in one row either by keeping them as they are or rotating the corresponding dominoes.
- We can iterate through the dominoes and check if it's possible to make all top values or all bottom values equal for any common value.
{{< dots >}}
### Edge Cases 🌐
- The input arrays will never be empty, as per the problem constraints.
- The solution should efficiently handle input arrays with lengths up to 2 * 10^4.
- If all values in either row are already the same, no rotations are needed.
- The solution must handle the largest case efficiently, requiring a linear solution in terms of the length of the input arrays.
{{< dots >}}
## Code 💻
```cpp
int minDominoRotations(vector<int>& top, vector<int>& bottom) {
    map<int, int> mp;
    vector<int> tc(7, 0), uc(7, 0);
    int n = top.size();
    for(int i = 0; i < n; i++) {
        if(bottom[i] != top[i]) {
            mp[bottom[i]]++;
            mp[top[i]]++;
        } else mp[top[i]]++;

        uc[bottom[i]]++;
        tc[top[i]]++;
    }
    
    vector<int> opt;
    for(auto it: mp) {
        if(it.second == n)
            opt.push_back(it.first);
    }
    if(opt.empty()) return -1;
    
    int res = INT_MAX;
    for(int x: opt) {
        if(uc[x] == n || tc[x] == n) return 0;
        res = min(res, n - uc[x]);
        res = min(res, n - tc[x]);
    }
    return res;
}
```

This function calculates the minimum number of rotations needed to make all the dominoes in both top and bottom arrays show the same number. It uses a map to track occurrences of each number and calculates the minimum rotation based on the condition.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int minDominoRotations(vector<int>& top, vector<int>& bottom) {
	```
	Declares the main function which takes two vectors, top and bottom, representing the top and bottom numbers of each domino.

2. **Map Initialization**
	```cpp
	    map<int, int> mp;
	```
	Initializes a map to store the frequency of each number across both top and bottom arrays.

3. **Vector Initialization**
	```cpp
	    vector<int> tc(7, 0), uc(7, 0);
	```
	Initializes two vectors, tc and uc, each of size 7 to track the count of numbers on top and bottom, respectively.

4. **Variable Initialization**
	```cpp
	    int n = top.size();
	```
	Sets the variable n to the size of the top vector, which represents the number of dominoes.

5. **Loop Begin**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Starts a loop that iterates through each domino in the top and bottom arrays.

6. **Condition Check**
	```cpp
	        if(bottom[i] != top[i]) {
	```
	Checks if the top and bottom values for the current domino are different.

7. **Map Update**
	```cpp
	            mp[bottom[i]]++;
	```
	Increases the count for the bottom value in the map.

8. **Map Update**
	```cpp
	            mp[top[i]]++;
	```
	Increases the count for the top value in the map.

9. **Same Number Check**
	```cpp
	        } else mp[top[i]]++;
	```
	If the top and bottom values are the same, just increase the count for the top value in the map.

10. **Vector Update**
	```cpp
	        uc[bottom[i]]++;
	```
	Increases the count for the bottom number in the uc vector.

11. **Vector Update**
	```cpp
	        tc[top[i]]++;
	```
	Increases the count for the top number in the tc vector.

12. **Optional Numbers**
	```cpp
	    vector<int> opt;
	```
	Initializes a vector to store the numbers that could be used for the minimum rotation.

13. **Map Iteration**
	```cpp
	    for(auto it: mp) {
	```
	Iterates through the map to find which numbers appear in all the dominoes.

14. **Condition Check**
	```cpp
	        if(it.second == n)
	```
	Checks if a number appears in all dominoes (top and bottom arrays combined).

15. **Vector Update**
	```cpp
	            opt.push_back(it.first);
	```
	Adds the number to the options vector if it appears in all dominoes.

16. **Empty Check**
	```cpp
	    if(opt.empty()) return -1;
	```
	If no numbers can be used for rotation, return -1 indicating it's not possible.

17. **Result Initialization**
	```cpp
	    int res = INT_MAX;
	```
	Initializes the result variable with the maximum possible value to find the minimum rotations.

18. **Option Iteration**
	```cpp
	    for(int x: opt) {
	```
	Iterates through the possible numbers in the options vector to find the minimum rotations.

19. **Condition Check**
	```cpp
	        if(uc[x] == n || tc[x] == n) return 0;
	```
	Checks if all dominoes can already show the same number either on the top or bottom.

20. **Result Update**
	```cpp
	        res = min(res, n - uc[x]);
	```
	Calculates the minimum number of rotations needed for the bottom values.

21. **Result Update**
	```cpp
	        res = min(res, n - tc[x]);
	```
	Calculates the minimum number of rotations needed for the top values.

22. **Return Result**
	```cpp
	    return res;
	```
	Returns the minimum number of rotations needed.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the number of dominoes, as we process each domino a constant number of times.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1), as we only need a few extra variables to track counts of numbers in the rows.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
