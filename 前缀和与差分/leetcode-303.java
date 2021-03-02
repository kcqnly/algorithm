class NumArray {
    int[] s;
    public NumArray(int[] nums) {
        int n=nums.length;
        s = new int[n+1];
        for(int i=1;i<=n;i++){
            s[i]=s[i-1]+nums[i-1];
        }
    }

    public int sumRange(int i, int j) {
        return s[j+1]-s[i];
    }
}