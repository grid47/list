
+++
authors = ["grid47"]
title = "Leetcode 779: K-th Symbol in Grammar"
date = "2024-08-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 779: K-th Symbol in Grammar in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Bit Manipulation","Recursion"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/779.webp"
youtube = "pmD2HCKaqRQ"
youtube_upload_date="2023-10-25"
youtube_thumbnail="https://i.ytimg.com/vi/pmD2HCKaqRQ/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/779.webp" 
    alt="A sequence where the kth symbol is found, glowing softly as it is located."
    caption="Solution to LeetCode 779: K-th Symbol in Grammar Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
We build a sequence of rows starting with the string '0' in the first row. For each subsequent row, every occurrence of '0' from the previous row is replaced with '01', and every occurrence of '1' is replaced with '10'. Given two integers n and k, return the k-th (1-indexed) symbol in the n-th row.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integers n and k, where n represents the row number and k represents the position of the symbol in that row.
- **Example:** `Input: n = 3, k = 4`
- **Constraints:**
	- 1 <= n <= 30
	- 1 <= k <= 2^n - 1

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the k-th (1-indexed) symbol in the n-th row of the sequence.
- **Example:** `Output: 1`
- **Constraints:**
	- The output must be either 0 or 1, depending on the symbol at position k in row n.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine the k-th symbol in the n-th row without explicitly constructing the entire row.

- If n is 1, return 0 (base case).
- If k is even, recursively find the symbol in the previous row at the index k / 2, and invert it.
- If k is odd, recursively find the symbol in the previous row at the index (k + 1) / 2, and return it as is.
{{< dots >}}
### Problem Assumptions ✅
- Both n and k are valid inputs, with k within the range for the n-th row.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: Input: n = 1, k = 1`  \
  **Explanation:** The first row is '0', so the 1st symbol is '0'.

- **Input:** `Example 2: Input: n = 3, k = 4`  \
  **Explanation:** Row 3 is '0110', and the 4th symbol is '1'.

- **Input:** `Example 3: Input: n = 2, k = 2`  \
  **Explanation:** Row 2 is '01', and the 2nd symbol is '1'.

{{< dots >}}
## Approach 🚀
The approach involves leveraging the recursive pattern of the sequence generation. Instead of generating entire rows, we recursively find the k-th symbol in the previous row and determine its value.

### Initial Thoughts 💭
- The sequence generation follows a recursive pattern, where each row depends on the previous one.
- Instead of constructing the entire row, we can solve this problem by recursively narrowing down the position of the desired symbol.
{{< dots >}}
### Edge Cases 🌐
- There will always be valid values for n and k, as per the constraints.
- The solution must be efficient enough to handle n = 30, where the row size is 2^30.
- When k is 1 or 2^n - 1, the solution must handle these boundary cases.
- n is guaranteed to be at most 30, so handling up to 2^30 symbols is feasible.
{{< dots >}}
## Code 💻
```cpp
int kthGrammar(int n, int k) {
    if (n == 1)   return 0;
    if (k%2 == 0) return kthGrammar(n - 1,       k / 2) == 0? 1 : 0;
    else          return kthGrammar(n - 1, (k + 1) / 2) == 0? 0 : 1;
}
```

The function implements a recursive solution to find the k-th value in the n-th row of the binary grammar sequence.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int kthGrammar(int n, int k) {
	```
	Defines the function `kthGrammar` which takes two arguments: `n` (the row number) and `k` (the position in the row). It returns the value at the k-th position of the n-th row in a binary grammar sequence.

2. **Base Case**
	```cpp
	    if (n == 1)   return 0;
	```
	The base case: when n equals 1, the first row of the grammar sequence is always [0]. Therefore, it returns 0.

3. **Recursive Case**
	```cpp
	    if (k%2 == 0) return kthGrammar(n - 1,       k / 2) == 0? 1 : 0;
	```
	If k is even, the function calls itself recursively with n-1 and k/2, then returns the complement (1 if 0, 0 if 1) of the result.

4. **Recursive Case**
	```cpp
	    else          return kthGrammar(n - 1, (k + 1) / 2) == 0? 0 : 1;
	```
	If k is odd, the function calls itself recursively with n-1 and (k+1)/2, and returns the same value (0 if 0, 1 if 1).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log n), as we reduce the problem size by half at each step.
- **Average Case:** O(log n), since the recursive depth is logarithmic.
- **Worst Case:** O(log n), as the maximum depth of recursion is log n.

Time complexity is logarithmic due to the halving nature of the recursion.

### Space Complexity 💾
- **Best Case:** O(1), when no recursion depth is needed.
- **Worst Case:** O(log n), as the recursion depth can be at most log n.

Space complexity is logarithmic due to recursion stack.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/k-th-symbol-in-grammar/description/)

---
{{< youtube pmD2HCKaqRQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
