
+++
authors = ["grid47"]
title = "Leetcode 2240: Number of Ways to Buy Pens and Pencils"
date = "2024-03-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2240: Number of Ways to Buy Pens and Pencils in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "WzmIQmBNa0A"
youtube_upload_date="2022-04-16"
youtube_thumbnail="https://i.ytimg.com/vi/WzmIQmBNa0A/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long cnt = 0;
        int sum = total;
        while(sum >= 0 || sum/cost2 > 0) {
            cnt+= (sum/cost2 + 1);
            sum -= cost1;
        }
        return cnt;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to determine how many different ways we can buy pens and pencils with a given amount of money. The user is provided with a total amount of money (`total`) and the costs of a single pen (`cost1`) and a single pencil (`cost2`). The task is to calculate how many ways the user can buy these items in such a way that the total cost does not exceed the available money.

### Approach

To solve this problem, we need to compute all possible combinations of buying pens and pencils such that the total cost does not exceed the given `total`. Specifically:

1. **Understanding the Constraints**: 
   - We can buy multiple pens and multiple pencils as long as the total cost doesn't exceed the total amount of money (`total`). The pens cost `cost1` each, and pencils cost `cost2` each.
   
2. **Iterative Approach**:
   - The goal is to calculate how many ways we can buy pens and pencils. We can iterate over all possible numbers of pens we can buy (ranging from 0 to the maximum number of pens we can afford). For each number of pens, we calculate how many pencils can be bought with the remaining money.
   - The total number of ways we can buy pens and pencils can be determined by iterating through all possible numbers of pens and calculating how many pencils we can buy for each.

3. **Breakdown of the Steps**:
   - **First, calculate how many pens can be bought**: For each possible number of pens (starting from 0 up to the total amount of money divided by the cost of a pen), we subtract the cost of the pens from the total money to get the remaining money.
   - **Then calculate how many pencils can be bought with the remaining money**: Using the remaining money after buying the pens, calculate how many pencils can be bought by dividing the remaining money by the cost of a pencil. Each iteration contributes a possible combination of pens and pencils.

4. **Optimization Consideration**:
   - Instead of recalculating the possible number of pencils for every iteration, we can directly calculate it by dividing the remaining money by the cost of the pencil in each iteration, making the solution efficient.

5. **Counting Combinations**:
   - For each number of pens, we count how many pencils can be bought. This is done by calculating `(remaining money / cost of a pencil) + 1`. The `+1` accounts for the possibility of buying zero pencils if no money remains after buying pens.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long cnt = 0;  // This will store the total number of combinations
        int sum = total;    // Variable to track the remaining money
        
        // While the remaining money is non-negative or we can still buy at least one pencil
        while(sum >= 0 || sum/cost2 > 0) {
            // Add the number of pencils that can be bought with the remaining money
            cnt += (sum/cost2 + 1);  // +1 to account for the case where we buy 0 pencils
            
            // Subtract the cost of one pen from the remaining money
            sum -= cost1;
        }
        
        // Return the total number of combinations
        return cnt;
    }
};
```

#### 1. **Function Declaration**:
```cpp
long long waysToBuyPensPencils(int total, int cost1, int cost2) {
```
- The function `waysToBuyPensPencils` takes three arguments: `total` (the total money available), `cost1` (the cost of a single pen), and `cost2` (the cost of a single pencil).
- The return type is `long long`, as the result can be a large number depending on the input values.

#### 2. **Initialization**:
```cpp
long long cnt = 0;
int sum = total;
```
- `cnt` is initialized to `0` and will keep track of the total number of ways we can buy pens and pencils.
- `sum` is initialized with the value of `total` to keep track of the remaining money as we iterate through the possible purchases of pens and pencils.

#### 3. **While Loop**:
```cpp
while(sum >= 0 || sum/cost2 > 0) {
```
- The `while` loop continues as long as `sum` is non-negative or there is enough money left to buy at least one pencil (`sum/cost2 > 0`).
- The condition ensures that we keep checking for all valid combinations until we can no longer afford any items.

#### 4. **Calculating Pencils**:
```cpp
cnt += (sum/cost2 + 1);
```
- For the current amount of money in `sum`, we calculate how many pencils can be bought (`sum/cost2`).
- We add `1` to this result to account for the possibility of buying zero pencils (if no money is left for pencils after buying pens).
- This counts how many combinations are possible for the current number of pens we are considering.

#### 5. **Update the Remaining Money**:
```cpp
sum -= cost1;
```
- After considering how many pencils can be bought for the current amount of money, we subtract the cost of one pen (`cost1`) from `sum` to check how many more combinations are possible if we buy one more pen.

#### 6. **Returning the Result**:
```cpp
return cnt;
```
- Once the loop finishes, we return the value of `cnt`, which contains the total number of combinations of pens and pencils that can be bought with the available money.

### Complexity

#### Time Complexity:
- **O(total/cost1)**: The `while` loop runs approximately `total/cost1` times, as in each iteration we subtract the cost of one pen (`cost1`) from the total money (`total`).
- For each iteration, the calculation of how many pencils can be bought (i.e., `sum/cost2 + 1`) takes constant time, so the time complexity is linear in terms of how many iterations are needed.

#### Space Complexity:
- **O(1)**: The space complexity is constant, as we only use a few variables (`cnt`, `sum`) to store intermediate values, and no additional data structures are created that depend on the input size.

### Conclusion

The solution efficiently calculates how many ways pens and pencils can be bought within the available budget using an iterative approach. The logic ensures that we account for all possible combinations of purchases, including the case where no pencils are bought for a given number of pens. By iterating through the possible number of pens and calculating the number of pencils that can be bought for each, the algorithm efficiently computes the total number of valid combinations.

This solution performs well with a time complexity of **O(total/cost1)**, which is optimal for this problem, and the space complexity of **O(1)** ensures that the solution uses a constant amount of memory.

The approach is intuitive, easy to understand, and efficient, making it suitable for a wide range of input sizes. This algorithm is a good example of how to solve problems involving combinations or iterations over possible values efficiently.

[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-ways-to-buy-pens-and-pencils/description/)

---
{{< youtube WzmIQmBNa0A >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
