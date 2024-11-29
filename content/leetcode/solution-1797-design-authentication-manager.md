
+++
authors = ["grid47"]
title = "Leetcode 1797: Design Authentication Manager"
date = "2024-05-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1797: Design Authentication Manager in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Linked List","Design","Doubly-Linked List"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "IG6X2CXMdKw"
youtube_upload_date="2021-03-20"
youtube_thumbnail="https://i.ytimg.com/vi_webp/IG6X2CXMdKw/maxresdefault.webp"
comments = true
+++



---
You are tasked with creating an authentication system that handles tokens. Each token has an expiration time, and a user can generate new tokens or renew existing ones before they expire. The system should track and count the number of unexpired tokens at any given time.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a series of operations: creating new tokens, renewing tokens, and counting unexpired tokens. Each token has an expiration time determined by the timeToLive parameter provided during the initialization of the AuthenticationManager.
- **Example:** `Input: ["AuthenticationManager", "generate", "renew", "countUnexpiredTokens"]
[[5], ["aaa", 1], ["aaa", 2], [6]]`
- **Constraints:**
	- 1 <= timeToLive <= 10^8
	- 1 <= currentTime <= 10^8
	- 1 <= tokenId.length <= 5
	- tokenId consists only of lowercase letters
	- All generate calls will have unique tokenIds
	- currentTime will strictly increase with each operation

{{< dots >}}
### Output Specifications 📤
- **Output:** The output consists of the results of the operations, with generate and renew methods returning 'null' and the countUnexpiredTokens method returning the count of unexpired tokens at the given time.
- **Example:** `Output: [null, null, null, 1]`
- **Constraints:**
	- The function must be efficient enough to handle up to 2000 operations.

{{< dots >}}
### Core Logic 🔍
**Goal:** Implement a system to manage token generation, renewal, and expiration, ensuring the correct number of unexpired tokens is returned when requested.

- Initialize an authentication manager with a given timeToLive.
- For each token, store its expiration time when it is generated.
- For renewals, check if the token exists and is unexpired before extending its expiration time.
- Implement a method to count the number of unexpired tokens based on the current time.
{{< dots >}}
### Problem Assumptions ✅
- Tokens are uniquely identified by their tokenId.
- All tokens have an expiration time that is based on the current time and the timeToLive value.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: ["AuthenticationManager", "generate", "renew", "countUnexpiredTokens"]
[[5], ["aaa", 1], ["aaa", 2], [6]]`  \
  **Explanation:** The system initializes with a timeToLive of 5 seconds. A new token 'aaa' is generated at time 1. At time 6, there is one unexpired token, 'aaa', so the count is 1.

- **Input:** `Input: ["AuthenticationManager", "generate", "renew", "countUnexpiredTokens"]
[[5], ["aaa", 1], ["aaa", 2], [7]]`  \
  **Explanation:** At time 7, the token 'aaa' has expired, so there are no unexpired tokens, and the count is 0.

{{< dots >}}
## Approach 🚀
The approach to solving this problem involves using a priority queue to track token expiration times and a map to store the number of unexpired tokens.

### Initial Thoughts 💭
- We need to efficiently track and update the expiration times of each token.
- A priority queue can be used to easily manage the earliest expiration times.
- We can process tokens efficiently by using a priority queue to manage expiration times, and a map to track how many tokens are unexpired at any given time.
{{< dots >}}
### Edge Cases 🌐
- Ensure that the function handles cases where no tokens are generated.
- The solution must be able to handle up to 2000 operations efficiently.
- Handle cases where a token is requested for renewal after it has already expired.
- The system should be able to handle up to 2000 operations and must perform efficiently within the time and space constraints.
{{< dots >}}
## Code 💻
```cpp
priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
map<string, int> mp;
int ttl;
AuthenticationManager(int timeToLive) {
    ttl = timeToLive;
}

void generate(string tokenId, int currentTime) {
    while(!pq.empty() && currentTime >= pq.top().first) {
        mp[pq.top().second]--;
        if(mp[pq.top().second] == 0) mp.erase(pq.top().second);
        pq.pop();
    }
    pq.push({currentTime + ttl, tokenId});
    mp[tokenId]++;
}

void renew(string tokenId, int currentTime) {
    while(!pq.empty() && currentTime >= pq.top().first) {
        mp[pq.top().second]--;
        if(mp[pq.top().second] == 0) mp.erase(pq.top().second);
        pq.pop();
    }
    if(mp.count(tokenId)) {
        pq.push({currentTime + ttl, tokenId});            
        mp[tokenId]++;
    }
}

