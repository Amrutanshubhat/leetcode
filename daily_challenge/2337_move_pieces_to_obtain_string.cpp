class Solution {
public:
    bool canChange(string start, string target) {
		int a=0, b=0, c=0;
		for (size_t i=0; i<start.size(); i++) {
			if (start[i] == 'L') a++;
			if (start[i] == '_') b++;
			if (start[i] == 'R') c++;
			if (target[i] == 'L') a--;
			if (target[i] == '_') b--;
			if (target[i] == 'R') c--;
		}
		if (a != 0 || b != 0 || c != 0) return false;
		size_t i=0, j=0, u=0, r=0;
		while ( i<start.size() && j<target.size()) {
			if (start[i] == target[j]) {
				if (start[i] == 'L' && r) return false;
				if (start[i] == 'R' && u) return false;
				i++; j++; continue;
			}
			if (target[j] == 'L') {
				if (r) return false;
				while (i<start.size() && start[i]=='_') {
					u++; i++;
				}
				if (i == start.size() || start[i] == 'R') return false;
				i++; j++;
			} else if (target[j] == 'R') {
				if (u) return false;
				if (r) {
					r--; j++;
				}
				else return false;
			} else {
				if (u) {
					u--; j++;
				}  else {
					while (i<start.size() && start[i] == 'R') {
						r++; i++;
					}
					if (i == start.size() || start[i] == 'L') return false;
					i++; j++;
				}
			}
		}
		if (start.back() == 'L' && r) return false;
		if (start.back() == 'R' && u) return false;
		if (i < start.size() || i != j+max(r,u)) return false;
		return true;
    }
};
