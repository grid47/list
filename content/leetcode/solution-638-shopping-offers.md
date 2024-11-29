
+++
authors = ["grid47"]
title = "Leetcode 638: Shopping Offers"
date = "2024-09-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 638: Shopping Offers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Backtracking","Bit Manipulation","Memoization","Bitmask"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/638.webp"
youtube = "t6atP4Yv7_4"
youtube_upload_date="2021-06-05"
youtube_thumbnail="https://i.ytimg.com/vi/t6atP4Yv7_4/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/638.webp" 
    alt="A set of shopping offers with discounts, where each offer is softly glowing based on its value."
    caption="Solution to LeetCode 638: Shopping Offers Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
In a store, there are n items available for sale, each with a given price. You are also given a list of special offers where you can buy multiple items at a discounted price. Your task is to determine the minimum total price to purchase the required quantities of each item, while utilizing the special offers optimally. You can use any offer as many times as you like, but cannot buy more items than you need.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array of prices, a list of special offers, and a list of the items you need to buy. Each offer consists of quantities of different items and the price for that offer.
- **Example:** `price = [3, 6], special = [[4, 0, 8], [2, 3, 10]], needs = [5, 6]`
- **Constraints:**
	- 1 <= n <= 6
	- 0 <= price[i], needs[i] <= 10
	- 1 <= special.length <= 100
	- special[i].length == n + 1
	- 0 <= special[i][j] <= 50

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum cost to purchase exactly the required items, taking into account the special offers.
- **Example:** `26`
- **Constraints:**
	- The result must be the minimum total cost to satisfy the item needs.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the lowest total price while considering all available special offers.

- Iterate through each offer and decide whether to use it based on the remaining needs.
- Track the total cost as you use the optimal combination of offers.
{{< dots >}}
### Problem Assumptions ✅
- At least one of the special offers includes non-zero quantities of the items.
- The input will always be valid and satisfies the constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `price = [3, 6], special = [[4, 0, 8], [2, 3, 10]], needs = [5, 6]`  \
  **Explanation:** You need 5 units of Item 0 and 6 units of Item 1. The best option is to buy the second offer twice and 1 more unit of Item 0 for a total cost of 26.

{{< dots >}}
## Approach 🚀
The optimal strategy involves recursively trying each special offer and calculating the total cost. Use memoization to store previously computed results to avoid redundant calculations.

### Initial Thoughts 💭
- We should take advantage of special offers that reduce the price for multiple items.
- We can recursively try each offer and compute the cost after applying the offer, then memoize the results to avoid recalculations.
{{< dots >}}
### Edge Cases 🌐
- The problem will always have valid inputs, so there will never be an empty list for 'price', 'needs', or 'special'.
- The input sizes are manageable (n <= 6, special.length <= 100), so a solution with time complexity up to O(n^2) is feasible.
- Special cases include when all offers result in the same cost or when no offer provides any savings.
- The solution should handle up to 100 offers and 6 items efficiently.
{{< dots >}}
## Code 💻
```cpp
map<vector<int>, int> mp;
int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
    if(mp[needs]) return mp[needs];
    int best = calculate(price, needs);
    for(auto &sp: special) {
        sub(needs, sp);
        if(noneg(needs)) {
            int woffer = sp.back() + shoppingOffers(price, special, needs);
            best = min(best, woffer);
        }
        add(needs, sp);
    }        
    return mp[needs] = best;
}

int calculate(vector<int> &prices, vector<int> &needs) {
    int res = 0;
    for(int i = 0; i < needs.size(); i++) {
        res += (needs[i] * prices[i]);
    }
    return res;        
}
void add(vector<int> &needs, vector<int> &sp) {
    for(int i = 0; i < needs.size(); i++) {
        needs[i] += sp[i];
    }     
}    
void sub(vector<int> &needs, vector<int> &sp) {
    for(int i = 0; i < needs.size(); i++) {
        needs[i] -= sp[i];
    }
}
bool noneg(vector<int> &needs) {
    for(int i = 0; i < needs.size(); i++) {
        if(needs[i] < 0) return false;
    }
    return true;
}
```

