
+++
authors = ["grid47"]
title = "Leetcode 2212: Maximum Points in an Archery Competition"
date = "2024-03-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2212: Maximum Points in an Archery Competition in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Backtracking","Bit Manipulation","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "nnwNXfYz2mo"
youtube_upload_date="2022-03-20"
youtube_thumbnail="https://i.ytimg.com/vi/nnwNXfYz2mo/maxresdefault.jpg"
comments = true
+++



---
Alice and Bob are opponents in an archery competition. Alice first shoots numArrows arrows, followed by Bob, in the target scoring sections from 0 to 11. The goal is to maximize Bob's total score, ensuring that the sum of arrows shot by Bob equals numArrows.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given the total number of arrows Bob can shoot and an array representing the arrows shot by Alice in each section of the target. Bob's goal is to maximize his score while shooting exactly numArrows arrows.
- **Example:** `numArrows = 6, aliceArrows = [2, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0]`
- **Constraints:**
	- 1 <= numArrows <= 100000
	- aliceArrows.length == bobArrows.length == 12
	- 0 <= aliceArrows[i], bobArrows[i] <= numArrows
	- sum(aliceArrows[i]) == numArrows

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array of length 12 representing the number of arrows Bob shoots in each scoring section. The sum of the values in this array must equal numArrows.
- **Example:** `[0, 1, 0, 0, 1, 1, 1, 0, 2, 0, 0, 0]`
- **Constraints:**
	- The array must have exactly 12 elements.

{{< dots >}}
### Core Logic 🔍
**Goal:** Maximize Bob's score by strategically choosing the number of arrows to shoot in each section.

- Iterate through all sections and decide where Bob can shoot more arrows than Alice.
- Calculate the total score for Bob based on these decisions and ensure Bob shoots exactly numArrows arrows.
{{< dots >}}
### Problem Assumptions ✅
- Alice's arrow distribution is fixed.
- Bob can shoot any number of arrows, provided it sums to numArrows.
{{< dots >}}
## Examples 🧩
- **Input:** `numArrows = 6, aliceArrows = [2, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0]`  \
  **Explanation:** In this example, Alice shoots arrows in certain sections. Bob needs to shoot arrows in other sections where he can score points, ensuring his total shots equal numArrows.

{{< dots >}}
## Approach 🚀
The approach involves selecting sections where Bob can score maximum points and decide the number of arrows to shoot to achieve this.

### Initial Thoughts 💭
- Alice's arrows are fixed, so we can only adjust Bob's arrows in response.
- Bob needs to maximize the sections where he can take points.
- This problem involves a dynamic approach where we need to explore how Bob can beat Alice's arrows in each section while managing his total arrows.
{{< dots >}}
### Edge Cases 🌐
- Handle edge cases where no arrows are shot.
- Ensure the solution works for large values of numArrows.
- Consider edge cases like Alice shooting all arrows in one section.
- Optimize for large inputs to avoid time-limit exceed errors.
{{< dots >}}
## Code 💻
```cpp
vector<int> bob, alice;
int n;
int mask;
int ans;

void dp(int idx, int rm, int pts, int msk) {
    // cout << idx << " " << rm << " " << pts << "\n";
    if((rm <= 0) || (idx == n)){
        if(ans < pts) {
            ans = pts;
            mask = msk;
        }
        return;
    }        
    dp(idx + 1, rm, pts, msk);        
    if(rm > alice[idx]) {
        msk |= (1 << idx);
        dp(idx + 1, rm - alice[idx] - 1, pts + idx, msk);            
    }
}

vector<int> maximumBobPoints(int net, vector<int>& alice) {
    n = alice.size();
    this->alice = alice;
    bob.resize(n, 0);
    int idx = 0;
    int pts = 0;
    mask = 0;
    ans = 0;
    dp(idx, net, pts, 0);
    
    for(int i = n - 1; i >= 0; i--) {
        if((mask >> i) & 1) {
            bob[i] = alice[i] + 1;
            net -= bob[i];
        }
    }
    
    if(net > 0) bob[0] += net;
    
    return bob;
}
```

