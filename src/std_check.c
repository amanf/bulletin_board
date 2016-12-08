#include <stdio.h>

int main(void) {

# if defined(__STDC__)
  printf("STD >= 89\n");
#   if (__STDC_VERSION__ >= 199901L)
      printf("STD >= 99\n");
#   endif
#   if (__STDC_VERSION__ >= 201112L)
      printf("STD >= 11\n");
#   endif
# endif

}
