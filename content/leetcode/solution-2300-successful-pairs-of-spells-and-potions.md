
+++
authors = ["grid47"]
title = "Leetcode 2300: Successful Pairs of Spells and Potions"
date = "2024-03-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2300: Successful Pairs of Spells and Potions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "vO6FxLZpKg4"
youtube_upload_date="2023-04-02"
youtube_thumbnail="https://i.ytimg.com/vi/vO6FxLZpKg4/maxresdefault.jpg"
comments = true
+++



---
You are given two arrays: `spells` and `potions`, representing the strength of spells and potions, respectively. Each element in the arrays represents the strength of a specific spell or potion. You are also given an integer `success`, which defines the minimum product of a spell and a potion required for a successful pair. For each spell, determine how many potions can pair with it to form a successful combination (i.e., their product is greater than or equal to `success`).
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integer arrays `spells` and `potions`, followed by an integer `success`.
- **Example:** `Input: spells = [4, 1, 6], potions = [1, 2, 3, 4, 5], success = 10`
- **Constraints:**
	- 1 <= n, m <= 10^5
	- 1 <= spells[i], potions[i] <= 10^5
	- 1 <= success <= 10^10

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an integer array where each element at index `i` represents the number of potions that will form a successful pair with the `i`-th spell.
- **Example:** `Output: [4, 0, 4]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** For each spell, determine how many potions can create a product greater than or equal to the `success` value.

- Step 1: Sort the `potions` array in non-decreasing order.
- Step 2: For each spell, calculate the target potion strength that would form a successful pair (i.e., the minimum potion strength needed).
- Step 3: Use binary search to find the number of potions that meet the condition for success.
- Step 4: Return the results for all spells.
{{< dots >}}
### Problem Assumptions ✅
- The input arrays are non-empty and contain valid values within the given ranges.
- The arrays `spells` and `potions` may have different lengths, but both are within the bounds of 1 and 100,000 elements.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: spells = [4, 1, 6], potions = [1, 2, 3, 4, 5], success = 10`  \
  **Explanation:** The 0th spell (4) forms successful pairs with potions [3, 4, 5] (products: 12, 16, 20). The 1st spell (1) forms no successful pairs. The 2nd spell (6) forms successful pairs with potions [2, 3, 4, 5] (products: 12, 18, 24, 30). Hence, the output is [4, 0, 4].

- **Input:** `Input: spells = [3, 1, 2], potions = [8, 5, 8], success = 16`  \
  **Explanation:** The 0th spell (3) forms successful pairs with potions [8, 8] (products: 24, 24). The 1st spell (1) forms no successful pairs. The 2nd spell (2) forms successful pairs with potions [8, 8] (products: 16, 16). Hence, the output is [2, 0, 2].

{{< dots >}}
## Approach 🚀
To solve this problem efficiently, we need to consider sorting the potions array and then use binary search to quickly determine how many potions can form a successful pair with each spell.

### Initial Thoughts 💭
- The problem requires us to find how many potions can pair with a given spell in a time-efficient manner.
- Sorting the `potions` array allows us to use binary search to determine how many potions are valid for each spell.
{{< dots >}}
### Edge Cases 🌐
- If either the `spells` or `potions` array is empty, return an empty result.
- Ensure the solution handles large inputs efficiently, with the size of `spells` and `potions` up to 100,000.
- If `success` is very large (e.g., 10^10), the solution should still work correctly by checking for valid potion pairs without excessive computation.
- The solution should operate in O(n log m) time complexity, where `n` is the length of the spells array and `m` is the length of the potions array.
{{< dots >}}
## Code 💻
```cpp
vector<int> successfulPairs(vector<int>& spells, vector<int>& potion, long long success) {
    
    int n = spells.size();
    
    vector<int> ans(n, 0);
    
    sort(potion.begin(), potion.end());
    
    for(int i = 0; i < n; i++) {
        
        long long tgt = success % spells[i]? (success/ spells[i]) + 1 : (success/ spells[i]);
        
        ans[i] = potion.end() - lower_bound(potion.begin(), potion.end(), tgt);
    }
    
    return ans;
}
```

The function `successfulPairs` computes how many pairs of spells and potions result in a product greater than or equal to a given `success` threshold. It uses binary search to efficiently count the valid pairs.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> successfulPairs(vector<int>& spells, vector<int>& potion, long long success) {
	```
	The function `successfulPairs` is declared, which takes three parameters: a vector `spells` containing spell values, a vector `potion` containing potion values, and a long long value `success` representing the success threshold for the product of spell and potion values.

2. **Variable Initialization**
	```cpp
	    int n = spells.size();
	```
	The variable `n` is initialized to the size of the `spells` vector, representing the number of spells.

3. **Result Vector Initialization**
	```cpp
	    vector<int> ans(n, 0);
	```
	A result vector `ans` of size `n` is initialized, with each element set to 0. This vector will store the count of valid potion pairs for each spell.

4. **Sorting Potions**
	```cpp
	    sort(potion.begin(), potion.end());
	```
	The `potion` vector is sorted in ascending order. Sorting allows us to use binary search to efficiently find the number of valid potion values for each spell.

5. **Loop Through Spells**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	A for-loop is initiated to iterate over each spell in the `spells` vector.

6. **Target Calculation**
	```cpp
	        long long tgt = success % spells[i] ? (success / spells[i]) + 1 : (success / spells[i]);
	```
	For each spell, the target potion value `tgt` is calculated based on the success threshold. If the division of `success` by the spell value leaves a remainder, the target is incremented by 1.

7. **Binary Search**
	```cpp
	        ans[i] = potion.end() - lower_bound(potion.begin(), potion.end(), tgt);
	```
	The `lower_bound` function is used to perform a binary search on the sorted `potion` vector to find the first potion that is greater than or equal to the target `tgt`. The difference between the end of the `potion` vector and the position returned by `lower_bound` gives the count of valid potions for the current spell.

8. **Return Result**
	```cpp
	    return ans;
	```
	The function returns the `ans` vector, which contains the count of valid potion pairs for each spell.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log m)
- **Average Case:** O(n log m)
- **Worst Case:** O(n log m)

The time complexity is O(n log m) due to sorting the potions array and performing binary search for each spell.

### Space Complexity 💾
- **Best Case:** O(m)
- **Worst Case:** O(m)

The space complexity is O(m) for storing the sorted `potions` array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/)

---
{{< youtube vO6FxLZpKg4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
