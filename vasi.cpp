//
//  main.cpp
//  AVLmod2.0
//
//  Created by Nicolò Mazzucato on 07/07/15.
//  Copyright (c) 2015 Nicolò Mazzucato. All rights reserved.
//


// spunto da: http://www.nayuki.io/page/avl-tree-list


#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <set>
#include <utility>
#include <iostream>
#include <time.h>
clock_t start, _end;
double tempo;

//#define safe
using namespace std;

#define MAXN 10000000
void * virtualy_deleted;

class AvlTreeMOD {
    
private:
    class Node;  // Forward declaration
    Node *root;
    
    
public:
    
    AvlTreeMOD() :
    root(&Node::emptyLeafNode) {}
    
    AvlTreeMOD(int N)
    {
        root = construct(0, N-1);
    }
    
    
    
    ~AvlTreeMOD() {
        // clear();
    }
    
    
    
    inline int size() const {
        return root->size;
    }
    
    
    int &at(int index) {
#ifdef safe
        if (index >= size())
            throw "Index out of bounds";
#endif
        return root->getNodeAt(index)->id;
    }
    
    
    inline const int &at(int index) const {
#ifdef safe
        if (index >= size())
            throw "Index out of bounds";
#endif
        return root->getNodeAt(index)->id;
    }
    
    
    inline void insert(int index, const int &val) {
#ifdef safe
        if (index > size())
            throw "Index out of bounds";
#endif
        root = root->insertAt(index, val);
    }
    
    
    inline void insert(int index, int && val) {
#ifdef safe
        if (index > size())
            throw "Index out of bounds";
#endif
        root = root->insertAt(index, std::move(val));
    }
    
    
    void erase(int index) {
#ifdef safe
        if (index >= size())
            throw "Index out of bounds";
#endif
        Node *toDelete = NULL;
        root = root->removeAt(index, &toDelete);
#ifdef safe
        if (toDelete != NULL)
#endif
            virtualy_deleted =  toDelete;
    }

private:
    
    
    class Node {
        
    public:
        
        
        
        // For the singleton empty leaf node
        Node() :
        id(),  // Default constructor on type E
        height(0),
        size  (0),
        left (NULL),
        right(NULL)
        {}
        
        
        // A bit of a hack, but more elegant than using null ids as leaf nodes
        static Node emptyLeafNode;
        static Node *virtualy_del;
        
        
        // The object stored at this node
        int id;
        
        // The height of the tree rooted at this node. Empty nodes have height 0.
        // This node has height equal to max(left->height, right->height) + 1.
        int height;
        
        // The number of nodes in the tree rooted at this node, including this node.
        // Empty nodes have size 0. This node has size equal to left->size + right->size + 1.
        int size;
        
        // The root node of the left subtree
        Node *left;
        
        // The root node of the right subtree
        Node *right;
        
        
    private:
        
        inline Node* new_node(const int &val)
        {
            return getNodeNew(val);
        }
        inline Node* new_node( int &&val)
        {
            return getNodeNew(std::move(val));
        }
        inline Node* getNodeNew(const int &val)
        {
            Node* new_n = (Node*) virtualy_deleted;
            new_n->id = val;
            new_n->height = 1;
            new_n->size = 1;
            new_n->left = &Node::emptyLeafNode;
            new_n->right = &Node::emptyLeafNode;
            return new_n;
            
        }
        
        
        // Normal non-leaf nodes
        Node(const int &val) :
        id(val),  // Copy constructor on type E
        height(1),
        size  (1),
        left (&emptyLeafNode),
        right(&emptyLeafNode) {}
        
        
        // Normal non-leaf nodes
        Node(int &&val) :
        id(std::move(val)),  // Move constructor on type E
        height(1),
        size  (1),
        left (&emptyLeafNode),
        right(&emptyLeafNode) {}
        
        
    public:
       
        
        
