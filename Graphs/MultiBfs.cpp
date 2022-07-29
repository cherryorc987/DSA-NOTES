/*
    https://leetcode.com/problems/as-far-from-land-as-possible/
    good multisource bfs question.
    push all nodes with ones and then calulating distances inplace.
*/
int maxDistance(vector<vector<int>>& grid) {
		int locMax = 0;
		queue<pair<int, int>> q;
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[i].size(); ++j) {
				if (grid[i][j] == 1) q.push({ i, j });
			}
		}
		while (!q.empty()) {
			pair<int, int> cur = q.front();
			q.pop();
			pair<int, int> dirs[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
			for (auto dir : dirs) {
				int nx = dir.first + cur.first;
				int ny = dir.second + cur.second;
				if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == 0) {
					q.push({ nx, ny });
					grid[nx][ny] = grid[cur.first][cur.second] + 1;    //min distance from a 1 to reach current 0.
					locMax = max(grid[nx][ny], locMax);
				}
			}
		}
		return (locMax > 0 ? locMax-1 : -1);
}

/*
    https://leetcode.com/problems/rotting-oranges/
    multisource bfs question again.
    done till last node is reached.
*/
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1)
                    cnt++;
            }
        }
        int ans=0;
        while(!q.empty()){
            int k=q.size();
            int flag=0;
            while(k--){
                pair<int,int> x=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nx=x.first+dx[i];
                    int ny=x.second+dy[i];
                    if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1){
                        q.push({nx,ny});
                        grid[nx][ny]=2;
                        flag++;
                        cnt--;
                    }
                }
            }
            if(flag)
                ans++;
        }
        if(cnt)
            return -1;
        return ans;
}