//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        // code here
        
        Node* curr1 = num1;
        Node* curr2 = num2;
        Node* prev1 = NULL;
        while(curr1 != NULL){
            Node* nxt = curr1->next;
            curr1->next = prev1;
            prev1 = curr1;
            curr1 = nxt;
        }
        Node* head1 = prev1;
        Node* prev2 = NULL;
        while(curr2 != NULL){
            Node* nxt = curr2->next;
            curr2->next = prev2;
            prev2 = curr2;
            curr2 = nxt;
        }
        Node* head2 = prev2;
        Node* dummyNode = new Node(-1);
        curr1 = head1;
        curr2 = head2;
        int carry = 0;
        while(curr1 != NULL || curr2 != NULL || carry != 0){
            int currValue1 = curr1 == NULL ? 0 : curr1->data;
            int currValue2 = curr2 == NULL ? 0 : curr2->data;
            Node* curr = new Node((currValue1 + currValue2 + carry) % 10);
            carry = (currValue1 + currValue2 + carry)/10;
            if(dummyNode->data != -1){
                curr->next = dummyNode;
            }else{
                curr->next = NULL;
            }
            dummyNode = curr;
            curr1 = curr1 == NULL ? curr1 : curr1->next;
            curr2 = curr2 == NULL ? curr2 : curr2->next;
        }
        Node* head = dummyNode;
        while(head != NULL && head->data == 0){
            head = head->next;
        }
        if(head == NULL){
            return new Node(0);
        }
        return head;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends