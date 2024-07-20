
class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        long long ans=0;
        long long num1, num2;
        long long N =1000000007; // very very imp step
      
        num1 = first->data;
        first=first->next;
        while(first != NULL)
        {
            num1  = (num1 * 10)%N + first->data;
            first =first->next;
        }
         num2 = second->data;
        second=second->next;
        while(second!=NULL)
        {
            num2 = (num2 * 10)%N + second->data;
            second =second->next;
        }
        // cout<<num1<<"\n "<<num2<<"\n";
        ans = (num1% N) * (num2%N) %N;
        return ans;
    }
};

