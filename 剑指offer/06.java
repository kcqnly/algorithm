
class Solution {
    public int[] reversePrint(ListNode head) {
        ListNode temp = head;
        Stack<ListNode> stack=new Stack<>();
        while (temp != null) {
            stack.push(temp);
            temp=temp.next;
        }
        int n=stack.size();
        int[] res = new int[n];
        for(int i=0;i<n;i++){
            res[i]=stack.pop().val;
        }
        return res;
    }
}