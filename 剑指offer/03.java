class Solution {
    public int findRepeatNumber(int[] nums) {
        int[] count =new int[nums.length];
        for(int i=0;i<nums.length;i++){
            count[nums[i]]++;
        }
        int index=0;
        for(int i=0;i<nums.length;i++){
            if(count[i]==0||count[i]==1) continue;
            else{
                 index=i;
                 break;
            }
        }
        return index;
    }
}