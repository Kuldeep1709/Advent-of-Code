import java.io.FileReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.ArrayList;

public class Problem2
{
    public static void main(String[] args) {solve();}

    public static void solve()
    {
        try(BufferedReader br = new BufferedReader(new FileReader("Day04/input.txt")))
        {   
            String line;
            ArrayList<String> grid = new ArrayList<>();
            long ans = 0;

            while((line = br.readLine()) != null) grid.add(line);

            int M = grid.size(), N = grid.get(0).length();
            int[][] dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
            ArrayList<ArrayList<Boolean>> seen = new ArrayList<>();

            for(int i=0;i<M;i++){
                ArrayList<Boolean> row = new ArrayList<>();
                for(int j=0;j<N;j++){
                    row.add(false);
                }
                seen.add(row);
            }

            while(true){
                int count = 0;
                for(int i=0;i<M;i++){
                    for(int j=0;j<N;j++){
                        if(grid.get(i).charAt(j) != '@' || seen.get(i).get(j)) continue;

                        int neigh = 0;

                        for(int[] d: dirs){
                            int di = d[0], dj = d[1];

                            if(in(i+di, j+dj, M, N) && grid.get(i+di).charAt(j+dj) == '@' && !seen.get(i+di).get(j+dj)){
                                neigh++;
                            }
                        }

                        if(neigh < 4){
                            count++;
                            seen.get(i).set(j, true);
                        }
                    }
                }
                
                if(count == 0) break;
                ans += count;
            }
                

            System.out.println(ans);
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }

    public static boolean in(int x, int y, int m, int n){ return x >= 0 && y >=0 && x < m && y < n;}
}