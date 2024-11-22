
+++
authors = ["grid47"]
title = "Leetcode 2260: Minimum Consecutive Cards to Pick Up"
date = "2024-03-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2260: Minimum Consecutive Cards to Pick Up in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "BIHnh-MH6CQ"
youtube_upload_date="2022-05-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/BIHnh-MH6CQ/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int, int> mp;
        int n = cards.size();
        int ans = n + 1;
        
        for(int i = 0; i < n; i++){
            if(mp.count(cards[i])) {
                ans = min(ans, i - mp[cards[i]] + 1);
            }
            mp[cards[i]] = i;            
        }
        
        return ans == n + 1? -1: ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

In this problem, you are given a list of cards represented by integers. Each integer represents a card, and the goal is to find the minimum number of cards between two identical cards in the list. If there are no such pairs of identical cards, the function should return `-1`.

The task is to find the minimum number of cards between any two identical cards. Specifically, the goal is to determine the smallest number of cards you must pick up, starting from one identical card and ending at the next identical card, in such a way that the total number of picked-up cards (including both ends) is minimized.

### Approach

To solve this problem, we need to identify the minimum distance between two identical cards in the list. The key to efficiently solving this problem is using a **hash map** (in this case, a `map` in C++) to store the last seen index of each card. By doing this, we can easily calculate the difference in indices between consecutive identical cards and find the minimum difference.

Here’s the general approach:
1. **Use a Map to Track Indices**: As we iterate through the list of cards, we use a `map` to track the index of each card. The key of the map is the card's value, and the value is the last index where the card was encountered.
2. **Calculate Differences**: Each time we encounter a card that we have seen before (i.e., it exists in the map), we calculate the difference in the current index and the index of the previously seen card. This gives us the number of cards between the two identical cards (including the cards themselves).
3. **Track the Minimum**: We keep track of the minimum number of cards between any two identical cards. If we find a smaller difference, we update our answer.
4. **Handle No Identical Cards**: If no pair of identical cards exists, we return `-1`.

### Code Breakdown (Step by Step)

#### Step 1: Initialize Data Structures
```cpp
map<int, int> mp;
int n = cards.size();
int ans = n + 1;
```
- We use a `map<int, int>` called `mp` to store the last seen index of each card. The key is the card value, and the value is the index where the card was last seen.
- We also initialize a variable `ans` to keep track of the minimum number of cards between two identical cards. Initially, we set `ans` to `n + 1` (where `n` is the size of the `cards` array), which represents an impossible large value (since we cannot have more than `n` cards between identical cards).

#### Step 2: Iterate Through the Cards
```cpp
for(int i = 0; i < n; i++){
    if(mp.count(cards[i])) {
        ans = min(ans, i - mp[cards[i]] + 1);
    }
    mp[cards[i]] = i;            
}
```
- We iterate through the cards using the variable `i` (which represents the current index of the card).
- For each card `cards[i]`, we check if this card has appeared before by using the `map.count()` method. If the card has appeared before (i.e., it exists in the map), it means we found a pair of identical cards.
- If we find such a pair, we calculate the number of cards between these two identical cards, which is `i - mp[cards[i]] + 1` (where `mp[cards[i]]` is the index of the last occurrence of the card). We update `ans` with the smaller of the current `ans` and this new distance.
- After processing the current card, we update the map with the current index of the card, so we can refer to it when we encounter the same card again.

#### Step 3: Return the Result
```cpp
return ans == n + 1 ? -1 : ans;
```
- After the loop, if `ans` is still equal to `n + 1`, it means we never found any pair of identical cards, so we return `-1`.
- Otherwise, we return the value of `ans`, which represents the minimum number of cards between two identical cards.

### Complexity

#### Time Complexity:
- The time complexity of this solution is **O(n)**, where `n` is the size of the `cards` array. This is because we iterate through the array once and perform constant-time operations (like map lookups and insertions) for each card.

#### Space Complexity:
- The space complexity is **O(n)**, where `n` is the size of the `cards` array. This is due to the storage required by the `map` to keep track of the indices of the cards. In the worst case, all cards are unique, so the map will contain `n` entries.

### Conclusion

This solution efficiently solves the problem of finding the minimum number of cards between two identical cards using a hash map. The approach ensures that we only need to iterate through the list once, providing an optimal time complexity of **O(n)**. Additionally, it uses extra space proportional to the size of the input array, leading to a space complexity of **O(n)**. This solution is optimal for large input sizes and handles all edge cases, such as when no identical cards exist, by returning `-1`.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/description/)

---
{{< youtube BIHnh-MH6CQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
