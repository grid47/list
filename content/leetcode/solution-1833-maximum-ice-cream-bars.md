
+++
authors = ["grid47"]
title = "Leetcode 1833: Maximum Ice Cream Bars"
date = "2024-05-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1833: Maximum Ice Cream Bars in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting","Counting Sort"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "40qxrlPwBMM"
youtube_upload_date="2021-04-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/40qxrlPwBMM/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int sum = 0;
        for(int i = 0; i < costs.size(); i++) {
            sum += costs[i];
            if(sum == coins)
                return i +1;
            if(sum > coins)
                return i;
        }
        return costs.size();
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem is to determine the maximum number of ice creams that can be bought with a given amount of coins. You are provided with an array `costs`, where each element represents the cost of a different ice cream. The goal is to maximize the number of ice creams purchased without exceeding the total number of coins available.

### Approach

To solve this problem efficiently, we can follow a greedy approach:

1. **Sort the Costs**: Start by sorting the array of ice cream costs in ascending order. This way, we can prioritize buying the cheapest ice creams first, maximizing the total number of ice creams we can purchase with the given coins.

2. **Iterate Over Costs**: Initialize a variable to keep track of the total spent coins. Loop through the sorted costs and keep adding the cost of each ice cream to the total. 

3. **Check Against Available Coins**: After adding each ice cream's cost, check if the total spent coins equal or exceed the available coins. If they match, return the current number of ice creams purchased. If the total exceeds the available coins, return the number of ice creams purchased before that point.

4. **Return the Total Count**: If all ice creams can be purchased without exceeding the total coins, return the total count of ice creams.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
```
- We define a class `Solution` with a public method `maxIceCream` that takes a vector `costs` and an integer `coins` as parameters. This method will compute the maximum number of ice creams that can be bought.

```cpp
        sort(costs.begin(), costs.end());
```
- The first step inside the method is to sort the `costs` array. Sorting helps us efficiently purchase the cheapest ice creams first, which is crucial for maximizing the number we can buy.

```cpp
        int sum = 0;
```
- We initialize a variable `sum` to keep track of the total amount spent on ice creams as we iterate through the costs.

```cpp
        for(int i = 0; i < costs.size(); i++) {
```
- We start a loop to iterate over the sorted `costs` array.

```cpp
            sum += costs[i];
```
- For each ice cream cost, we add its value to `sum`.

```cpp
            if(sum == coins)
                return i + 1;
```
- We check if `sum` exactly matches `coins`. If it does, we return `i + 1`, which represents the total number of ice creams purchased (as `i` is zero-indexed).

```cpp
            if(sum > coins)
                return i;
```
- If `sum` exceeds `coins`, we return `i`, which indicates the number of ice creams bought before exceeding the budget.

```cpp
        return costs.size();
```
- If the loop completes without exceeding `coins`, we return the total number of ice creams, which is the size of the `costs` array, indicating that all ice creams could be purchased.

### Complexity

- **Time Complexity**: The time complexity of this solution is \(O(n \log n)\), where \(n\) is the number of ice creams (the size of the `costs` array). This is due to the sorting step. The subsequent iteration through the sorted costs takes \(O(n)\) time.

- **Space Complexity**: The space complexity is \(O(1)\) if we consider the sorting done in-place and not accounting for the input size itself. If we consider the input size, it would be \(O(n)\) to store the costs.

### Conclusion

The provided solution efficiently determines the maximum number of ice creams that can be purchased with the available coins using a greedy algorithm. By sorting the costs and iterating through them, we can make optimal decisions on which ice creams to buy first.

In summary, the `maxIceCream` function effectively addresses the problem by prioritizing cheaper ice creams, ensuring that we maximize the count while adhering to the budget constraints. The combination of sorting and a single pass through the costs allows for a solution that is both straightforward and efficient, making it ideal for scenarios involving budget management and purchasing decisions.

This method is particularly useful in competitive programming or interview settings, where demonstrating a clear understanding of greedy algorithms and their applications can be beneficial. It exemplifies how sorting can simplify complex purchasing problems and lead to optimal solutions.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-ice-cream-bars/description/)

---
{{< youtube 40qxrlPwBMM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
