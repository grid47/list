
+++
authors = ["grid47"]
title = "Leetcode 875: Koko Eating Bananas"
date = "2024-08-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 875: Koko Eating Bananas in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "ceYZ5RgwQwQ"
youtube_upload_date="2024-02-29"
youtube_thumbnail="https://i.ytimg.com/vi/ceYZ5RgwQwQ/maxresdefault.jpg"
comments = true
+++



---
Koko loves to eat bananas and there are multiple piles of bananas. Each pile has a certain number of bananas. Koko can decide how many bananas she wants to eat per hour, and each hour she can choose any pile to eat from. If the pile contains fewer bananas than her chosen rate, she finishes that pile and moves to another pile. Koko needs to finish all the bananas before the guards return in h hours. You need to determine the minimum number of bananas per hour Koko should eat in order to finish all piles within the given time.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list of integers where each integer represents the number of bananas in a pile, and an integer h representing the total hours Koko has to finish the bananas.
- **Example:** `Input: piles = [4, 10, 7, 13], h = 6`
- **Constraints:**
	- 1 <= piles.length <= 10^4
	- piles.length <= h <= 10^9
	- 1 <= piles[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum integer k such that Koko can eat all the bananas within h hours. If no such integer exists, return 0.
- **Example:** `Output: 8`
- **Constraints:**
	- The output should be a single integer representing the minimum speed Koko needs to eat the bananas.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the minimum number of bananas per hour, k, that allows Koko to eat all the bananas within h hours.

- Perform a binary search on the possible eating speeds from 1 to the maximum number of bananas in any pile.
- For each candidate eating speed k, calculate the total number of hours Koko would take to eat all piles at that speed.
- If the total hours exceed h, increase the speed; otherwise, try a smaller speed until you find the minimum k.
{{< dots >}}
### Problem Assumptions ✅
- The input array piles is non-empty and contains positive integers.
- Koko's eating speed is adjustable and the goal is to minimize it while ensuring all bananas are eaten within h hours.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: piles = [4, 10, 7, 13], h = 6`  \
  **Explanation:** The minimum speed Koko needs to eat all bananas in 6 hours is 8 bananas per hour, as at this speed she can finish all piles within the given time.

- **Input:** `Input: piles = [5, 15, 12, 30], h = 4`  \
  **Explanation:** The minimum speed Koko needs to eat all bananas in 4 hours is 15 bananas per hour.

{{< dots >}}
## Approach 🚀
We will use binary search to find the optimal eating speed. This allows us to efficiently find the minimum speed that allows Koko to finish eating within the given time limit.

### Initial Thoughts 💭
- The problem can be solved efficiently with binary search since the relationship between speed and time is monotonic (higher speed leads to fewer hours).
- We need to carefully calculate the total time for each speed and adjust the search range based on whether it is sufficient to eat all bananas.
{{< dots >}}
### Edge Cases 🌐
- If piles is empty, return 0 since there are no bananas to eat.
- The algorithm should efficiently handle large inputs, with pile sizes and hours potentially reaching up to 10^9.
- If piles has only one element, the answer will simply be that element divided by the hours.
- The solution must handle inputs with up to 10^4 piles and large integer values within the specified range.
{{< dots >}}
## Code 💻
```cpp
int minEatingSpeed(vector<int>& piles, int H) {
    int l = 0, r = 1000000000;
    while(l <= r) {
        int k = l + (r - l) / 2;
        double h = 0;
        for(int x: piles)
            h += ceil((double) x / k);
        
        if(h > H)   l = k + 1;
        else        r = k - 1;
    }
    return l;
}
```

This code implements a binary search solution to determine the minimum eating speed for an array of piles of bananas to be eaten in `H` hours.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minEatingSpeed(vector<int>& piles, int H) {
	```
	The function `minEatingSpeed` takes two inputs: a vector of integers `piles` representing the number of bananas in each pile, and an integer `H` representing the total number of hours available.

2. **Variable Initialization**
	```cpp
	    int l = 0, r = 1000000000;
	```
	The variables `l` and `r` represent the lower and upper bounds for the possible eating speeds. `l` starts at 0 and `r` is set to a very large number.

3. **While Loop**
	```cpp
	    while(l <= r) {
	```
	A `while` loop is used to perform the binary search, which continues as long as the lower bound is less than or equal to the upper bound.

4. **Binary Search Step**
	```cpp
	        int k = l + (r - l) / 2;
	```
	The midpoint `k` is calculated as the average of `l` and `r` (the current lower and upper bounds of the eating speed). This is the candidate eating speed to check.

5. **Variable Initialization**
	```cpp
	        double h = 0;
	```
	A variable `h` is initialized to 0. This will track the total number of hours required to eat all the piles at the current speed `k`.

6. **For Loop**
	```cpp
	        for(int x: piles)
	```
	A `for` loop iterates over each pile `x` in the `piles` array, calculating how many hours it would take to eat that pile at speed `k`.

7. **Calculation**
	```cpp
	            h += ceil((double) x / k);
	```
	For each pile `x`, the number of hours required to eat the pile at speed `k` is calculated using `ceil((double) x / k)`, and the result is added to `h`.

8. **Condition Check**
	```cpp
	        if(h > H)   l = k + 1;
	```
	If the total number of hours `h` exceeds the available hours `H`, it means the speed `k` is too slow, so the lower bound `l` is increased to `k + 1`.

9. **Condition Check**
	```cpp
	        else        r = k - 1;
	```
	If the total number of hours `h` is within the allowed limit `H`, it means the speed `k` may be valid, so the upper bound `r` is decreased to `k - 1`.

10. **Return Statement**
	```cpp
	    return l;
	```
	Once the binary search loop finishes, the variable `l` contains the minimum eating speed that allows all piles to be eaten within `H` hours. This value is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log M)
- **Average Case:** O(n log M)
- **Worst Case:** O(n log M)

The time complexity is O(n log M), where n is the number of piles and M is the maximum number of bananas in any pile.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant since only a few variables are used to track the process.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/koko-eating-bananas/description/)

---
{{< youtube ceYZ5RgwQwQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
