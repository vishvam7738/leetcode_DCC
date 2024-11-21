// class Solution {
// public:
//     int countUnguarded(int m, int n, vector<vector<int>>& g, vector<vector<int>>& w) {
//         vector<vector<int>> vis(m, vector<int>(n, 0));
        
//         // Mark walls = 2
//         for (auto val : w) {
//             vis[val[0]][val[1]] = 2;
//         }

//         // Mark guards = 3
//         for (auto val : g) {
//             vis[val[0]][val[1]] = 3;
//         }

//         // Traverse in four directions to mark guarded cells
//         for (auto val : g) {
//             int row = val[0], col = val[1];

//             // Down
//             for (int i = row + 1; i < m; i++) {
//                 if (vis[i][col] == 2 || vis[i][col] == 3) break; // Stop at wall or guard
//                 vis[i][col] = 1; // Mark as guarded
//             }

//             // Up
//             for (int i = row - 1; i >= 0; i--) {
//                 if (vis[i][col] == 2 || vis[i][col] == 3) break;
//                 vis[i][col] = 1;
//             }

//             // Right
//             for (int i = col + 1; i < n; i++) {
//                 if (vis[row][i] == 2 || vis[row][i] == 3) break;
//                 vis[row][i] = 1;
//             }

//             // Left
//             for (int i = col - 1; i >= 0; i--) {
//                 if (vis[row][i] == 2 || vis[row][i] == 3) break;
//                 vis[row][i] = 1;
//             }
//         }

//         // Count unguarded cells
//         int unguarded = 0;
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (vis[i][j] == 0) unguarded++;
//             }
//         }

//         return unguarded;
//     }
// };


class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // Initialize grid with zeros
        int g[m][n];
        memset(g, 0, sizeof(g));
        
        // Mark guards and walls as 2
        for (auto& e : guards) {
            g[e[0]][e[1]] = 2;
        }
        for (auto& e : walls) {
            g[e[0]][e[1]] = 2;
        }
        
        // Directions: up, right, down, left
        int dirs[5] = {-1, 0, 1, 0, -1};
        
        // Process each guard's line of sight
        for (auto& e : guards) {
            for (int k = 0; k < 4; ++k) {
                int x = e[0], y = e[1];
                int dx = dirs[k], dy = dirs[k + 1];
                
                // Check cells in current direction until hitting boundary or obstacle
                while (x + dx >= 0 && x + dx < m && y + dy >= 0 && y + dy < n && g[x + dx][y + dy] < 2) {
                    x += dx;
                    y += dy;
                    g[x][y] = 1;
                }
            }
        }
        
        // Count unguarded cells (cells with value 0)
        int unguardedCount = 0;
        for (int i = 0; i < m; i++) {
            unguardedCount += count(g[i], g[i] + n, 0);
        }
        
        return unguardedCount;
    }
};