        Node *getNodeAt(int index) {
#ifdef safe
            assert(index < size);
            if (this == &emptyLeafNode)
                throw "Illegal argument";
#endif
            
            int leftSize = left->size;
            if (index < leftSize)
                return left->getNodeAt(index);
            else if (index > leftSize)
                return right->getNodeAt(index - leftSize - 1);
            else
                return this;
        }
        
        
        Node *insertAt(int index, const int &obj) {
#ifdef safe
            assert(index <= size);
            if (this == &emptyLeafNode) {
                if (index == 0)
                    return  new_node(obj);// new Node(obj);
                else
                    throw "Index out of bounds";
            }
#else
            if (this == &emptyLeafNode)
                return new_node(obj);//new Node(obj);
#endif
            
            int leftSize = left->size;
            if (index <= leftSize)
                left = left->insertAt(index, obj);
            else
                right = right->insertAt(index - leftSize - 1, obj);
            recalculate();
            return balance();
        }
        
        
        Node *insertAt(int index, int &&obj) {
#ifdef safe
            assert(index <= size);
            if (this == &emptyLeafNode) {
                if (index == 0)
                    return new_node(std::move(obj));//new Node(std::move(obj));
                else
                    throw "Index out of bounds";
            }
#else
            if (this == &emptyLeafNode)
                return new_node(std::move(obj));
#endif
            
            int leftSize = left->size;
            if (index <= leftSize)
                left = left->insertAt(index, std::move(obj));
            else
                right = right->insertAt(index - leftSize - 1, std::move(obj));
            recalculate();
            return balance();
        }
        
        
        Node *removeAt(int index, Node **toDelete) {
#ifdef safe
            assert(index < size);
            if (this == &emptyLeafNode)
                throw "Illegal argument";
#endif
            
            int leftSize = left->size;
            if (index < leftSize)
                left = left->removeAt(index, toDelete);
            else if (index > leftSize)
                right = right->removeAt(index - leftSize - 1, toDelete);
            else if (left == &emptyLeafNode && right == &emptyLeafNode) {
#ifdef safe
                assert(*toDelete == NULL);
#endif
                *toDelete = this;
                return &emptyLeafNode;
            } else if (left != &emptyLeafNode && right == &emptyLeafNode) {
                Node *result = left;
                left = NULL;
#ifdef safe
                assert(*toDelete == NULL);
#endif
                *toDelete = this;
                return result;
            } else if (left == &emptyLeafNode && right != &emptyLeafNode) {
                Node *result = right;
                right = NULL;
#ifdef safe
                assert(*toDelete == NULL);
#endif
                *toDelete = this;
                return result;
            } else {
                // We can remove the successor or the predecessor
             //   std::swap(id, getSuccessor());
                int & suc = getSuccessor();
                int tmp = id;
                id = suc;
                suc = tmp;
                right = right->removeAt(0, toDelete);
            }
            recalculate();
            return balance();
        }
        
        
    private:
        
