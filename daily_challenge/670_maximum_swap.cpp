class Solution {
	static int
		cmp(const void* x, const void* y) {
			return *(int*)x > *(int*)y;
		}
public:
    int maximumSwap(int num) {
       	size_t len = 0;
		int arr[10] = {0};
		for (size_t i=10, k=num; 
				k;
				arr[len++]=k%10, k=num/i, i*=10);
		int check[10];
		memcpy(check, arr, sizeof(arr));
		qsort(check, len, sizeof(*check), cmp);
		int out = 0;
		for (size_t i=len, swap=0; i-- != 0;) {
			if (!swap && check[i] != arr[i]) {
				ssize_t j=i;
				while (check[i] != arr[j]) j--;
				//if equal swap as late as possible
				size_t swap_index = j;
				if (i>0 && check[i] == check[i-1]) {
					while (j>=0) {
						if (check[i] == arr[j]) {
							swap_index = j;
						}
						j--;
					}
				}
				arr[swap_index] = arr[i];
				arr[i] = check[i];
				swap++;
			}
			out += arr[i]*pow(10, i);
		}
		return out;
    }
};
