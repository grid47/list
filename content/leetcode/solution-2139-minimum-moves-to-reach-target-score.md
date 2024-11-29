
+++
authors = ["grid47"]
title = "Leetcode 2139: Minimum Moves to Reach Target Score"
date = "2024-04-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2139: Minimum Moves to Reach Target Score in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "y3r6o712auw"
youtube_upload_date="2022-01-16"
youtube_thumbnail="https://i.ytimg.com/vi/y3r6o712auw/maxresdefault.jpg"
comments = true
+++



---
You start with the integer 1, and you need to reach the target integer using the minimum number of moves. In one move, you can either increment the current integer by 1 or double it. The doubling operation can be used at most `maxDoubles` times.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integers: `target` (the target integer to reach) and `maxDoubles` (the maximum number of times the doubling operation can be used).
- **Example:** `Input: target = 19, maxDoubles = 2`
- **Constraints:**
	- 1 <= target <= 10^9
	- 0 <= maxDoubles <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a single integer representing the minimum number of moves required to reach the target starting from 1.
- **Example:** `Output: 7`
- **Constraints:**
	- The result should be a non-negative integer representing the minimum moves.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the minimum number of moves to reach the target using increment and doubling operations.

- Start at 1 and try to reach the target.
- At each step, if the current integer is even and the doubling operation is available, try doubling it.
- Otherwise, increment the integer by 1.
- Repeat the process until the target is reached.
{{< dots >}}
### Problem Assumptions ✅
- The input values for `target` and `maxDoubles` are valid.
- The input `target` will always be greater than or equal to 1.
{{< dots >}}
## Examples 🧩
- **Input:** `target = 19, maxDoubles = 2`  \
  **Explanation:** In this example, we can increment to 4, double to 8, increment to 9, double to 18, and finally increment to 19. This process takes 7 steps.

{{< dots >}}
## Approach 🚀
The approach is to simulate the process of reaching the target by using the operations optimally. If the target is divisible by 2 and we still have available doubles, we should perform the doubling operation to speed up reaching the target.

### Initial Thoughts 💭
- If `maxDoubles` is 0, we can only increment to reach the target.
- If `maxDoubles` is large, using the doubling operation strategically can minimize the number of steps.
- Use a greedy approach to either double the number or increment it based on the current situation.
{{< dots >}}
### Edge Cases 🌐
- Since the input is always valid (1 <= target <= 10^9), there will never be empty inputs.
- For large values of `target`, ensure that the approach handles numbers up to 10^9 efficiently.
- When `target` is 1, no moves are needed, so the answer should be 0.
- When `maxDoubles` is 0, the only option is to increment the number.
- The approach must handle both large `target` values and small `maxDoubles` values efficiently.
{{< dots >}}
## Code 💻
```cpp
map<int, map<int, int>> mp;
int dp(int cur, int end, int dops) {
    if(cur == end) return 0;
    if(cur > end) return INT_MAX - 1;
    
    if(mp.count(cur) && mp[cur].count(dops)) return mp[cur][dops];
    
    int ans = 1 + dp(cur + 1, end, dops);
    if(dops > 0)
    ans = min(ans, 1 + dp(cur * 2, end, dops - 1));
    
    return mp[cur][dops] = ans;
}

int minMoves(int end, int dops) {
    
    int cnt = 0;
    
    while(end > 1) {
        if(end % 2) end -= 1;
        else if(dops > 0) {
            end /= 2;
            dops--;
        } else {
            cnt += (end -1);
            break;                
        }
        cnt++;
    }
    return cnt;
    
    // return dp(1, end, dops);
    
}
```

