
+++
authors = ["grid47"]
title = "Leetcode 823: Binary Trees With Factors"
date = "2024-08-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 823: Binary Trees With Factors in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Dynamic Programming","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "vzjMGYUG7qY"
youtube_upload_date="2021-03-13"
youtube_thumbnail="https://i.ytimg.com/vi/vzjMGYUG7qY/maxresdefault.jpg"
comments = true
+++



---
Given an array of unique integers, where each integer is greater than 1, we can create a binary tree using these integers. The value of each non-leaf node must be the product of the values of its children. The goal is to return the number of distinct binary trees that can be constructed. Since the result may be large, return the answer modulo 10^9 + 7.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single array of unique integers, arr, where each integer is strictly greater than 1.
- **Example:** `Input: arr = [3, 6]`
- **Constraints:**
	- 1 <= arr.length <= 1000
	- 2 <= arr[i] <= 10^9
	- All the values of arr are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an integer representing the number of distinct binary trees that can be constructed, modulo 10^9 + 7.
- **Example:** `Output: 5`
- **Constraints:**
	- The output must be an integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** To solve this problem, we need to calculate the number of valid binary trees that can be formed by using the integers from the input array. The non-leaf nodes should be the product of their children, and each integer in the array can be used multiple times.

- Step 1: Sort the array of integers.
- Step 2: Use dynamic programming to calculate the number of valid binary trees for each number in the array, considering that each number can be the product of other integers in the array.
- Step 3: Use a map to store the number of binary trees for each number. For each number, check if it can be the product of any two smaller numbers in the array, and update the count accordingly.
- Step 4: Return the sum of all the counts modulo 10^9 + 7.
{{< dots >}}
### Problem Assumptions ✅
- The input array contains unique integers, and each integer is greater than 1.
- The binary tree structure allows for repeated use of the integers from the array.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: arr = [3, 6]`  \
  **Explanation:** In this case, the number of distinct binary trees that can be constructed is 5. The possible trees are [3], [6], [3, 3, 3], [6, 3, 2], and [6, 2, 3].

- **Input:** `Input: arr = [2, 4, 5, 10]`  \
  **Explanation:** Here, the possible binary trees are: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], and [10, 5, 2]. The total count is 7.

{{< dots >}}
## Approach 🚀
The approach involves using dynamic programming to count the number of binary trees that can be made from each number in the array. By considering each number as a possible root and checking for valid products among smaller numbers, we can efficiently compute the solution.

### Initial Thoughts 💭
- We need to calculate how many ways we can factor each number in the array using smaller numbers from the array.
- Dynamic programming is ideal for this problem since we can build the solution incrementally by considering smaller subproblems first.
{{< dots >}}
### Edge Cases 🌐
- The problem does not have empty input cases since the array always contains at least one element.
- The solution should handle arrays with up to 1000 elements efficiently.
- Consider cases where the array has only one element, or where no valid products can be formed.
- The solution must compute the result efficiently even for large arrays and large integer values.
{{< dots >}}
## Code 💻
```cpp
int numFactoredBinaryTrees(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    unordered_map<int, long> rootWithCount;
    rootWithCount[arr[0]] = 1;
    for(int i = 0; i < arr.size(); i++) {
        long count = 1;
        for(auto j : rootWithCount) {
            int root = j.first;
            if((arr[i] % root == 0) && (rootWithCount.find(arr[i]/root) != rootWithCount.end())) {
                count += rootWithCount[root] * rootWithCount[arr[i]/root];
            }
        }
        rootWithCount[arr[i]] = count;
    }
    int no = 0;
    for(auto it: rootWithCount) no = (no + it.second) % (int)(1e9+7);
    return no;
}
```

This function calculates the number of binary trees that can be formed using the given factors. The function first sorts the array, then computes the number of ways each element can be a root of a binary tree, storing the results in a map.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int numFactoredBinaryTrees(vector<int>& arr) {
	```
	The function `numFactoredBinaryTrees` is defined to take an array `arr` as input, where each element represents a potential factor to form binary trees.

2. **Sorting**
	```cpp
	    sort(arr.begin(), arr.end());
	```
	The array `arr` is sorted in ascending order, which helps in ensuring that smaller numbers (potential roots) are considered first when counting possible trees.

3. **Map Initialization**
	```cpp
	    unordered_map<int, long> rootWithCount;
	```
	An unordered map `rootWithCount` is initialized to store the number of binary trees that can be rooted at each element in the array.

4. **Base Case**
	```cpp
	    rootWithCount[arr[0]] = 1;
	```
	The first element in the sorted array is initialized with a count of 1, meaning that it can form one tree by itself.

5. **Outer Loop**
	```cpp
	    for(int i = 0; i < arr.size(); i++) {
	```
	The loop iterates over each element `arr[i]` in the sorted array, calculating how many binary trees can be rooted at that element.

6. **Count Initialization**
	```cpp
	        long count = 1;
	```
	A variable `count` is initialized to 1, representing the minimum number of binary trees that can be rooted at `arr[i]` (itself as a single node tree).

7. **Inner Loop**
	```cpp
	        for(auto j : rootWithCount) {
	```
	This inner loop iterates over the map `rootWithCount` to check which previously encountered roots can combine with `arr[i]` to form a binary tree.

8. **Root Assignment**
	```cpp
	            int root = j.first;
	```
	The `root` variable is assigned the key from the map `rootWithCount`, representing a previously encountered potential root for binary trees.

9. **Factor Check**
	```cpp
	            if((arr[i] % root == 0) && (rootWithCount.find(arr[i]/root) != rootWithCount.end())) {
	```
	This condition checks if `arr[i]` can be factored by the current `root` and if the factor `arr[i] / root` also exists in the map `rootWithCount`.

10. **Count Update**
	```cpp
	                count += rootWithCount[root] * rootWithCount[arr[i]/root];
	```
	If the factorization condition holds, the number of binary trees rooted at `arr[i]` is updated by adding the product of the tree counts for `root` and `arr[i] / root`.

11. **Store Result**
	```cpp
	        rootWithCount[arr[i]] = count;
	```
	After processing all possible factors, the final count of binary trees rooted at `arr[i]` is stored in the map `rootWithCount`.

12. **Final Result Initialization**
	```cpp
	    int no = 0;
	```
	The variable `no` is initialized to 0, which will hold the final result — the total number of binary trees that can be formed.

13. **Final Sum Calculation**
	```cpp
	    for(auto it: rootWithCount) no = (no + it.second) % (int)(1e9+7);
	```
	The map `rootWithCount` is iterated over, and the total count of binary trees is calculated by summing up all the values. The result is taken modulo 1e9 + 7 to avoid overflow.

14. **Return Statement**
	```cpp
	    return no;
	```
	The final result `no`, which contains the total number of binary trees, is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2), where n is the number of integers in the array.
- **Average Case:** O(n^2), where n is the number of integers in the array.
- **Worst Case:** O(n^2), where n is the number of integers in the array.

The time complexity is quadratic due to the nested loop that checks for factor pairs for each number in the array.

### Space Complexity 💾
- **Best Case:** O(n), where n is the number of integers in the array, for storing the number of binary trees for each number.
- **Worst Case:** O(n), where n is the number of integers in the array, for storing the number of binary trees for each number.

The space complexity is linear because we need to store the number of valid binary trees for each number.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/binary-trees-with-factors/description/)

---
{{< youtube vzjMGYUG7qY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
