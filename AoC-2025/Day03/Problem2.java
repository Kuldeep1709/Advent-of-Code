import java.io.FileReader;
import java.io.IOException;
import java.io.BufferedReader;

public class Problem2
{
    public static void main(String[] args) {solve();}

    public static void solve()
    {
        try(BufferedReader br = new BufferedReader(new FileReader("Day03/input.txt")))
        {   
            String line;
            long ans = 0;

            while((line = br.readLine()) != null) ans += max_number(line, 0, 12);

            System.out.println(ans);
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }

    public static long max_number(String line, int idx, int len)
    {   
        int n = line.length();

        if(idx >= n || len <= 0) return 0;

        int max_idx = idx;
        for(int i=idx+1;i <= n-len;i++){
            if(line.charAt(i) > line.charAt(max_idx)){
                max_idx = i;
            }
        }

        long ans = max_number(line, max_idx+1, len-1);
        ans += (long)(Math.pow(10, len-1))*(line.charAt(max_idx) - '0');

        return ans;
    }
}