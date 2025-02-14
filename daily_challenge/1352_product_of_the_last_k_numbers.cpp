class ProductOfNumbers {
    vector<int> arr;
public:
    ProductOfNumbers() { 
		arr.push_back(1);
	}
    
    void add(int num) {
		if (!num) {
			arr.clear();
			arr.push_back(1);
		} else {
			arr.push_back(num*arr.back());
		}
    }
    
    int getProduct(int k) {
		if (k >= arr.size()) return 0;
		return arr.back()/arr[arr.size()-k-1];
	}
};
