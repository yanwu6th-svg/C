#include<bits/stdc++.h>
using namespace std;
struct Node{
int data;
Node *r_node,*l_node;
Node(int x) : l_node(nullptr),r_node(nullptr),data(x){};
};

Node *Insert(Node* root,int x){
if(root == nullptr){
    return new Node(x);
}

if(x < root -> data){
    root->l_node = Insert(root->l_node,x);
}

if(x > root -> data){
    root->r_node = Insert(root->r_node,x);
}

return root;
}

vector<int> BFS(Node* root){
vector<int> res;
queue<Node*> Queue;
Queue.push(root);
while(!Queue.empty()){
    res.push_back(Queue.front() -> data);
    Node* node = Queue.front();
    Queue.pop();
    if(node -> l_node != nullptr){
        Queue.push(node -> l_node);
    }
    if(node -> r_node != nullptr){
        Queue.push(node -> r_node);
    }

}
return res;
}

void DFS_pre(vector<int> &res,Node* root){
    if(root == nullptr) return;
    res.push_back(root -> data);
    DFS_pre(res,root-> l_node);
    DFS_pre(res,root-> r_node);

}

void DFS_in(vector<int> &res,Node* root){
    if(root == nullptr) return;
    DFS_in(res,root -> l_node);
    res.push_back(root -> data);
    DFS_in(res,root -> r_node);
}

void root_to_tree(int i,vector<int> &tree,Node* root){
    if(root == nullptr)return;
    tree[i] = root -> data;
    root_to_tree(2*i+1,tree,root -> l_node);
    root_to_tree(2*i+2,tree,root -> r_node);
}

int Deep(Node* root){
    if(root == nullptr) return 0;
    int l_node_deep = Deep(root->l_node);
    int r_node_deep = Deep(root->r_node);
    return max(l_node_deep,r_node_deep) +1;
}

void vec_DFS(vector<int> &tree,int i,string order,vector<int> &res){
    if(tree[i] == INT_MAX||i > tree.size()-1 ) return;
    if(order == "pre")res.push_back(tree[i]);
    vec_DFS(tree,2*i+1,order,res);
    if(order == "in")res.push_back(tree[i]);
    vec_DFS(tree,2*i+2,order,res);
    if(order == "past")res.push_back(tree[i]);
}

Node* FIND_min(Node* root){
    if(root->l_node != nullptr) return FIND_min(root->l_node);
    return root;
}


Node* Delete(Node* curr,int num){
    if(curr == nullptr)return nullptr;

    if(curr->data > num){
        curr->l_node = Delete(curr->l_node,num);
    }else if(curr->data < num){
        curr->r_node = Delete(curr->r_node,num);
    }else{

    if(curr->l_node == nullptr){
        Node* temp =  curr->r_node;
        delete curr;
        return temp;
    }else if(curr->r_node == nullptr){
        Node* temp =  curr->l_node;
        delete curr;
        return temp;
    }

    Node* NEW = FIND_min(curr->r_node);
    Node* NEW_l_node = curr->l_node;
    Node* NEW_r_node = Delete(curr->r_node,NEW->data);
    
    NEW->l_node = NEW_l_node;
    NEW->r_node = NEW_r_node;
    delete curr;
    return NEW;
    }
    return curr;
}

int main(){

vector<int> nums = {8,4,12,1,6,10,14,7,9,11,13,15};

Node *root = nullptr;

for(int i=0;i<12;i++){
    root = Insert(root,nums[i]);
}

root = Delete(root,12);
vector<int> res;
res = BFS(root);
for(int i:res){
    cout <<i<<" ";
}
}
