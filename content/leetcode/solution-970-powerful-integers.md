
+++
authors = ["grid47"]
title = "Leetcode 970: Powerful Integers"
date = "2024-08-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 970: Powerful Integers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math","Enumeration"]
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
Given three integers x, y, and bound, find all powerful integers that are less than or equal to bound. A powerful integer can be expressed in the form x^i + y^j for non-negative integers i and j. Return the results as a list with no duplicates, and the order of the elements does not matter.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** Three integers x, y, and bound.
- **Example:** `Input: x = 2, y = 3, bound = 20`
- **Constraints:**
	- 1 <= x, y <= 100
	- 0 <= bound <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** A list of all unique powerful integers less than or equal to bound.
- **Example:** `Output: [2, 3, 4, 5, 9, 10, 17]`
- **Constraints:**
	- Each powerful integer must appear only once in the list.
	- The integers in the output can be in any order.

{{< dots >}}
### Core Logic 🔍
**Goal:** Compute all unique powerful integers less than or equal to the given bound.

- Iterate over possible values of i such that x^i <= bound.
- For each i, iterate over possible values of j such that x^i + y^j <= bound.
- If x or y is 1, break early to avoid infinite loops.
- Store the resulting sums in a set to ensure uniqueness.
- Convert the set to a list and return it.
{{< dots >}}
### Problem Assumptions ✅
- x and y are positive integers.
- The values of x and y can be 1, which simplifies the calculation.
- The bound is non-negative.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: x = 3, y = 2, bound = 25`  \
  **Explanation:** The powerful integers are calculated as follows: 
3^0 + 2^0 = 2, 3^1 + 2^0 = 4, 3^0 + 2^1 = 3, 3^1 + 2^1 = 5, 3^2 + 2^0 = 9, 3^2 + 2^1 = 11, 3^0 + 2^2 = 6, 3^1 + 2^2 = 10, 3^2 + 2^2 = 13, ...
Output: [2, 3, 4, 5, 6, 9, 10, 11, 13]

- **Input:** `Input: x = 1, y = 1, bound = 5`  \
  **Explanation:** Since x and y are both 1, only one unique powerful integer can be formed: 1 + 1 = 2. Output: [2]

{{< dots >}}
## Approach 🚀
Use nested loops to calculate all possible values of x^i + y^j within the bound, ensuring no duplicates by using a set.

### Initial Thoughts 💭
- Both x and y can potentially grow exponentially, so the number of iterations depends on the logarithmic scale of the bound.
- Using a set ensures uniqueness of results.
- Iterate over all possible powers of x and y while ensuring their sum remains within the bound.
- Break early when either x or y equals 1 since their powers do not grow.
{{< dots >}}
### Edge Cases 🌐
- If bound is 0, the result should be an empty list.
- For large values of bound, ensure the algorithm terminates efficiently by breaking early when x == 1 or y == 1.
- If x == 1 and y == 1, the only valid output is [2] (if bound >= 2).
- If x or y is 1, the respective loop becomes constant.
- Ensure that x^i and y^j are calculated without overflow within the constraints of bound.
{{< dots >}}
## Code 💻
```cpp
vector<int> powerfulIntegers(int x, int y, int bound) {
    unordered_set<int> s;
    for(int i = 1; i <= bound; i *= x) {
        for(int j = 1; i + j <= bound; j *= y) {
            s.insert(i + j);
            if(y == 1) break;
        }
        if(x == 1) break;
    }
    return vector<int>(s.begin(), s.end());
}
```

The `powerfulIntegers` function generates a list of all integers of the form `x^i + y^j` that do not exceed a given bound. It uses a set to avoid duplicate values.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> powerfulIntegers(int x, int y, int bound) {
	```
	This is the function header where `x`, `y`, and `bound` are the input parameters. It defines the function that will generate all powerful integers.

2. **Set Initialization**
	```cpp
	    unordered_set<int> s;
	```
	A set `s` is initialized to store the unique powerful integers found during the process.

3. **Outer Loop**
	```cpp
	    for(int i = 1; i <= bound; i *= x) {
	```
	Start a loop with `i` initialized to 1. It will multiply `i` by `x` in each iteration to generate powers of `x` up to the bound.

4. **Inner Loop**
	```cpp
	        for(int j = 1; i + j <= bound; j *= y) {
	```
	Start an inner loop with `j` initialized to 1. It multiplies `j` by `y` to generate powers of `y` while ensuring that the sum `i + j` does not exceed the bound.

5. **Set Insertion**
	```cpp
	            s.insert(i + j);
	```
	Add the sum of `i + j` to the set `s`. This ensures all combinations of `x^i + y^j` are stored without duplicates.

6. **Break Condition**
	```cpp
	            if(y == 1) break;
	```
	If `y` is 1, the loop breaks early because further powers of `y` will always be 1, leading to redundant results.

7. **Outer Loop Break**
	```cpp
	        if(x == 1) break;
	```
	If `x` is 1, the outer loop breaks early because further powers of `x` will always be 1, leading to redundant results.

8. **Return Statement**
	```cpp
	    return vector<int>(s.begin(), s.end());
	```
	Convert the set `s` into a vector and return it as the result, containing all the unique powerful integers.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log(bound))
- **Average Case:** O(log(bound)^2)
- **Worst Case:** O(log(bound)^2)

The worst case involves nested loops iterating logarithmically with respect to x and y.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

Space complexity is determined by the size of the set storing results, which is O(n), where n is the number of unique results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/powerful-integers/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
