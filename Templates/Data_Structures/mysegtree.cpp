int stree[4 * M2], lazy[4 * M2];
void apply(int u, int val) {
	stree[u] += val;
	lazy[u] += val;
}
void push (int u) {
	apply(u * 2, lazy[u]);
	apply(u * 2 + 1, lazy[u]);
	lazy[u] = 0;
}
void update (int l, int r, int val, int u = 1, int tl = 0, int tr = M2 - 1) {
	assert(u < 4 * M2);
	if (l > r) return;
	if (tl == l && tr == r) {
		apply(u, val);
		return;
	}
	push(u);
	int mid = (tl + tr) / 2;
	int l1 = l, r1 = min(mid, r), l2 = max(mid + 1, l), r2  = r;
	update(l1, r1, val, u * 2, tl, mid);
	update(l2, r2, val, u * 2 + 1, mid + 1, tr);
	stree[u] = min(stree[u * 2], stree[u * 2 + 1]);
}
int query (int l, int r, int val, int u = 1, int tl = 0, int tr = M2 - 1) {
	if (l > r) return 0;
	if (tl == l & tr == r) {
		int cur = u;
		if (stree[cur] > val) return 0;
		while (tl != tr) {
			push(cur);
			int mid = (tl + tr) / 2;
			if (stree[cur * 2 + 1] <= val) {
				tl = mid + 1;
				cur = cur * 2 + 1;
			}
			else {
				tr = mid;
				cur = cur * 2;
			}
		}
		return tl;
	}
	push(u);
	int mid = (tl + tr) / 2;
	int l1 = l, r1 = min(mid, r), l2 = max(mid + 1, l), r2  = r;
	int m2 = query(l2, r2, val, u * 2 + 1, mid + 1, tr);
	//if (m2 > 0) return m2;
	int m1 = query(l1, r1, val, u * 2, tl, mid);
	//if (m1 > 0) return m1;
	return max(m1, m2);
}
/*
printf("A+ %d\n", mp["A+"]);
    printf("A- %d", mp["A-"]);
    printf("AB+ %d\n", mp["AB+"]);
    printf("AB- %d", mp["AB-"]);
    printf("B+ %d\n", mp["B+"]);
    printf("B- %d", mp["B-"]);
    printf("O+ %d\n", mp["O+"]);
    printf("O- %d", mp["O-"]);
    */