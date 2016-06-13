#include <stdio.h>

// defined variables:
int a;
bool __temp_var_0;
bool __temp_var_1;
bool __temp_var_2;
bool __temp_var_3;

int main() {

Line0: a = -6;
Line1: __temp_var_0 = a < 2;
Line2: __temp_var_1 = 3 == 3;
Line3: __temp_var_2 = __temp_var_0 && __temp_var_1;
Line4: if (!__temp_var_2) goto Line9;
Line5: __temp_var_3 = (a < 1);
Line6: if (!__temp_var_3) goto Line9;
printf("%d, %d, %d\n", a, __temp_var_3, (a < 1));
Line7: a = a + 1;
Line8: goto Line5;
Line9: return 0;
}
