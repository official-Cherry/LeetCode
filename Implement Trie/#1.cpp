/* [LeetCode] Implement Trie (Prefix Tree)
    : https://leetcode.com/problems/implement-trie-prefix-tree/ */

// problem description 
/* A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise. */

/* 
input: 
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]

output:
[null, null, true, false, true, null, true]
*/

// prefix tree 
// 문자열 집합에서 키를 효율적으로 저장 및 검색하기 위해 사용되는 트리기반 데이터구조

class Trie {

public:
    vector<Trie*> children;
    bool isEndOfWord;

    Trie() : children(26,nullptr), isEndOfWord(false) {}
    
    void insert(string word) {
        Trie* node = this; // 현재 객체를 사용 

        // 알파벳 삽입
        for(char c : word)
        {
            int index = c-'a';
            if(node->children[index] == nullptr)
            {
                node->children[index] = new Trie();
            }
            node = node->children[index];
        }

        // 단어의 끝 표시 
        node->isEndOfWord = true; 
    }
    
    bool search(string word) { // == 
        // return true if the string word is in the trie
        Trie* node = this;

        for(char c : word)
        {
            int index = c-'a';
            if(node->children[index] == nullptr)
            {
                return false; // 해당 문자를 가진 노드가 없으면 단어가 없는 것
            }
            node = node->children[index];
        }

        return node->isEndOfWord; // 단어의 끝인지 확인 

    }
    
    bool startsWith(string prefix) { // ~= 
        // return true if there is a previously inserted string `word` 
        // that has the `prefix`

        Trie* node = this;
        for(char c : prefix)
        {
            int index = c-'a';
            if(node->children[index] == nullptr)
            {
                return false; // 해당 문자를 가진 노드가 없으면 접두사 X 
            }
            node = node->children[index];
        }
        return true; // 모든 문자 찾으면 접두사 존재 
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
