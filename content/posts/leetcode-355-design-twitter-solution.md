
+++
authors = ["grid47"]
title = "Leetcode 355: Design Twitter"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 355: Design Twitter in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Linked List","Design","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/design-twitter/description/)

---
**Code:**

{{< highlight cpp >}}
class Tweet {
public:
    int id;
    int time;
    Tweet* next;
    Tweet(int id, int time) {
        this->id = id;
        this->time = time;
        next = NULL;
    }
};

class User {
public:
    int id;
    set<int> followed;
    Tweet* tweet_head;

    User(int id) {
        id = id;
        follow(id); // follow self;
        tweet_head = NULL;
    }

    void follow(int id) {
        followed.insert(id);
    }

    void unfollow(int id) {
        followed.erase(id);
    }

    void post(int id, int times) {
        Tweet* t = new Tweet(id, times);
        t->next = tweet_head;
        tweet_head = t;
    }
};


class Twitter {
public:
    int timeStamp = 0;
    map<int, User*> userMap;
    
public:
    Twitter() {
        // user map init
    }
    
    void postTweet(int userId, int tweetId) {
        if(!userMap.count(userId)) {
            User* u = new User(userId);
            userMap[userId] = u;
        }
        userMap[userId]->post(tweetId, timeStamp++);
    }
    
    struct compare {
        bool operator()(const Tweet* l, const Tweet* r) {
            return l->time < r->time;
        }
    };

    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        if(!userMap.count(userId)) {
            return res;
        };
        set<int> users = userMap[userId]->followed;
        
        priority_queue<Tweet*, vector<Tweet*>, compare> pq;

        for(int user: users) {
            Tweet* t = userMap[user]->tweet_head;
            if(t != NULL)
                pq.push(t);
        }
        int n = 0;
        while(!pq.empty() && n < 10) {
            Tweet* t = pq.top();
            pq.pop();
            res.push_back(t->id);
            n++;
            if(t->next != NULL)
                pq.push(t->next);
        }
        cout << n << "-";
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(!userMap.count(followerId)) {
            User* u = new User(followerId);
            userMap[followerId] = u;
        }
        if(!userMap.count(followeeId)) {
            User* u = new User(followeeId);
            userMap[followeeId] = u;
        }        
        userMap[followerId]->follow(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(userMap.count(followerId) && followerId == followeeId)
            return;
            userMap[followerId]->unfollow(followeeId);
    }

};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/355.md" >}}
---
{{< youtube pNichitDD2E >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #357: Count Numbers with Unique Digits](https://grid47.xyz/posts/leetcode-357-count-numbers-with-unique-digits-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}