 Node* copyRandomList(Node* head) {
       if(head == NULL ) return NULL;
       
       // store the node and the corresponding new node
        unordered_map<Node* , Node* > mp;

        Node* temp = head;

        while(temp != NULL)
        {
            // create a new node with value 
            Node* p = new Node(temp->val);
            // save the original node with corresponding node
            mp[temp] =  p;

            temp =temp->next;
        }
     
        temp = head;

        while(temp != NULL)
        {
            // extract copied node from map
            Node* p = mp[temp];

            p->next = mp[temp->next];
            p->random = mp[temp->random];
            temp = temp->next;
        }

        return mp[head];

    }
