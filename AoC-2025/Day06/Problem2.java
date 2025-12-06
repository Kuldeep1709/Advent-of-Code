import java.io.FileReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.ArrayList;

public class Problem2
{
    public static void main(String[] args) {solve();}

    public static void solve()
    {
        try(BufferedReader br = new BufferedReader(new FileReader("Day06/input.txt")))
        {   
            String line;
            long ans = 0;
            ArrayList<String> arr = new ArrayList<>();

            while((line = br.readLine()) != null) arr.add(line);

            int m = arr.size(), n = arr.get(0).length();

            boolean add = true;
            long pro = 0, sum = 0;

            for(int j=0;j<n;j++){
                StringBuilder curr = new StringBuilder();

                if(arr.get(m-1).charAt(j) == '+') add = true;
                if(arr.get(m-1).charAt(j) == '*') add = false;

                for(int i=0;i<m-1;i++){
                    if(arr.get(i).charAt(j) != ' '){
                        curr.append(arr.get(i).charAt(j));
                    }
                }

                if(curr.length() == 0){
                    ans += pro; ans += sum;
                    pro = 0; sum = 0;
                    continue;
                }

                if(add) sum += Long.parseLong(curr.toString());
                else{
                    pro = Math.max(pro, 1);
                    pro *= Long.parseLong(curr.toString());
                }
            }
            
            ans += pro; ans += sum;

            System.out.println(ans);
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }
}