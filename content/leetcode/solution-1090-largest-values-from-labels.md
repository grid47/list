
+++
authors = ["grid47"]
title = "Leetcode 1090: Largest Values From Labels"
date = "2024-07-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1090: Largest Values From Labels in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Sorting","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "E0OkE3G95vU"
youtube_upload_date="2020-12-06"
youtube_thumbnail="https://i.ytimg.com/vi/E0OkE3G95vU/maxresdefault.jpg"
comments = true
+++



---
You are given two arrays, `values` and `labels`, representing the value and label of items, respectively. Your goal is to choose a subset of items with the maximum sum of values such that the number of items selected is at most `numWanted` and no label appears more than `useLimit` times in the subset. Return the maximum possible sum of the values from the selected subset of items.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two arrays: `values` and `labels` of length `n`, where each element in `values` represents the value of the corresponding item, and each element in `labels` represents the label of the corresponding item. Additionally, you are given two integers: `numWanted` (the maximum number of items that can be selected) and `useLimit` (the maximum number of items that can be selected with the same label).
- **Example:** `Input: values = [10, 8, 5, 4, 3], labels = [1, 1, 2, 2, 3], numWanted = 3, useLimit = 1`
- **Constraints:**
	- n == values.length == labels.length
	- 1 <= n <= 2 * 10^4
	- 0 <= values[i], labels[i] <= 2 * 10^4
	- 1 <= numWanted, useLimit <= n

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum sum of the values from the selected subset of items that satisfies the constraints on selection and label usage.
- **Example:** `Output: 18`
- **Constraints:**
	- The maximum sum should be obtained by selecting the best possible combination of items while respecting the label constraints.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to select the subset of items that yields the maximum sum of values while ensuring that no more than `numWanted` items are chosen and that no label appears more than `useLimit` times.

- 1. Sort the items by their values in descending order to prioritize the highest value items.
- 2. Track the frequency of each label as items are selected.
- 3. Select items one by one while ensuring that the total number of selected items does not exceed `numWanted`, and no label appears more than `useLimit` times.
{{< dots >}}
### Problem Assumptions ✅
- The input arrays `values` and `labels` are non-empty and contain valid values within the specified range.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: values = [10, 8, 5, 4, 3], labels = [1, 1, 2, 2, 3], numWanted = 3, useLimit = 1`  \
  **Explanation:** The optimal subset of items with the highest values while respecting the label constraints is the first, third, and fifth items, yielding a total value of 10 + 5 + 3 = 18.

- **Input:** `Input: values = [9, 8, 7, 6, 5], labels = [0, 0, 1, 1, 0], numWanted = 3, useLimit = 2`  \
  **Explanation:** In this example, the best subset is the first, second, and third items, which gives the maximum sum of values: 9 + 8 + 7 = 24.

- **Input:** `Input: values = [5, 4, 3, 2, 1], labels = [1, 1, 2, 2, 3], numWanted = 3, useLimit = 1`  \
  **Explanation:** The subset chosen is the first, third, and fifth items with the sum of values: 5 + 3 + 1 = 9.

{{< dots >}}
## Approach 🚀
We can solve this problem using a greedy approach where we prioritize selecting items with the highest values while ensuring that the label constraints are satisfied.

### Initial Thoughts 💭
- We need to ensure that the number of items selected does not exceed `numWanted`, and no label appears more than `useLimit` times.
- Sorting the items by value and then iterating over them while respecting the label constraints will allow us to efficiently find the optimal solution.
{{< dots >}}
### Edge Cases 🌐
- If the input arrays `values` and `labels` are empty, the result should be 0.
- For large inputs, the algorithm should handle up to 20,000 items efficiently, ensuring that the solution works within the time limits.
- If all items have the same label, the solution should ensure that no more than `useLimit` items with the same label are selected.
- The algorithm should respect the constraints on the number of items selected and the label limitations.
{{< dots >}}
## Code 💻
```cpp
int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
    multimap<int, int> s;
    unordered_map<int, int> m;
    for(int i = 0; i < values.size(); i++) 
        s.insert({values[i], labels[i]});
    int res = 0;
    for(auto it = rbegin(s); it != rend(s) && numWanted > 0; it++) {
        if(++m[it->second] <= useLimit) {
            res += it->first;
            --numWanted;                
        }
    }
    return res;
}
```

The function `largestValsFromLabels` returns the sum of the largest values that can be selected based on a label constraint, where a label can be used up to a specified limit (`useLimit`), and a total of `numWanted` values are chosen.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
	```
	This line defines the function `largestValsFromLabels`, which takes four parameters: `values`, `labels`, `numWanted`, and `useLimit`.

2. **Variable Initialization - Multimap**
	```cpp
	    multimap<int, int> s;
	```
	A multimap `s` is initialized to store pairs of values and their corresponding labels, with the ability to store multiple values with the same key.

3. **Variable Initialization - Unordered Map**
	```cpp
	    unordered_map<int, int> m;
	```
	An unordered map `m` is initialized to count how many times a label has been used.

4. **Loop - Insert Values and Labels**
	```cpp
	    for(int i = 0; i < values.size(); i++) 
	```
	This loop iterates through the `values` vector and inserts each value with its corresponding label into the multimap `s`.

5. **Insert Pair into Multimap**
	```cpp
	        s.insert({values[i], labels[i]});
	```
	Each pair of value and label is inserted into the multimap `s`, where the value will be sorted in ascending order by default.

6. **Result Initialization**
	```cpp
	    int res = 0;
	```
	The variable `res` is initialized to 0. It will hold the sum of the selected largest values.

7. **Loop - Process Values**
	```cpp
	    for(auto it = rbegin(s); it != rend(s) && numWanted > 0; it++) {
	```
	This loop iterates through the multimap `s` in reverse order, processing the largest values first. The loop continues until `numWanted` becomes 0.

8. **Condition - Label Usage Limit Check**
	```cpp
	        if(++m[it->second] <= useLimit) {
	```
	This condition checks if the label of the current item has been used fewer times than the allowed limit (`useLimit`). If the condition is true, the value is included in the sum.

9. **Add Value to Result**
	```cpp
	            res += it->first;
	```
	The value (`it->first`) from the current multimap entry is added to the result sum `res`.

10. **Decrement numWanted**
	```cpp
	            --numWanted;
	```
	Since one value has been added to the result, `numWanted` is decremented to track how many more values need to be selected.

11. **Return Result**
	```cpp
	    return res;
	```
	The function returns the result, which is the sum of the largest values that have been selected.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The sorting step dominates the time complexity, which is O(n log n) where n is the number of items.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the need to store the items and track their labels and counts.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/largest-values-from-labels/description/)

---
{{< youtube E0OkE3G95vU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
