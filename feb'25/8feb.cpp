class NumberContainers {
public:
    unordered_map<int,int> m1;
    unordered_map<int,set<int>> m2;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(m1.count(index)){
            int prev=m1[index];
            m2[prev].erase(index);
            if(m2[prev].empty()) m2.erase(prev);
        }
        m1[index]=number;
        m2[number].insert(index);
    }
    
    int find(int number) {
        if(m2.count(number)) return *m2[number].begin();
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
