// Generated Code - DO NOT EDIT !!
// generated by 'emugen'


#include <string.h>
#include "renderControl_opcodes.h"

#include "renderControl_dec.h"


#include "external\android-emugl\shared\OpenglCodecCommon\ProtocolUtils.h"

#include "external\android-emugl\shared\OpenglCodecCommon\ChecksumCalculatorThreadInfo.h"

#include <stdio.h>

typedef unsigned int tsize_t; // Target "size_t", which is 32-bit for now. It may or may not be the same as host's size_t when emugen is compiled.

#  define DEBUG(...) do { if (emugl_cxt_logger) { emugl_cxt_logger(LogLevel::TRACE, __VA_ARGS__); } } while(0)

#ifdef CHECK_GLERROR
#  define SET_LASTCALL(name)  sprintf(lastCall, #name)
#else
#  define SET_LASTCALL(name)  ((void)0)
#endif

using namespace emugl;

size_t renderControl_decoder_context_t::decode(void *buf, size_t len, IOStream *stream)
{
                           
	size_t pos = 0;
	if (len < 8) return pos; 
	unsigned char *ptr = (unsigned char *)buf;
	bool unknownOpcode = false;  
#ifdef CHECK_GL_ERROR 
	char lastCall[256] = {0}; 
#endif 
	while ((len - pos >= 8) && !unknownOpcode) {   
		uint32_t opcode = *(uint32_t *)ptr;   
		size_t packetLen = *(uint32_t *)(ptr + 4);
		if (len - pos < packetLen)  return pos; 
		bool useChecksum = ChecksumCalculatorThreadInfo::getVersion() > 0;
		size_t checksumSize = 0;
		if (useChecksum) {
			checksumSize = ChecksumCalculatorThreadInfo::checksumByteSize();
		}
		if (opcode >= 10000) {
			printf("%d \n", opcode);
		}
		switch(opcode) {
		case OP_rcGetRendererVersion: {
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8, ptr + 8, checksumSize, 
					"8::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			size_t totalTmpSize = sizeof(GLint);
			totalTmpSize += checksumSize;
			unsigned char *tmpBuf = stream->alloc(totalTmpSize);
			DEBUG("renderControl(%p): rcGetRendererVersion()", stream);
			*(GLint *)(&tmpBuf[0]) = 			this->rcGetRendererVersion();
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::writeChecksum(&tmpBuf[0], totalTmpSize - checksumSize, &tmpBuf[totalTmpSize - checksumSize], checksumSize);
			}
			stream->flush();
			SET_LASTCALL("rcGetRendererVersion");
			break;
		}
		case OP_rcGetEGLVersion: {
			uint32_t size_major  = Unpack<uint32_t,uint32_t>(ptr + 8);
			uint32_t size_minor  = Unpack<uint32_t,uint32_t>(ptr + 8 + 4);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8 + 4 + 4, ptr + 8 + 4 + 4, checksumSize, 
					"8 + 4 + 4::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			size_t totalTmpSize = size_major;
			totalTmpSize += size_minor;
			totalTmpSize += sizeof(EGLint);
			totalTmpSize += checksumSize;
			unsigned char *tmpBuf = stream->alloc(totalTmpSize);
			OutputBuffer outptr_major(&tmpBuf[0], size_major);
			OutputBuffer outptr_minor(&tmpBuf[0 + size_major], size_minor);
			DEBUG("renderControl(%p): rcGetEGLVersion(%p(%u) %p(%u) )", stream,(EGLint*)(outptr_major.get()), size_major, (EGLint*)(outptr_minor.get()), size_minor);
			*(EGLint *)(&tmpBuf[0 + size_major + size_minor]) = 			this->rcGetEGLVersion((EGLint*)(outptr_major.get()), (EGLint*)(outptr_minor.get()));
			outptr_major.flush();
			outptr_minor.flush();
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::writeChecksum(&tmpBuf[0], totalTmpSize - checksumSize, &tmpBuf[totalTmpSize - checksumSize], checksumSize);
			}
			stream->flush();
			SET_LASTCALL("rcGetEGLVersion");
			break;
		}
		case OP_rcQueryEGLString: {
			EGLenum var_name = Unpack<EGLenum,uint32_t>(ptr + 8);
			uint32_t size_buffer  = Unpack<uint32_t,uint32_t>(ptr + 8 + 4);
			EGLint var_bufferSize = Unpack<EGLint,uint32_t>(ptr + 8 + 4 + 4);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8 + 4 + 4 + 4, ptr + 8 + 4 + 4 + 4, checksumSize, 
					"8 + 4 + 4 + 4::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			size_t totalTmpSize = size_buffer;
			totalTmpSize += sizeof(EGLint);
			totalTmpSize += checksumSize;
			unsigned char *tmpBuf = stream->alloc(totalTmpSize);
			OutputBuffer outptr_buffer(&tmpBuf[0], size_buffer);
			DEBUG("renderControl(%p): rcQueryEGLString(0x%08x %p(%u) 0x%08x )", stream,var_name, (void*)(outptr_buffer.get()), size_buffer, var_bufferSize);
			*(EGLint *)(&tmpBuf[0 + size_buffer]) = 			this->rcQueryEGLString(var_name, (void*)(outptr_buffer.get()), var_bufferSize);
			outptr_buffer.flush();
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::writeChecksum(&tmpBuf[0], totalTmpSize - checksumSize, &tmpBuf[totalTmpSize - checksumSize], checksumSize);
			}
			stream->flush();
			SET_LASTCALL("rcQueryEGLString");
			break;
		}
		case OP_rcGetGLString: {
			EGLenum var_name = Unpack<EGLenum,uint32_t>(ptr + 8);
			uint32_t size_buffer  = Unpack<uint32_t,uint32_t>(ptr + 8 + 4);
			EGLint var_bufferSize = Unpack<EGLint,uint32_t>(ptr + 8 + 4 + 4);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8 + 4 + 4 + 4, ptr + 8 + 4 + 4 + 4, checksumSize, 
					"8 + 4 + 4 + 4::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			size_t totalTmpSize = size_buffer;
			totalTmpSize += sizeof(EGLint);
			totalTmpSize += checksumSize;
			unsigned char *tmpBuf = stream->alloc(totalTmpSize);
			OutputBuffer outptr_buffer(&tmpBuf[0], size_buffer);
			DEBUG("renderControl(%p): rcGetGLString(0x%08x %p(%u) 0x%08x )", stream,var_name, (void*)(outptr_buffer.get()), size_buffer, var_bufferSize);
			*(EGLint *)(&tmpBuf[0 + size_buffer]) = 			this->rcGetGLString(var_name, (void*)(outptr_buffer.get()), var_bufferSize);
			outptr_buffer.flush();
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::writeChecksum(&tmpBuf[0], totalTmpSize - checksumSize, &tmpBuf[totalTmpSize - checksumSize], checksumSize);
			}
			stream->flush();
			SET_LASTCALL("rcGetGLString");
			break;
		}
		case OP_rcGetNumConfigs: {
			uint32_t size_numAttribs  = Unpack<uint32_t,uint32_t>(ptr + 8);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8 + 4, ptr + 8 + 4, checksumSize, 
					"8 + 4::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			size_t totalTmpSize = size_numAttribs;
			totalTmpSize += sizeof(EGLint);
			totalTmpSize += checksumSize;
			unsigned char *tmpBuf = stream->alloc(totalTmpSize);
			OutputBuffer outptr_numAttribs(&tmpBuf[0], size_numAttribs);
			DEBUG("renderControl(%p): rcGetNumConfigs(%p(%u) )", stream,(uint32_t*)(outptr_numAttribs.get()), size_numAttribs);
			*(EGLint *)(&tmpBuf[0 + size_numAttribs]) = 			this->rcGetNumConfigs((uint32_t*)(outptr_numAttribs.get()));
			outptr_numAttribs.flush();
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::writeChecksum(&tmpBuf[0], totalTmpSize - checksumSize, &tmpBuf[totalTmpSize - checksumSize], checksumSize);
			}
			stream->flush();
			SET_LASTCALL("rcGetNumConfigs");
			break;
		}
		case OP_rcGetConfigs: {
			uint32_t var_bufSize = Unpack<uint32_t,uint32_t>(ptr + 8);
			uint32_t size_buffer  = Unpack<uint32_t,uint32_t>(ptr + 8 + 4);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8 + 4 + 4, ptr + 8 + 4 + 4, checksumSize, 
					"8 + 4 + 4::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			size_t totalTmpSize = size_buffer;
			totalTmpSize += sizeof(EGLint);
			totalTmpSize += checksumSize;
			unsigned char *tmpBuf = stream->alloc(totalTmpSize);
			OutputBuffer outptr_buffer(&tmpBuf[0], size_buffer);
			DEBUG("renderControl(%p): rcGetConfigs(0x%08x %p(%u) )", stream,var_bufSize, (GLuint*)(outptr_buffer.get()), size_buffer);
			*(EGLint *)(&tmpBuf[0 + size_buffer]) = 			this->rcGetConfigs(var_bufSize, (GLuint*)(outptr_buffer.get()));
			outptr_buffer.flush();
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::writeChecksum(&tmpBuf[0], totalTmpSize - checksumSize, &tmpBuf[totalTmpSize - checksumSize], checksumSize);
			}
			stream->flush();
			SET_LASTCALL("rcGetConfigs");
			break;
		}
		case OP_rcChooseConfig: {
			uint32_t size_attribs  = Unpack<uint32_t,uint32_t>(ptr + 8);
			InputBuffer inptr_attribs(ptr + 8 + 4, size_attribs);
			uint32_t var_attribs_size = Unpack<uint32_t,uint32_t>(ptr + 8 + 4 + size_attribs);
			uint32_t size_configs  = Unpack<uint32_t,uint32_t>(ptr + 8 + 4 + size_attribs + 4);
			uint32_t var_configs_size = Unpack<uint32_t,uint32_t>(ptr + 8 + 4 + size_attribs + 4 + 4);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8 + 4 + size_attribs + 4 + 4 + 4, ptr + 8 + 4 + size_attribs + 4 + 4 + 4, checksumSize, 
					"8 + 4 + size_attribs + 4 + 4 + 4::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			size_t totalTmpSize = size_configs;
			totalTmpSize += sizeof(EGLint);
			totalTmpSize += checksumSize;
			unsigned char *tmpBuf = stream->alloc(totalTmpSize);
			OutputBuffer outptr_configs(&tmpBuf[0], size_configs);
			DEBUG("renderControl(%p): rcChooseConfig(%p(%u) 0x%08x %p(%u) 0x%08x )", stream,(EGLint*)(inptr_attribs.get()), size_attribs, var_attribs_size, (uint32_t*)(outptr_configs.get()), size_configs, var_configs_size);
			*(EGLint *)(&tmpBuf[0 + size_configs]) = 			this->rcChooseConfig((EGLint*)(inptr_attribs.get()), var_attribs_size, size_configs == 0 ? NULL : (uint32_t*)(outptr_configs.get()), var_configs_size);
			outptr_configs.flush();
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::writeChecksum(&tmpBuf[0], totalTmpSize - checksumSize, &tmpBuf[totalTmpSize - checksumSize], checksumSize);
			}
			stream->flush();
			SET_LASTCALL("rcChooseConfig");
			break;
		}
		case OP_rcGetFBParam: {
			EGLint var_param = Unpack<EGLint,uint32_t>(ptr + 8);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8 + 4, ptr + 8 + 4, checksumSize, 
					"8 + 4::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			size_t totalTmpSize = sizeof(EGLint);
			totalTmpSize += checksumSize;
			unsigned char *tmpBuf = stream->alloc(totalTmpSize);
			DEBUG("renderControl(%p): rcGetFBParam(0x%08x )", stream,var_param);
			*(EGLint *)(&tmpBuf[0]) = 			this->rcGetFBParam(var_param);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::writeChecksum(&tmpBuf[0], totalTmpSize - checksumSize, &tmpBuf[totalTmpSize - checksumSize], checksumSize);
			}
			stream->flush();
			SET_LASTCALL("rcGetFBParam");
			break;
		}
		case OP_rcCreateContext: {
			uint32_t var_config = Unpack<uint32_t,uint32_t>(ptr + 8);
			uint32_t var_share = Unpack<uint32_t,uint32_t>(ptr + 8 + 4);
			uint32_t var_glVersion = Unpack<uint32_t,uint32_t>(ptr + 8 + 4 + 4);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8 + 4 + 4 + 4, ptr + 8 + 4 + 4 + 4, checksumSize, 
					"8 + 4 + 4 + 4::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			size_t totalTmpSize = sizeof(uint32_t);
			totalTmpSize += checksumSize;
			unsigned char *tmpBuf = stream->alloc(totalTmpSize);
			DEBUG("renderControl(%p): rcCreateContext(0x%08x 0x%08x 0x%08x )", stream,var_config, var_share, var_glVersion);
			*(uint32_t *)(&tmpBuf[0]) = 			this->rcCreateContext(var_config, var_share, var_glVersion);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::writeChecksum(&tmpBuf[0], totalTmpSize - checksumSize, &tmpBuf[totalTmpSize - checksumSize], checksumSize);
			}
			stream->flush();
			SET_LASTCALL("rcCreateContext");
			break;
		}
		case OP_rcDestroyContext: {
			uint32_t var_context = Unpack<uint32_t,uint32_t>(ptr + 8);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8 + 4, ptr + 8 + 4, checksumSize, 
					"8 + 4::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			DEBUG("renderControl(%p): rcDestroyContext(0x%08x )", stream,var_context);
			this->rcDestroyContext(var_context);
			SET_LASTCALL("rcDestroyContext");
			break;
		}
		case OP_rcCreateWindowSurface: {
			uint32_t var_config = Unpack<uint32_t,uint32_t>(ptr + 8);
			uint32_t var_width = Unpack<uint32_t,uint32_t>(ptr + 8 + 4);
			uint32_t var_height = Unpack<uint32_t,uint32_t>(ptr + 8 + 4 + 4);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8 + 4 + 4 + 4, ptr + 8 + 4 + 4 + 4, checksumSize, 
					"8 + 4 + 4 + 4::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			size_t totalTmpSize = sizeof(uint32_t);
			totalTmpSize += checksumSize;
			unsigned char *tmpBuf = stream->alloc(totalTmpSize);
			DEBUG("renderControl(%p): rcCreateWindowSurface(0x%08x 0x%08x 0x%08x )", stream,var_config, var_width, var_height);
			*(uint32_t *)(&tmpBuf[0]) = 			this->rcCreateWindowSurface(var_config, var_width, var_height);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::writeChecksum(&tmpBuf[0], totalTmpSize - checksumSize, &tmpBuf[totalTmpSize - checksumSize], checksumSize);
			}
			stream->flush();
			SET_LASTCALL("rcCreateWindowSurface");
			break;
		}
		case OP_rcDestroyWindowSurface: {
			uint32_t var_windowSurface = Unpack<uint32_t,uint32_t>(ptr + 8);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8 + 4, ptr + 8 + 4, checksumSize, 
					"8 + 4::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			DEBUG("renderControl(%p): rcDestroyWindowSurface(0x%08x )", stream,var_windowSurface);
			this->rcDestroyWindowSurface(var_windowSurface);
			SET_LASTCALL("rcDestroyWindowSurface");
			break;
		}
		case OP_rcCreateColorBuffer: {
			uint32_t var_width = Unpack<uint32_t,uint32_t>(ptr + 8);
			uint32_t var_height = Unpack<uint32_t,uint32_t>(ptr + 8 + 4);
			GLenum var_internalFormat = Unpack<GLenum,uint32_t>(ptr + 8 + 4 + 4);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8 + 4 + 4 + 4, ptr + 8 + 4 + 4 + 4, checksumSize, 
					"8 + 4 + 4 + 4::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			size_t totalTmpSize = sizeof(uint32_t);
			totalTmpSize += checksumSize;
			unsigned char *tmpBuf = stream->alloc(totalTmpSize);
			DEBUG("renderControl(%p): rcCreateColorBuffer(0x%08x 0x%08x 0x%08x )", stream,var_width, var_height, var_internalFormat);
			*(uint32_t *)(&tmpBuf[0]) = 			this->rcCreateColorBuffer(var_width, var_height, var_internalFormat);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::writeChecksum(&tmpBuf[0], totalTmpSize - checksumSize, &tmpBuf[totalTmpSize - checksumSize], checksumSize);
			}
			stream->flush();
			SET_LASTCALL("rcCreateColorBuffer");
			break;
		}
		case OP_rcOpenColorBuffer: {
			uint32_t var_colorbuffer = Unpack<uint32_t,uint32_t>(ptr + 8);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8 + 4, ptr + 8 + 4, checksumSize, 
					"8 + 4::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			DEBUG("renderControl(%p): rcOpenColorBuffer(0x%08x )", stream,var_colorbuffer);
			this->rcOpenColorBuffer(var_colorbuffer);
			SET_LASTCALL("rcOpenColorBuffer");
			break;
		}
		case OP_rcCloseColorBuffer: {
			uint32_t var_colorbuffer = Unpack<uint32_t,uint32_t>(ptr + 8);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8 + 4, ptr + 8 + 4, checksumSize, 
					"8 + 4::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			DEBUG("renderControl(%p): rcCloseColorBuffer(0x%08x )", stream,var_colorbuffer);
			this->rcCloseColorBuffer(var_colorbuffer);
			SET_LASTCALL("rcCloseColorBuffer");
			break;
		}
		case OP_rcSetWindowColorBuffer: {
			uint32_t var_windowSurface = Unpack<uint32_t,uint32_t>(ptr + 8);
			uint32_t var_colorBuffer = Unpack<uint32_t,uint32_t>(ptr + 8 + 4);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8 + 4 + 4, ptr + 8 + 4 + 4, checksumSize, 
					"8 + 4 + 4::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			DEBUG("renderControl(%p): rcSetWindowColorBuffer(0x%08x 0x%08x )", stream,var_windowSurface, var_colorBuffer);
			this->rcSetWindowColorBuffer(var_windowSurface, var_colorBuffer);
			SET_LASTCALL("rcSetWindowColorBuffer");
			break;
		}
		case OP_rcFlushWindowColorBuffer: {
			uint32_t var_windowSurface = Unpack<uint32_t,uint32_t>(ptr + 8);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8 + 4, ptr + 8 + 4, checksumSize, 
					"8 + 4::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			size_t totalTmpSize = sizeof(int);
			totalTmpSize += checksumSize;
			unsigned char *tmpBuf = stream->alloc(totalTmpSize);
			DEBUG("renderControl(%p): rcFlushWindowColorBuffer(0x%08x )", stream,var_windowSurface);
			*(int *)(&tmpBuf[0]) = 			this->rcFlushWindowColorBuffer(var_windowSurface);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::writeChecksum(&tmpBuf[0], totalTmpSize - checksumSize, &tmpBuf[totalTmpSize - checksumSize], checksumSize);
			}
			stream->flush();
			SET_LASTCALL("rcFlushWindowColorBuffer");
			break;
		}
		case OP_rcMakeCurrent: {
			uint32_t var_context = Unpack<uint32_t,uint32_t>(ptr + 8);
			uint32_t var_drawSurf = Unpack<uint32_t,uint32_t>(ptr + 8 + 4);
			uint32_t var_readSurf = Unpack<uint32_t,uint32_t>(ptr + 8 + 4 + 4);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8 + 4 + 4 + 4, ptr + 8 + 4 + 4 + 4, checksumSize, 
					"8 + 4 + 4 + 4::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			size_t totalTmpSize = sizeof(EGLint);
			totalTmpSize += checksumSize;
			unsigned char *tmpBuf = stream->alloc(totalTmpSize);
			DEBUG("renderControl(%p): rcMakeCurrent(0x%08x 0x%08x 0x%08x )", stream,var_context, var_drawSurf, var_readSurf);
			*(EGLint *)(&tmpBuf[0]) = 			this->rcMakeCurrent(var_context, var_drawSurf, var_readSurf);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::writeChecksum(&tmpBuf[0], totalTmpSize - checksumSize, &tmpBuf[totalTmpSize - checksumSize], checksumSize);
			}
			stream->flush();
			SET_LASTCALL("rcMakeCurrent");
			break;
		}
		case OP_rcFBPost: {
			uint32_t var_colorBuffer = Unpack<uint32_t,uint32_t>(ptr + 8);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8 + 4, ptr + 8 + 4, checksumSize, 
					"8 + 4::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			DEBUG("renderControl(%p): rcFBPost(0x%08x )", stream,var_colorBuffer);
			this->rcFBPost(var_colorBuffer);
			SET_LASTCALL("rcFBPost");
			break;
		}
		case OP_rcFBSetSwapInterval: {
			EGLint var_interval = Unpack<EGLint,uint32_t>(ptr + 8);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8 + 4, ptr + 8 + 4, checksumSize, 
					"8 + 4::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			DEBUG("renderControl(%p): rcFBSetSwapInterval(0x%08x )", stream,var_interval);
			this->rcFBSetSwapInterval(var_interval);
			SET_LASTCALL("rcFBSetSwapInterval");
			break;
		}
		case OP_rcBindTexture: {
			uint32_t var_colorBuffer = Unpack<uint32_t,uint32_t>(ptr + 8);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8 + 4, ptr + 8 + 4, checksumSize, 
					"8 + 4::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			DEBUG("renderControl(%p): rcBindTexture(0x%08x )", stream,var_colorBuffer);
			this->rcBindTexture(var_colorBuffer);
			SET_LASTCALL("rcBindTexture");
			break;
		}
		case OP_rcBindRenderbuffer: {
			uint32_t var_colorBuffer = Unpack<uint32_t,uint32_t>(ptr + 8);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8 + 4, ptr + 8 + 4, checksumSize, 
					"8 + 4::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			DEBUG("renderControl(%p): rcBindRenderbuffer(0x%08x )", stream,var_colorBuffer);
			this->rcBindRenderbuffer(var_colorBuffer);
			SET_LASTCALL("rcBindRenderbuffer");
			break;
		}
		case OP_rcColorBufferCacheFlush: {
			uint32_t var_colorbuffer = Unpack<uint32_t,uint32_t>(ptr + 8);
			EGLint var_postCount = Unpack<EGLint,uint32_t>(ptr + 8 + 4);
			int var_forRead = Unpack<int,uint32_t>(ptr + 8 + 4 + 4);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8 + 4 + 4 + 4, ptr + 8 + 4 + 4 + 4, checksumSize, 
					"8 + 4 + 4 + 4::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			size_t totalTmpSize = sizeof(EGLint);
			totalTmpSize += checksumSize;
			unsigned char *tmpBuf = stream->alloc(totalTmpSize);
			DEBUG("renderControl(%p): rcColorBufferCacheFlush(0x%08x 0x%08x %d )", stream,var_colorbuffer, var_postCount, var_forRead);
			*(EGLint *)(&tmpBuf[0]) = 			this->rcColorBufferCacheFlush(var_colorbuffer, var_postCount, var_forRead);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::writeChecksum(&tmpBuf[0], totalTmpSize - checksumSize, &tmpBuf[totalTmpSize - checksumSize], checksumSize);
			}
			stream->flush();
			SET_LASTCALL("rcColorBufferCacheFlush");
			break;
		}
		case OP_rcReadColorBuffer: {
			uint32_t var_colorbuffer = Unpack<uint32_t,uint32_t>(ptr + 8);
			GLint var_x = Unpack<GLint,uint32_t>(ptr + 8 + 4);
			GLint var_y = Unpack<GLint,uint32_t>(ptr + 8 + 4 + 4);
			GLint var_width = Unpack<GLint,uint32_t>(ptr + 8 + 4 + 4 + 4);
			GLint var_height = Unpack<GLint,uint32_t>(ptr + 8 + 4 + 4 + 4 + 4);
			GLenum var_format = Unpack<GLenum,uint32_t>(ptr + 8 + 4 + 4 + 4 + 4 + 4);
			GLenum var_type = Unpack<GLenum,uint32_t>(ptr + 8 + 4 + 4 + 4 + 4 + 4 + 4);
			uint32_t size_pixels  = Unpack<uint32_t,uint32_t>(ptr + 8 + 4 + 4 + 4 + 4 + 4 + 4 + 4);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8 + 4 + 4 + 4 + 4 + 4 + 4 + 4 + 4, ptr + 8 + 4 + 4 + 4 + 4 + 4 + 4 + 4 + 4, checksumSize, 
					"8 + 4 + 4 + 4 + 4 + 4 + 4 + 4 + 4::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			size_t totalTmpSize = size_pixels;
			totalTmpSize += checksumSize;
			unsigned char *tmpBuf = stream->alloc(totalTmpSize);
			OutputBuffer outptr_pixels(&tmpBuf[0], size_pixels);
			DEBUG("renderControl(%p): rcReadColorBuffer(0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x %p(%u) )", stream,var_colorbuffer, var_x, var_y, var_width, var_height, var_format, var_type, (void*)(outptr_pixels.get()), size_pixels);
			this->rcReadColorBuffer(var_colorbuffer, var_x, var_y, var_width, var_height, var_format, var_type, (void*)(outptr_pixels.get()));
			outptr_pixels.flush();
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::writeChecksum(&tmpBuf[0], totalTmpSize - checksumSize, &tmpBuf[totalTmpSize - checksumSize], checksumSize);
			}
			stream->flush();
			SET_LASTCALL("rcReadColorBuffer");
			break;
		}
		case OP_rcUpdateColorBuffer: {
			uint32_t var_colorbuffer = Unpack<uint32_t,uint32_t>(ptr + 8);
			GLint var_x = Unpack<GLint,uint32_t>(ptr + 8 + 4);
			GLint var_y = Unpack<GLint,uint32_t>(ptr + 8 + 4 + 4);
			GLint var_width = Unpack<GLint,uint32_t>(ptr + 8 + 4 + 4 + 4);
			GLint var_height = Unpack<GLint,uint32_t>(ptr + 8 + 4 + 4 + 4 + 4);
			GLenum var_format = Unpack<GLenum,uint32_t>(ptr + 8 + 4 + 4 + 4 + 4 + 4);
			GLenum var_type = Unpack<GLenum,uint32_t>(ptr + 8 + 4 + 4 + 4 + 4 + 4 + 4);
			uint32_t size_pixels  = Unpack<uint32_t,uint32_t>(ptr + 8 + 4 + 4 + 4 + 4 + 4 + 4 + 4);
			InputBuffer inptr_pixels(ptr + 8 + 4 + 4 + 4 + 4 + 4 + 4 + 4 + 4, size_pixels);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8 + 4 + 4 + 4 + 4 + 4 + 4 + 4 + 4 + size_pixels, ptr + 8 + 4 + 4 + 4 + 4 + 4 + 4 + 4 + 4 + size_pixels, checksumSize, 
					"8 + 4 + 4 + 4 + 4 + 4 + 4 + 4 + 4 + size_pixels::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			size_t totalTmpSize = sizeof(int);
			totalTmpSize += checksumSize;
			unsigned char *tmpBuf = stream->alloc(totalTmpSize);
			DEBUG("renderControl(%p): rcUpdateColorBuffer(0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x %p(%u) )", stream,var_colorbuffer, var_x, var_y, var_width, var_height, var_format, var_type, (void*)(inptr_pixels.get()), size_pixels);
			*(int *)(&tmpBuf[0]) = 			this->rcUpdateColorBuffer(var_colorbuffer, var_x, var_y, var_width, var_height, var_format, var_type, (void*)(inptr_pixels.get()));
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::writeChecksum(&tmpBuf[0], totalTmpSize - checksumSize, &tmpBuf[totalTmpSize - checksumSize], checksumSize);
			}
			stream->flush();
			SET_LASTCALL("rcUpdateColorBuffer");
			break;
		}
		case OP_rcOpenColorBuffer2: {
			uint32_t var_colorbuffer = Unpack<uint32_t,uint32_t>(ptr + 8);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8 + 4, ptr + 8 + 4, checksumSize, 
					"8 + 4::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			size_t totalTmpSize = sizeof(int);
			totalTmpSize += checksumSize;
			unsigned char *tmpBuf = stream->alloc(totalTmpSize);
			DEBUG("renderControl(%p): rcOpenColorBuffer2(0x%08x )", stream,var_colorbuffer);
			*(int *)(&tmpBuf[0]) = 			this->rcOpenColorBuffer2(var_colorbuffer);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::writeChecksum(&tmpBuf[0], totalTmpSize - checksumSize, &tmpBuf[totalTmpSize - checksumSize], checksumSize);
			}
			stream->flush();
			SET_LASTCALL("rcOpenColorBuffer2");
			break;
		}
		case OP_rcCreateClientImage: {
			uint32_t var_context = Unpack<uint32_t,uint32_t>(ptr + 8);
			EGLenum var_target = Unpack<EGLenum,uint32_t>(ptr + 8 + 4);
			GLuint var_buffer = Unpack<GLuint,uint32_t>(ptr + 8 + 4 + 4);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8 + 4 + 4 + 4, ptr + 8 + 4 + 4 + 4, checksumSize, 
					"8 + 4 + 4 + 4::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			size_t totalTmpSize = sizeof(uint32_t);
			totalTmpSize += checksumSize;
			unsigned char *tmpBuf = stream->alloc(totalTmpSize);
			DEBUG("renderControl(%p): rcCreateClientImage(0x%08x 0x%08x 0x%08x )", stream,var_context, var_target, var_buffer);
			*(uint32_t *)(&tmpBuf[0]) = 			this->rcCreateClientImage(var_context, var_target, var_buffer);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::writeChecksum(&tmpBuf[0], totalTmpSize - checksumSize, &tmpBuf[totalTmpSize - checksumSize], checksumSize);
			}
			stream->flush();
			SET_LASTCALL("rcCreateClientImage");
			break;
		}
		case OP_rcDestroyClientImage: {
			uint32_t var_image = Unpack<uint32_t,uint32_t>(ptr + 8);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8 + 4, ptr + 8 + 4, checksumSize, 
					"8 + 4::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			size_t totalTmpSize = sizeof(int);
			totalTmpSize += checksumSize;
			unsigned char *tmpBuf = stream->alloc(totalTmpSize);
			DEBUG("renderControl(%p): rcDestroyClientImage(0x%08x )", stream,var_image);
			*(int *)(&tmpBuf[0]) = 			this->rcDestroyClientImage(var_image);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::writeChecksum(&tmpBuf[0], totalTmpSize - checksumSize, &tmpBuf[totalTmpSize - checksumSize], checksumSize);
			}
			stream->flush();
			SET_LASTCALL("rcDestroyClientImage");
			break;
		}
		case OP_rcSelectChecksumCalculator: {
			uint32_t var_newProtocol = Unpack<uint32_t,uint32_t>(ptr + 8);
			uint32_t var_reserved = Unpack<uint32_t,uint32_t>(ptr + 8 + 4);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8 + 4 + 4, ptr + 8 + 4 + 4, checksumSize, 
					"8 + 4 + 4::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			DEBUG("renderControl(%p): rcSelectChecksumCalculator(0x%08x 0x%08x )", stream,var_newProtocol, var_reserved);
			this->rcSelectChecksumCalculator(var_newProtocol, var_reserved);
			SET_LASTCALL("rcSelectChecksumCalculator");
			break;
		}
		case OP_rcGetNumDisplays: {
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8, ptr + 8, checksumSize, 
					"8::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			size_t totalTmpSize = sizeof(int);
			totalTmpSize += checksumSize;
			unsigned char *tmpBuf = stream->alloc(totalTmpSize);
			DEBUG("renderControl(%p): rcGetNumDisplays()", stream);
			*(int *)(&tmpBuf[0]) = 			this->rcGetNumDisplays();
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::writeChecksum(&tmpBuf[0], totalTmpSize - checksumSize, &tmpBuf[totalTmpSize - checksumSize], checksumSize);
			}
			stream->flush();
			SET_LASTCALL("rcGetNumDisplays");
			break;
		}
		case OP_rcGetDisplayWidth: {
			uint32_t var_displayId = Unpack<uint32_t,uint32_t>(ptr + 8);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8 + 4, ptr + 8 + 4, checksumSize, 
					"8 + 4::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			size_t totalTmpSize = sizeof(int);
			totalTmpSize += checksumSize;
			unsigned char *tmpBuf = stream->alloc(totalTmpSize);
			DEBUG("renderControl(%p): rcGetDisplayWidth(0x%08x )", stream,var_displayId);
			*(int *)(&tmpBuf[0]) = 			this->rcGetDisplayWidth(var_displayId);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::writeChecksum(&tmpBuf[0], totalTmpSize - checksumSize, &tmpBuf[totalTmpSize - checksumSize], checksumSize);
			}
			stream->flush();
			SET_LASTCALL("rcGetDisplayWidth");
			break;
		}
		case OP_rcGetDisplayHeight: {
			uint32_t var_displayId = Unpack<uint32_t,uint32_t>(ptr + 8);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8 + 4, ptr + 8 + 4, checksumSize, 
					"8 + 4::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			size_t totalTmpSize = sizeof(int);
			totalTmpSize += checksumSize;
			unsigned char *tmpBuf = stream->alloc(totalTmpSize);
			DEBUG("renderControl(%p): rcGetDisplayHeight(0x%08x )", stream,var_displayId);
			*(int *)(&tmpBuf[0]) = 			this->rcGetDisplayHeight(var_displayId);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::writeChecksum(&tmpBuf[0], totalTmpSize - checksumSize, &tmpBuf[totalTmpSize - checksumSize], checksumSize);
			}
			stream->flush();
			SET_LASTCALL("rcGetDisplayHeight");
			break;
		}
		case OP_rcGetDisplayDpiX: {
			uint32_t var_displayId = Unpack<uint32_t,uint32_t>(ptr + 8);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8 + 4, ptr + 8 + 4, checksumSize, 
					"8 + 4::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			size_t totalTmpSize = sizeof(int);
			totalTmpSize += checksumSize;
			unsigned char *tmpBuf = stream->alloc(totalTmpSize);
			DEBUG("renderControl(%p): rcGetDisplayDpiX(0x%08x )", stream,var_displayId);
			*(int *)(&tmpBuf[0]) = 			this->rcGetDisplayDpiX(var_displayId);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::writeChecksum(&tmpBuf[0], totalTmpSize - checksumSize, &tmpBuf[totalTmpSize - checksumSize], checksumSize);
			}
			stream->flush();
			SET_LASTCALL("rcGetDisplayDpiX");
			break;
		}
		case OP_rcGetDisplayDpiY: {
			uint32_t var_displayId = Unpack<uint32_t,uint32_t>(ptr + 8);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8 + 4, ptr + 8 + 4, checksumSize, 
					"8 + 4::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			size_t totalTmpSize = sizeof(int);
			totalTmpSize += checksumSize;
			unsigned char *tmpBuf = stream->alloc(totalTmpSize);
			DEBUG("renderControl(%p): rcGetDisplayDpiY(0x%08x )", stream,var_displayId);
			*(int *)(&tmpBuf[0]) = 			this->rcGetDisplayDpiY(var_displayId);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::writeChecksum(&tmpBuf[0], totalTmpSize - checksumSize, &tmpBuf[totalTmpSize - checksumSize], checksumSize);
			}
			stream->flush();
			SET_LASTCALL("rcGetDisplayDpiY");
			break;
		}
		case OP_rcGetDisplayVsyncPeriod: {
			uint32_t var_displayId = Unpack<uint32_t,uint32_t>(ptr + 8);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8 + 4, ptr + 8 + 4, checksumSize, 
					"8 + 4::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			size_t totalTmpSize = sizeof(int);
			totalTmpSize += checksumSize;
			unsigned char *tmpBuf = stream->alloc(totalTmpSize);
			DEBUG("renderControl(%p): rcGetDisplayVsyncPeriod(0x%08x )", stream,var_displayId);
			*(int *)(&tmpBuf[0]) = 			this->rcGetDisplayVsyncPeriod(var_displayId);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::writeChecksum(&tmpBuf[0], totalTmpSize - checksumSize, &tmpBuf[totalTmpSize - checksumSize], checksumSize);
			}
			stream->flush();
			SET_LASTCALL("rcGetDisplayVsyncPeriod");
			break;
		}
		case OP_rcPostLayer: {
			uint32_t size_name  = Unpack<uint32_t,uint32_t>(ptr + 8);
			InputBuffer inptr_name(ptr + 8 + 4, size_name);
			uint32_t var_colorBuffer = Unpack<uint32_t,uint32_t>(ptr + 8 + 4 + size_name);
			float var_alpha = Unpack<float,uint32_t>(ptr + 8 + 4 + size_name + 4);
			int32_t var_sourceCropLeft = Unpack<int32_t,uint32_t>(ptr + 8 + 4 + size_name + 4 + 4);
			int32_t var_sourceCropTop = Unpack<int32_t,uint32_t>(ptr + 8 + 4 + size_name + 4 + 4 + 4);
			int32_t var_sourceCropRight = Unpack<int32_t,uint32_t>(ptr + 8 + 4 + size_name + 4 + 4 + 4 + 4);
			int32_t var_sourceCropBottom = Unpack<int32_t,uint32_t>(ptr + 8 + 4 + size_name + 4 + 4 + 4 + 4 + 4);
			int32_t var_displayFrameLeft = Unpack<int32_t,uint32_t>(ptr + 8 + 4 + size_name + 4 + 4 + 4 + 4 + 4 + 4);
			int32_t var_displayFrameTop = Unpack<int32_t,uint32_t>(ptr + 8 + 4 + size_name + 4 + 4 + 4 + 4 + 4 + 4 + 4);
			int32_t var_displayFrameRight = Unpack<int32_t,uint32_t>(ptr + 8 + 4 + size_name + 4 + 4 + 4 + 4 + 4 + 4 + 4 + 4);
			int32_t var_displayFrameBottom = Unpack<int32_t,uint32_t>(ptr + 8 + 4 + size_name + 4 + 4 + 4 + 4 + 4 + 4 + 4 + 4 + 4);
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8 + 4 + size_name + 4 + 4 + 4 + 4 + 4 + 4 + 4 + 4 + 4 + 4, ptr + 8 + 4 + size_name + 4 + 4 + 4 + 4 + 4 + 4 + 4 + 4 + 4 + 4, checksumSize, 
					"8 + 4 + size_name + 4 + 4 + 4 + 4 + 4 + 4 + 4 + 4 + 4 + 4::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			DEBUG("renderControl(%p): rcPostLayer(%p(%u) 0x%08x %d 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x )", stream,(const char*)(inptr_name.get()), size_name, var_colorBuffer, var_alpha, var_sourceCropLeft, var_sourceCropTop, var_sourceCropRight, var_sourceCropBottom, var_displayFrameLeft, var_displayFrameTop, var_displayFrameRight, var_displayFrameBottom);
			this->rcPostLayer((const char*)(inptr_name.get()), var_colorBuffer, var_alpha, var_sourceCropLeft, var_sourceCropTop, var_sourceCropRight, var_sourceCropBottom, var_displayFrameLeft, var_displayFrameTop, var_displayFrameRight, var_displayFrameBottom);
			SET_LASTCALL("rcPostLayer");
			break;
		}
		case OP_rcPostAllLayersDone: {
			if (useChecksum) {
				ChecksumCalculatorThreadInfo::validOrDie(ptr, 8, ptr + 8, checksumSize, 
					"8::decode, OP_renderControl_decoder_context_t: GL checksumCalculator failure\n");
			}
			DEBUG("renderControl(%p): rcPostAllLayersDone()", stream);
			this->rcPostAllLayersDone();
			SET_LASTCALL("rcPostAllLayersDone");
			break;
		}
			default:
				unknownOpcode = true;
		} //switch
		if (!unknownOpcode) {
			pos += packetLen;
			ptr += packetLen;
		}
	} // while
	return pos;
}
