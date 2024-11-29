
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
comments = true
+++



---
Alice and Bob are tasked with watering a garden of n plants. The plants are arranged in a row and need varying amounts of water. Alice waters the plants from left to right, while Bob waters them from right to left. They both begin with full watering cans. If they don’t have enough water for the next plant, they refill their cans. In case they both reach the same plant, the one with more water in their can should water the plant, or Alice waters it in case of a tie. The goal is to determine how many times Alice and Bob have to refill their cans to water all the plants.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a 0-indexed integer array, plants, where each element represents the amount of water a corresponding plant needs. Additionally, two integers, capacityA and capacityB, represent the capacities of Alice’s and Bob’s watering cans, respectively.
- **Example:** `plants = [3, 2, 5, 4], capacityA = 6, capacityB = 6`
- **Constraints:**
	- 1 <= plants.length <= 10^5
	- 1 <= plants[i] <= 10^6
	- max(plants[i]) <= capacityA, capacityB <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of times Alice and Bob need to refill their watering cans in order to water all the plants.
- **Example:** `For plants = [3, 2, 5, 4], capacityA = 6, capacityB = 6, the output is 2.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to efficiently compute the number of refills required by simulating the watering process while tracking the remaining water in Alice's and Bob's cans.

- Initialize two pointers, one for Alice starting from the left (i = 0) and one for Bob starting from the right (j = n - 1).
- Initialize counters for Alice's and Bob's current water levels (alice, bob) with the respective capacities.
- Simulate the process of watering plants for both Alice and Bob, adjusting the number of refills as needed.
- If either Alice or Bob runs out of water for their current plant, they refill their can and continue watering.
{{< dots >}}
### Problem Assumptions ✅
- Alice and Bob always start with full watering cans.
- Alice waters the plants from left to right, and Bob waters the plants from right to left.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: plants = [3, 2, 5, 4], capacityA = 6, capacityB = 6`  \
  **Explanation:** Initially, both Alice and Bob have 6 units of water. Alice waters plant 0 (3 units), leaving 3 units in her can. Bob waters plant 3 (4 units), leaving 2 units in his can. Alice then waters plant 1 (2 units), leaving 1 unit in her can, and Bob refills and waters plant 2 (5 units), leaving 1 unit in his can. Total refills = 2.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to simulate the watering process for both Alice and Bob. We keep track of their current water levels and count how many times they need to refill during the process.

### Initial Thoughts 💭
- We need to simulate a simultaneous watering process for both Alice and Bob, which means tracking their water usage at the same time.
- Refills are required when either Alice or Bob doesn't have enough water to water the next plant.
- Efficiently handling the watering process and counting refills is key to solving this problem in optimal time.
{{< dots >}}
### Edge Cases 🌐
- If there are no plants (empty list), no watering is needed and thus no refills.
- For very large input sizes, ensuring the algorithm is efficient enough to handle up to 10^5 plants is crucial.
- If all plants require less water than the capacities of Alice and Bob, no refills are needed.
- The solution should operate within O(n) time complexity to handle the upper constraint of 10^5 plants.
{{< dots >}}
## Code 💻
```cpp
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
```

