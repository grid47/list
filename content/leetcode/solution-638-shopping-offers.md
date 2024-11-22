
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
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to find the minimum cost of buying products given the prices for each item and a list of special offers. Each special offer provides a discount if certain quantities of items are bought together. We need to calculate the minimum cost to satisfy a set of product needs using the given prices and special offers.

We are given:
1. `price`: A list of prices for each product.
2. `special`: A list of special offers, where each offer contains a set of quantities of products and the corresponding price for that set.
3. `needs`: A list of quantities of products needed.

Our goal is to find the minimum cost to fulfill the needs, utilizing the special offers optimally, without purchasing more than required.

### Approach

The key challenge in solving this problem is efficiently deciding whether to buy individual products at full price or utilize the special offers. We need to recursively explore both options while ensuring that we minimize the total cost. The approach uses **memoization** (dynamic programming) to avoid recomputation of previously solved subproblems.

We use a **depth-first search (DFS)** with memoization to explore all possible ways to fulfill the needs:
1. **Base case**: If we reach a state where no more products are needed, the cost is 0.
2. **Recursive case**: For each special offer, we check if we can apply it and then recursively calculate the cost for the remaining needs. We keep track of the minimum cost found.

In addition, we calculate the cost of buying products at the full price for the current needs and compare it with the costs obtained by applying the special offers.

### Code Breakdown (Step by Step)

Let's break down the code and understand how it works:

#### 1. **Data Structures and Initialization**
   ```cpp
   map<vector<int>, int> mp;
   ```
   - `mp` is a memoization map that stores the minimum cost for a given state of `needs`. This map helps avoid redundant calculations for the same needs.

#### 2. **Recursive Function `shoppingOffers`**
   ```cpp
   int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
       if(mp[needs]) return mp[needs];
       int best = calculate(price, needs);
   ```
   - The function `shoppingOffers` is the main entry point. It checks if the current `needs` have been computed previously using the `mp` map. If yes, it returns the stored result.
   - Otherwise, it calculates the cost of fulfilling the current `needs` without any offers using the `calculate` function and stores it in `best`.

#### 3. **Processing Special Offers**
   ```cpp
   for(auto &sp: special) {
       sub(needs, sp);
       if(noneg(needs)) {
           int woffer = sp.back() + shoppingOffers(price, special, needs);
           best = min(best, woffer);
       }
       add(needs, sp);
   }
   ```
   - The function then iterates through each special offer in `special`. For each offer, it first attempts to apply the offer by subtracting the quantities of the items in the offer from the current `needs` using the `sub` function.
   - If the result is valid (i.e., no negative needs remain), it recursively calculates the total cost of using the special offer (which is the offer's cost plus the cost of the remaining needs).
   - The `best` variable is updated to store the minimum cost encountered.

#### 4. **Calculate Full Price for Current Needs**
   ```cpp
   return mp[needs] = best;
   ```
   - After considering all possible special offers, the function stores the minimum cost found for the current `needs` in the memoization map `mp`.

#### 5. **Helper Functions**
   - **`calculate`**: This function calculates the cost of fulfilling the current `needs` without any offers.
   ```cpp
   int calculate(vector<int> &prices, vector<int> &needs) {
       int res = 0;
       for(int i = 0; i < needs.size(); i++) {
           res += (needs[i] * prices[i]);
       }
       return res;
   }
   ```
   - **`add`**: This function adds the quantities from a special offer to the `needs` vector.
   ```cpp
   void add(vector<int> &needs, vector<int> &sp) {
       for(int i = 0; i < needs.size(); i++) {
           needs[i] += sp[i];
       }
   }
   ```
   - **`sub`**: This function subtracts the quantities from a special offer from the `needs` vector.
   ```cpp
   void sub(vector<int> &needs, vector<int> &sp) {
       for(int i = 0; i < needs.size(); i++) {
           needs[i] -= sp[i];
       }
   }
   ```
   - **`noneg`**: This function checks if any of the values in the `needs` vector are negative. If any value is negative, it means the offer cannot be applied, so the function returns false.
   ```cpp
   bool noneg(vector<int> &needs) {
       for(int i = 0; i < needs.size(); i++) {
           if(needs[i] < 0) return false;
       }
       return true;
   }
   ```

### Complexity

#### Time Complexity:
- **O(n * m * k)**, where:
  - `n` is the number of products (size of `needs` and `price`),
  - `m` is the number of special offers (size of `special`),
  - `k` is the size of the state vector (size of `needs`).
  
  The algorithm explores all possible ways to fulfill the `needs` recursively, while memoizing the results to avoid redundant calculations.

#### Space Complexity:
- **O(n * k)**, where:
  - `n` is the number of products,
  - `k` is the size of the state vector (size of `needs`).

  The space complexity is determined by the memoization map `mp`, which stores the minimum cost for each unique state of `needs`.

### Conclusion

This solution efficiently calculates the minimum cost to fulfill the shopping needs using dynamic programming and memoization. By recursively exploring all combinations of full price and special offers, we ensure that the minimum cost is obtained. The use of helper functions like `sub`, `add`, and `noneg` ensures that the state transitions (i.e., applying and removing special offers) are correctly handled. This approach allows the solution to scale well even with a large number of products and special offers.

[`Link to LeetCode Lab`](https://leetcode.com/problems/shopping-offers/description/)

---
{{< youtube t6atP4Yv7_4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
