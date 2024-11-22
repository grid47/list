
+++
authors = ["grid47"]
title = "Leetcode 822: Card Flipping Game"
date = "2024-08-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 822: Card Flipping Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/822.webp"
youtube = "K-g8sOWW4F0"
youtube_upload_date="2024-01-24"
youtube_thumbnail="https://i.ytimg.com/vi/K-g8sOWW4F0/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/822.webp" 
    alt="A set of cards being flipped, with the correct card glowing softly as it's flipped over."
    caption="Solution to LeetCode 822: Card Flipping Game Problem"
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
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> same;
        for(int i = 0; i < fronts.size(); i++) if(fronts[i] == backs[i]) same.insert(fronts[i]);
        int res = 3000;
        for(auto &num: fronts) if(!same.count(num)) res = min(res, num);
        for(auto &num: backs)  if(!same.count(num)) res = min(res, num);        
        return res % 3000;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem is to determine the smallest number that can appear on a card after flipping any card, given two lists of integers, `fronts` and `backs`. Each card has a front and a back side, with the values in `fronts` and `backs` representing the numbers on each side of the cards. The task is to flip the cards in such a way that the smallest possible number that is not on both sides of the same card appears. If no such number exists (i.e., all the numbers appear on both the front and back of at least one card), return `0`.

### Approach

To solve the problem efficiently, the following approach is used:

1. **Identify Matching Numbers**:
   - We start by identifying all the numbers that appear on both the front and back of the same card. These numbers are redundant in terms of flipping because flipping such a card does not change its outcome.
   - These redundant numbers are stored in an unordered set called `same`.

2. **Find the Smallest Number Not in `same`**:
   - Next, we iterate through both the `fronts` and `backs` lists to find the smallest number that is not in the `same` set. This is done by checking if a number exists in `same`. If it doesn't, the number is a valid candidate for the result.

3. **Return the Result**:
   - The final result is the smallest such number. If no valid number is found, it means that all numbers appear on both sides of at least one card, and we return `0`.

### Code Breakdown (Step by Step)

1. **Identify Matching Numbers**:
   ```cpp
   unordered_set<int> same;
   for(int i = 0; i < fronts.size(); i++) 
       if(fronts[i] == backs[i]) 
           same.insert(fronts[i]);
   ```
   - This block initializes an unordered set `same` that will store all the numbers that appear on both the front and back of the same card. 
   - The `for` loop iterates through each index `i` of the `fronts` and `backs` lists. If the number at `fronts[i]` is equal to the number at `backs[i]`, it means that card has the same number on both sides. This number is then inserted into the `same` set.

2. **Initialize the Result**:
   ```cpp
   int res = 3000;
   ```
   - This line initializes `res` to a large value (3000 in this case, which is guaranteed to be larger than any number on the cards) to represent the smallest possible result. It will be updated as we find smaller valid numbers.

3. **Find the Smallest Valid Number on the Fronts**:
   ```cpp
   for(auto &num: fronts) 
       if(!same.count(num)) 
           res = min(res, num);
   ```
   - The first `for` loop iterates over each number in the `fronts` list. For each number, it checks if it is **not** in the `same` set. If the number is not in `same`, it is a valid candidate for the smallest number that can be shown on the card after flipping.
   - The result `res` is updated to be the minimum of `res` and the current number `num`, ensuring that `res` holds the smallest valid number found so far.

4. **Find the Smallest Valid Number on the Backs**:
   ```cpp
   for(auto &num: backs)  
       if(!same.count(num)) 
           res = min(res, num);
   ```
   - The second `for` loop does the same for the `backs` list. It checks each number in `backs` and updates `res` if the number is not found in `same`.

5. **Return the Result**:
   ```cpp
   return res % 3000;
   ```
   - The result `res` is returned after taking it modulo 3000. This step ensures that if no valid number was found (i.e., `res` remains 3000), the function will return 0, indicating that no valid number can be flipped to appear.

### Complexity

- **Time Complexity**: 
  - The time complexity of this solution is O(n), where `n` is the number of cards. 
  - The main time-consuming operations are iterating through the `fronts` and `backs` lists, which takes O(n) time. The insertion and lookup operations in the unordered set `same` take O(1) on average, so the overall complexity remains O(n).
  
- **Space Complexity**: 
  - The space complexity is O(n), where `n` is the number of cards. This is because we use an unordered set to store at most `n` elements (the numbers that appear on both sides of the same card).

### Conclusion

This solution efficiently solves the problem by using an unordered set to store redundant numbers that appear on both sides of the same card. By identifying and excluding these redundant numbers, the algorithm calculates the smallest number that can appear on the cards after flipping. The approach works in O(n) time and O(n) space, making it well-suited for handling large inputs efficiently. This method ensures that the smallest valid number is selected while minimizing unnecessary computations.

[`Link to LeetCode Lab`](https://leetcode.com/problems/card-flipping-game/description/)

---
{{< youtube K-g8sOWW4F0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