This code defines two functions to solve the problem of determining the minimum number of operations needed to transform a number `end` to 1. The operations allowed are decrementing by 1, dividing by 2, or using a limited number of operations `dops` to perform division by 2 more efficiently.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	map<int, map<int, int>> mp;
	```
	This line initializes a 2D map `mp` which will be used for memoization. It stores previously computed results for the dynamic programming function to avoid redundant calculations.

2. **Function Definition**
	```cpp
	int dp(int cur, int end, int dops) {
	```
	This is the definition of the `dp` function, which recursively calculates the minimum number of steps required to transform the number `cur` to `end`, using `dops` remaining operations that allow division by 2.

3. **Base Case 1**
	```cpp
	    if(cur == end) return 0;
	```
	If `cur` is equal to `end`, no more operations are needed, so the function returns 0.

4. **Base Case 2**
	```cpp
	    if(cur > end) return INT_MAX - 1;
	```
	If `cur` exceeds `end`, it's not possible to reach `end`, so a large value (essentially infinity) is returned to signify an invalid path.

5. **Memoization Retrieval**
	```cpp
	    if(mp.count(cur) && mp[cur].count(dops)) return mp[cur][dops];
	```
	This checks whether the result for `dp(cur, dops)` is already computed and stored in the memoization table `mp`. If so, it returns the cached result.

6. **Recursive Case 1**
	```cpp
	    int ans = 1 + dp(cur + 1, end, dops);
	```
	This line computes the result of performing a decrement operation (`cur + 1`) and recursively calls `dp` to calculate the remaining steps.

7. **Conditional Division**
	```cpp
	    if(dops > 0)
	```
	This checks if there are remaining division operations (`dops > 0`) available to divide by 2.

8. **Recursive Case 2**
	```cpp
	    ans = min(ans, 1 + dp(cur * 2, end, dops - 1));
	```
	If division by 2 is allowed (i.e., `dops > 0`), the function recursively tries the division operation and compares the result to the previously calculated value to find the minimum number of operations.

9. **Memoization Save**
	```cpp
	    return mp[cur][dops] = ans;
	```
	This line stores the computed minimum number of operations for the current state `(cur, dops)` into the memoization table `mp` to avoid redundant calculations in future recursive calls.

10. **Function Definition**
	```cpp
	int minMoves(int end, int dops) {
	```
	This defines the `minMoves` function, which calculates the minimum number of moves needed to transform `end` to 1, possibly using up to `dops` division operations.

11. **Variable Initialization**
	```cpp
	    int cnt = 0;
	```
	This initializes a counter `cnt` to track the number of operations performed.

12. **While Loop**
	```cpp
	    while(end > 1) {
	```
	This while loop continues as long as `end` is greater than 1, repeatedly applying operations to reduce `end`.

13. **Odd Number Check**
	```cpp
	        if(end % 2) end -= 1;
	```
	If `end` is odd, it is decremented by 1.

14. **Even Number Check**
	```cpp
	        else if(dops > 0) {
	```
	If `end` is even and division by 2 is allowed (`dops > 0`), the function proceeds with division.

15. **Division Operation**
	```cpp
	            end /= 2;
	```
	If division by 2 is allowed, `end` is halved.

16. **Decrement dops**
	```cpp
	            dops--;
	```
	After performing a division by 2, the available division operations (`dops`) are decremented.

17. **No Division Available**
	```cpp
	        } else {
	```
	If no division operation is available (i.e., `dops` is 0), the function enters the else block.

18. **Final Adjustment**
	```cpp
	            cnt += (end -1);
	```
	If no division operations are left, the remaining difference between `end` and 1 is added to `cnt` to perform simple decrements until `end` becomes 1.

19. **Break**
	```cpp
	            break;                
	```
	The loop breaks after performing the necessary decrements when no division operations are left.

20. **Return Statement**
	```cpp
	    return cnt;
	```
	This returns the total count of operations performed to reduce `end` to 1.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log target)
- **Average Case:** O(log target)
- **Worst Case:** O(target)

In the best and average cases, the time complexity is O(log target), as doubling reduces the target rapidly. In the worst case (when only incrementing is needed), the time complexity is O(target).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant (O(1)), as the algorithm only requires a few variables to track the current state.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-moves-to-reach-target-score/description/)

---
{{< youtube y3r6o712auw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
