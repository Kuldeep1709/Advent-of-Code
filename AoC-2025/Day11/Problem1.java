import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.util.Map;
import java.util.Arrays;
import java.util.HashMap;

public class Problem1
{
    public static void main(String[] args) {solve();}

    public static void solve()
    {
        try(BufferedReader br = new BufferedReader(new FileReader("Day11/input.txt")))
        {
            String line;
            Map<String, ArrayList<String>> adj = new HashMap<>();

            while((line = br.readLine()) != null){
               int idx = line.indexOf(':');

               String root = line.substring(0, idx).trim();
               
               String[] tokens = line.substring(idx+1).trim().split("\\s+");
               ArrayList<String> childs = new ArrayList<>(Arrays.asList(tokens));

               adj.put(root, childs);
            }

            long ans = dfs(adj, "you", "out");
            
            System.out.println(ans);
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }

    public static long dfs(Map<String, ArrayList<String>> adj, String curr, String target){
        if(curr.equals(target)) return 1;

        long ans = 0;
        for(String next: adj.get(curr)) ans += dfs(adj, next, target);

        return ans;
    }
}