#include <vector>
using namespace std;

struct SegmentTreeNode{
    //index of range
    int start;
    int end;

    int sum;//also can be min/max
    SegmentTreeNode* left;
    SegmentTreeNode* right;

    SegmentTreeNode(int s,int e,int sum):start(s),end(e),sum(sum),left(NULL),right(NULL){}

    SegmentTreeNode(int s,int e,int sum,SegmentTreeNode* l,SegmentTreeNode* r)
    :start(s),end(e),sum(sum),left(l),right(r){}
};

SegmentTreeNode* bulidTree(int start,int end,vector<int>& v){
    if(start == end)
        return new SegmentTreeNode(start,end,v[start]);

    int mid = (start + end) / 2;
    SegmentTreeNode* left = bulidTree(start,mid,v);
    SegmentTreeNode* right = bulidTree(mid + 1,end,v);
    SegmentTreeNode* root = new SegmentTreeNode(start,end,left->sum+right->sum,left,right);
    return root;
}

void updateTree(SegmentTreeNode* root, int index,int val){
    //if already in the leaf, only update val and return
    if(index == root->start && index == root->end){
        root->sum = val;
        return;
    }
    int mid = (root->start + root->end) / 2;
    if(index <= mid)//uodate left subtree
        updateTree(root->left,index,val);
    else
        updateTree(root->right,index,val);
    
    //need to update sum after update left/right suntree
    root->sum = root->left->sum + root->right->sum;
    
}

//query sum of [l,r]
int querySum(SegmentTreeNode* root, int l, int r){
    if(l == root->start && r == root->end)
        return root->sum;
    
    int mid = (root->start+root->end) / 2;
    if(r <= mid)//[l,r] is include in left subtree
        return querySum(root->left,l,r);
    else if(l > mid)//[l,r] is include in right subtree
        return querySum(root->right,l,r);
    else
        return querySum(root->left,l,mid)+querySum(root->right,mid+1,r);
    
}