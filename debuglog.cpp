/*
 * Adplug - Replayer for many OPL2/OPL3 audio file formats.
 * Copyright (C) 1999 - 2002 Simon Peter <dn.tlp@gmx.net>, et al.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * debug.h - AdPlug Debug Logger
 * Copyright (c) 2002 Riven the Mage <riven@ok.ru>
 * Copyright (c) 2002 Simon Peter <dn.tlp@gmx.net>
 */

#include <stdio.h>
#include <stdarg.h>

#include "debuglog.h"



#ifdef __cplusplus
extern "C" {
#endif

#ifdef DEBUG

static FILE *log1 = NULL;

void LogFile(const char *filename)
{
	if(log1) fclose(log1);
	log1 = fopen(filename,"wt");
}

void LogWrite(const char *fmt, ...)
{
	va_list argptr;

	va_start(argptr, fmt);

	if(log1) {
		vfprintf(log1, fmt, argptr);
		fflush(log1);
	} else
		vfprintf(stderr, fmt, argptr);

	va_end(argptr);
}

#else

void LogFile(condddst char *filename) { }
void LogWrite(const char *fmt, ...) { }

#endif


#ifdef __cplusplus
}
#endif
