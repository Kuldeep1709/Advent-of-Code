import java.io.FileReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.ArrayList;

public class Problem1
{
    public static void main(String[] args) {solve();}

    public static void solve()
    {
        try(BufferedReader br = new BufferedReader(new FileReader("Day05/input.txt")))
        {   
            String line;
            ArrayList<ArrayList<Long>> ranges = new ArrayList<>();
            long ans = 0;

            while((line = br.readLine()) != null){
                if(line.isEmpty()) break;

                int idx = line.indexOf('-');
                long a = Long.parseLong(line.substring(0,idx));
                long b = Long.parseLong(line.substring(idx+1));

                ArrayList<Long> pair = new ArrayList<>();
                pair.add(a);pair.add(b);

                ranges.add(pair);
            }

            while((line = br.readLine()) != null){
                if(line.isEmpty()) break;
                
                long c = Long.parseLong(line);

                for(ArrayList<Long> range: ranges){
                    if(range.get(0) <= c && c <= range.get(1)){
                        ans++;
                        break;
                    }
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