This code implements a solution to the problem where Alice and Bob are refilling plants, and the goal is to determine the minimum number of refills they need based on their tank capacities and the water needs of each plant. The code uses a two-pointer technique, where one pointer starts at the beginning and the other at the end of the plant list.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int minimumRefill(vector<int>& plant, int capA, int capB) {
	```
	Define the function minimumRefill that accepts the plant water requirements and the tank capacities of Alice and Bob.

2. **Variable Initialization**
	```cpp
	    int n = plant.size();
	```
	Get the size of the plant array (number of plants).

3. **Variable Initialization**
	```cpp
	    int i = 0, j = n - 1;
	```
	Initialize two pointers, i and j, to represent Alice and Bob's positions in the plant array. i starts at the beginning, and j starts at the end.

4. **Variable Initialization**
	```cpp
	    int cnt = 0;
	```
	Initialize a counter to track the number of refills.

5. **Variable Initialization**
	```cpp
	    int alice = capA, bob = capB;
	```
	Set the initial water levels for Alice and Bob to their respective tank capacities.

6. **Control Flow**
	```cpp
	    while(i <= j) {
	```
	Start a while loop to iterate while i and j are within bounds, representing that Alice and Bob have plants to water.

7. **Control Flow**
	```cpp
	        if(i < j) {
	```
	Check if there are plants to be watered by both Alice and Bob.

8. **Condition Check**
	```cpp
	            if(alice >= plant[i]) {
	```
	Check if Alice has enough water to water the plant at index i.

9. **Variable Modification**
	```cpp
	                alice -= plant[i];
	```
	Subtract the amount of water Alice uses to water the plant.

10. **Condition Check**
	```cpp
	            } else {
	```
	If Alice doesn't have enough water, refill the tank.

11. **Variable Modification**
	```cpp
	                cnt++;
	```
	Increment the refill counter since Alice needs to refill her tank.

12. **Variable Assignment**
	```cpp
	                alice = capA;
	```
	Refill Alice's tank to its full capacity.

13. **Variable Modification**
	```cpp
	                alice -= plant[i];
	```
	After refilling, subtract the water Alice uses for the plant.

14. **Variable Modification**
	```cpp
	            i++;
	```
	Move Alice's pointer forward to the next plant.

15. **Condition Check**
	```cpp
	            if(bob >= plant[j]) {
	```
	Check if Bob has enough water to water the plant at index j.

16. **Variable Modification**
	```cpp
	                bob -= plant[j];
	```
	Subtract the amount of water Bob uses to water the plant.

17. **Condition Check**
	```cpp
	            } else {
	```
	If Bob doesn't have enough water, refill his tank.

18. **Variable Modification**
	```cpp
	                cnt++;
	```
	Increment the refill counter since Bob needs to refill his tank.

19. **Variable Assignment**
	```cpp
	                bob = capB;
	```
	Refill Bob's tank to its full capacity.

20. **Variable Modification**
	```cpp
	                bob -= plant[j];
	```
	After refilling, subtract the water Bob uses for the plant.

21. **Variable Modification**
	```cpp
	            j--;
	```
	Move Bob's pointer backward to the next plant.

22. **Control Flow**
	```cpp
	        } else {
	```
	Else block for when there is only one plant left for either Alice or Bob.

23. **Condition Check**
	```cpp
	            if(alice >= bob) {
	```
	Check if Alice has more water than Bob to prioritize her watering the next plant.

24. **Condition Check**
	```cpp
	                if(alice >= plant[i]) {
	```
	Check if Alice has enough water for the plant.

25. **Variable Modification**
	```cpp
	                    alice -= plant[i];
	```
	Subtract the water used by Alice for the plant.

26. **Condition Check**
	```cpp
	                } else {
	```
	If Alice doesn't have enough water, refill her tank.

27. **Variable Modification**
	```cpp
	                    cnt++;
	```
	Increment the refill counter since Alice needs to refill her tank.

28. **Variable Assignment**
	```cpp
	                    alice = capA;
	```
	Refill Alice's tank.

29. **Variable Modification**
	```cpp
	                    alice -= plant[i];
	```
	After refilling, subtract the water Alice uses for the plant.

30. **Condition Check**
	```cpp
	            } else {
	```
	If Bob has more water than Alice, Bob waters the plant.

31. **Condition Check**
	```cpp
	                if(bob >= plant[i]) {
	```
	Check if Bob has enough water for the plant.

32. **Variable Modification**
	```cpp
	                    bob -= plant[i];
	```
	Subtract the water used by Bob.

33. **Condition Check**
	```cpp
	                } else {
	```
	If Bob doesn't have enough water, refill his tank.

34. **Variable Modification**
	```cpp
	                    cnt++;
	```
	Increment the refill counter.

35. **Variable Assignment**
	```cpp
	                    bob = capB;
	```
	Refill Bob's tank.

36. **Variable Modification**
	```cpp
	                    bob -= plant[i];
	```
	After refilling, subtract the water Bob uses for the plant.

37. **Loop End**
	```cpp
	            i++, j--;
	```
	Move both pointers to the next plant.

38. **Function Return**
	```cpp
	    return cnt;
	```
	Return the number of refills made.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear because we only iterate through the list of plants once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant as we only need a few variables to track the water levels and the current plant positions.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/watering-plants-ii/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
