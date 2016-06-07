// TreeFun.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <string>

class Leaf
{
public:
   Leaf(int value) { left = NULL; right = NULL; depth = value; }
   ~Leaf() {}
   Leaf* left;
   Leaf* right;
   int depth;
};

class Tree
{
public:
   Tree() { root = NULL; }
   ~Tree() {}
   void fillTree(int maxDepth);
   void traverseTree();
private:
   void recursiveFill(Leaf* branch, int currDepth, int maxDepth);
   void recursiveTraverse(Leaf* branch);
   Leaf* root;
};

void Tree::fillTree(int maxDepth)
{
   // Tree will only be filled once for now
   if (root == NULL)
   {
      root = new Leaf(0);
      recursiveFill(root, 1, maxDepth);
   }
}

void Tree::recursiveFill(Leaf* branch, int currDepth, int maxDepth)
{
   // Check for an empty left leaf off the branch and make sure not to surpass the max depth
   if ((branch->left == NULL) && (currDepth < maxDepth))
   {
      branch->left = new Leaf(currDepth);
      recursiveFill(branch->left, (currDepth + 1), maxDepth);
   }
   // Check for an empty right leaf off the branch and make sure not to surpass the max depth
   if ((branch->right == NULL) && (currDepth < maxDepth))
   {
      branch->right = new Leaf(currDepth);
      recursiveFill(branch->right, (currDepth + 1), maxDepth);
   }
}


void Tree::traverseTree()
{
   std::cout << "Root: " << root->depth;
   recursiveTraverse(root);
   std::cout << std::endl;
}

void Tree::recursiveTraverse(Leaf* branch)
{
   // Traverse down the left branches first
   if (branch->left != NULL)
   {
      std::cout << " Left: " << branch->left->depth;
      recursiveTraverse(branch->left);
   }
   // Then traverse down the right branches
   if (branch->right != NULL)
   {
      std::cout << " Right: " << branch->right->depth;
      recursiveTraverse(branch->right);
   }
}

int main()
{
   Tree tree;
   tree.fillTree(4);
   tree.traverseTree();
   system("PAUSE");
    return 0;
}

/*
                O0
        L1              R1
    L2      R2      L2      R2
  L3  R3  L3  R3  L3  R3  L3  R3
*/