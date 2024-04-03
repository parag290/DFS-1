// Apporach 1 : BFS
// Time Complexity : O(n * m) 
// Space Complexity : O(n * m)
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this :
/*
Leetcode : https://leetcode.com/problems/01-matrix/description/

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.
*/


/**
 * Approach 1 : BFS
*/


class Solution {
    vector<vector<int>>dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        queue<vector<int>>q;
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                } else {
                    mat[i][j] = -1;
                }
            }
        }
        int val = 0;

        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                vector<int>temp = q.front();
                q.pop();
                int ci = temp[0];
                int cj = temp[1];
                for(auto &pair : dir){
                    int ni = ci + pair[0];
                    int nj = cj + pair[1];
                    if(ni >= 0 && nj >= 0 && ni < mat.size() && nj < mat[0].size() && mat[ni][nj] == -1){
                        q.push({ni, nj});
                        mat[ni][nj] = val +1;
                    }
                }
            }
            val++;
        }
        return mat;
    }
};