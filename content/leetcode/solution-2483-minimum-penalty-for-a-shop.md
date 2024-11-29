
+++
authors = ["grid47"]
title = "Leetcode 2483: Minimum Penalty for a Shop"
date = "2024-03-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2483: Minimum Penalty for a Shop in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "0d7ShRoOFVE"
youtube_upload_date="2023-08-29"
youtube_thumbnail="https://i.ytimg.com/vi/0d7ShRoOFVE/maxresdefault.jpg"
comments = true
+++



---
You are given a string representing the log of a shop's customer visits over a series of hours. Each character in the string is either 'Y' (customer visits) or 'N' (no customer visits). The shop can close at any given hour, and the penalty is determined by two factors: when the shop is open but no customers visit, and when the shop is closed but customers still arrive. You need to determine the earliest hour at which the shop should close to minimize the penalty.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A string customers of length n, consisting of characters 'Y' and 'N', representing customer visits during each hour.
- **Example:** `customers = "YYNY"`
- **Constraints:**
	- 1 <= customers.length <= 10^5
	- customers consists only of characters 'Y' and 'N'.

{{< dots >}}
### Output Specifications 📤
- **Output:** The earliest hour at which the shop should close to incur the minimum penalty.
- **Example:** `Output: 2`
- **Constraints:**
	- The returned value will be an integer between 0 and the length of the customers string.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the earliest hour to close the shop such that the penalty is minimized.

- Count the number of 'N' characters (hours with no customers) and 'Y' characters (hours with customers).
- Calculate the penalty for closing the shop at each hour, considering both the hours open without customers and the hours closed with customers.
- Return the earliest hour that results in the least penalty.
{{< dots >}}
### Problem Assumptions ✅
- The penalty is computed by considering both the shop's open and closed hours relative to customer visits.
{{< dots >}}
## Examples 🧩
- **Input:** `customers = "YYNY"`  \
  **Explanation:** When closing the shop at hour 0, the penalty is 3 (1 hour of no customers while open, 1 hour of customers while closed). Closing at hour 2 results in the lowest penalty of 1, which is the optimal time to close.

- **Input:** `customers = "NNNNN"`  \
  **Explanation:** Since no customers visit, the best time to close is immediately at hour 0 to avoid any penalties.

- **Input:** `customers = "YYYY"`  \
  **Explanation:** In this case, the best time to close the shop is at hour 4, since there are customers at every hour.

{{< dots >}}
## Approach 🚀
To solve this problem, we can simulate the shop closing at each possible hour and calculate the penalty for each case. We can then return the earliest hour with the least penalty.

### Initial Thoughts 💭
- We need to consider both customers arriving while the shop is closed and the shop being open without customers.
- Using cumulative sums can help us efficiently calculate penalties without recalculating from scratch for each possible closing time.
{{< dots >}}
### Edge Cases 🌐
- An empty string of customers is invalid based on the constraints.
- For large inputs (up to 10^5 characters), the solution must efficiently handle the penalty calculations in linear time.
- If all characters are 'Y' or all characters are 'N', the penalty calculation should still work as expected.
- Ensure that the solution is optimized for large inputs.
{{< dots >}}
## Code 💻
```cpp
int bestClosingTime(string a) {
    int s = a.size();
    vector<int> y,n;
    y.push_back(0);
    n.push_back(0);
    int cnt = 0;
    for (int i = 0; i < s; i++) {
        if(a[i] == 'N') cnt++;
        n.push_back(cnt);
    }
    cnt = 0;
    for (int i = s -1; i >= 0; i--) {
        if(a[i] == 'Y') cnt++;
        y.push_back(cnt);
    }
    
    reverse (y.begin(), y.end());
    int ans = INT_MAX, ind = 0;
    for(int i = 0; i < s +1; i++) {
        int h = n[i] + y[i];
        if(h<ans) {
            ans = h;
            ind = i;
        }
    }
    return ind;        
}
```

