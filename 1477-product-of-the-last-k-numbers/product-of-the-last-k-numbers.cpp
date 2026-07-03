class ProductOfNumbers {
public:
    vector<int>v;int n;
    ProductOfNumbers() {
        n=0;
    }
    
    void add(int num) {
        v.push_back(num);n++;
    }
    
    int getProduct(int k) {
        long long int prod=1;
        for(int i=1;i<=k;i++){
            if(v[n-i]==0)return 0;
            prod*=1LL*v[n-i];
        }
        return (int)prod;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */