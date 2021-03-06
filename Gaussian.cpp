int gaussian(vector<vector<int>>&v, int n){
    int ans = 1;
    for(int j = 0; j < n - 1; j++){
        for(int k = 1 + j; k < n; k++){
            int x = v[k][j];
            int y = v[j][j];
            for(int i = 0; i < n - j; i++){
                v[k][j + i] = ((v[k][j + i] * y) % M - (v[j][j + i] * x) % M + M) % M;
                v[k][j + i] = (v[k][j + i] * power(y, M - 2, M)) % M;
            }
        }
    }
    for(int i = 0; i < n; i++){
        ans = ans * v[i][i];
        ans %= M;
    }
    return ans;
}
