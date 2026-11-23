class ProductOfNumbers {
public:
vector<int>nums;
    ProductOfNumbers() {
        nums.push_back(1);
    }
    
    void add(int num) {
        int n=nums.size();
        if(num!=0){
            nums.push_back(nums[n-1]*num);
        }
        else{
            nums.clear();
            nums.push_back(1);
        }
    }
    
    int getProduct(int k) {
        int n=nums.size();
        if(k>=n){
            return 0;
        }
        return nums[n-1]/nums[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */