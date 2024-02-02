#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void increaseEnd()
    {
        cntEndWith++;
    }

    void increasePrefix()
    {
        cntPrefix++;
    }

    int getEnd()
    {
        return cntEndWith;
    }

    int getPrefix()
    {
        return cntPrefix;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualto(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->getEnd();
    }

    vector<string> FindWordsStartingWith(string &prefix)
    {
        Node *node = root;
        vector<string> words;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (node->containsKey(prefix[i]))
            {
                node = node->get(prefix[i]);
            }
            else
            {
                return words;
            }
        }
        collectWordsWithPrefix(node, prefix, words);
        return words;
    }

    void collectWordsWithPrefix(Node *node, string current, vector<string> &words)
    {
        if (node->getEnd() > 0)
        {
            words.push_back(current);
        }
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            if (node->containsKey(ch))
            {
                collectWordsWithPrefix(node->get(ch), current + ch, words);
            }
        }
    }
};

int main()
{
    Trie trie;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        trie.insert(s);
    }

    string prefix;
    cin >> prefix;
    vector<string> wordsWithPrefix = trie.FindWordsStartingWith(prefix);
    vector<pair<int, string>> ans;
    for (const string &word : wordsWithPrefix)
    {
        string str = word;

        ans.push_back({trie.countWordsEqualto(str), word});
    }

    sort(ans.begin(), ans.end());
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << "Word: " << ans[i].second << "\tFrequency: " << ans[i].first << endl;
    }

    return 0;
}
