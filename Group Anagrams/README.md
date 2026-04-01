🧩 Group Anagrams
📌 Problem Statement

Given an array of strings strs, group the anagrams together.
You can return the answer in any order.

🎯 Group Same Words (Intuition)

Imagine you and your friends are playing with colorful alphabet blocks 🧱

One builds "listen"
Another builds "silent"
Someone else builds "enlist"

Even though they look different, they use the same letters 🤯

👉 So we group them together!

Now someone builds "hello"
❌ Different letters → stays alone

👉 This is exactly how anagram grouping works.

🧪 Examples
Example 1
Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2
Input: strs = [""]
Output: [[""]]
Example 3
Input: strs = ["a"]
Output: [["a"]]
⚡ Approaches
🟡 Better Approach
🔹 Using Sorting + HashMap
💡 Idea

If we sort a word, all its anagrams become identical.

eat → aet  
tea → aet  
ate → aet  

👉 Use sorted string as key.

🪜 Steps
Create a hashmap
Key → sorted string
Value → list of words
Traverse each word:
Store original word
Sort it
Push into map
Collect all grouped values
Return result
⏱ Complexity
Type	Complexity
Time	O(N * K log K)
Space	O(N * K)
💻 Code (C++)
class Solution {
public:
   vector<vector<string>> groupAnagrams(vector<string>& arr) {
       vector<vector<string>> ans;
       unordered_map<string, vector<string>> m;

       for(int i = 0; i < arr.size(); i++) {
           string str = arr[i];
           sort(arr[i].begin(), arr[i].end());
           m[arr[i]].push_back(str);
       }

       for(auto x : m) {
           ans.push_back(x.second);
       }

       return ans;
   }
};
🟢 Best Approach
🔹 Signature Hashing (Frequency Count)
💡 Idea

Instead of sorting, count frequency of characters.

👉 Anagrams always have same frequency
So we build a unique hash from character counts.

🪜 Steps
Create frequency array of size 26
Count characters of each word
Convert frequency into a string hash
Use hash as key in hashmap
Group words with same hash
⏱ Complexity
Type	Complexity
Time	O(N * K)
Space	O(N * K)
💻 Code (C++)
class Solution {
public:

    string getHash(string &s) {
        vector<int> freq(26, 0);
        
        for(char ch : s) {
            freq[ch - 'a']++;
        }

        string hash = "";
        for(int i = 0; i < 26; i++) {
            hash += to_string(freq[i]) + "$";
        }

        return hash;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(string &word : strs) {
            string key = getHash(word);
            mp[key].push_back(word);
        }

        vector<vector<string>> res;
        for(auto &x : mp) {
            res.push_back(x.second);
        }

        return res;
    }
};
🔥 Key Takeaways

✅ Anagrams = same characters, different order
✅ Sorting makes them identical → easy grouping
✅ Frequency hashing avoids sorting → faster
✅ HashMap is the core data structure

🚀 Summary
Approach	Idea	Time
Better	Sort strings	O(N*K log K)
Best	Frequency hash	O(N*K)
⭐ Tip

👉 Use sorting approach for simplicity
👉 Use frequency hashing for optimal performance

