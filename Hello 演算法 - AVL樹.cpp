#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data{};
    int height=0;
    Node* left{};
    Node* right{};
    Node() = default;
    explicit Node(int x) : data(x){};
};

int Height(Node* curr){
    return curr==nullptr ? -1:curr->height;
}

void updateHeight(Node* node){
    node->height = max(Height(node->left),Height(node->right))+1;
}

int balanceFactor(Node* node){
    if(node == nullptr) return 0;
    return Height(node->left)-Height(node->right);
}

Node* R_rotate(Node* node){
        Node* child = node->left;
        Node* temp = child->right;
        child->right = node;
        node->left = temp;
        updateHeight(node);
        updateHeight(child);
        return child;
}

Node* L_rotate(Node* node){
        Node* child = node->right;
        Node* temp = child->left;
        child->left = node;
        node->right = temp;

        updateHeight(node);
        updateHeight(child);

        return child;
}

Node* Rotate(Node* node){
int _balanceFactor = balanceFactor(node);

if(_balanceFactor > 1){
    if(balanceFactor(node->left) >= 0){
        return R_rotate(node);
    }else{
        node->left = L_rotate(node->left);
        return R_rotate(node);
    }
}


if(_balanceFactor < -1){
    if(balanceFactor(node->right) <= 0){
        return L_rotate(node);
    }else{
        node->right = R_rotate(node->right);
        return L_rotate(node);
    }
}

return node;
}

void BFS(vector<int> &res,Node* curr){
    if(curr == nullptr)return;
    queue<Node*> Queue;
    Queue.push(curr);
    while(!Queue.empty()){
        Node* node = Queue.front();
        if(node->left!=nullptr)Queue.push(node->left);
        if(node->right!=nullptr)Queue.push(node->right);
        res.push_back(node->data);
        Queue.pop();
    }
}

Node* Insert(int num,Node* root){
    if(root == nullptr)return new Node(num);

    if(num > root->data){
        root->right = Insert(num,root->right);
        updateHeight(root);
    }else if(num < root->data){
        root->left = Insert(num,root->left);
        updateHeight(root);
    }else{
        return root;
    }
    return Rotate(root);
}

Node* Find_min(Node* curr){
    if(curr->left != nullptr)return Find_min(curr->left);
    return curr;
}

Node* Delete(int num,Node* curr){
    if(curr == nullptr) return curr;

    if(num > curr->data){
        curr->right = Delete(num,curr->right);
    }else if(num < curr->data){
        curr->left = Delete(num,curr->left);
    }else{
        if(curr->left == nullptr){
            return curr->right;
        }else if(curr->right == nullptr){
            return curr->left;
        }else{
            Node* NEW = Find_min(curr->right);
            Node* NEW_right = Delete(NEW->data,curr->right);
            NEW->left = curr->left;
            NEW->right= NEW_right;
            delete curr;
            return NEW;
        }
    }
    updateHeight(curr);
    return Rotate(curr);
}

int main(){
    vector<int> nums={5,3,6,1,4,0};
    Node* root = nullptr;
    for(int i=0;i<nums.size();i++){
        root = Insert(nums[i],root);
    }
    root = Delete(4,root);
    vector<int> res;
    BFS(res,root);
    for(int i: res){
        cout << i <<" ";
    }
}
