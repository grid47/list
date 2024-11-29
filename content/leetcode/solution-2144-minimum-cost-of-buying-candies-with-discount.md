
+++
authors = ["grid47"]
title = "Leetcode 2144: Minimum Cost of Buying Candies With Discount"
date = "2024-04-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2144: Minimum Cost of Buying Candies With Discount in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "KvdPgFfH1t0"
youtube_upload_date="2022-01-22"
youtube_thumbnail="https://i.ytimg.com/vi_webp/KvdPgFfH1t0/maxresdefault.webp"
comments = true
+++



---
A shop offers a special deal: for every two candies you purchase, you get a third candy for free. The free candy must have a cost that is less than or equal to the minimum cost of the two candies purchased. Calculate the minimum cost of purchasing all candies.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array `cost`, where each element represents the cost of a candy.
- **Example:** `Input: cost = [3, 5, 7]`
- **Constraints:**
	- 1 <= cost.length <= 100
	- 1 <= cost[i] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a single integer, representing the minimum cost of buying all the candies while making use of the 'buy 2, get 1 free' offer.
- **Example:** `Output: 10`
- **Constraints:**
	- The result should be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** Minimize the total cost by selecting pairs of candies to buy and making use of the third free candy when applicable.

- Sort the candy prices in descending order.
- For every three consecutive candies, only pay for the first two.
- Sum up the costs of the candies you actually paid for to get the minimum cost.
{{< dots >}}
### Problem Assumptions ✅
- The input is always valid and contains at least one candy.
{{< dots >}}
## Examples 🧩
- **Input:** `cost = [3, 5, 7]`  \
  **Explanation:** The optimal strategy is to buy the candies with costs 7 and 5, then take the candy priced at 3 for free. This results in a total cost of 5 + 7 = 10.

- **Input:** `cost = [4, 9, 3, 6, 2, 1]`  \
  **Explanation:** The optimal strategy is to buy candies with costs 9 and 6, then take the candy priced at 4 for free. After that, buy candies with costs 3 and 2, then take the candy priced at 1 for free. This results in a total cost of 9 + 6 + 3 + 2 = 17.

{{< dots >}}
## Approach 🚀
The approach to solving this problem involves sorting the candy prices in descending order and then pairing the candies optimally to minimize the cost using the 'buy 2, get 1 free' offer.

### Initial Thoughts 💭
- By buying the most expensive candies first, we can maximize the value of the free candy.
- Sorting the prices in descending order ensures that the free candy is always the cheapest option.
- A greedy approach works well in this case because it allows us to efficiently maximize the value of the 'buy 2, get 1 free' offer.
{{< dots >}}
### Edge Cases 🌐
- The input will always contain at least one candy, so there will be no empty inputs.
- The approach must efficiently handle up to 100 candies.
- If there are fewer than three candies, no candy will be free.
- The solution must ensure that the time complexity remains manageable, even for the largest inputs.
{{< dots >}}
## Code 💻
```cpp
int minimumCost(vector<int>& cost) {
    sort(cost.begin(), cost.end());
    int n = cost.size(), res = 0;
    for(int i = 0; i < n; i++) {
      if(i % 3 == n % 3) continue;
      res += cost[i];
    }
    return res;
}
```

This function calculates the minimum cost by sorting the input vector and excluding every third element in the sorted list.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int minimumCost(vector<int>& cost) {
	```
	This line defines the function `minimumCost`, which takes a reference to a vector `cost` as input and returns an integer representing the minimum cost.

2. **Sorting**
	```cpp
	    sort(cost.begin(), cost.end());
	```
	This line sorts the vector `cost` in ascending order to arrange the cost values from smallest to largest.

3. **Variable Initialization**
	```cpp
	    int n = cost.size(), res = 0;
	```
	This initializes two variables: `n` as the size of the sorted vector and `res` to store the accumulated result (initially set to 0).

4. **Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	This initiates a loop that iterates over each element of the sorted `cost` vector.

5. **Condition Check**
	```cpp
	      if(i % 3 == n % 3) continue;
	```
	This condition skips every third element in the sorted vector by checking the modulus of the current index `i` against `n % 3`.

6. **Accumulate Cost**
	```cpp
	      res += cost[i];
	```
	If the condition is not met (i.e., the current element is not skipped), this line adds the value of `cost[i]` to the result `res`.

7. **Return Result**
	```cpp
	    return res;
	```
	After processing all elements, this line returns the accumulated result `res`, which is the minimum cost excluding every third element.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting step, which is O(n log n), where n is the number of candies.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space required for storing the sorted list of candy prices.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/description/)

---
{{< youtube KvdPgFfH1t0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
