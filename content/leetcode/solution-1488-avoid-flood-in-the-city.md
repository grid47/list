
+++
authors = ["grid47"]
title = "Leetcode 1488: Avoid Flood in The City"
date = "2024-06-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1488: Avoid Flood in The City in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Greedy","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "EcvhHoFaDoU"
youtube_upload_date="2020-06-21"
youtube_thumbnail="https://i.ytimg.com/vi/EcvhHoFaDoU/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        
        set<int> dry;
        unordered_map<int, int> mp;
        
        int n = rains.size();
        
        vector<int> ans;
        
        for(int i = 0; i < n; i++) {
            if(rains[i] == 0) {
                dry.insert(i);
                ans.push_back(1);
            } else {
                int lake = rains[i];
                
                if(mp.count(lake)) {
                    
                    auto it = dry.lower_bound(mp[lake]);
                    if(it == dry.end()) return {};
                    
                    ans[*it] = lake;
                    dry.erase(*it);
                }
                mp[lake] = i;
                ans.push_back(-1);
            }
        }

        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand is to determine the behavior of lakes in a given sequence of rainfalls, represented by an array `rains`. Each index of the array represents a day, and the value indicates the lake that receives rain on that day. If the value is `0`, it means no rain falls on that day, and the ground can be dry. The objective is to avoid flooding in the lakes by strategically choosing which dry days to use for draining the lakes when they overflow. The solution must return an array where each element corresponds to a day in `rains`, with the following meanings:
- If it rains on a lake, the output is `-1`.
- If it's a dry day that is used to drain a lake, the output is the lake's identifier.
- If a lake overflows and there are no dry days available to drain it, the output should be an empty array indicating the impossibility of avoiding flooding.

### Approach

To solve this problem, we need to maintain a record of the lakes and their corresponding rain days, as well as a set of dry days available for draining. Here’s a step-by-step breakdown of the approach:

1. **Data Structures**: Utilize a set to keep track of dry days and an unordered map to record the last rainy day for each lake.

2. **Iterate Through Rains**: Loop through the `rains` array. For each day:
   - If it rains (`rains[i] != 0`), check if the corresponding lake has rained before.
   - If it has rained before, find the nearest available dry day after the last rainy day for that lake.
   - If such a dry day exists, drain the lake on that day.
   - If it is a dry day (`rains[i] == 0`), add it to the set of dry days.

3. **Fill the Answer Array**: Create an answer array to store the results for each day as described above.

4. **Return Result**: Finally, return the constructed answer array.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        
        set<int> dry;  // Set to store indices of dry days
        unordered_map<int, int> mp;  // Map to track the last rainy day for each lake
        
        int n = rains.size();  // Size of the input array
        
        vector<int> ans;  // Result array to be returned
        
        for(int i = 0; i < n; i++) {
            if(rains[i] == 0) {  // If it's a dry day
                dry.insert(i);  // Add the index to the dry set
                ans.push_back(1);  // Mark it as a dry day in the answer
            } else {
                int lake = rains[i];  // Identify the lake that is receiving rain
                
                if(mp.count(lake)) {  // If this lake has rained before
                    auto it = dry.lower_bound(mp[lake]);  // Find the next available dry day
                    
                    if(it == dry.end()) return {};  // If no dry day is available, return empty array
                    
                    ans[*it] = lake;  // Drain the lake on the dry day found
                    dry.erase(*it);  // Remove that day from the dry set
                }
                mp[lake] = i;  // Update the last rainy day for this lake
                ans.push_back(-1);  // Mark the day as a rainy day in the answer
            }
        }

        return ans;  // Return the final answer
    }
};
```

1. **Set Initialization**: A `set<int> dry` is used to track indices of dry days, allowing for efficient insertion and lookups.

2. **Map Initialization**: An `unordered_map<int, int> mp` keeps the last day when it rained for each lake, allowing for quick access.

3. **Loop Through the Input**: The main loop iterates through the `rains` array, checking each day's weather conditions.

4. **Handling Dry Days**: When encountering a dry day, the index is added to the `dry` set and `1` is appended to the result array.

5. **Handling Rainy Days**:
   - If it rains on a lake that has rained before, the code checks for a dry day to drain it.
   - Using `lower_bound`, it finds the smallest index in the dry set that is greater than or equal to the last rainy day of the lake.
   - If a suitable dry day is found, the lake is drained on that day by updating the result array and removing that index from the dry set.

6. **Returning the Result**: The function returns the result array, which contains the operations performed on each day.

### Complexity

- **Time Complexity**: The time complexity of this solution is \(O(n \log n)\), where \(n\) is the length of the `rains` array. This is due to the logarithmic time complexity for operations on the set (insertion, deletion, and finding the lower bound).

- **Space Complexity**: The space complexity is \(O(n)\), as we maintain a set for dry days and a map for the last rainy days, which can grow up to the size of the input.

### Conclusion

The `avoidFlood` function efficiently determines how to manage lake flooding based on a given sequence of rainfall events. It adeptly utilizes a combination of a set and a hash map to track dry days and rainy occurrences, ensuring optimal performance even with large inputs.

Key highlights include:

1. **Effective Use of Data Structures**: The solution employs `set` and `unordered_map` to facilitate quick lookups and updates, enhancing performance.

2. **Logical Flow**: The step-by-step approach logically handles different scenarios (rainy and dry days) in a clear manner.

3. **Real-world Applications**: This solution is applicable in scenarios involving resource management, such as water reservoir systems, where the optimal handling of resources is critical.

Overall, this solution effectively addresses the problem while demonstrating good coding practices and efficient algorithms, making it a robust and scalable implementation for managing lake flooding during rain events.

[`Link to LeetCode Lab`](https://leetcode.com/problems/avoid-flood-in-the-city/description/)

---
{{< youtube EcvhHoFaDoU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
