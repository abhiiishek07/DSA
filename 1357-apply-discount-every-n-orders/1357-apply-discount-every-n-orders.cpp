class Cashier {
public:
    int k,cnt=0,dis;
    unordered_map<int,int>mp;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        k=n;
        dis=discount;
        mp.clear();
        for(int i=0;i<products.size();i++){
            mp[products[i]]=prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        cnt++;
        double bill=0.0;
        for(int i=0;i<product.size();i++){
            bill+= mp[product[i]]*amount[i];
        }
        if(cnt==k){
            cnt=0;
            bill= bill*((double)(100-dis)/100);
            
        }
        return bill;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */