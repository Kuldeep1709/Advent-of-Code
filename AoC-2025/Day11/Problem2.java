import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.util.Map;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Objects;

class State {
    String s;
    boolean b1;
    boolean b2;

    State(String s, boolean b1, boolean b2) {
        this.s = s;
        this.b1 = b1;
        this.b2 = b2;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof State)) return false;
        State st = (State) o;
        return b1 == st.b1 && b2 == st.b2 && s.equals(st.s);
    }

    @Override
    public int hashCode() {
        return Objects.hash(s, b1, b2);
    }
}


public class Problem2
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

            Map<State, Long> dp = new HashMap<>();

            long ans = dfs(adj, "svr", "out", false, false, dp);
            
            System.out.println(ans);
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }

    public static long dfs(Map<String, ArrayList<String>> adj, String curr, String target, boolean dac, boolean fft, Map<State, Long> dp){
        if(curr.equals(target)){
            if(dac && fft) return 1L;
            return 0L;
        }

        State key = new State(curr, dac, fft);

        if(dp.containsKey(key)) return dp.get(key);

        
        if(curr.equals("dac")) dac = true;
        if(curr.equals("fft")) fft = true;

        long ans = 0;
        for(String next: adj.get(curr)) ans += dfs(adj, next, target, dac, fft, dp);

        dp.put(key, ans);

        return ans;
    }
}