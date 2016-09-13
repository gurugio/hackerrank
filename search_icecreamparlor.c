

#include <stdio.h>
#include <stdlib.h>


int main() {
    int num;
    int money;
    int flavors;
    int *costs;
    
    scanf("%d", &num);
    
    for (int i = 0; i < num; i++) {
        int a, b;
        
        scanf("%d", &money);
        scanf("%d", &flavors);
        
        costs = calloc(flavors, sizeof(int));
        for (int j = 0; j < flavors; j++) {
            scanf("%d", &costs[j]);
        }
        
        for (a = 0; a < flavors - 1; a++) {
            for (b = a+1; b < flavors; b++) {
		    if ((costs[a] + costs[b]) == money) {
			    printf("%d %d\n", a, b);
			    goto found;
		    }
            }
        }
    found:        
        free(costs);
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
