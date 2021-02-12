/*
 * @Author: kcqnly 
 * @Date: 2021-02-12 17:57:00 
 * @Last Modified by: kcqnly
 * @Last Modified time: 2021-02-12 17:58:03
 * @Message: leetcode-1351
 */

// 执行时间击败 100.0%
class Solution {
    public int countNegatives(int[][] grid) {
        int cnt=0;
        for (int i = 0; i < grid.length; i++) {
            int l = 0, r = grid[i].length - 1;
            while (l < r) {
                int mid = (l + r )/2;
                if (grid[i][mid] < 0) r = mid;
                else l = mid+1;
            }
            // 说明没有负数
            if(grid[i][l]>=0);
            else cnt+=grid[i].length-l;
        }
        return cnt;
    }
}