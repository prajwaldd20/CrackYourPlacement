
// structure of trie node
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

class Trie {

    TrieNode* root ;
public:
    Trie() {
        // initialize root node
        root = new TrieNode();
    }
    
    void insert(string word) {
        
        int n= word.length();

        //create pointer to root node
        TrieNode* node = root;


        for(int i=0;i<n;i++)
        {
            char ch =word[i];
            if(node->contains(ch) == false) // char not present
            {
                // create new node
                TrieNode* newNode = new TrieNode();

                node->put(ch, newNode);
                
            }

            node = node->getNext(ch);

        }
        // after complete insertion
        // set flag as true
        node->setEnd();

    }
    
    bool search(string word) {
        
        TrieNode* node= root;
        for(int i=0;i<word.length();i++)
        {
            char ch = word[i];
            if( node->contains(ch) == false)
            return false;

            node = node->getNext(ch);
        }

        if(node->isEnd()) return true;
        else return false;



    }
    
    bool startsWith(string prefix) {
        TrieNode* node =root;

        for(int i= 0;i<prefix.length();i++)
        {
            char ch =prefix[i];

            if(node->contains(ch) == false)
            return false;

            node =node->getNext(ch);
        }

        if(node != NULL)
        {
            return true;
        }

        return false;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
