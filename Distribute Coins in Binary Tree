/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var distributeCoins = function(root) {
    let sum = 0;
    function helper(root){
        if(root === null)
            return 0;
        if(root.left == null && root.right == null){
            return root.val - 1;
        }
        let left = helper(root.left);
        let right = helper(root.right);
        sum += Math.abs(left) + Math.abs(right);
        return left + right + root.val - 1;
    }
    helper(root);
    return sum;
    
};
