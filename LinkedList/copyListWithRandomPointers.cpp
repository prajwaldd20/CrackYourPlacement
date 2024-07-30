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


  
        // Approach 2: 
        //  create node in between two nodes


        Node* temp = head;

        while(temp != NULL) 
        {
            // create new node
            Node* p= new Node(temp->val);
            p->next = temp->next;
            temp->next = p;

            temp = temp->next->next;

        }

        // connect random pointers
     
        temp = head; // copied list

        while(temp != NULL)
        {
            // copynode
            Node* p = temp->next;
            if(temp->random)
            p->random = temp->random->next;
            else
            p->random = NULL;

            temp = temp->next->next;
        }

        // connect next pointers
        Node* dummy = new Node(-1);

        Node* res = dummy;


        temp = head;

        while(temp != NULL )
        {
            res -> next = temp->next;
            res =res->next;
             temp->next = temp->next->next;
             
             temp = temp->next;
           
        }

        return dummy->next;

    }
