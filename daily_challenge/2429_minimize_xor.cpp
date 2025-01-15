class Solution {
public:
    int minimizeXor(int num1, int num2) {
		// bit set count of num2
       	int cnt = 0;
		for (int i=num2; i>0; i>>=1)
			cnt += i&1;

		// set bits from msb to lsb
		int out=0;
		for (int i=(sizeof(num1)*8)-1; cnt>0 && i>=0; i--) {
			if ((1<<i) & num1) {
				out |= (1<<i);
				cnt--;
			}
		}
		// set bits from lsb to msb
		for (int i=0; cnt>0; i++) {
			if (!(out & (1<<i))) {
				out |= (1<<i);
				cnt--;
			}
		}
		return out;
    }
};
