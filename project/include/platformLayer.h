/* Exit Games Common - C Client Lib
 * Copyright (C) 2004-2013 by Exit Games GmbH. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __PLATFORM_LAYER_H
#define __PLATFORM_LAYER_H

#include "defines.h"

#ifdef _EG_UNIX_PLATFORM
	int EG_strnicmp(const char* str1, const char* str2, unsigned int count);
	int getTimeUnix(void);
#endif

#if defined _EG_MARMALADE_PLATFORM && defined I3D_ARCH_ARM || defined _EG_ANDROID_PLATFORM
	int EG_vswprintf(EG_CHAR* wcs, size_t maxlen, const EG_CHAR* format, va_list args);
	int EG_swprintf(EG_CHAR* wcs, size_t maxlen, const EG_CHAR* format, ...);
#endif

#ifdef _EG_APPLE_PLATFORM
	void clientCB(CFReadStreamRef stream, CFStreamEventType eventType, void* clientCallBackInfo);
#endif

#ifdef _EG_ANDROID_PLATFORM
	size_t EG_wcslen(const EG_CHAR* wcs);
	int EG_wcscmp (const EG_CHAR* src, const EG_CHAR* dst);
	EG_CHAR* EG_wcscpy(EG_CHAR * dst, const EG_CHAR * src);
	EG_CHAR* EG_wcscat (EG_CHAR * dst, const EG_CHAR * src);
	EG_CHAR* EG_wcsstr(const EG_CHAR* wcs1, const EG_CHAR* wcs2);
	size_t EG_wcsnlen(const EG_CHAR *s, size_t maxlen);
	EG_CHAR* EG_wcschr(const EG_CHAR * string, EG_CHAR ch);
	int EG_wcsncmp(const EG_CHAR * first, const EG_CHAR * last, size_t count);
	wchar_t * EG_wcsrchr (const EG_CHAR * string, EG_CHAR ch);
#endif

#endif