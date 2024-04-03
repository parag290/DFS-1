// Apporach 1 : BFS
// Time Complexity : O(n * m) 
// Space Complexity : O(n * m)
//
// Apporach 2 : DFS
// Time Complexity : O(n * m) 
// Space Complexity : O(n * m)
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this :
/*
Leetcode : https://leetcode.com/problems/flood-fill/description/

An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].
To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the 
same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.
Return the modified image after performing the flood fill.
*/


/**
 * Apporach : BFS
 * 
*/


class Solution {
    vector<vector<int>>dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color){
            return image;
        }
        int val = image[sr][sc];

        queue<vector<int>>q;
        q.push({sr, sc});

        while(!q.empty()){
            vector<int>temp = q.front();
            q.pop();
            int i = temp[0];
            int j = temp[1];
            image[i][j] = color;
            for(auto &pair : dir){
                int ni = i + pair[0];
                int nj = j + pair[1];

                if(ni >= 0 && nj >= 0 && ni < image.size() && nj < image[0].size() && image[ni][nj] == val){
                    image[ni][nj] = color;
                    q.push({ni, nj});
                }
            }
        }
        return image;
    }
};


/**
 * 
 * Approach 2 : DFS
 * 
*/

class Solution {
    vector<vector<int>>dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color){
            return image;
        }
        int val = image[sr][sc];

        dfs(image, sr, sc, color, val);
        return image;
    }

    void dfs (vector<vector<int>>& image, int i, int j, int color, int val){
        if(i >= image.size() || j >= image[0].size() || i < 0 || j < 0 || image[i][j] != val) {
            return;
        }

        image[i][j] = color;

        for(auto &pair : dir){
            int ni = i + pair[0];
            int nj = j + pair[1];
            dfs(image, ni, nj, color, val);
        }
    }
};