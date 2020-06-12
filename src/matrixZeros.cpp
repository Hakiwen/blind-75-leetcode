class Solution {
public:
    void printMatrix(const vector<vector<int>>& matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i =0;i<n;++i){
            for(int j =0;j<m;++j){
                cout << matrix[i][j] << ",";
            }
            cout << endl;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int rstore = -1;
        int cstore = -1;
        for(int i = 0;i<n;++i){
            for(int j=0;j<m;++j){
                if(!matrix[i][j]){
                    if( (rstore == -1) && (cstore == -1)){
                        rstore = i;
                        cstore = j;
                    }
                    else{
                        matrix[rstore][j] = 0;
                        matrix[i][cstore] = 0;
                    }
                    
                }
            }
        }
        // cout << rstore << ", " << cstore << endl;
        // this->printMatrix(matrix);
        if(cstore != -1){
            for(int i = 0; i < n;++i){
                if(matrix[i][cstore] == 0 && i!= rstore){
                    for(int j=0;j<m;++j){
                        matrix[i][j] = 0;
                    }
                }
            }   
        // this->printMatrix(matrix);
            for(int i =0; i<m;++i){
                if(matrix[rstore][i] == 0 && i!= cstore){
                    for(int j=0;j<n;++j){
                        matrix[j][i] = 0;
                    }
                }
            }
            // this->printMatrix(matrix);
            for(int i=0;i<n;++i){
                matrix[i][cstore] = 0;
            }
            for(int j=0;j<m;++j){
                matrix[rstore][j] = 0;
            }
        }
      
    }
};