This is the complete solution code to the problem, including the helper function dp that calculates the optimal points and the maximumBobPoints function which returns the optimal configuration for Bob's points.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	vector<int> bob, alice;
	```
	These are two vectors: 'bob' holds the points for Bob, and 'alice' holds the points for Alice.

2. **Variable Initialization**
	```cpp
	int n;
	```
	This integer variable 'n' stores the size of the 'alice' vector, which determines the number of rounds or problems.

3. **Variable Initialization**
	```cpp
	int mask;
	```
	The 'mask' integer holds a bitmask representing which problems Bob decides to attempt.

4. **Variable Initialization**
	```cpp
	int ans;
	```
	This integer variable stores the maximum points Bob can achieve.

5. **Helper Function Declaration**
	```cpp
	
	```
	This section sets up the helper function for dynamic programming (dp) to calculate the optimal points for Bob.

6. **Helper Function Implementation**
	```cpp
	void dp(int idx, int rm, int pts, int msk) {
	```
	The 'dp' function is a recursive function that explores all the possibilities for Bob's points based on the current problem index, remaining rounds, and the current points and bitmask.

7. **Conditional Check**
	```cpp
	    if((rm <= 0) || (idx == n)){
	```
	This checks if the remaining rounds are exhausted or if all problems have been considered.

8. **Conditional Block**
	```cpp
	        if(ans < pts) {
	```
	If the current points exceed the maximum points found so far, update the answer.

9. **Assignment**
	```cpp
	            ans = pts;
	```
	Assign the current points to 'ans' if they represent the new maximum.

10. **Assignment**
	```cpp
	            mask = msk;
	```
	Update the bitmask with the current bitmask (msk) if this configuration yields more points.

11. **Return Statement**
	```cpp
	        return;
	```
	Exit the current recursive call if the condition above is met.

12. **Condition Check**
	```cpp
	    dp(idx + 1, rm, pts, msk);        
	```
	Continue to the next problem without assigning it to Bob.

13. **Conditional Check**
	```cpp
	    if(rm > alice[idx]) {
	```
	Check if Bob has enough remaining rounds to attempt the current problem.

14. **Bitmask Manipulation**
	```cpp
	        msk |= (1 << idx);
	```
	Set the corresponding bit in the bitmask to represent that Bob attempts the current problem.

15. **Recursive Call**
	```cpp
	        dp(idx + 1, rm - alice[idx] - 1, pts + idx, msk);            
	```
	Recursive call to consider the next problem, updating remaining rounds and points.

16. **Main Function Definition**
	```cpp
	vector<int> maximumBobPoints(int net, vector<int>& alice) {
	```
	This function calculates Bob's maximum points given the total remaining points (net) and Alice's points for each problem.

17. **Variable Assignment**
	```cpp
	    n = alice.size();
	```
	Assign the size of Alice's vector to 'n'.

18. **Variable Assignment**
	```cpp
	    this->alice = alice;
	```
	Assign the passed-in 'alice' vector to the instance variable.

19. **Vector Initialization**
	```cpp
	    bob.resize(n, 0);
	```
	Resize the 'bob' vector to match the size of Alice's vector and initialize all elements to 0.

20. **Variable Initialization**
	```cpp
	    int idx = 0;
	```
	Initialize the index variable 'idx' to 0.

21. **Variable Initialization**
	```cpp
	    int pts = 0;
	```
	Initialize the points variable 'pts' to 0.

22. **Variable Initialization**
	```cpp
	    mask = 0;
	```
	Initialize the bitmask variable 'mask' to 0.

23. **Variable Initialization**
	```cpp
	    ans = 0;
	```
	Initialize the answer variable 'ans' to 0.

24. **Function Call**
	```cpp
	    dp(idx, net, pts, 0);
	```
	Call the dynamic programming function to compute the maximum points and the optimal configuration for Bob.

25. **Loop**
	```cpp
	    for(int i = n - 1; i >= 0; i--) {
	```
	Loop through the problems in reverse order to assign the optimal values to the 'bob' vector.

26. **Condition Check**
	```cpp
	        if((mask >> i) & 1) {
	```
	Check if the current bit in the bitmask indicates that Bob attempts this problem.

27. **Assignment**
	```cpp
	            bob[i] = alice[i] + 1;
	```
	Assign the optimal points for Bob on this problem based on the bitmask.

28. **Variable Update**
	```cpp
	            net -= bob[i];
	```
	Update the remaining points after Bob takes this problem.

29. **Condition Check**
	```cpp
	    if(net > 0) bob[0] += net;
	```
	If there are remaining points, assign them to Bob's first problem.

30. **Return Statement**
	```cpp
	    return bob;
	```
	Return the final 'bob' vector with the optimal points for each problem.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(numArrows)
- **Average Case:** O(numArrows)
- **Worst Case:** O(numArrows)

The time complexity depends on how we process each section and the number of arrows Bob needs to shoot.

### Space Complexity 💾
- **Best Case:** O(12)
- **Worst Case:** O(12)

The space complexity is constant since we are only working with a fixed number of sections (12).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-points-in-an-archery-competition/description/)

---
{{< youtube nnwNXfYz2mo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
