#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

void local_now(void);

void utc_now(void);

#define MORPHO_LOCAL_NOW_FUNCTION "local_now"
#define MORPHO_UTC_NOW_FUNCTION "utc_now"
