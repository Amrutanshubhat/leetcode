class CustomStack {
	int max_size;
	int cur_size;
	int arr[1001];
public:
    CustomStack(int maxSize) {
		max_size = maxSize;
		cur_size = 0;
    }
    
    void push(int x) {
		if (cur_size != max_size) {
			arr[cur_size++] = x;
		}
    }
    
    int pop() {
    	if (cur_size) {
			return arr[--cur_size];
		}
		return -1;
    }
    
    void increment(int k, int val) {
		for (int i=0; i<k && i < cur_size; i++) {
			arr[i] += val;
		}
    }
};
