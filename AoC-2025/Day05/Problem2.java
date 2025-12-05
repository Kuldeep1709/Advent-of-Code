import java.io.FileReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.ArrayList;
import java.util.Collections;

public class Problem2
{
    public static void main(String[] args) {solve();}

    public static void solve()
    {
        try(BufferedReader br = new BufferedReader(new FileReader("Day05/input.txt")))
        {   
            String line;
            ArrayList<ArrayList<Long>> ranges = new ArrayList<>();

            while((line = br.readLine()) != null){
                if(line.isEmpty()) break;

                int idx = line.indexOf('-');
                long a = Long.parseLong(line.substring(0,idx));
                long b = Long.parseLong(line.substring(idx+1));

                ArrayList<Long> pair = new ArrayList<>();
                pair.add(a);pair.add(b);

                ranges.add(pair);
            }

            Collections.sort(ranges, (r1, r2) -> Long.compare(r1.get(0), r2.get(0)));

            long ans = 0;
            int n = ranges.size();
            long left = ranges.get(0).get(0), right = ranges.get(0).get(1);

            ArrayList<Long> inf = new ArrayList<>();
            inf.add(Long.MAX_VALUE); inf.add(Long.MAX_VALUE);
            ranges.add(inf);

            for(int i=1;i<=n;i++){
                if(right < ranges.get(i).get(0)){
                    ans += (right - left + 1);
                    left = ranges.get(i).get(0);
                    right = ranges.get(i).get(1);
                }
                else{
                    left = Math.min(left, ranges.get(i).get(0));
                    right = Math.max(right, ranges.get(i).get(1));
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