This code defines a solution to the shopping offers problem, using dynamic programming to calculate the minimum cost of purchasing a list of items, considering available special offers. It makes use of memoization to avoid redundant calculations, optimizing the process of finding the best combination of offers.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	map<vector<int>, int> mp;
	```
	This line initializes a map, 'mp', which stores the minimum cost for each combination of item quantities (represented as a vector). The key is a vector of integers representing the current needs, and the value is the minimum cost for fulfilling that set of needs.

2. **Function Definition**
	```cpp
	int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
	```
	This is the function signature of 'shoppingOffers'. It takes in the prices of items, the special offers, and the current needs (quantities of items to buy) as input. It returns the minimum cost to fulfill the needs considering the special offers.

3. **Memoization**
	```cpp
	    if(mp[needs]) return mp[needs];
	```
	This line checks if the result for the current set of needs has already been computed. If so, it returns the cached result from the map 'mp' to avoid redundant calculations.

4. **Initial Calculation**
	```cpp
	    int best = calculate(price, needs);
	```
	This line initializes the best cost as the result of the 'calculate' function, which computes the cost of fulfilling the needs without considering any special offers.

5. **Iterating over Offers**
	```cpp
	    for(auto &sp: special) {
	```
	This loop iterates through each special offer in the 'special' vector. Each special offer contains a vector of item quantities and the price for that offer.

6. **Subtraction of Items**
	```cpp
	        sub(needs, sp);
	```
	The 'sub' function subtracts the quantities of items in the special offer from the current 'needs' vector, simulating the purchase of the offer.

7. **Check for Valid Needs**
	```cpp
	        if(noneg(needs)) {
	```
	This checks whether the remaining needs are all non-negative. If any need is negative, it means the current offer is invalid (i.e., the special offer cannot be used to fulfill the needs).

8. **Recursive Call with Special Offer**
	```cpp
	            int woffer = sp.back() + shoppingOffers(price, special, needs);
	```
	This line recursively calculates the cost if the current special offer is used, adding the cost of the offer (sp.back()) to the result of fulfilling the updated needs.

9. **Update Best Cost**
	```cpp
	            best = min(best, woffer);
	```
	This updates the 'best' variable to the minimum of the current 'best' and the new cost ('woffer') obtained from using the current special offer.

10. **Restore Needs**
	```cpp
	        add(needs, sp);
	```
	The 'add' function restores the quantities of items in 'needs' by adding back the quantities subtracted by the special offer.

11. **Memoization Store**
	```cpp
	    return mp[needs] = best;
	```
	This stores the computed 'best' result in the map 'mp' for the current set of needs, ensuring it can be reused in future calculations.

12. **Helper Function**
	```cpp
	int calculate(vector<int> &prices, vector<int> &needs) {
	```
	This is the helper function 'calculate', which calculates the total cost of fulfilling the needs without considering special offers.

13. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	This initializes the result variable 'res' to 0. It will accumulate the total cost of fulfilling the needs.

14. **Cost Calculation Loop**
	```cpp
	    for(int i = 0; i < needs.size(); i++) {
	```
	This loop iterates through each item in the 'needs' vector, calculating the total cost based on the price and the quantity needed.

15. **Accumulating Cost**
	```cpp
	        res += (needs[i] * prices[i]);
	```
	This line adds the cost for the current item to the total cost 'res'. It multiplies the price of the item by the quantity needed.

16. **Return Calculation**
	```cpp
	    return res;        
	```
	This returns the total cost calculated by the 'calculate' function.

17. **Helper Function**
	```cpp
	void add(vector<int> &needs, vector<int> &sp) {
	```
	This is the 'add' function, which restores the quantities of items in 'needs' by adding the quantities in the special offer 'sp'.

18. **Loop through Items**
	```cpp
	    for(int i = 0; i < needs.size(); i++) {
	```
	This loop iterates through the items in the 'needs' vector.

19. **Add Item Quantities**
	```cpp
	        needs[i] += sp[i];
	```
	This adds the quantity of the current item in the special offer 'sp' to the 'needs' vector.

20. **Helper Function**
	```cpp
	void sub(vector<int> &needs, vector<int> &sp) {
	```
	This is the 'sub' function, which subtracts the quantities of items in the special offer 'sp' from the 'needs' vector.

21. **Loop through Items**
	```cpp
	    for(int i = 0; i < needs.size(); i++) {
	```
	This loop iterates through the items in the 'needs' vector.

22. **Subtract Item Quantities**
	```cpp
	        needs[i] -= sp[i];
	```
	This subtracts the quantity of the current item in the special offer 'sp' from the 'needs' vector.

23. **Helper Function**
	```cpp
	bool noneg(vector<int> &needs) {
	```
	This is the 'noneg' function, which checks if all the values in the 'needs' vector are non-negative.

24. **Loop through Needs**
	```cpp
	    for(int i = 0; i < needs.size(); i++) {
	```
	This loop iterates through the 'needs' vector to check if any value is negative.

25. **Check for Negative Values**
	```cpp
	        if(needs[i] < 0) return false;
	```
	This checks if any value in the 'needs' vector is negative. If it finds a negative value, it returns false.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * special.length)
- **Average Case:** O(n * special.length)
- **Worst Case:** O(n^2 * special.length)

The time complexity is primarily determined by the number of special offers and the number of items.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n * special.length)

The space complexity is influenced by the memoization and the need to track the 'needs' array for each recursive call.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/shopping-offers/description/)

---
{{< youtube t6atP4Yv7_4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