        int &getSuccessor() {
#ifdef safe
            if (this == &emptyLeafNode || right == &emptyLeafNode)
                throw "Illegal argument";
#endif
            Node *node = right;
            while (node->left != &emptyLeafNode)
                node = node->left;
            return node->id;
        }
        
#define b_const 10
        // Balances the subtree rooted at this node and returns the new root
        Node *balance() {
            Node *result = this;
            //if ( rand() % 100000 ) return result;
            
            int bal = getBalance();
#ifdef safe
            assert(std::abs(bal) <= 2);
#endif
            if (bal < -b_const) {
#ifdef safe
                assert(std::abs(left->getBalance()) <= 1);
#endif
                if (left->getBalance() > b_const)
                    left = left->rotateLeft();
                result = rotateRight();
            } else if (bal > b_const ) {
#ifdef safe
                assert(std::abs(right->getBalance()) <= 1);
#endif
                if (right->getBalance() < b_const)
                    right = right->rotateRight();
                result = rotateLeft();
            }
#ifdef safe
            assert(std::abs(result->getBalance()) <= 1);
#endif
            return result;
        }
        
        
        /*
         *   A            B
         *  / \          / \
         * 0   B   ->   A   2
         *    / \      / \
         *   1   2    0   1
         */
        Node *rotateLeft() {
#ifdef safe
            if (right == &emptyLeafNode)
                throw "Illegal state";
#endif
            Node *root = this->right;
            this->right = root->left;
            root->left = this;
            
            this->recalculate();
            root->recalculate();
            return root;
        }
        
        
        /*
         *     B          A
         *    / \        / \
         *   A   2  ->  0   B
         *  / \            / \
         * 0   1          1   2
         */
        Node *rotateRight() {
#ifdef safe
            if (left == &emptyLeafNode)
                throw "Illegal state";
#endif
            Node *root = this->left;
            this->left = root->right;
            root->right = this;
            this->recalculate();
            root->recalculate();
            return root;
        }
        
        
        // Needs to be called every time the left or right subtree is changed.
        // Assumes the left and right subtrees have the correct ids computed already.
         inline void recalculate() {
            height = max(left->height,right->height) + 1;
            size = left->size + right->size + 1;
        }
        
        
        inline int getBalance() const {
            return right->height - left->height;
        }
        
    };
    
    
    inline int height(Node* n)
    {
        return n? n->height:0;
    }
    inline int size_node(Node* n)
    {
        return n? n->size: 0;
    }
    
 //   Node belli_e_pronti[MAXN];
    
    Node* construct(int s, int d)
    {
        if ( s > d ) return &Node::emptyLeafNode;
        
        int mid = (s+d)>>1;
        //  cout<<"s: "<<s<<"  d:"<<d<<"  mid: "<< mid<<endl;
        
        static int i = 0;
        
        Node* new_node = new Node();//&belli_e_pronti[i++];
        new_node->id = mid;
        new_node->left = construct(s, mid-1);
        new_node->right = construct(mid+1, d);
        
        new_node->size = size_node(new_node->left) + size_node(new_node->right) + 1;
        new_node->height = max(height(new_node->left), height(new_node->right)) + 1;
        
        return new_node;
    }
    
};


typename AvlTreeMOD::Node AvlTreeMOD::Node::emptyLeafNode;

#define gc  getchar_unlocked

inline void scanInt(int &x)
{
    register char c=gc();
    x = 0;
    while( c<48 || c>57) { c=gc();}
    for(;c>47 && c<58;c = gc()){x = (x<<1) + (x<<3) + c - 48;}
}
#define pc(x) putchar_unlocked(x);
inline void writeInt (int n)
{
    int N = n, rev, count = 0;
    rev = N;
    if (N == 0) { pc('0');  return ;}
    while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
    rev = 0;
    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
    while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
    while (count--) pc('0');
}

int main()
{
    
    // ios::sync_with_stdio(false);
    
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    
    int N, Q;
    scanInt(N); scanInt(Q);
    start=clock();
    AvlTreeMOD tree(N);
    
    _end=clock();
    tempo=((double)(_end-start))/CLOCKS_PER_SEC;
    cerr<<"tempo per immissione: "<<tempo;
    
    char c = 0;
    int da, a;
    
    for (int i = 0; i < Q; i++)
    {
        scanf(" %c",&c);
        
        if ( c == 'c') // ith
        {
            scanInt(a);// cin>>a;
            printf("%d ",tree.at(a));
            //  cout<<tree.at(a)<<" ";
        }
        else
        {
            scanInt(da); scanInt(a);
            if ( da == a) continue;
            int source_id = tree.at(da);
            tree.erase(da);
            tree.insert(a, source_id);
            
        }
    }
    _end=clock();
    tempo=((double)(_end-start))/CLOCKS_PER_SEC;
    cerr<<"\ntempo totale: "<<tempo;
    
    
    return 0;
}

