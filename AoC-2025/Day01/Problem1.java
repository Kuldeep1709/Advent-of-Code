import java.io.FileReader;
import java.io.IOException;
import java.io.BufferedReader;

public class Problem1
{
    public static void main(String[] args)
    {
        try(BufferedReader br = new BufferedReader(new FileReader("Day01/input.txt")))
        {
            String line;
            int ans = 0, pos = 50;

            while((line = br.readLine()) != null)
            {
                char dir = line.charAt(0);
                int steps = Integer.parseInt(line.substring(1));

                if(dir == 'L') pos = (pos - steps + 100)%100;
                else pos = (pos + steps)%100;

                if(pos == 0) ans++;
            }

            System.out.println(ans);
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }
}