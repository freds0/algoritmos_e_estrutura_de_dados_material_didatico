//
//  main.c
//  BTree
//
//  Created by Christopher Early on 3/20/15.
//
//
#include <stdio.h>
#include <stdlib.h>


typedef int Object;

typedef struct BTreeNode {
    
    Object *keys;
    
    int t;
    
    struct BTreeNode **children;
    
    int n;
    
    int leaf;
    
} BTreeNode;


typedef struct BTree {
    
    BTreeNode *root;
    
    int t;
    
} BTree;

BTreeNode* allocateNode(int t, int leaf) {
    
    BTreeNode *x = (BTreeNode*)malloc(sizeof(BTreeNode));
    
    x->t = t;
    x->leaf = leaf;
    x->keys = (Object*)malloc((2*t-1)*sizeof(Object));
    x->children = (BTreeNode**)malloc((2*t)*sizeof(BTreeNode));
    x->n = 0;
    
    return x;
}

void BTreeCreate(BTree *T, int t) {
    
    T->t = t;
    
    BTreeNode *x = allocateNode(t, 1);
    
    x->leaf = 1;
    
    x->n = 0;
    
    T->root = x;
    
}

void BTreeSplitChild(BTreeNode *x, int i) {
    
    int t = x->t;
    
    BTreeNode *y = x->children[i];
    BTreeNode *z = allocateNode(t, y->leaf);
    z->n = t - 1;
    
    int j;
    
    for(j = 0; j < t-1; j++) {
        z->keys[j] = y->keys[j+t];
    }
    
    if(y->leaf == 0) {
        for(j = 0; j < t; j++) {
            z->children[j] = y->children[j+t];
        }
    }
    
    y->n = t-1;
    
    for(j = x->n; j >= i+1; j--) {
        x->children[j+1] = x->children[j];
    }
    
    x->children[i+1] = z;
    
    for(j = x->n - 1; j >= i; j--) {
        x->keys[j+1] = x->keys[j];
    }
    
    x->keys[i] = y->keys[t-1];
    
    x->n += 1;
    
}

void BTreeInsertNonFull(BTreeNode *x, Object k) {
    
    int i = x->n - 1;
    
    if(x->leaf == 1) {
        while(i >= 0 && x->keys[i] > k) {
            x->keys[i+1] = x->keys[i];
            i--;
        }
        x->keys[i+1] = k;
        x->n += 1;
    }
    else {
        while(i >= 0 && x->keys[i] > k) i--;
        if(x->children[i+1]->n == 2*x->t-1) {
            BTreeSplitChild(x, i+1);
            if(k > x->keys[i+1]) i++;
        }
        BTreeInsertNonFull(x->children[i+1], k);
    }
    
}

void BTreeInsert(BTree *T, Object k) {
    
    int t = T->t;
    
    BTreeNode *r = T->root;
    
    if(r->n == 2*t-1) {
        BTreeNode *s = allocateNode(t, 0);
        T->root = s;
        
        s->children[0] = r;
        
        BTreeSplitChild(s, 0);
        
        int i = 0;
        if (s->keys[0] < k) i++;
        BTreeInsertNonFull(s->children[i], k);
        
    }
    else {
        BTreeInsertNonFull(r, k);
    }
}

void BTreeTraverseRecurse(BTreeNode *x) {
    int i;
    
    for(i = 0; i < x->n; i++) {
        if(x->leaf == 0) BTreeTraverseRecurse(x->children[i]);
        printf("%d ", x->keys[i]);
    }
    
    if(x->leaf == 0) BTreeTraverseRecurse(x->children[i]);
}

void BTreeTraverse(BTreeNode *x) {
    
    BTreeTraverseRecurse(x);
    printf("\n");
}

int main (int argc, char *argv[]) {
    
    BTree T;
    
    BTreeCreate(&T, 3);
    
    srand(48);
    
    for (int i = 0; i<100; i++) BTreeInsert(&T, rand() % 1000);
    
    BTreeTraverse(T.root);
    
    return 0;
} 
