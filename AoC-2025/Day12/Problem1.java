import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// I just tried fitting all shapes without overlapping it worked on the INPUT :)

public class Problem1
{
    public static void main(String[] args) {solve();}

    public static void solve()
    {
        try(BufferedReader br = new BufferedReader(new FileReader("Day12/input.txt")))
        {
            String line;
            long ans = 0;

            while((line = br.readLine()) != null){
                if(line.length() < 1 || line.indexOf('x') == -1) continue;

                int idx = line.indexOf(':');
                String dims = line.substring(0, idx);
                String nums = line.substring(idx+1);

                String[] dimParts = dims.split("x");
                int length = Integer.parseInt(dimParts[0]);
                int breadth = Integer.parseInt(dimParts[1]);

                int count = 0;
                StringTokenizer st = new StringTokenizer(nums);
                while (st.hasMoreTokens()) count += Integer.parseInt(st.nextToken());

                if((length/3 * breadth/3) >= count) ans++;                
            }
            
            System.out.println(ans);
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }      
}