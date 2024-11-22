
+++
authors = ["grid47"]
title = "Leetcode 2105: Watering Plants II"
date = "2024-04-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2105: Watering Plants II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumRefill(vector<int>& plant, int capA, int capB) {
        int n = plant.size();
        int i = 0, j = n - 1;
        int cnt = 0;
        
        int alice = capA, bob = capB;
        
        while(i <= j) {
            if(i < j) {
                if(alice >= plant[i]) {
                    alice -= plant[i];
                } else {
                    cnt++;
                    alice = capA;
                    alice -= plant[i];
                }
                i++;
                
                if(bob >= plant[j]) {
                    bob -= plant[j];
                } else {
                    cnt++;
                    bob = capB;
                    bob -= plant[j];
                }
                j--;
            } else {
                if(alice >= bob) {
                    if(alice >= plant[i]) {
                        alice -= plant[i];
                    } else {
                        cnt++;
                        alice = capA;
                        alice -= plant[i];                        
                    }
                } else {
                    if(bob >= plant[i]) {
                        bob -= plant[i];
                    } else {
                        cnt++;
                        bob = capB;
                        bob -= plant[i];                        
                    }                    
                }
                i++, j--;
            }
        }
        return cnt;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires finding the minimum number of refills needed for two people, Alice and Bob, to water plants in a garden. Alice starts from the left side and Bob from the right. Each plant requires a specific amount of water to be watered. Alice and Bob have separate water capacities (`capA` and `capB`), and they refill only when they run out of water for a plant. We need to determine the total number of refills needed for both Alice and Bob to water every plant in the garden.

### Approach

The solution uses a two-pointer technique. Alice begins watering plants from the left (index `i = 0`), while Bob starts from the right (index `j = n - 1`). For each plant:

1. **Determine if Alice or Bob Needs a Refill**: If the water capacity each has is enough to water the current plant, they proceed without a refill; otherwise, they refill and reset their respective capacities.

2. **Move Pointers Inward**: After each plant is watered, Alice moves one plant to the right (increment `i`), and Bob moves one plant to the left (decrement `j`). If Alice and Bob reach the same plant, the one with more remaining water will water it. If they have the same amount, Alice waters it.

3. **Count Refills**: Each time either Alice or Bob refills, the refill counter (`cnt`) increments by 1.

### Code Breakdown (Step by Step)

1. **Initialize Variables**:
   ```cpp
   int n = plant.size();
   int i = 0, j = n - 1;
   int cnt = 0;
   int alice = capA, bob = capB;
   ```
   - `n`: Number of plants.
   - `i` and `j`: Pointers for Alice and Bob, starting from the beginning and end, respectively.
   - `cnt`: Counter for the number of refills.
   - `alice` and `bob`: Current capacities for Alice and Bob.

2. **Main Loop**:
   ```cpp
   while(i <= j) {
   ```
   - Loop continues as long as Alice (`i`) and Bob (`j`) have plants to water.
   - The `if` statement inside handles cases where `i < j` (when Alice and Bob have separate plants to water), and an `else` block addresses the case where they meet at the same plant.

3. **Alice and Bob Water Plants**:
   ```cpp
   if(i < j) {
       if(alice >= plant[i]) { alice -= plant[i]; }
       else { cnt++; alice = capA - plant[i]; }
       i++;
       
       if(bob >= plant[j]) { bob -= plant[j]; }
       else { cnt++; bob = capB - plant[j]; }
       j--;
   }
   ```
   - If Alice or Bob’s remaining water is enough to water the plant, they proceed. If not, they refill, increase `cnt`, and continue.

4. **Handle Meeting Point**:
   ```cpp
   else {
       if(alice >= bob) {
           if(alice >= plant[i]) { alice -= plant[i]; }
           else { cnt++; alice = capA - plant[i]; }
       } else {
           if(bob >= plant[i]) { bob -= plant[i]; }
           else { cnt++; bob = capB - plant[i]; }
       }
       i++, j--;
   }
   ```
   - When Alice and Bob meet at the same plant, the one with the larger remaining water capacity will water it.

5. **Return Total Refills**:
   ```cpp
   return cnt;
   ```
   - Once all plants are watered, the function returns the total number of refills.

### Complexity Analysis

- **Time Complexity**: \(O(n)\)
  - The algorithm iterates through each plant at most once, with two pointers moving inward. Thus, it operates in linear time relative to the number of plants, `n`.
  
- **Space Complexity**: \(O(1)\)
  - The algorithm uses a constant amount of additional space, only storing a few variables like `cnt`, `alice`, and `bob`.

### Conclusion

This solution effectively manages Alice and Bob’s capacities while traversing from opposite ends of the plant array, ensuring they only refill when necessary. By tracking the number of refills each needs and controlling who waters the plant when they meet, the algorithm ensures an optimal solution. The two-pointer approach is efficient, with linear time complexity, and minimizes unnecessary refills for a well-optimized, clear solution. This makes the code highly effective for large arrays, ensuring minimum refills and avoiding extra calculations.

[`Link to LeetCode Lab`](https://leetcode.com/problems/watering-plants-ii/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
