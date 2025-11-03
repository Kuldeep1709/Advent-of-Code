#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define n 50
#define m 20

void print(vector<string> &arr,int x,int y){
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2*n; j++) {
            if(i==x && j==y) cout<<"@";
            else cout<<arr[i][j];
        }
        cout<<"\n";
    }
    cout<<"\n";
}
bool in(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < 2*n;
}

bool PushUp(vector<string> &arr,int x,int y){
	vector<vector<pair<int,int>>> mp;
	mp.push_back({{x,y}});

	while(true){
		bool clear=true,end=false;
		vector<vector<bool>> vis(n,vector<bool>(2*n,false));
		vector<pair<int,int>> nxt;

		for(auto ele: mp[mp.size()-1]){
			int a=ele.first,b=ele.second;
			if(vis[a-1][b]) continue;

			if(arr[a-1][b]=='['){
				nxt.push_back({a-1,b});
				nxt.push_back({a-1,b+1});
				clear=false;
			}
			else if(arr[a-1][b]==']'){
				nxt.push_back({a-1,b});
				nxt.push_back({a-1,b-1});
				clear=false;
			}
			else if(arr[a-1][b]=='#'){
				end=true;
				break;
			}
		}
		if(end) return false;
		mp.push_back(nxt);

		if(clear){
			while(mp.size()){
				for(auto ele:mp[mp.size()-1]){
					int a=ele.first,b=ele.second;
					if(arr[a][b]=='['){
						arr[a-1][b]='[';
						arr[a-1][b+1]=']';
						arr[a][b]='.';
						arr[a][b+1]='.';
					}
				}
				mp.pop_back();
			}
			return true;
		}
	}
}

bool PushDown(vector<string> &arr,int x,int y){
	vector<vector<pair<int,int>>> mp;
	mp.push_back({{x,y}});

	while(true){
		bool clear=true,end=false;
		vector<vector<bool>> vis(n,vector<bool>(2*n,false));
		vector<pair<int,int>> nxt;

		for(auto ele: mp[mp.size()-1]){
			int a=ele.first,b=ele.second;
			if(vis[a+1][b]) continue;

			if(arr[a+1][b]=='['){
				nxt.push_back({a+1,b});
				nxt.push_back({a+1,b+1});
				clear=false;
			}
			else if(arr[a+1][b]==']'){
				nxt.push_back({a+1,b});
				nxt.push_back({a+1,b-1});
				clear=false;
			}
			else if(arr[a+1][b]=='#'){
				end=true;
				break;
			}
		}
		if(end) return false;
		mp.push_back(nxt);

		if(clear){
			while(mp.size()){
				for(auto ele:mp[mp.size()-1]){
					int a=ele.first,b=ele.second;
					if(arr[a][b]=='['){
						arr[a+1][b]='[';
						arr[a+1][b+1]=']';
						arr[a][b]='.';
						arr[a][b+1]='.';
					}
				}
				mp.pop_back();
			}
			return true;
		}
	}
}

int main() {
    vector<string> temp(n), move(m);
    for (int i = 0; i < n; i++) cin >> temp[i];
    for (int i = 0; i < m; i++) cin >> move[i];
	
    vector<string> arr;
	for(string s:temp){
		string ele="";
		for(char c:s){
			if(c=='.') ele+="..";
			else if(c=='O') ele+="[]";
			else if(c=='@') ele+="@.";
			else ele+="##";
		}
		arr.push_back(ele);
	}

    int x = 0, y = 0;
    bool found = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2*n; j++) {
            if (arr[i][j] == '@') {
                x = i;
                y = j;
                arr[x][y] = '.';
                found = true;
                break;
            }
        }
        if (found) break;
    }
    
    for (string s : move) {
        for (char c : s) {
            if (c == '^') {
            	if(!in(x-1,y)) continue;
                if (arr[x - 1][y] == '.')  x--;
                else if (arr[x - 1][y] == '[' || arr[x-1][y]==']'){
                	bool done=PushUp(arr,x,y);
                	if(done) x--;
                }
            } 

            if (c == '>') {
            	if(!in(x,y+1)) continue;
                if (arr[x][y + 1] == '.') y++;
                else if (arr[x][y + 1] == '[') {
                    int j = 3;
                    while (in(x, y + j) && arr[x][y + j] == '[') j+=2;
                    if (in(x, y + j) && arr[x][y + j] == '.') {
                    	int k=2;
                    	while(k<j){
                    		if(arr[x][y+k]=='[') arr[x][y+k]=']';
                    		else arr[x][y+k]='[';
                    		k++;
                    	}
                        arr[x][y + j] = ']';
                        arr[x][y + 1] = '.';
                        y++;
                    }
                }
            }

            else if (c == 'v') {
            	if(!in(x+1,y)) continue;
                if (arr[x+1][y] == '.')  x++;
                else if (arr[x+1][y] == '[' || arr[x+1][y]==']'){
                	bool done=PushDown(arr,x,y);
                	if(done) x++;
                }
            } 

            else if(c == '<'){
                if(!in(x,y-1)) continue;
                if (arr[x][y - 1] == '.') y--;
                else if (arr[x][y - 1] == ']') {
                    int j = 3;
                    while (in(x, y - j) && arr[x][y - j] == ']') j+=2;
                    if (in(x, y - j) && arr[x][y - j] == '.') {
                    	int k=2;
                    	while(k<j){
                    		if(arr[x][y-k]=='[') arr[x][y-k]=']';
                    		else arr[x][y-k]='[';
                    		k++;
                    	}
                        arr[x][y - j] = '[';
                        arr[x][y - 1] = '.';
                        y--;
                    }
                }
            }
        }
    }

    ull ans = 0;	
    for (int i = 1; i < n ; i++) {
        for (int j = 2; j < 2*n-3; j++) {
            if (arr[i][j] == '[') {
                ans += (100 * i + j);
            }
        }
    }

    cout << ans << "\n";

    return 0;
}