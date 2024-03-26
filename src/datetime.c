
// datetime.c
#include "datetime.h"
#include <morpho/builtin.h>
#include <morpho/morpho.h>
#include <stdio.h>

// C-based functions defined for this module go here

// Then, the Morpho veneer functions for the C functions can be defined here
value MorphoLocalNow(vm *v, int nargs, value *args) {
  local_now();
  return MORPHO_NIL;
}

value MorphoUTCNow(vm *v, int nargs, value *args) {
  utc_now();
  return MORPHO_NIL;
}
// These are necessary functions to interface with the morpho extension manager
void datetime_initialize(void) {
  // Add builtin functions, define errors, etc
  builtin_addfunction(MORPHO_LOCAL_NOW_FUNCTION, MorphoLocalNow,
                      BUILTIN_FLAGSEMPTY);
  builtin_addfunction(MORPHO_UTC_NOW_FUNCTION, MorphoUTCNow,
                      BUILTIN_FLAGSEMPTY);
}

void datetime_finalize(void) {
  // Optional cleanup function
}
