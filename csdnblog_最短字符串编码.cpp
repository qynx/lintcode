#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
using namespace std;
string to_string(int a){
	char *temp;
	sprintf(temp,"%d",a);
	string result=string(temp);
	//free(temp);
	return result;
} 
    string encode(string s) {
        int n = s.size();   //求出s的大小，用于定义数组大小
        vector< vector<string> > dp(n, vector<string>(n, ""));  //定义了一个二维数组dp
        for (int step = 1; step <= n; ++step) {
            for (int i = 0; i + step - 1 < n; ++i) {
                int j = i + step - 1;
                dp[i][j] = s.substr(i, step);    //将从i到step的字符赋给dp[i][j]
                for (int k = i; k < j; ++k) {
                    string left = dp[i][k], right = dp[k + 1][j];
                    if (left.size() + right.size() < dp[i][j].size()) {
                        dp[i][j] = left + right;
                    }
                }
                string t = s.substr(i, j - i + 1), replace = "";
                int pos = (t + t).find(t, 1);
                if (pos >= t.size()) replace = t;
                else replace = to_string(t.size() / pos) + '[' + dp[i][i + pos - 1] + ']';
                if (replace.size() < dp[i][j].size()) dp[i][j] = replace;
            }
        }
        return dp[0][n - 1];
    }

int main()
{
    string s;
    cin >> s;
 
    string result = "";
    result = encode(s);
 	cout<<result<<endl;
    cout << result.size() << endl;
 
    return 0;
}
