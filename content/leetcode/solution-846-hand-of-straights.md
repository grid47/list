
+++
authors = ["grid47"]
title = "Leetcode 846: Hand of Straights"
date = "2024-08-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 846: Hand of Straights in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "amnrMCVd2YI"
youtube_upload_date="2021-05-21"
youtube_thumbnail="https://i.ytimg.com/vi/amnrMCVd2YI/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> mp;
        for(int x: hand) mp[x]++;
        
        for(auto it: mp) {
            if(mp[it.first] > 0)
            for(int i = 1; i < groupSize; i++){
                mp[it.first + i] -= mp[it.first];
                if(mp[it.first + i] < 0)
                    return false;
            }
            mp[it.first] = 0;
        }
        return true;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand requires us to determine if a given hand of cards can be divided into groups of a specified size, where each group is a consecutive sequence of cards. The cards are represented by integers, and the task is to verify if the hand can be partitioned into groups of consecutive integers of the given size, without any leftovers.

### Example:
- **Input**: `hand = [1,2,3,6,2,3,4,7,8]`, `groupSize = 3`
- **Output**: `True`
- **Explanation**: The cards can be divided into the following groups: `[1,2,3]`, `[2,3,4]`, and `[6,7,8]`.

- **Input**: `hand = [1,2,3,4,5]`, `groupSize = 4`
- **Output**: `False`
- **Explanation**: It is impossible to divide the cards into groups of size 4.

The problem ensures that the cards in the hand can be used to form multiple consecutive groups, where each group must consist of exactly `groupSize` consecutive numbers.

### Approach

To solve this problem, we can use a **greedy algorithm** that iteratively checks if it is possible to form a group starting from the smallest available card. The steps for the solution are as follows:

1. **Frequency Counting**: The first step is to count the frequency of each card in the hand using a **map** (or hash map). This helps us quickly access the number of available cards of each value.

2. **Forming Consecutive Groups**: 
   - Starting with the smallest card, we attempt to form a consecutive sequence of length `groupSize`. This involves checking if there are enough cards to form a complete group.
   - If a group can be formed, we decrement the frequency of those cards and move on to the next group.
   - If at any point we cannot form a group of size `groupSize`, we return `false`.

3. **Edge Case Handling**: If at any point the group formation fails (i.e., a card is needed to form a consecutive sequence but is not available), the function should immediately return `false`.

4. **Return Result**: If all groups can be formed, return `true`.

The algorithm operates greedily by always trying to use the smallest available card to start a sequence, ensuring that the number of groups formed is maximized with the smallest values first.

### Code Breakdown (Step by Step)

#### Step 1: Count the Frequency of Each Card
The first operation in the code is to create a map that counts how many times each card appears in the hand.

```cpp
map<int, int> mp;
for(int x: hand) mp[x]++;
```

This map will allow us to efficiently check how many times each card appears, so we can decide whether we can form a valid group starting from a particular card.

#### Step 2: Iterate Over the Map to Form Groups
After counting the frequency of each card, we iterate over the keys in the map (the card values). The algorithm works by starting with the smallest available card and attempting to create a sequence of consecutive cards. For each card, it checks if there are enough cards to form a complete group of size `groupSize`.

```cpp
for(auto it: mp) {
    if(mp[it.first] > 0) // Only process cards that still have remaining frequency
    for(int i = 1; i < groupSize; i++) {
        mp[it.first + i] -= mp[it.first];
        if(mp[it.first + i] < 0)
            return false;
    }
    mp[it.first] = 0; // Mark this card as fully used
}
```

- `mp[it.first] > 0`: We check if the current card (i.e., `it.first`) is still available to be used in a group.
- We then attempt to form a group by checking the next `groupSize - 1` consecutive cards (`it.first + 1`, `it.first + 2`, ..., `it.first + groupSize - 1`).
- For each of these cards, we decrement their count in the map (`mp[it.first + i] -= mp[it.first]`).
- If at any point we find that a card cannot be used (i.e., `mp[it.first + i] < 0`), we immediately return `false`.
- Finally, after using the current card to form a group, we set its frequency to zero (`mp[it.first] = 0`), indicating it has been used up.

#### Step 3: Return the Result
If the function has not returned `false` during the loop, then all cards have been successfully used to form consecutive groups. Therefore, the function returns `true` to indicate that the hand can be divided into valid groups.

```cpp
return true;
```

### Complexity

#### Time Complexity:
- The time complexity of this solution is **O(n log n)**, where `n` is the number of cards in the hand. This complexity arises from:
  - Building the map, which takes O(n) time.
  - Iterating through the map, where the map keys (card values) are sorted in ascending order. Thus, each operation involves iterating over the map and performing constant time updates, leading to a total time complexity of O(n log n) due to the sorting step inherent in the map's implementation.

#### Space Complexity:
- The space complexity of this solution is **O(n)**, as we use a map to store the frequency of each card in the hand. The size of the map will be proportional to the number of unique cards in the hand.

### Conclusion

This solution is an efficient way to determine if a hand of cards can be split into consecutive groups of a specified size. By leveraging a map to count the frequency of each card, and then applying a greedy approach to form groups starting from the smallest card, we can solve the problem in `O(n log n)` time and `O(n)` space. This approach ensures that we can handle large input sizes effectively, making it a suitable solution for this problem.

The algorithm is easy to understand and implements a clear strategy for forming consecutive sequences of cards. By utilizing the properties of maps (sorted keys and efficient lookups), it ensures that the process of checking for valid groups is optimized.

[`Link to LeetCode Lab`](https://leetcode.com/problems/hand-of-straights/description/)

---
{{< youtube amnrMCVd2YI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
