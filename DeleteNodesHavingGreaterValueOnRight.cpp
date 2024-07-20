//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *compute(Node *head)
    {
        vector<int> nodes;
        while(head) {
            nodes.push_back(head->data);
            head = head->next;
        }
        
        int n = nodes.size();
        int largest = INT_MIN;
        for(int i=n-1; i>=0; i--) {
            if(nodes[i] >= largest) {
                largest = nodes[i];
            } else {
                nodes[i] = -1;
            }
        }
        
        Node* newHead = new Node(-1);
        Node* temp = newHead;
        for(int i=0; i<nodes.size(); i++) {
            if(nodes[i] != -1) {
                Node* newNode = new Node(nodes[i]);
                temp->next = newNode;
                temp = temp->next;
            }
        }
        
        return newHead->next;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends