
+++
authors = ["grid47"]
title = "Leetcode 2305: Fair Distribution of Cookies"
date = "2024-03-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2305: Fair Distribution of Cookies in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Backtracking","Bit Manipulation","Bitmask"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "74-V6AjJ4wg"
youtube_upload_date="2022-06-12"
youtube_thumbnail="https://i.ytimg.com/vi/74-V6AjJ4wg/maxresdefault.jpg"
comments = true
+++



---
You are given an integer array cookies, where each element represents the number of cookies in a particular bag. You are also given an integer k, which denotes the number of children to distribute these bags of cookies to. Each bag must go to exactly one child, and cookies cannot be split between children. The unfairness of a distribution is defined as the maximum number of cookies any single child receives. Your goal is to return the minimum unfairness across all possible distributions.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two parameters: cookies, an integer array representing the number of cookies in each bag, and an integer k, the number of children.
- **Example:** `cookies = [10, 20, 15, 30], k = 3`
- **Constraints:**
	- 2 <= cookies.length <= 8
	- 1 <= cookies[i] <= 10^5
	- 2 <= k <= cookies.length

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum unfairness of all possible distributions, defined as the maximum number of cookies any single child receives.
- **Example:** `For cookies = [10, 20, 15, 30] and k = 3, the output is 35.`
- **Constraints:**
	- The distribution should minimize the maximum number of cookies assigned to any child.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to distribute the cookies in such a way that the maximum number of cookies any child receives is minimized.

- Sort the cookies array for easier distribution.
- Use backtracking to try distributing cookies to each child, keeping track of the total cookies each child receives.
- Recursively explore all possible distributions and calculate the maximum unfairness for each combination.
- Return the minimum unfairness across all distributions.
{{< dots >}}
### Problem Assumptions ✅
- Each bag of cookies must go to exactly one child.
- All cookies in a bag must be distributed together; they cannot be split.
{{< dots >}}
## Examples 🧩
- **Input:** `cookies = [10, 20, 15, 30], k = 3`  \
  **Explanation:** An optimal distribution could be: [10, 20] to child 1, [15] to child 2, and [30] to child 3. The maximum number of cookies any child gets is 35.

{{< dots >}}
## Approach 🚀
To solve this problem, we will use backtracking to explore all possible distributions of cookies, minimizing the unfairness.

### Initial Thoughts 💭
- We need to divide the cookies into k groups such that the group with the maximum sum of cookies has the smallest possible value.
- Using backtracking, we can try every distribution and calculate the maximum cookies any child receives. We need to minimize this maximum.
{{< dots >}}
### Edge Cases 🌐
- Empty arrays or k greater than cookies.length should not occur as per the problem constraints.
- The solution should handle the maximum input size efficiently.
- If all cookies are the same, the unfairness will be minimized.
- Make sure the number of cookies is always greater than or equal to k.
{{< dots >}}
## Code 💻
```cpp
int k, ans = INT_MAX;
vector<int> cook, dist;

int dp(int idx) {
    if(idx == cook.size()) {            
        int sol = dist[0];
        for(int i = 0; i < k; i++) {
            sol = max(sol, dist[i]);
        }
        ans = min(ans, sol);
        return sol;
    }

    int ans = INT_MAX;
    for(int i = 0; i < k; i++) {
        dist[i] += cook[idx];
        ans = min(ans, dp(idx + 1));
        dist[i] -= cook[idx];
    }

    return ans;
}

int distributeCookies(vector<int>& cook, int k) {
    this->k = k;
    dist.resize(k, 0);
    this->cook = cook;
    dp(0);
    return ans;
}
```

