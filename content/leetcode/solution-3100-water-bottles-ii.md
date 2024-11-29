
+++
authors = ["grid47"]
title = "Leetcode 3100: Water Bottles II"
date = "2024-01-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3100: Water Bottles II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Ll_mTkG1rEc"
youtube_upload_date="2024-03-31"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Ll_mTkG1rEc/maxresdefault.webp"
comments = true
+++



---
You are given two integers: numBottles, representing the number of full water bottles you initially have, and numExchange, representing the number of empty bottles required to exchange for a full bottle. In one operation, you can drink any number of full water bottles, turning them into empty bottles, or exchange numExchange empty bottles for one full bottle, with numExchange increasing by 1 after each exchange. Return the maximum number of water bottles you can drink.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integers: numBottles (1 <= numBottles <= 100) and numExchange (1 <= numExchange <= 100).
- **Example:** `numBottles = 12, numExchange = 4`
- **Constraints:**
	- 1 <= numBottles <= 100
	- 1 <= numExchange <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum number of water bottles you can drink after performing all possible operations.
- **Example:** `Output: 15`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Maximize the number of water bottles consumed by performing exchanges while possible.

- 1. Start by drinking all the initial full bottles.
- 2. After drinking, accumulate empty bottles and attempt to exchange them for full bottles if possible.
- 3. Increase numExchange by 1 after each exchange.
- 4. Repeat the process until no further exchanges can be made.
{{< dots >}}
### Problem Assumptions ✅
- numBottles and numExchange will always be within the given constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `numBottles = 12, numExchange = 4`  \
  **Explanation:** You drink 12 full bottles initially, exchange empty bottles for full bottles while possible, and keep track of the total number of bottles drunk, which amounts to 15.

- **Input:** `numBottles = 8, numExchange = 3`  \
  **Explanation:** You drink 8 full bottles initially, then exchange empty bottles for full bottles and continue until no more exchanges can be made, resulting in 10 bottles drunk.

{{< dots >}}
## Approach 🚀
To solve this problem, we can simulate the process of drinking and exchanging bottles, keeping track of the full and empty bottles after each operation.

### Initial Thoughts 💭
- We need to track the full and empty bottles separately, and perform exchanges while possible.
- The number of bottles drunk can be maximized by continuously performing exchanges as long as there are enough empty bottles.
{{< dots >}}
### Edge Cases 🌐
- This problem doesn't have any empty inputs as numBottles and numExchange are always positive.
- The input limits of 1 <= numBottles <= 100 and 1 <= numExchange <= 100 are small, so performance is not an issue.
- The case where numBottles is exactly divisible by numExchange should be handled to ensure that exchanges are performed optimally.
- The solution should efficiently handle the given input constraints.
{{< dots >}}
## Code 💻
```cpp
int maxBottlesDrunk(int bot, int ex) {
    
    int full = bot;
    int empty = 0;
    int drunk = 0;
    
    
    while((empty + full) >= ex) {
        drunk   += full;
        empty   += full;
        full     = 0;
        while(empty >= ex) {
            empty   -= ex;
            full    += 1;
            ex      += 1;                
        }
    }
    
    return drunk + full;
    
}
```

This function simulates drinking a set number of bottles based on the current number of full and empty bottles, and the number of empty bottles required to get a new full bottle. It returns the total number of drunk bottles.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maxBottlesDrunk(int bot, int ex) {
	```
	Defines the function `maxBottlesDrunk` that takes two integers, `bot` (the number of full bottles) and `ex` (the number of empty bottles needed to get a full bottle), and returns the total number of drunk bottles.

2. **Variable Initialization**
	```cpp
	    int full = bot;
	```
	Initializes the `full` variable to the number of full bottles (`bot`).

3. **Variable Initialization**
	```cpp
	    int empty = 0;
	```
	Initializes the `empty` variable to 0, which will keep track of the number of empty bottles.

4. **Variable Initialization**
	```cpp
	    int drunk = 0;
	```
	Initializes the `drunk` variable to 0, which will accumulate the total number of drunk bottles.

5. **While Loop**
	```cpp
	    while((empty + full) >= ex) {
	```
	Enters the `while` loop as long as the total number of full and empty bottles is greater than or equal to `ex`, the number of empty bottles needed to get one full bottle.

6. **Bottle Consumption**
	```cpp
	        drunk   += full;
	```
	Adds all the current full bottles to the `drunk` count, as all full bottles will be consumed.

7. **Bottle Movement**
	```cpp
	        empty   += full;
	```
	Adds the consumed full bottles to the `empty` count, since they are now empty after being drunk.

8. **Bottle Reset**
	```cpp
	        full     = 0;
	```
	Resets the `full` variable to 0, since all full bottles have been consumed.

9. **Inner While Loop Setup**
	```cpp
	        while(empty >= ex) {
	```
	Enters a nested `while` loop, which continues as long as there are enough empty bottles to exchange for full ones.

10. **Empty Bottle Reduction**
	```cpp
	            empty   -= ex;
	```
	Reduces the `empty` count by `ex`, the number of empty bottles required to obtain one full bottle.

11. **Full Bottle Increase**
	```cpp
	            full    += 1;
	```
	Increases the `full` count by 1, since a new full bottle has been obtained.

12. **Empty Bottle Exchange**
	```cpp
	            ex      += 1;                
	```
	Increases the value of `ex` (the number of empty bottles required to exchange for a full one) by 1, simulating a change in exchange rules or a progressive difficulty.

13. **Return Statement**
	```cpp
	    return drunk + full;
	```
	Returns the total number of drunk bottles (`drunk`) plus any remaining full bottles (`full`).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the number of full bottles. This is because we simulate each drink and exchange operation.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we use a constant amount of extra space to track the bottles.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/water-bottles-ii/description/)

---
{{< youtube Ll_mTkG1rEc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
