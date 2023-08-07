//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends


class Solution 
{
    public:
    //id Safe function
    bool isSafe(int val,int row,int col,int grid[N][N]){
        for(int i=0;i<N;i++){
            // for row
            if(grid[row][i]==val){
                return false;
            }
            //for col
            if(grid[i][col]==val){
                return false;
            }
            //for particular grid
            if(grid[3*(row/3)+i/3][3*(col/3)+i%3]==val){
                return false;
            }
        }
        return true;
    }
    //Function to find a solved Sudoku. 
    bool solve(int grid[N][N]){
        for(int row=0; row<N; row++){
            for(int col=0;col<N; col++){
                //if empty slot
                if(grid[row][col]==0){
                    for(int val=1;val<=9;val++){
                        if(isSafe(val,row,col,grid)){
                            grid[row][col]=val;
                            bool temp=solve(grid);
                            if(temp==true){
                                return true;
                            }
                            else{
                                grid[row][col]=0;
                                // return false;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        solve(grid);
        //printGrid(grid);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<grid[i][j]<<" ";
            
        }
      }
    }
};


//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends