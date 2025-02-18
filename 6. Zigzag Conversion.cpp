string convert(string s, int numRows) {
    if (numRows == 1) return s; 

    vector<string> arr(numRows);

    int len = s.size();
    int row = 0;
    bool down = false;

    for (int i = 0; i < len; i++) {
        arr[row] += s[i];
        
        if (row == 0 || row == numRows - 1) {
            down = !down; 
        }

        row += down ? 1 : -1;  
    }

    string new_str = "";
    for (auto str : arr) {
        new_str += str;
    }
    return new_str;
}
