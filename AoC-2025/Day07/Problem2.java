import java.io.FileReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.Queue;
import java.util.ArrayList;
import java.util.LinkedList;

class Pair {
    int x, y;
    Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Problem2
{
    public static void main(String[] args) {solve();}

    public static void solve()
    {
        try(BufferedReader br = new BufferedReader(new FileReader("Day07/input.txt")))
        {   
            String line;
            ArrayList<String> grid = new ArrayList<>();

            while((line = br.readLine()) != null) grid.add(line);

            int M = grid.size(), N = grid.get(0).length();

            int sx = -1, sy = -1;
            for(int i=0;i<M;i++){
                boolean found = false;

                for(int j=0;j<N;j++){
                    if(grid.get(i).charAt(j) == 'S'){
                        sx = i; sy = j;
                        found = true;
                        break;
                    }
                }

                if(found) break;
            }

            ArrayList<ArrayList<Boolean>> seen = new ArrayList<>();
            for(int i=0;i<M;i++){
                ArrayList<Boolean> row = new ArrayList<>();
                for(int j=0;j<N;j++){
                    row.add(false);
                }
                seen.add(row);
            }

            Queue<Pair> Q = new LinkedList<>();
            Q.add(new Pair(sx, sy));
            seen.get(sx).set(sy, true);

            while(! Q.isEmpty()){
                Pair f = Q.poll();

                if(!in(f.x + 1, f.y + 1, M, N) || seen.get(f.x+1).get(f.y)) continue;

                if(grid.get(f.x+1).charAt(f.y) == '^'){
                    if(in(f.x + 1, f.y - 1, M, N)){
                        Q.add(new Pair(f.x+1, f.y - 1));
                        seen.get(f.x+1).set(f.y - 1, true);
                    }
                    if(in(f.x + 1, f.y + 1, M, N)){
                        Q.add(new Pair(f.x+1, f.y + 1));
                        seen.get(f.x+1).set(f.y + 1, true);
                    }
                }
                else{
                    Q.add(new Pair(f.x+1, f.y));
                    seen.get(f.x+1).set(f.y, true);
                }
            }

            ArrayList<ArrayList<Long>> timelines = new ArrayList<>();

            for(int i=0;i<M;i++){
                ArrayList<Long> row = new ArrayList<>();
                for(int j=0;j<N;j++){
                    if(i == M-1 && seen.get(i).get(j)) row.add(1L);
                    else row.add(0L);
                }
                timelines.add(row);
            }

            for(int i = M - 1; i >= sx; i--){
                for(int j = 0; j < N; j++){
                    if(!seen.get(i).get(j)) continue;

                    // left diagonal
                    if(in(i+1, j-1, M, N) && seen.get(i+1).get(j-1) && grid.get(i+1).charAt(j) == '^'){
                        timelines.get(i).set(j, timelines.get(i).get(j) + timelines.get(i+1).get(j-1));
                    }
                    // right diagonal
                    if(in(i+1, j+1, M, N) && seen.get(i+1).get(j+1) && grid.get(i+1).charAt(j) == '^'){
                        timelines.get(i).set(j, timelines.get(i).get(j) + timelines.get(i+1).get(j+1));
                    }
                    // straight down
                    if(in(i+1, j, M, N) && seen.get(i+1).get(j)){
                        timelines.get(i).set(j, timelines.get(i).get(j) + timelines.get(i+1).get(j));
                    }
                }
            }

            long ans = timelines.get(sx).get(sy) + 1;

            System.out.println(ans);
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }

    public static boolean in(int x, int y, int m, int n){ return x >= 0 && y >=0 && x < m && y < n;}
}