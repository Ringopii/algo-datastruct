// Implementation of Path Count Problem using Dynamic Programming

package pathCount.DP;
import java.util.*;

public class PathCountDP
{
    public static void main(String[] args)
        {
            Scanner sc = new Scanner(System.in);
            System.out.print("Enter the Number of Rows: ");

            int row = sc.nextInt();

            System.out.print("Enter the Number of Columns: ");

            int col = sc.nextInt();
            System.out.println();

            System.out.print("Total Number of Paths: " + countPath(row, col));
            
            sc.close();
        }
        
        static long countPath(int row, int col)
        {
            if (row == 0 || col == 0)
            {
                return 0;
            }
            else
            {
                int array2D[][] = new int[row][col];
                array2D[0][0] = 1;

                for (int i = 0; i < row; i++)
                {
                    array2D[i][0] = 1;
                }

                for (int i = 0; i < col; i++)
                {
                    array2D[0][i] = 1;
                }

                for (int r = 1; r < row; r++)
                {
                    for (int c = 1; c < col; c++)
                    {
                        array2D[r][c] = array2D[r - 1][c] + array2D[r][c - 1];
                    }
                }

                return array2D[row - 1][col - 1];
            }
        }
}