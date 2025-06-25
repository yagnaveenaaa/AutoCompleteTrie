#include <iostream>
#include <vector>
using namespace std;

#define CHAR_SIZE 26

// Trie node def
class TrieNode {
public:
    bool isEndOfWord;
    TrieNode* children[CHAR_SIZE];

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < CHAR_SIZE; i++)
            children[i] = nullptr;
    }
};

// Trie class with insert and suggestion
class Trie {
private:
    TrieNode* root;

    void insertWord(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index])
                node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    bool isLastNode(TrieNode* node) {
        for (int i = 0; i < CHAR_SIZE; i++)
            if (node->children[i])
                return false;
        return true;
    }

    void suggestionsRec(TrieNode* node, string currentPrefix) {
        if (node->isEndOfWord)
            cout << currentPrefix << endl;

        for (int i = 0; i < CHAR_SIZE; i++) {
            if (node->children[i]) {
                currentPrefix.push_back('a' + i);
                suggestionsRec(node->children[i], currentPrefix);
                currentPrefix.pop_back();
            }
        }
    }

public:
    Trie() {
        root = new TrieNode();
    }

    void insertWords(const vector<string>& words) {
        for (const string& word : words)
            insertWord(word);
    }

    void getSuggestions(const string& query) {
        TrieNode* node = root;
        for (char c : query) {
            int index = c - 'a';
            if (!node->children[index]) {
                cout << "No string found with this prefix\n";
                return;
            }
            node = node->children[index];
        }

        bool isWord = node->isEndOfWord;
        bool isLast = isLastNode(node);

        if (isWord && isLast) {
            cout << query << endl;
            cout << "No other strings found with this prefix\n";
            return;
        }

        suggestionsRec(node, query);
    }
};

int main() {
    int n;
    cout << "Enter the number of words: ";
    cin >> n;

    vector<string> words(n);
    cout << "Enter the words:\n";
    for (int i = 0; i < n; i++)
        cin >> words[i];

    Trie trie;
    trie.insertWords(words);

    string prefix;
    cout << "\nEnter prefix to autocomplete: ";
    cin >> prefix;

    cout << "\nSuggestions:\n";
    trie.getSuggestions(prefix);

    return 0;
}