This function calculates the best closing time by determining how many 'N' (No) and 'Y' (Yes) operations occur at each step. The goal is to find the time where the sum of 'N' before and 'Y' after the time is minimized, returning the index of that time.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int bestClosingTime(string a) {
	```
	This line defines the function `bestClosingTime`, which takes a string `a` as input representing the sequence of operations and returns an integer representing the best closing time.

2. **Variable Initialization**
	```cpp
	    int s = a.size();
	```
	The size of the string `a` is stored in the variable `s`, which represents the number of operations.

3. **Vector Initialization**
	```cpp
	    vector<int> y,n;
	```
	Two vectors, `y` and `n`, are initialized to store the counts of 'Y' and 'N' at each position in the string.

4. **Push Initialization**
	```cpp
	    y.push_back(0);
	```
	Initialize the `y` vector by adding 0 to represent the starting count of 'Y' operations.

5. **Push Initialization**
	```cpp
	    n.push_back(0);
	```
	Initialize the `n` vector by adding 0 to represent the starting count of 'N' operations.

6. **Loop Setup**
	```cpp
	    int cnt = 0;
	```
	Initialize a counter variable `cnt` to keep track of the number of 'N' operations encountered so far.

7. **Forward Loop**
	```cpp
	    for (int i = 0; i < s; i++) {
	```
	Start a loop from the beginning of the string to count the 'N' operations.

8. **Count 'N'**
	```cpp
	        if(a[i] == 'N') cnt++;
	```
	If the current character is 'N', increment the counter `cnt`.

9. **Store 'N' Count**
	```cpp
	        n.push_back(cnt);
	```
	Store the current count of 'N' operations in the `n` vector at the corresponding index.

10. **Reset Counter**
	```cpp
	    cnt = 0;
	```
	Reset the counter `cnt` to 0 for the reverse traversal of the string to count 'Y' operations.

11. **Reverse Loop**
	```cpp
	    for (int i = s -1; i >= 0; i--) {
	```
	Start a loop from the end of the string to count the 'Y' operations.

12. **Count 'Y'**
	```cpp
	        if(a[i] == 'Y') cnt++;
	```
	If the current character is 'Y', increment the counter `cnt`.

13. **Store 'Y' Count**
	```cpp
	        y.push_back(cnt);
	```
	Store the current count of 'Y' operations in the `y` vector at the corresponding index.

14. **Reverse 'Y' Vector**
	```cpp
	    reverse (y.begin(), y.end());
	```
	Reverse the `y` vector to align the counts with the positions of the string.

15. **Initialize Answer**
	```cpp
	    int ans = INT_MAX, ind = 0;
	```
	Initialize `ans` to the maximum possible integer value and `ind` to 0. These will store the best closing time and its index.

16. **Find Minimum Closing Time**
	```cpp
	    for(int i = 0; i < s +1; i++) {
	```
	Loop through all possible closing times to find the one that minimizes the sum of 'N' before and 'Y' after.

17. **Calculate Time Sum**
	```cpp
	        int h = n[i] + y[i];
	```
	Calculate the sum `h` of 'N' operations before and 'Y' operations after the current time.

18. **Update Best Time**
	```cpp
	        if(h<ans) {
	```
	If the calculated sum `h` is smaller than the current best answer `ans`, update `ans` and the index `ind`.

19. **Store Best Time**
	```cpp
	            ans = h;
	```
	Store the new best sum `h` as the answer.

20. **Store Index**
	```cpp
	            ind = i;
	```
	Store the index of the current best time.

21. **Return Statement**
	```cpp
	    return ind;        
	```
	Return the index `ind` of the best closing time.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The solution involves a single pass through the input string and another pass to calculate penalties, resulting in a linear time complexity.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is linear due to the additional arrays used to store cumulative sums of 'Y' and 'N' counts.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-penalty-for-a-shop/description/)

---
{{< youtube 0d7ShRoOFVE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
