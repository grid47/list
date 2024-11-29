
+++
authors = ["grid47"]
title = "Leetcode 2741: Special Permutations"
date = "2024-02-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2741: Special Permutations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Bit Manipulation","Bitmask"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "AxXNOXj1upY"
youtube_upload_date="2023-06-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/AxXNOXj1upY/maxresdefault.webp"
comments = true
+++



---
You are given a list of distinct positive integers `nums`. A permutation of `nums` is considered special if, for every pair of consecutive numbers in the permutation, one number is divisible by the other. Your task is to return the total number of special permutations of `nums`, modulo `10^9 + 7`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single array of distinct positive integers `nums`.
- **Example:** `nums = [2, 3, 6]`
- **Constraints:**
	- 2 <= nums.length <= 14
	- 1 <= nums[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the total number of special permutations modulo `10^9 + 7`.
- **Example:** `Output: 2`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To count the number of special permutations of `nums` that satisfy the divisibility condition.

- Build a graph representing the divisibility relation between numbers in `nums`.
- Use depth-first search (DFS) to explore all valid permutations while respecting the divisibility constraints.
- Return the count of special permutations modulo `10^9 + 7`.
{{< dots >}}
### Problem Assumptions ✅
- All elements in `nums` are distinct positive integers.
- The array has at least two elements.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [2, 3, 6]`  \
  **Explanation:** The two special permutations of `nums` are `[3, 6, 2]` and `[2, 6, 3]`.

- **Input:** `nums = [5, 10, 2]`  \
  **Explanation:** The four special permutations of `nums` are `[2, 10, 5]`, `[5, 2, 10]`, `[10, 5, 2]`, and `[10, 2, 5]`.

{{< dots >}}
## Approach 🚀
The approach involves building a graph to represent divisibility relationships, then using DFS to explore all valid permutations.

### Initial Thoughts 💭
- DFS can be used to explore all possible special permutations while maintaining the divisibility condition.
- We need to handle permutations carefully, ensuring that each number is checked for divisibility against others in the sequence.
{{< dots >}}
### Edge Cases 🌐
- The input array will never be empty, as per the constraints.
- The solution must handle arrays with up to 14 elements efficiently, which is manageable with DFS and memoization.
- If the array contains only two elements, the answer is simply whether the two elements are divisible by each other.
- The solution needs to handle arrays with up to 14 elements and elements as large as 10^9.
{{< dots >}}
## Code 💻
```cpp
int mod = (int) 1e9 + 7;
vector<vector<int>> grid;
vector<map<int, int>> mp;
int specialPerm(vector<int>& nums) {
    
    int conn = 0, n = nums.size();
    grid.resize(n);
    mp.resize(n);
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++)
            if(nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0){
                grid[i].push_back(j);
                grid[j].push_back(i);
            }
    }
    long ans = 0;

    for(int i = 0; i < n; i++) {
        int msk = 0;
        msk |= (1 << i);
        ans = (ans + dfs(i, n - 1, msk)) % mod;            
    }
    return ans;
}

int dfs(int i, int n, int msk) {
    
    if(n == 0) return 1;
    if(mp[i].count(msk)) return mp[i][msk];
    long ans = 0;
    for(int x: grid[i]) {
        if(!(msk & (1 << x))) {
            msk ^= (1 << x);
            ans = (ans + dfs(x, n - 1, msk)) % mod;
            msk ^= (1 << x);
        }
    }
    return mp[i][msk] = ans;
}
```

This function calculates the number of special permutations of an array where for each pair of elements, one is divisible by the other. It uses dynamic programming and depth-first search with memoization to solve the problem.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int mod = (int) 1e9 + 7;
	```
	The constant `mod` is defined to store the modulus value (1e9 + 7), which is used to prevent overflow and ensure the result fits within the integer limit.

2. **Grid and Map Initialization**
	```cpp
	vector<vector<int>> grid;
	```
	A 2D vector `grid` is declared to store the connections between the elements, representing pairs where one element is divisible by the other.

3. **Grid and Map Initialization**
	```cpp
	vector<map<int, int>> mp;
	```
	A vector `mp` of maps is initialized to store memoized results of subproblems during the depth-first search (DFS).

4. **Function Definition**
	```cpp
	int specialPerm(vector<int>& nums) {
	```
	The function `specialPerm` is defined, taking a vector `nums` of integers as input. It aims to return the count of special permutations of `nums`.

