#include <iostream>
using namespace std;

struct Node
{ // representing every character

    Node *links[26];
    bool flag = false;

    // checks if character is present in links list or not;
    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    // insert character into trie and places new refrence node at it's place;
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    // returns the refrence node for the character;
    Node*   get(char ch)
    {
        return links[ch - 'a'];
    }

    // sets the flag of the last charcter of the word to true (end of the word);
    void setEnd()
    {
        flag = true;
    }

    // returns the flag value;
    bool isEnd()
    {
        return flag;
    }
};

class Trie
{

private:
    Node *root; // starting character word;

public:
    Trie()
    { // initialize node when object is called;

        root = new Node();
    }

    // inserts the word in the Trie;
    void insert(string word)
    {

        Node *node = root; // pointing to the address of the root node;

        for (int i = 0; i < word.size(); i++)
        {

            // does not contain character
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }

            // moves to refrence node;
            node = node->get(word[i]);
        }

        node->setEnd();
    }

    // searchs the word in Trie;
    bool search(string word)
    {
        Node *node = root;

        for (int i = 0; i < word.length(); i++)
        {

            // does not contain word;
            if (!node->containsKey(word[i]))
            {
                return false;
            }

            node = node->get(word[i]);
        }

        // Whole word is present;
        if (node->isEnd())
            return true;

        // word is present but as a prefix;
        return false;
    }

    bool startsWith(string word)
    {

        Node *node = root;

        for (int i = 0; i < word.length(); i++)
        {

            // does not contain word;
            if (!node->containsKey(word[i]))
            {
                return false;
            }

            node = node->get(word[i]);
        }

        return true; // Whole word is present OR as a prefix .
    }
};

int main()
{

    Trie *T = new Trie();

    T->insert("him");
    T->insert("her");
    T->insert("his");
    T->insert("tim");
    T->insert("hi");
    cout << T->search("he") << endl;
    cout << T->search("hi") << endl;
    // cout << T->startsWith("appl") << endl;
}