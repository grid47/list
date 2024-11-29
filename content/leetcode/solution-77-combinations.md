
+++
authors = ["grid47"]
title = "Leetcode 77: Combinations"
date = "2024-10-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 77: Combinations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/77.webp"
youtube = "q0s6m7AiM7o"
youtube_upload_date="2021-08-31"
youtube_thumbnail="https://i.ytimg.com/vi/q0s6m7AiM7o/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/77.webp" 
    alt="A glowing, radiant combination of elements gently shifting together."
    caption="Solution to LeetCode 77: Combinations Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given two integers `n` and `k`. Find all possible combinations of `k` numbers selected from the range [1, n], where the numbers are chosen without repetition. The answer should contain all possible combinations of `k` numbers in any order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integers, `n` and `k`. `n` represents the upper bound of the range of numbers, and `k` represents the number of numbers to be selected.
- **Example:** `n = 5, k = 3`
- **Constraints:**
	- 1 <= n <= 20
	- 1 <= k <= n

{{< dots >}}
### Output Specifications 📤
- **Output:** Return all possible combinations of `k` numbers from the range [1, n], in any order.
- **Example:** `[[1,2,3], [1,2,4], [1,2,5], [1,3,4], [1,3,5], [1,4,5], [2,3,4], [2,3,5], [2,4,5], [3,4,5]]`
- **Constraints:**
	- The output should be a list of combinations, each containing exactly `k` numbers from the range [1, n].

{{< dots >}}
### Core Logic 🔍
**Goal:** Generate all possible combinations of `k` numbers from the range [1, n] using a backtracking approach.

- Use a backtracking technique to explore all possible combinations by selecting a number from the range [1, n] and recursively adding it to the current combination.
- If the current combination has `k` elements, add it to the result list.
- Backtrack by removing the last selected element and exploring other possible combinations.
{{< dots >}}
### Problem Assumptions ✅
- The input integers `n` and `k` are valid, with `k <= n`.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 5, k = 3`  \
  **Explanation:** The output consists of all possible combinations of 3 numbers selected from the range [1, 5]. There are a total of 10 combinations.

- **Input:** `n = 3, k = 2`  \
  **Explanation:** The output consists of all possible combinations of 2 numbers selected from the range [1, 3]. There are a total of 3 combinations.

{{< dots >}}
## Approach 🚀
The approach to solving this problem involves using backtracking to generate all combinations of `k` numbers from the range [1, n].

### Initial Thoughts 💭
- We need to generate combinations, not permutations, so order doesn't matter.
- Backtracking is a natural fit for generating combinations, as it allows us to explore all possibilities and backtrack when we reach a valid combination.
{{< dots >}}
### Edge Cases 🌐
- If `k` is greater than `n`, there are no valid combinations.
- For the upper bound of `n = 20`, ensure the solution handles the large number of possible combinations efficiently.
- If `k = 1`, the output will contain `n` combinations, each containing a single number from 1 to n.
- Ensure that the solution efficiently handles the constraints of `1 <= n <= 20`.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> combinations;
    vector<int> combination;
    backtrack(combinations, combination, 1, n, k);
    return combinations;
}

void backtrack(vector<vector<int>>& combinations, vector<int>& combination, int start, int n, int k) {
    if (combination.size() == k) {
        combinations.push_back(combination);
        return;
    }

    for (int i = start; i <= n; ++i) {
        combination.push_back(i);
        backtrack(combinations, combination, i + 1, n, k);
        combination.pop_back();
    }
}
```

This code generates all possible combinations of `k` numbers from the range `[1, n]` using a backtracking approach.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<vector<int>> combine(int n, int k) {
	```
	Declares a function `combine` that takes two integers `n` and `k` as input and returns a vector of vectors representing all possible combinations.

2. **Variable Initialization**
	```cpp
	    vector<vector<int>> combinations;
	```
	Initializes an empty vector `combinations` to store the generated combinations.

3. **Variable Initialization**
	```cpp
	    vector<int> combination;
	```
	Initializes an empty vector `combination` to store the current combination being built.

4. **Function Call**
	```cpp
	    backtrack(combinations, combination, 1, n, k);
	
	```
	Calls the `backtrack` function to recursively generate combinations.

5. **Return**
	```cpp
	    return combinations;
	```
	Returns the `combinations` vector containing all the generated combinations.

6. **Function Declaration**
	```cpp
	void backtrack(vector<vector<int>>& combinations, vector<int>& combination, int start, int n, int k) {
	```
	Declares a recursive `backtrack` function to explore combinations.

7. **Conditional**
	```cpp
	    if (combination.size() == k) {
	```
	Checks if the current `combination` has `k` elements.

8. **Vector Operation**
	```cpp
	        combinations.push_back(combination);
	```
	Adds the current `combination` to the `combinations` vector.

9. **Return**
	```cpp
	        return;
	```
	Returns from the recursive call as a complete combination is found.

10. **Conditional**
	```cpp
	    if (i > n) return;
	```
	Checks if the current index `i` has exceeded the maximum value `n`.

11. **Loop Iteration**
	```cpp
	    for (int i = start; i <= n; ++i) {
	```
	Iterates from `start` to `n` to explore possible numbers for the current position in the combination.

12. **Vector Operation**
	```cpp
	        combination.push_back(i);
	```
	Adds the current number `i` to the `combination`.

13. **Recursive Call**
	```cpp
	        backtrack(combinations, combination, i + 1, n, k);
	
	```
	Recursively calls the `backtrack` function with the updated `combination` and `start` index.

14. **Vector Operation**
	```cpp
	        combination.pop_back();
	```
	Removes the last added number from the `combination` to explore other possibilities.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n choose k)
- **Average Case:** O(n choose k)
- **Worst Case:** O(n choose k)

The time complexity is determined by the number of combinations that need to be generated, which is `n choose k`.

### Space Complexity 💾
- **Best Case:** O(k)
- **Worst Case:** O(k)

The space complexity is O(k) due to the temporary storage used to hold the current combination during recursion.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/combinations/description/)

---
{{< youtube q0s6m7AiM7o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
