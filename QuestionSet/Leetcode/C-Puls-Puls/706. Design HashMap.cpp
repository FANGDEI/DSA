/*
 * @Author: FANG
 * @Date: 2021-10-15 16:17:09
 */
class MyHashMap {
private:
    int m[10000005];
public:
    MyHashMap() {
        for (int i = 0; i < 10000005; i++) m[i] = -1;
    }
    
    void put(int key, int value) {
        m[key] = value;
    }
    
    int get(int key) {
        return m[key];
    }
    
    void remove(int key) {
        m[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */