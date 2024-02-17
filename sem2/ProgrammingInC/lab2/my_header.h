#ifdef ZLIB
    #include <zlib.h>
    //#error "zlib is not supported"
#endif

#ifdef LIBDEFLATE
    //#include <libdeflate.h>
    #error "libdeflate not supported"
#endif

#ifdef ISAL
    //#include <include/igzip_lib.h>
    #error "igzip_lib not supported"
#endif

#include "return_codes.h"
#include <stdio.h>
#include <stdlib.h>