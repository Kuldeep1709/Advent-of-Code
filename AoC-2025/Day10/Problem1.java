import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.io.BufferedReader;

public class Problem1
{
    public static void main(String[] args) {solve();}

    public static void solve()
    {
        try(BufferedReader br = new BufferedReader(new FileReader("Day10/input.txt")))
        {
            String line;
            long ans = 0;

            while((line = br.readLine()) != null){
                int idx1 = line.indexOf('['), idx2 = line.indexOf(']');
                
                String tar = (line.substring(idx1+1, idx2));
                int target = 0;

                for(int i=tar.length()-1;i>=0;i--){
                    if(tar.charAt(i) == '.') target = target*2;
                    else target = target*2 + 1;
                }

                String curr = line.substring(idx2 + 1);
                ArrayList<Integer> nums = new ArrayList<>();

                while(curr.indexOf('(') != -1) {
                    int start = curr.indexOf('(');
                    int end = curr.indexOf(')');

                    String inside = curr.substring(start + 1, end);

                    String[] tokens = inside.split(",");

                    int num = 0;
                    for (String t : tokens) num += (1<<(Integer.parseInt(t.trim())));
                    nums.add(num);
                    
                    curr = curr.substring(end + 1);
                }

                ans += bruteForce(nums, target, 0, 0, 0);
            }
            
            System.out.println(ans);
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }

    public static int bruteForce(ArrayList<Integer> nums, int target, int idx, int xor, int len){
        if(idx == nums.size()){
            if(len > 0 && xor == target) return len;
            return Integer.MAX_VALUE;
        }

        int include = bruteForce(nums, target, idx+1, xor^nums.get(idx), len+1);
        int notInclude = bruteForce(nums, target, idx+1, xor, len);

        return Math.min(include, notInclude);
    }
}