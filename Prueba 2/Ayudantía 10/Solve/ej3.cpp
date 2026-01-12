TreeNode* buildTree(vector& preorder, vector& inorder) {
    if (preorder.empty() || inorder.empty()) {
        return nullptr;
    }
    
    // El primer elemento del preorder es la raíz
    int rootVal = preorder[0];
    TreeNode* root = new TreeNode(rootVal);
    
    // Encontrar la posición de la raíz en inorder
    int rootIndex = 0;
    for (int i = 0; i < inorder.size(); i++) {
        if (inorder[i] == rootVal) {
            rootIndex = i;
            break;
        }
    }
    
    // Dividir inorder en izquierda y derecha
    vector leftInorder(inorder.begin(), inorder.begin() + rootIndex);
    vector rightInorder(inorder.begin() + rootIndex + 1, inorder.end());
    
    // Dividir preorder en izquierda y derecha
    vector leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + leftInorder.size());
    vector rightPreorder(preorder.begin() + 1 + leftInorder.size(), preorder.end());
    
    // Construir recursivamente subárboles
    root->left = buildTree(leftPreorder, leftInorder);
    root->right = buildTree(rightPreorder, rightInorder);
    
    return root;
}