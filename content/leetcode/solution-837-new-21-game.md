
+++
authors = ["grid47"]
title = "Leetcode 837: New 21 Game"
date = "2024-08-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 837: New 21 Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Dynamic Programming","Sliding Window","Probability and Statistics"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "zKi4LzjK27k"
youtube_upload_date="2023-05-25"
youtube_thumbnail="https://i.ytimg.com/vi/zKi4LzjK27k/maxresdefault.jpg"
comments = true
+++



---
Alice is playing a game where she starts with 0 points and randomly draws a number from the range [1, maxPts] each time. Alice continues drawing until her points reach or exceed a target value k. After each draw, she may stop if her total points reach or exceed k. The goal is to determine the probability that Alice has at most n points before reaching k points.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of three integers: n, k, and maxPts. Here, n is the maximum number of points Alice can have without exceeding it, k is the target score Alice needs to reach or exceed to stop drawing, and maxPts is the maximum number of points Alice can draw in each round.
- **Example:** `Input: n = 15, k = 10, maxPts = 5`
- **Constraints:**
	- 0 <= k <= n <= 10^4
	- 1 <= maxPts <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the probability that Alice has at most n points when she stops drawing.
- **Example:** `Output: 0.80000`
- **Constraints:**
	- The probability should be accurate within a relative or absolute error of 10^-5.

{{< dots >}}
### Core Logic 🔍
**Goal:** To calculate the probability that Alice's points are at most n before she reaches the target k.

- Step 1: Initialize a dp array to store the probabilities of Alice having exactly i points.
- Step 2: Start with the base case where Alice has 0 points (probability = 1).
- Step 3: For each possible score from 1 to n, calculate the probability of reaching that score by drawing a number from the range [1, maxPts].
- Step 4: Use a sliding window to sum the probabilities efficiently to calculate the next values in the dp array.
- Step 5: If the points exceed or reach k, stop the process and sum the probabilities for the cases where the points are less than or equal to n.
{{< dots >}}
### Problem Assumptions ✅
- Alice draws random numbers independently and each draw has an equal probability of any number in the range [1, maxPts].
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 15, k = 10, maxPts = 5`  \
  **Explanation:** In this case, Alice can draw numbers from 1 to 5, and she needs to stop when her points exceed or equal 10. We need to calculate the probability that she has 15 or fewer points before stopping.

- **Input:** `Input: n = 10, k = 1, maxPts = 10`  \
  **Explanation:** Alice draws a single card and immediately stops when she reaches or exceeds the target k = 1. Therefore, the probability of having 10 or fewer points is 1.

{{< dots >}}
## Approach 🚀
We need to calculate the probability of having n or fewer points, which involves dynamic programming and efficient sliding window sum computation.

### Initial Thoughts 💭
- This is a probability problem where we need to accumulate probabilities over multiple draws.
- We can use dynamic programming to efficiently calculate the probability distribution of the total points after each draw.
- The key challenge is to compute the probability of having a specific number of points, while ensuring we don't exceed the target score k.
{{< dots >}}
### Edge Cases 🌐
- Empty or invalid inputs should not be provided.
- Ensure the solution handles large inputs efficiently, especially when n, k, or maxPts are close to the upper limits of 10^4.
- Handle cases where n or k is 0, or maxPts is equal to 1.
- Make sure the values adhere to the constraints and do not exceed the bounds.
{{< dots >}}
## Code 💻
```cpp
double new21Game(int n, int k, int w) {
    

    if(k == 0 || n >= k + w)
        return 1;

    
    /*
    
    You will get number x (1 to w) in a draw, with probablity 1 / w
    
    if you need probablity of getting i points in a draw
    
    we can do slecting (i - x) points with probablity dp[i - x] and
    selecting x with probablity x
    
    so doing it together dp[i - x] * 1 / w
    
    and this to every x in [1, w] to get net prob of dp[i].
    
    once the pionts has crossed a limit k, there will be no more selections.
    
    then we look for only the over flows from previous trials.

    why target probablity counted from k onward instead of dp[n].

    */        
    
    vector<double> dp(n+1);
    dp[0] = 1;
    double Wsum = 1.0, res = 0.0;
    for(int i = 1; i <= n; i++) {
        dp[i] = Wsum/ w;
        if(i < k) Wsum += dp[i];
        else res += dp[i];
        if(i - w >= 0) Wsum -= dp[i - w];
    }
    return res;
}
```

This code implements a probability-based approach for the game described. It calculates the probability of reaching a score within a specified range and returns the overall probability of success.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	double new21Game(int n, int k, int w) {
	```
	Define a function to calculate the probability of winning a game given the parameters n (number of points), k (limit), and w (range of possible outcomes in a draw).

2. **Condition Check**
	```cpp
	    if(k == 0 || n >= k + w)
	```
	Check if the game is over based on the values of k and n. If k is zero or n exceeds the limit plus range, return a probability of 1.

3. **Return Statement**
	```cpp
	        return 1;
	```
	If the condition in the previous step is true, the game ends with a probability of 1.

4. **Dynamic Programming Setup**
	```cpp
	    vector<double> dp(n+1);
	```
	Initialize a vector dp to store probabilities for each score from 0 to n.

5. **Initialization**
	```cpp
	    dp[0] = 1;
	```
	Set the base case: the probability of getting 0 points is 1.

6. **Variable Initialization**
	```cpp
	    double Wsum = 1.0, res = 0.0;
	```
	Initialize variables for cumulative probability (Wsum) and the result (res).

7. **Main Loop**
	```cpp
	    for(int i = 1; i <= n; i++) {
	```
	Loop through all possible scores from 1 to n to calculate the probabilities.

8. **Probability Calculation**
	```cpp
	        dp[i] = Wsum / w;
	```
	Set the probability of reaching score i by dividing the cumulative probability by w.

9. **Cumulative Probability Update**
	```cpp
	        if(i < k) Wsum += dp[i];
	```
	If the score is less than k, update the cumulative probability.

10. **Result Calculation**
	```cpp
	        else res += dp[i];
	```
	If the score exceeds k, add the probability to the result.

11. **Cumulative Probability Adjust**
	```cpp
	        if(i - w >= 0) Wsum -= dp[i - w];
	```
	Adjust the cumulative probability by subtracting the value that is no longer in the valid range.

12. **Return Result**
	```cpp
	    return res;
	```
	Return the computed result as the final probability of winning.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear in terms of n, as we are iterating over the possible number of points and updating probabilities.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of the dp array for keeping track of probabilities.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/new-21-game/description/)

---
{{< youtube zKi4LzjK27k >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
