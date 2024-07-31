struct TrieNode{
    //contains links for 26 alphabets
    TrieNode* child[26];

    // flag to mark the word end
    bool flag= false;

    //funtion to check presence of char
    bool contains(char ch)
    {
        
        if( child[ch-'a'] != NULL )
        {
            // character is present
            return true;
        }
        else
        {
            return false;
        }
    }

    //Function to put new node
    void put(char ch, TrieNode* node)
    {
        child[ch-'a'] = node;
    }

    // funtion to get link of char
    TrieNode* getNext(char ch)
    {
        return child[ch-'a'];
    }
    // set end to true
    void setEnd()
    {
            flag = true;
    }

    //function to check whether the node is end of word or not

    bool isEnd()
    {
        return flag;
    }
};

class WordDictionary {
    TrieNode* root ;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        int n =word.length();
        TrieNode* node = root;

        for(int i= 0;i<n;i++)
        {
            char ch= word[i];

            if(node->contains(ch) == false)
            {
                TrieNode* newNode = new TrieNode();

                node->put(ch, newNode);
            }

            node =node->getNext(ch);
        }

        node->setEnd();
    }
    
    bool searchUtil(string word, TrieNode* root ) {
         TrieNode* node= root;

        for(int i=0;i<word.length();i++)
        {
            char ch = word[i];
            if(ch== '.')
            {
                for(int j=0;j<26;j++)
                {
                    if(node->child[j] != NULL && 
                    searchUtil(word.substr(i+1), node->child[j]) == true
                    )
                    {
                        return true;
                    }
                }

                return false;
            }

            
            if( node->contains(ch) == false)
            return false;

            node = node->getNext(ch);
        }

        if(node->isEnd()) return true;
        else return false;

    }

    bool search(string word)
    {
        return searchUtil(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