This code defines a dynamic programming solution for distributing cookies to k children while minimizing the maximum number of cookies a child receives. The function `distributeCookies` sets up the problem, and the helper function `dp` recursively explores all possible distributions to find the optimal solution.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	int k, ans = INT_MAX;
	```
	Declare two integer variables: `k` for the number of children, and `ans` for storing the minimum maximum number of cookies any child receives, initialized to `INT_MAX`.

2. **Vector Initialization**
	```cpp
	vector<int> cook, dist;
	```
	Declare two vectors: `cook`, which will store the number of cookies, and `dist`, which tracks the current distribution of cookies to the children.

3. **Function Declaration**
	```cpp
	int dp(int idx) {
	```
	Declare the recursive function `dp` that takes an integer `idx` representing the current index in the `cook` array. This function explores different ways to distribute cookies.

4. **Base Case**
	```cpp
	    if(idx == cook.size()) {
	```
	Base case for recursion: if the index `idx` equals the size of the `cook` array, meaning all cookies have been distributed, calculate the maximum number of cookies a child has received.

5. **Max Distribution Calculation**
	```cpp
	        int sol = dist[0];
	```
	Initialize `sol` to the number of cookies received by the first child. This will be used to track the maximum number of cookies any child has received.

6. **Loop Through Children**
	```cpp
	        for(int i = 0; i < k; i++) {
	```
	Loop through each child (from `i = 0` to `i = k-1`) to find the child with the maximum number of cookies.

7. **Update Maximum**
	```cpp
	            sol = max(sol, dist[i]);
	```
	Update `sol` to the maximum value between `sol` and `dist[i]`, which is the number of cookies received by the current child.

8. **Update Global Result**
	```cpp
	        ans = min(ans, sol);
	```
	Update the global `ans` with the minimum of the current `ans` and `sol` to track the optimal solution (the least worst case of cookie distribution).

9. **Return Maximum Distribution**
	```cpp
	        return sol;
	```
	Return the maximum number of cookies received by any child for the current distribution.

10. **Recursive Exploration**
	```cpp
	    int ans = INT_MAX;
	```
	Initialize `ans` to `INT_MAX` to store the minimum value of the maximum cookies a child receives, across all possible distributions.

11. **Loop Through Children**
	```cpp
	    for(int i = 0; i < k; i++) {
	```
	Loop through each child to explore different ways of distributing cookies.

12. **Update Distribution**
	```cpp
	        dist[i] += cook[idx];
	```
	Add the number of cookies from `cook[idx]` to the `i`-th child's current total in `dist[i]`.

13. **Recursive Call**
	```cpp
	        ans = min(ans, dp(idx + 1));
	```
	Recursively call `dp` with the next index `idx + 1`, updating `ans` with the minimum value between the current `ans` and the result of the recursive call.

14. **Undo Distribution**
	```cpp
	        dist[i] -= cook[idx];
	```
	Backtrack by subtracting `cook[idx]` from `dist[i]` to undo the distribution for the current child before trying the next one.

15. **Return Minimum Maximum Distribution**
	```cpp
	    return ans;
	```
	Return the minimum of the maximum distributions, which is the optimal solution for the problem.

16. **Main Function Declaration**
	```cpp
	int distributeCookies(vector<int>& cook, int k) {
	```
	Declare the main function `distributeCookies`, which takes a vector `cook` representing the number of cookies and an integer `k` for the number of children.

17. **Initialize k**
	```cpp
	    this->k = k;
	```
	Assign the value of `k` to the class member variable `k`.

18. **Resize Distribution Array**
	```cpp
	    dist.resize(k, 0);
	```
	Resize the `dist` array to have `k` elements, initializing all elements to 0.

19. **Initialize Cook Array**
	```cpp
	    this->cook = cook;
	```
	Assign the `cook` vector to the class member variable `cook`.

20. **Call dp Function**
	```cpp
	    dp(0);
	```
	Start the recursive `dp` function with index `0` to begin the distribution of cookies.

21. **Return Result**
	```cpp
	    return ans;
	```
	Return the optimal result stored in `ans`, which is the minimum maximum distribution of cookies.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(k^n)
- **Average Case:** O(k^n)
- **Worst Case:** O(k^n)

Since we explore all possible distributions of the cookies to k children, the time complexity depends on the number of possible assignments.

### Space Complexity 💾
- **Best Case:** O(k)
- **Worst Case:** O(k)

We need space for the current distribution of cookies to the k children, which takes O(k) space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/fair-distribution-of-cookies/description/)

---
{{< youtube 74-V6AjJ4wg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
