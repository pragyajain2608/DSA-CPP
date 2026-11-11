/*
Problem: LeetCode 2326 - Spiral Matrix IV

Approach: Direction Array + Simulation

Time Complexity: O(m * n)
Space Complexity: O(m * n) - Output matrix

Initialize an m x n matrix with -1 to represent empty cells.

Use a direction array to traverse the matrix in spiral order:
Right → Down → Left → Up.

Start from (0,0) and fill each cell with the current
linked list node's value.

Calculate the next position using the current direction.
If the next position is out of bounds or already filled,
change direction using (d + 1) % 4.

Continue until all linked list nodes are placed.
Unfilled cells remain -1.

Return the resulting matrix.
*/
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {

        vector<vector<int>> ans(m, vector<int>(n, -1));

        int dir[4][2] = {
            {0, 1},   // Right
            {1, 0},   // Down
            {0, -1},  // Left
            {-1, 0}   // Up
        };

        int row = 0, col = 0;
        int d = 0;

        while(head != NULL) {

            ans[row][col] = head->val;
            head = head->next;

            int nr = row + dir[d][0];
            int nc = col + dir[d][1];

            if(nr < 0 || nr >= m || nc < 0 || nc >= n || ans[nr][nc] != -1) {
                d = (d + 1) % 4;

                nr = row + dir[d][0];
                nc = col + dir[d][1];
            }

            row = nr;
            col = nc;
        }

        return ans;
    }
};
