import java.util.*;


class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class Solution {
    private Map<Integer, Integer> indexMap;

    public TreeNode myBuildTree(int[] preorder, int[] inorder, int preorderLeft, int preorderRight, int inorderLeft, int inorderRight) {
        if(preorderLeft>preorderRight || inorderLeft>inorderRight)return null;
        // 拿到根节点
        int preRoot = preorderLeft;
        // 中序根节点
        int inOrderRoot = indexMap.get(preorder[preorderLeft]);
        TreeNode root = new TreeNode(preorder[preorderLeft]);
        // 左子树的大小
        int sizeLeftSubTree = inOrderRoot-inorderLeft;
       root.left= myBuildTree(preorder,inorder,preorderLeft+1,preorderLeft+sizeLeftSubTree,inorderLeft,inOrderRoot-1);
       root.right=myBuildTree(preorder,inorder,preorderLeft+sizeLeftSubTree+1,preorderRight,inOrderRoot+1,inorderRight);
       return root;
    }


    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if(preorder.length==0 || inorder.length==0)return null;
        indexMap=new HashMap<>();
        int n=preorder.length;
        for(int i=0;i<preorder.length;i++){
            indexMap.put(inorder[i],i);
        }
       return myBuildTree(preorder,inorder,0,n-1,0,n-1);
    }
}