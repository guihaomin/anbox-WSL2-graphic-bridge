// Generated Code - DO NOT EDIT !!
// generated by 'emugen'

#ifndef GUARD_renderControl_decoder_context_t
#define GUARD_renderControl_decoder_context_t

#include <external\android-emugl\host\include\libOpenglRender\IOStream.h>
#include "renderControl_server_context.h"



#include "external\android-emugl\shared\emugl\common\logging.h"

struct renderControl_decoder_context_t : public renderControl_server_context_t {

	size_t decode(void *buf, size_t bufsize, IOStream *stream);

};

#endif  // GUARD_renderControl_decoder_context_t
