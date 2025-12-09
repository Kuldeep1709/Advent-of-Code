import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.io.BufferedReader;

class Pair {
    long x, y;
    Pair(long x, long y) {
        this.x = x;
        this.y = y;
    }
}

public class Problem1
{
    public static void main(String[] args) {solve();}

    public static void solve()
    {
        try(BufferedReader br = new BufferedReader(new FileReader("Day09/input.txt")))
        {
            String line;
            ArrayList<Pair> points = new ArrayList<>();

            while((line = br.readLine()) != null){
                int idx = line.indexOf(',');

                int x = Integer.parseInt(line.substring(0,idx).trim());
                int y = Integer.parseInt(line.substring(idx+1).trim());

                points.add(new Pair(x,y));
            }

            long ans = 0;
            int n = points.size();

            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    long length = (Math.abs(points.get(i).x - points.get(j).x) + 1);
                    long breadth = (Math.abs(points.get(i).y - points.get(j).y) + 1);

                    ans = Math.max(ans, length * breadth);
                }
            }
            
            System.out.println(ans);
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }
}