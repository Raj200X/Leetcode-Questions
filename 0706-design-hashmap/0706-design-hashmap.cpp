class Pair{
    public:
    int a;
    int b;
    Pair(int a,int b){
        this->a=a;
        this->b=b;
    }
};
class MyHashMap {
public:
    vector<vector<Pair>> hm;
    MyHashMap() {
    hm.resize(2069);
    }
    
    void put(int key, int value) {
        int z=key%2069;
        int flag=0;
        for(int i=0;i<hm[z].size();i++){
            if(hm[z][i].a==key){
                flag=1;
                hm[z][i].b=value;
            }
        }
        if(flag==0){
            hm[z].push_back(Pair(key,value));
        }
    }
    
    int get(int key) {
        int z=key%2069;
        for(int i=0;i<hm[z].size();i++){
            if(hm[z][i].a==key){
                return hm[z][i].b;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int z=key%2069;
        for(int i=0;i<hm[z].size();i++){
            if(hm[z][i].a==key){
                hm[z].erase(hm[z].begin() + i);
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */