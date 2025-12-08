import java.io.FileReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.Queue;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Collections;

class Point {
    int x, y, z;
    Point(int x, int y, int z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }
}

class DSU {
    int components;
    int [] parent, sz;

    DSU(int n){
        components = n;
        parent = new int[n];
        sz = new int[n];

        for(int i=0;i<n;i++){
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x) { return parent[x] == x ? x : (parent[x] = find(parent[x]));}

    void unite(int a, int b){
        a = find(a);
        b = find(b);

        if(a == b) return;

        if(sz[a] < sz[b]) {a = a^b; b = a^b; a = a^b;}

        parent[b] = a;
        sz[a] += sz[b];
        components--;
    }
}

public class Problem1
{
    public static void main(String[] args) {solve();}

    public static void solve()
    {
        try(BufferedReader br = new BufferedReader(new FileReader("Day08/input.txt")))
        {
            String line;
            ArrayList<Point> points = new ArrayList<>();

            while((line = br.readLine()) != null){
                int idx1 = line.indexOf(',');
                int idx2 = line.indexOf(',', idx1 + 1);

                int x = Integer.parseInt(line.substring(0,idx1).trim());
                int y = Integer.parseInt(line.substring(idx1+1, idx2).trim());
                int z = Integer.parseInt(line.substring(idx2+1).trim());

                points.add(new Point(x,y,z));
            }

            int n = points.size();

            ArrayList<ArrayList<Long>> edges = new ArrayList<>();

            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    ArrayList<Long> edge = new ArrayList<>();
                    edge.add(dist(points.get(i), points.get(j)));
                    edge.add((long)i);edge.add((long)j);

                    edges.add(edge);
                }
            }

            Collections.sort(edges, (a, b) -> Long.compare(a.get(0), b.get(0)));

            int count = 1;
            DSU dsu = new DSU(n);

            for(ArrayList<Long> edge: edges){
                int a = edge.get(1).intValue(), b = edge.get(2).intValue();

                if(dsu.find(a) != dsu.find(b)) dsu.unite(a, b);

                if(++count > 1000) break;
            }

            ArrayList<Integer> sizes = new ArrayList<>();

            for(int i=0;i<n;i++) sizes.add(dsu.sz[i]);

            int m = sizes.size();
            Collections.sort(sizes);

            if(sizes.size() < 3) System.out.println("Number of components < 3");
            else System.out.println(sizes.get(m-1) * sizes.get(m-2) * sizes.get(m-3));
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }

    public static long dist(Point a, Point b){
        long dx = a.x - b.x;
        long dy = a.y - b.y;
        long dz = a.z - b.z;

        return (dx*dx) + (dy*dy) + (dz*dz);
    }
}