5. **Variable Initialization**
	```cpp
	    int conn = 0, n = nums.size();
	```
	The integer `conn` is declared but not used. `n` stores the size of the input vector `nums`.

6. **Resize**
	```cpp
	    grid.resize(n);
	```
	The `grid` vector is resized to hold `n` rows, where `n` is the number of elements in `nums`.

7. **Resize**
	```cpp
	    mp.resize(n);
	```
	The `mp` vector is resized to hold `n` elements, corresponding to each element in `nums`.

8. **Nested Loops**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	A loop is initiated to iterate over each element `i` of the vector `nums`.

9. **Nested Loops**
	```cpp
	        for(int j = i + 1; j < n; j++)
	```
	A nested loop is used to compare each pair of elements `i` and `j` in the array, ensuring that `j > i`.

10. **Conditional Check**
	```cpp
	            if(nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0){
	```
	If one element is divisible by the other, a connection between `i` and `j` is established.

11. **Grid Update**
	```cpp
	                grid[i].push_back(j);
	```
	If the condition is satisfied, `j` is added as a neighbor of `i` in the `grid`.

12. **Grid Update**
	```cpp
	                grid[j].push_back(i);
	```
	Similarly, `i` is added as a neighbor of `j` in the `grid`.

13. **Answer Initialization**
	```cpp
	    long ans = 0;
	```
	The variable `ans` is initialized to store the final result, which is the number of special permutations.

14. **Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	A loop is initiated to start DFS from each element `i`.

15. **Bitmasking**
	```cpp
	        int msk = 0;
	```
	A bitmask `msk` is initialized to keep track of the elements that have already been visited during DFS.

16. **Bitmasking**
	```cpp
	        msk |= (1 << i);
	```
	The bit corresponding to the current element `i` is set to 1, indicating that `i` is the starting point of the DFS.

17. **DFS Call**
	```cpp
	        ans = (ans + dfs(i, n - 1, msk)) % mod;
	```
	The DFS function is called with the current element `i`, the size of the remaining elements `n - 1`, and the updated bitmask `msk`. The result is added to `ans` modulo `mod`.

18. **Return Statement**
	```cpp
	    return ans;
	```
	The final result `ans` is returned, representing the number of special permutations.

19. **Function Definition**
	```cpp
	int dfs(int i, int n, int msk) {
	```
	The `dfs` function is defined, which performs a depth-first search to explore all possible permutations, using memoization to store results.

20. **Base Case**
	```cpp
	    if(n == 0) return 1;
	```
	If there are no more elements to permute (`n == 0`), return 1 as this is a valid permutation.

21. **Memoization**
	```cpp
	    if(mp[i].count(msk)) return mp[i][msk];
	```
	Check if the result for the current state (`i`, `msk`) is already computed. If so, return the stored result.

22. **Answer Initialization**
	```cpp
	    long ans = 0;
	```
	Initialize the variable `ans` to accumulate the result of the DFS exploration.

23. **Loop**
	```cpp
	    for(int x: grid[i]) {
	```
	Loop through each neighbor `x` of the current element `i` in the `grid`.

24. **Bitmasking**
	```cpp
	        if(!(msk & (1 << x))) {
	```
	Check if the element `x` has not been visited yet by examining the bitmask `msk`.

25. **Bitmask Update**
	```cpp
	            msk ^= (1 << x);
	```
	Update the bitmask `msk` to mark element `x` as visited.

26. **DFS Call**
	```cpp
	            ans = (ans + dfs(x, n - 1, msk)) % mod;
	```
	Call the DFS function recursively with the updated bitmask `msk`, reduced size `n - 1`, and accumulate the result.

27. **Bitmask Update**
	```cpp
	            msk ^= (1 << x);
	```
	Backtrack by resetting the bitmask `msk` to unmark element `x` as visited.

28. **Memoization**
	```cpp
	    return mp[i][msk] = ans;
	```
	Memoize the computed result for the current state (`i`, `msk`) and return it.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n!)
- **Average Case:** O(n!)
- **Worst Case:** O(n!)

The time complexity is dominated by the DFS search through all permutations, which has a factorial time complexity.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n * 2^n)

The space complexity is O(n * 2^n) due to the storage of the DP state for memoization and the graph.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/special-permutations/description/)

---
{{< youtube AxXNOXj1upY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
