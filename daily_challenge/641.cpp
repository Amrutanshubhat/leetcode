class MyCircularDeque {
	int max_size;
	int f, r;
	int cur_size;
	int* arr;
public:
    MyCircularDeque(int k):max_size{k}, f{k-1}, r{0}, cur_size{0}, arr{new int[k]} {}
    
    bool insertFront(int value) {
		if (isFull()) return false;
		arr[f] = value;
		cur_size++;
		f = f == 0 ? max_size-1 : f-1;
		return true;
    }
    
    bool insertLast(int value) {
		if (isFull()) return false;
		arr[r] = value;
		cur_size++;
		r = (r+1)%max_size; 
		return true;
    }
    
    bool deleteFront() {
		if (isEmpty()) return false;
		f = (f+1)%max_size;
		cur_size--;
		return true;
    }
    
    bool deleteLast() {
		if (isEmpty()) return false;
		r = r == 0 ? max_size-1 : r-1;
		cur_size--;
		return true;
    }
    
    int getFront() {
		int index = f == max_size-1 ? 0 : f+1;
		return cur_size == 0 ? -1 : arr[index];
    }
    
    int getRear() {
		int index = r == 0 ? max_size-1 : r-1;
		return cur_size == 0 ? -1 : arr[index];
    }
    
    bool isEmpty() {
		return cur_size == 0;
    }
    
    bool isFull() {
		return cur_size == max_size;
    }
};
