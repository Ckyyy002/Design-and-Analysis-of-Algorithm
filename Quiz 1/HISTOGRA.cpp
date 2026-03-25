#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    
    while (cin >> n && n != 0) {
        vector<long long> heights(n);
        for (int i = 0; i < n; ++i) {
            cin >> heights[i];
        }
        
        stack<int> s;
        long long max_area = 0; 
        int i = 0;
        
        while (i < n) {
            if (s.empty() || heights[s.top()] <= heights[i]) {
                s.push(i);
                i++;
            } 
            else {
                int top_index = s.top();
                s.pop();
                
                long long width;
                if (s.empty()) {
                    width = i;
                } else {
                    width = i - s.top() - 1; 
                }
                
                long long area = heights[top_index] * width;
                
                if (area > max_area) {
                    max_area = area;
                }
            }
        }
        
        while (!s.empty()) {
            int top_index = s.top();
            s.pop();
            
            long long width;
            if (s.empty()) {
                width = i;
            } else {
                width = i - s.top() - 1;
            }
            
            long long area = heights[top_index] * width;
            if (area > max_area) {
                max_area = area;
            }
        }
        
        cout << max_area << endl;
    }
    
    return 0;
}