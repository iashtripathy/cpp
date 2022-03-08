// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

int getMaxWidth(Node* root);

int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        string inp;
        getline(cin, inp);
        Node* root = buildTree(inp);
        
        cout << getMaxWidth(root) <<endl;
    }
    return 0;
}


// } Driver Code Ends


/*  Structure of a Binary Tree 

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

int getwidth(Node* root,queue<pair<struct Node*,int>>&q,int level){
    int res = 0;
    int maxWidth = 1;
    int value = 1;
    while(!q.empty()){
        pair<struct Node*,int> p = q.front();
        if(p.second!=value){
            //maxwidth = max(maxWidth,res);
            res =  0;
        }
        q.pop();
        value = p.second;
        if((p.first)->left){
            q.push({(p.first)->left,p.second+1});
            res++;            
        }
        if((p.first)->right){
            q.push({(p.first)->right,p.second+1});
            res ++;
        }

        
        maxWidth = max(res,maxWidth);
    }
    
    return maxWidth;
} 

/* Function to get the maximum width of a binary tree*/
int getMaxWidth(Node* root)
{
    if(root==NULL){
        return -1;
    }
    else{
        queue<pair<struct Node*,int>>q;
        int level = 1;
        q.push({root,level});
        return getwidth(root,q,level);
    }
   // Your code here
}