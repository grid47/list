
+++
authors = ["grid47"]
title = "Leetcode 2961: Double Modular Exponentiation"
date = "2024-01-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2961: Double Modular Exponentiation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "I0NpbqgISas"
youtube_upload_date="2023-12-11"
youtube_thumbnail="https://i.ytimg.com/vi/I0NpbqgISas/maxresdefault.jpg"
comments = true
+++



---
Given a 2D array `variables` where each element is a list of integers `[a, b, c, m]`, and an integer `target`, find the indices where the formula `(a * b % 10) ^ c % m` equals the `target`. Return a list of these indices.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a 2D array `variables` and an integer `target`. Each element of the array represents a group of four integers `[a, b, c, m]`.
- **Example:** `variables = [[4, 2, 3, 5], [7, 2, 2, 4], [6, 1, 1, 10]], target = 3`
- **Constraints:**
	- 1 <= variables.length <= 100
	- 1 <= a, b, c, m <= 103
	- 0 <= target <= 103

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array of indices where the result of the formula equals `target`.
- **Example:** `[0, 2]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To identify which indices satisfy the condition `(a * b % 10) ^ c % m == target`.

- Iterate over the array `variables`.
- For each element `[a, b, c, m]`, compute `(a * b % 10) ^ c % m` and compare it with `target`.
- If they are equal, add the index to the result array.
- Return the result array.
{{< dots >}}
### Problem Assumptions ✅
- All elements of the input are within the given constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: variables = [[4, 2, 3, 5], [7, 2, 2, 4], [6, 1, 1, 10]], target = 3`  \
  **Explanation:** For index 0: (4 * 2 % 10)^3 % 5 = 3, for index 1: (7 * 2 % 10)^2 % 4 = 0, for index 2: (6 * 1 % 10)^1 % 10 = 6. Thus, the good indices are [0, 2].

- **Input:** `Input: variables = [[5, 5, 3, 10]], target = 7`  \
  **Explanation:** For index 0: (5 * 5 % 10)^3 % 10 = 5. No indices match the target.

{{< dots >}}
## Approach 🚀
We iterate through each element in the `variables` array, compute the formula, and check if it matches the target.

### Initial Thoughts 💭
- We can use modular arithmetic to simplify the computation.
- A helper function for exponentiation modulo m can be used to avoid overflow and ensure efficiency.
{{< dots >}}
### Edge Cases 🌐
- The input will always contain at least one element.
- Ensure that the solution handles inputs where `variables.length` is close to 100.
- Handle cases where `target` is 0 or the result of the formula is 0.
- The time complexity should be efficient enough to handle inputs at the upper bound of constraints.
{{< dots >}}
## Code 💻
```cpp
int power(long long b, long long p, int m){
if(p <= 0) return 1;
long long t = power(b, p/2, m);
t = ((t * t)%m);
return (p%2)?(t * b)%m : t;
}

vector<int> getGoodIndices(vector<vector<int>>& v, int target) {
vector<int> ans;
for(int i = 0; i < v.size(); ++i){
    long long a = v[i][0]%10, b = v[i][1], c = v[i][2], m = v[i][3], t = 1;
    t = power(a, b, 10);
    t = power(t, c, m);
    if(t == target) ans.push_back(i);
}
return ans;
}
```

This code defines two functions: 'power' to compute modular exponentiation and 'getGoodIndices' to find indices in a list where the computed value matches a target.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int power(long long b, long long p, int m){
	```
	Defines the function 'power' that computes b raised to the power p modulo m using recursion.

2. **Base Case**
	```cpp
	if(p <= 0) return 1;
	```
	Base case for the recursion: if p is 0 or less, the result is 1 (since any number raised to the power of 0 is 1).

3. **Recursive Case**
	```cpp
	long long t = power(b, p/2, m);
	```
	Recursively calls the power function with half the exponent (p/2).

4. **Square the Result**
	```cpp
	t = ((t * t)%m);
	```
	Squares the result of the recursive call and takes the modulo m.

5. **Final Result**
	```cpp
	return (p%2)?(t * b)%m : t;
	```
	If p is odd, multiplies the result by b and takes the modulo m. Otherwise, just returns the squared result.

6. **Function End**
	```cpp
	}
	```
	Marks the end of the 'power' function.

7. **Function Definition**
	```cpp
	vector<int> getGoodIndices(vector<vector<int>>& v, int target) {
	```
	Defines the function 'getGoodIndices' that takes a 2D vector 'v' and an integer 'target', returning indices where a certain computed value matches the target.

8. **Variable Initialization**
	```cpp
	vector<int> ans;
	```
	Initializes an empty vector 'ans' to store the indices of the elements that match the target.

9. **For Loop Start**
	```cpp
	for(int i = 0; i < v.size(); ++i){
	```
	Starts a for loop that iterates through each row in the 2D vector 'v'.

10. **Variable Setup**
	```cpp
	    long long a = v[i][0]%10, b = v[i][1], c = v[i][2], m = v[i][3], t = 1;
	```
	Extracts values from the current row 'v[i]' and performs modulo 10 on 'a'. Initializes t to 1.

11. **First Power Calculation**
	```cpp
	    t = power(a, b, 10);
	```
	Calculates the value of 'a' raised to the power of 'b' modulo 10 by calling the 'power' function.

12. **Second Power Calculation**
	```cpp
	    t = power(t, c, m);
	```
	Calculates the value of 't' raised to the power of 'c' modulo m using the 'power' function.

13. **Condition Check**
	```cpp
	    if(t == target) ans.push_back(i);
	```
	If the computed value 't' matches the target, adds the index 'i' to the result vector 'ans'.

14. **Return Result**
	```cpp
	return ans;
	```
	Returns the vector 'ans' containing the indices where the computed value matches the target.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the `variables` array.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) for storing the result indices.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/double-modular-exponentiation/description/)

---
{{< youtube I0NpbqgISas >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
