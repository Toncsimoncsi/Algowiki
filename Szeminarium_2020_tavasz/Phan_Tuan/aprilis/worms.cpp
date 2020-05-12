        #include<bits/stdc++.h>
        using namespace std;
        vector<int> pos(1e6 + 3, 0);
        int main() {
         
     
        	int n; cin >> n;
        	int first = 1; int x;
        	for (int i = 0; i < n; i++) {
        		cin >> x;
        		for (int j = first; j < first + x; j++)
        		{
        			pos[j] = i + 1;
        		}
        		first += x;
        	}
        	int q; cin >> q;
        	int query;
        	for (int i = 0; i < q; i++) {
        		cin >> query;
        		cout << pos[query] << endl;
        	}
         
        }
