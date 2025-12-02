import java.io.FileReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.ArrayList;

class Range
{

    int minShift;
    String prefix, left, right;

    Range (StringBuilder sb)
    {
        String range = sb.toString();
        int idx = range.indexOf("-");
        
        this.left = range.substring(0,idx);
        this.right = range.substring(idx+1);
        
        int index = 0;
        while(index < left.length() && left.charAt(index) == right.charAt(index)) index++;

        this.prefix = left.substring(0,index);
        this.minShift = left.length() - prefix.length();
    }
}

public class Problem1
{
    public static void main(String[] args) {solve();}

    public static void solve()
    {
        try(BufferedReader br = new BufferedReader(new FileReader("Day02/input.txt")))
        {   
            String line = br.readLine();
            ArrayList<Range> ranges = parseLine(line);

            long ans = 0;

            for(Range rng: ranges){
                long l = Long.parseLong(rng.left);
                long r = Long.parseLong(rng.right);

                for(long n = l; n <= r; n++){
                    String suffix = Long.toString(n);
                    while (suffix.length() < rng.minShift) suffix = "0" + suffix;

                    long num = Long.parseLong(suffix);

                    if (invalid(num)) ans += num;
                }

            }

            System.out.println(ans);
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }

    public static boolean invalid(long num)
    {   
        
        String s = Long.toString(num);
        int n = s.length();

        if(n%2 == 1) return false;

        for(int i=0;i<n/2;i++){
            if(s.charAt(i) != s.charAt(i+n/2)) return false;
        }

        return true;
    }

    public static ArrayList<Range> parseLine(String line)
    {
        ArrayList<Range> arr = new ArrayList<>();
        StringBuilder range = new StringBuilder();
        int n = line.length(), prev = 0;

        for(int i=0;i<=n;i++){
            if(i == n || line.charAt(i) == ','){
                arr.add(new Range(range));
                range = new StringBuilder();
            }
            else range.append(line.charAt(i));
        }

        return arr;
    }
}