int countUnexpiredTokens(int currentTime) {
    while(!pq.empty() && currentTime >= pq.top().first) {
        mp[pq.top().second]--;
        if(mp[pq.top().second] == 0) mp.erase(pq.top().second);
        pq.pop();
    }
    return mp.size();
}
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
```

This implementation of the AuthenticationManager class uses a priority queue to efficiently manage the expiration of authentication tokens. It supports three main operations: generating a token, renewing an existing token, and counting the number of unexpired tokens at any given time.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
	```
	Declare a priority queue to store the expiration time of tokens along with the token ID. It uses the `greater` comparator to ensure the token with the earliest expiration time is at the top.

2. **Variable Initialization**
	```cpp
	map<string, int> mp;
	```
	Declare a map to store the count of each token, which allows checking if a token exists and managing its renewals.

3. **Constructor**
	```cpp
	int ttl;
	```
	Declare an integer variable `ttl` to store the time-to-live value for the tokens.

4. **Constructor**
	```cpp
	AuthenticationManager(int timeToLive) {
	```
	Constructor that initializes the `ttl` variable with the provided time-to-live value for tokens.

5. **Constructor**
	```cpp
	    ttl = timeToLive;
	```
	Set the time-to-live value for the AuthenticationManager.

6. **Function Definition**
	```cpp
	void generate(string tokenId, int currentTime) {
	```
	Define the `generate` function that creates a new token with a specific ID and time, adding it to the priority queue and map.

7. **Token Management**
	```cpp
	    while(!pq.empty() && currentTime >= pq.top().first) {
	```
	Start a loop to remove expired tokens from the priority queue and map based on the current time.

8. **Token Management**
	```cpp
	        mp[pq.top().second]--;
	```
	Decrement the count of the token in the map.

9. **Token Cleanup**
	```cpp
	        if(mp[pq.top().second] == 0) mp.erase(pq.top().second);
	```
	If a token's count becomes zero, remove it from the map.

10. **Token Management**
	```cpp
	        pq.pop();
	```
	Remove the expired token from the priority queue.

11. **Token Insertion**
	```cpp
	    pq.push({currentTime + ttl, tokenId});
	```
	Push the new token with its expiration time into the priority queue.

12. **Token Insertion**
	```cpp
	    mp[tokenId]++;
	```
	Increment the count of the token in the map.

13. **Function Definition**
	```cpp
	void renew(string tokenId, int currentTime) {
	```
	Define the `renew` function that renews an existing token if it is still valid.

14. **Token Renewal**
	```cpp
	    while(!pq.empty() && currentTime >= pq.top().first) {
	```
	Similar to `generate`, remove expired tokens from the priority queue and map.

15. **Token Renewal**
	```cpp
	        mp[pq.top().second]--;
	```
	Decrement the count of the token being renewed.

16. **Token Cleanup**
	```cpp
	        if(mp[pq.top().second] == 0) mp.erase(pq.top().second);
	```
	Remove expired tokens from the map if their count reaches zero.

17. **Token Management**
	```cpp
	        pq.pop();
	```
	Pop the expired token from the priority queue.

18. **Token Renewal**
	```cpp
	    if(mp.count(tokenId)) {
	```
	Check if the token exists in the map.

19. **Token Renewal**
	```cpp
	        pq.push({currentTime + ttl, tokenId});
	```
	Push the renewed token with a new expiration time into the priority queue.

20. **Token Renewal**
	```cpp
	        mp[tokenId]++;
	```
	Increment the token count in the map.

21. **Function Definition**
	```cpp
	int countUnexpiredTokens(int currentTime) {
	```
	Define the `countUnexpiredTokens` function that counts the number of unexpired tokens.

22. **Token Counting**
	```cpp
	    while(!pq.empty() && currentTime >= pq.top().first) {
	```
	Remove expired tokens from the priority queue and map.

23. **Token Cleanup**
	```cpp
	        mp[pq.top().second]--;
	```
	Decrement the count of the expired token.

24. **Token Cleanup**
	```cpp
	        if(mp[pq.top().second] == 0) mp.erase(pq.top().second);
	```
	Remove expired tokens from the map.

25. **Token Cleanup**
	```cpp
	        pq.pop();
	```
	Pop the expired token from the priority queue.

26. **Return Statement**
	```cpp
	    return mp.size();
	```
	Return the number of unexpired tokens.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log n) for each generate, renew, and countUnexpiredTokens operation, where n is the number of tokens.
- **Average Case:** O(log n) for each operation due to the use of the priority queue.
- **Worst Case:** O(log n) for each operation, where n is the number of tokens in the system.

Each operation requires O(log n) time due to the priority queue operations.

### Space Complexity 💾
- **Best Case:** O(1), if no tokens are stored.
- **Worst Case:** O(n), where n is the number of tokens, due to the storage requirements of the priority queue and map.

The space complexity is O(n), where n is the number of tokens, as both the priority queue and the map store each token.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/design-authentication-manager/description/)

---
{{< youtube IG6X2CXMdKw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
