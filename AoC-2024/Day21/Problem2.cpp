#include <bits/stdc++.h>
using namespace std;

#define ppiis pair<pair<int,int>,string>
const int inf=17;

bool in(int x,int y,int n,int m){
    return x>=0 && y>=0 && x<n && y<m;
}

vector<vector<string>> bfs(const vector<vector<int>> &nums,int i,int j){
    int n=nums.size(),m=nums[0].size();
    vector<vector<string>>  ans(m*n -1);
    vector<vector<int>> vis(n,vector<int>(m,inf));
    
    queue<ppiis> q;
    q.push({{i,j},""});
    vis[i][j]=0;

    vector<vector<int>> move={{1,0},{0,1},{-1,0},{0,-1}};
    

    map<vector<int>,char> dir;
    dir[move[0]]='v';
    dir[move[1]]='>';
    dir[move[2]]='^';
    dir[move[3]]='<';

    while(!q.empty()){
        ppiis a=q.front();
        q.pop();

        int x=a.first.first,y=a.first.second;
        string s=a.second;

        for(auto mv : move){
            int dx=mv[0],dy=mv[1];
            if(in(x+dx,y+dy,n,m) && nums[x+dx][y+dy]!=-1 && vis[x+dx][y+dy]>=s.size()+1){
                int val=nums[x+dx][y+dy];
                s.push_back(dir[mv]);
                ans[val].push_back(s);
                q.push({{x+dx,y+dy},s});
                vis[x+dx][y+dy]=s.size()+1;
                s.pop_back();
            }
        }
    }
    return ans;
}

void ASSP(const vector<vector<int>> &nums,vector<vector<vector<string>>> &path){
    int n=nums.size(),m=nums[0].size(),p=path.size();
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int val=nums[i][j];
            if(val != -1) path[val]=bfs(nums,i,j);
        }
    }
}

void pushA(vector<vector<vector<string>>> &arr){
    for(auto &a:arr){
        for(auto &b:a){
            for(string &c:b) c.push_back('A');
        }
    }

    for(int i=arr.size()-1;i>=0;i--) arr[i][i].push_back("A");
}

vector<string> numpad(const string &s,const vector<vector<vector<string>>> &num_path){
    int prev=10,nxt=min(s[0]-'0',10);
    vector<string> arr=num_path[prev][nxt];
    prev=nxt;

    for(int i=1;i<s.size();i++){
        int nxt=min(s[i]-'0',10);
        vector<string> temp=num_path[prev][nxt];
        prev=nxt;

        vector<string> brr;

        for(string t:arr){
            for(string u:temp){
                brr.push_back(t+u);
            }
        }
        arr=brr;
    }
    return arr;
}

void robot(const string &s,const vector<vector<vector<string>>> &dir_path,int lev,unordered_map<string,vector<string>> &memo,vector<string> &ans){
    if(lev==0){
        ans.push_back(s);
        return;
    }

    vector<string> arr;
    if(memo.count(s)) arr=memo[s];
    else{
        unordered_map<char,int> m;
        m['^']=0,m['<']=1,m['v']=2,m['>']=3,m['A']=4;

        int prev=m['A'],nxt=m[s[0]];

        arr=dir_path[prev][nxt];
        prev=nxt;

        for(int i=1;i<s.size();i++){
            int nxt=m[s[i]];
            vector<string> temp=dir_path[prev][nxt];
            prev=nxt;

            vector<string> brr;

            for(string t:arr){
                for(string u:temp){
                    brr.push_back(t+u);
                }
            }
            arr=brr;
        }
        memo[s]=arr;
    }
    for(string x:arr) robot(x,dir_path,lev-1,memo,ans);
}

int main(){
    vector<vector<int>> nums={{7,8,9},{4,5,6},{1,2,3},{-1,0,10}}; // (A = 10) , (-1 Empty)
    vector<vector<int>> dirs={{-1,0,4},{1,2,3}}; // (A = 4) , (^ = 0) , (< = 1) , (v = 2) , (> = 3)
    
    vector<vector<vector<string>>> num_path(11),dir_path(5);

    ASSP(nums,num_path);
    ASSP(dirs,dir_path);

    pushA(num_path);
    pushA(dir_path);

    int ans=0;

    for(int i=0;i<5;i++){
        string s;cin>>s;
        int res=stoi(s.substr(0,s.size()-1));
        int temp=0,maxi=INT_MAX,lev=25;
        vector<string> arr=numpad(s,num_path);
        
        for(string v:arr){
            vector<string> brr;
            unordered_map<string,vector<string>> memo;
            robot(v,dir_path,lev,memo,brr);
            for(string x:brr){
                if(x.size()<maxi){
                    temp=res*(x.size());
                    maxi=x.size();
                }
            }
        }
        ans+=temp;
    }

    cout<<ans<<"\n";

    return 0;
}
