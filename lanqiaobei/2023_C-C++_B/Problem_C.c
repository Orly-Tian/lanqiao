//
// Created by Administrator on 2025/3/27.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int main() {
	int n;
	scanf("%d", &n);
	int V, O;
	int min = INT_MIN, max = INT_MAX;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &V, &O);
		int tempMax = V / O;
		int tempMin = (V / (O + 1)) + 1;
		if (tempMin > min)
			min = tempMin;
		if (tempMax < max)
			max = tempMax;
	}
	printf("%d %d", min, max);

	return 0;
}
