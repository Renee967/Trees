# Trees

1. Implement a function that will build a binary search tree.

2. Using the function above create a binary search tree.

3. Implement a swapSubtrees() function that will take a pointer to a root node and a target value. Function will search for the target value in the tree and swap all left nodes with right nodes for all descendant  nodes.

4. Pass the tree created in step 2 to test swapSubtrees() function.

5. You can use the inorder, postorder or preorder traversal implemented in class to display and confirm the logic. (trace it by hand as well)

6. (Extra credit) Create a display function which will take a pointer to a root node and display the tree in a tree form

TreeNode{

   int val;

   TreeNode* left = nullptr;

   TreeNode* right = nullptr;

   TreeNode(){}

   TreeNode(int val): val(val){}

};
