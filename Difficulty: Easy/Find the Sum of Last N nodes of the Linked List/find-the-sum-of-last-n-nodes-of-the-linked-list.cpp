//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
class Solution {
  public:
    /*Structure of the node of the linled list is as

    struct Node {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }
    };
    */
    // your task is to complete this function
    // function should return sum of last n nodes
    Node* reverselinkedlist(struct Node* head)
    {
        Node*current=head;
        Node*prev=NULL;
        Node*temp=NULL;
        
        while(current!=NULL)
        {
            temp=current->next;
            current->next=prev;
            prev=current;
            current=temp;
        }
        return prev;
    }
    int sumOfLastN_Nodes(struct Node* head, int n) {
        // Code here
        if(head==NULL)
        {
            return 0;
        }
        Node*reversehead=reverselinkedlist(head);
        Node*current=reversehead;
        
        int sum=0;
        int count=0;
        
        while(current!=NULL && count<n)
        {
            sum+=current->data;
            current=current->next;
            count++;
        }
        
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n;
        cin >> n;
        cin.ignore();
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution ob;
        cout << ob.sumOfLastN_Nodes(head, n) << endl;
    }
    return 0;
}
// } Driver Code Ends