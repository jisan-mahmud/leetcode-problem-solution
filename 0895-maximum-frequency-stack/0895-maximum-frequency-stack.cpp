class FreqStack {
private: 
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> freq_st;
    int max_freq;

public:
    FreqStack() {
        max_freq = 0;
    }
    
    void push(int val) {
        freq[val]++;
        max_freq = max(max_freq, freq[val]);
        freq_st[freq[val]].push(val);
    }
    
    int pop() {
        int value = freq_st[max_freq].top();
        freq_st[max_freq].pop();
        freq[value]--;

        if(freq_st[max_freq].empty()) max_freq--;

        return value;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */