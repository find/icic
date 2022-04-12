#include <stdlib.h>

static const char _qjscalc_src[] = {
#include "qjscalc.js.h"
};

static const size_t _qjscalc_src_len = sizeof(_qjscalc_src);

char const* qjscalc_src()     { return _qjscalc_src; }
size_t      qjscalc_src_len() { return _qjscalc_src_len-1; }

