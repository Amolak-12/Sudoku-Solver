#include <iostream>
#include <vector>
using namespace std;


  int arr[9][9]=
  {
  {4,5,0,0,0,0,0,0,0}, //Row 0
  {0,0,2,0,7,0,6,3,0}, //Row 1
  {0,0,0,0,0,0,0,2,8}, //Row 2
  {0,0,0,9,5,0,0,0,0}, //Row 3
  {0,8,6,0,0,0,2,0,0}, //Row 4
  {0,2,0,6,0,0,7,5,0}, //Row 5
  {0,0,0,0,0,0,4,7,6}, //Row 6
  {0,7,0,0,4,5,0,0,0}, //Row 7
  {0,0,8,0,0,9,0,0,0}  //Row 8
 };

bool isSafe(int value, int row, int col)
{
 

  for(int i=0;i<9;i++)
    {
       //Step 1 : Row Check
      if(arr[row][i]==value)
      {
        return false;
      }
      //Step 2 : Column Check
      if(arr[i][col]==value)
      {
        return false;
      }
      //Step 3 : 3*3 Board Check
      for(int j=0;j<9;j++)
      {
        if(arr[3*(row/3) + (i/3)][3*(col/3) + (i%3)] == value)
        {
          return false;
        }

      }
    }
  return true;
}
bool SudokuSolver( int n)
{
  //Step 1 : Outer Loop
  for(int i=0;i<n;i++)
    {
      //Step 2 : Inner Loop
      for(int j=0;j<n;j++)
        {
          //Sub step 1
          //Check for empty cell
          if(arr[i][j]==0)
          {
            //Step 1
            for(int value=1;value<=9;value++)
              {
                //Sub Step 1
                //Check is the current cell safe
                if(isSafe(value,  i, j))
                {
                  //Step 1
                  //Place the value
                  arr[i][j]=value;
                  //Step 2
                  //Recursive Call
                  bool FurtherSolution =  SudokuSolver( n);
                  //Step 3
                  //Condition Check
                  if(FurtherSolution == true)
                  {
                    return true;
                  }
                  else
                  {
                  //Backtracking
                  arr[i][j]=0;
                  }
                }
                
              }
            return false;
          }
        }
    }
  return true;
}
int main() {

  int n = 9;

  bool ans = SudokuSolver( n);
  cout << ans << endl;

  for(int i=0;i<n;i++)
    {
      for(int j=0;j<9;j++)
        {
          cout << arr[i][j] << " ";
        }
      cout << endl;
    }

}