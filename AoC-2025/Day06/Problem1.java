import java.io.FileReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.ArrayList;

public class Problem1
{
    public static void main(String[] args) {solve();}

    public static void solve()
    {
        try(BufferedReader br = new BufferedReader(new FileReader("Day06/input.txt")))
        {   
            String line;
            long ans = 0;
            ArrayList<ArrayList<Long>> arr = new ArrayList<>();

            while((line = br.readLine()) != null){
                if(line.charAt(0) == '+' || line.charAt(0) == '*'){
                    int index = 0, m = arr.size(), n = line.length();                    

                    for(int j=0;j<n;j++){
                        if(line.charAt(j) == '+'){
                            long sum = 0;
                            for(int i=0;i<m;i++) sum += arr.get(i).get(index);
                            
                            ans += sum;
                            index++;
                        }
                        else if(line.charAt(j) == '*'){
                            long pro = 1;
                            for(int i=0;i<m;i++) pro *= arr.get(i).get(index);
                            
                            ans += pro;
                            index++;
                        }
                    }
                }
                else{
                    int m = line.length();
                    ArrayList<Long> row = new ArrayList<>();
                    StringBuilder curr = new StringBuilder();

                    for(int j=0;j<m;j++){
                        if(line.charAt(j) == ' '){
                            if(curr.length() != 0) row.add(Long.parseLong(curr.toString()));

                            curr = new StringBuilder();
                            continue;
                        }
                        else curr.append(line.charAt(j));
                    }

                    if(curr.length() != 0) row.add(Long.parseLong(curr.toString()));

                    arr.add(row);
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