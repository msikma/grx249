/**
 ** sdl16.c ---- the 32768/65536 color SDL frame buffer driver
 **
 ** Copyright (C) 2004 Dimitar Zhekov
 ** [e-mail: jimmy@is-vn.bg]
 **
 ** This file is part of the GRX graphics library.
 **
 ** The GRX graphics library is free software; you can redistribute it
 ** and/or modify it under some conditions; see the "copying.grx" file
 ** for details.
 **
 ** This library is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 **
 **/

/* some systems map LFB in normal user space (eg. Linux/svgalib) */
/* near pointer stuff is equal to ram stuff :)                   */
/* in this is the far pointer code using %fs descriptor          */
#ifndef LFB_BY_NEAR_POINTER

#ifdef   __TURBOC__
#error This library will not work with as a 16-bit real-mode code
#endif

/* -------------------------------------------------------------------- */


#define FAR_ACCESS
#include "fdrivers/driver16.h"

static
#include "fdrivers/generic/putscl.c"

#include "fdrivers/sdlframe.h"

/* -------------------------------------------------------------------- */

GrFrameDriver _GrFrameDriverSDL16 = {
    GR_frameSDL16,              /* frame mode */
    GR_frameRAM16,              /* compatible RAM frame mode */
    TRUE,                       /* onscreen */
    4,                          /* scan line width alignment */
    1,                          /* number of planes */
    16,                         /* bits per pixel */
    16*16*1024L*1024L,          /* max plane size the code can handle */
    NULL,
    readpixel,
    sdl_drawpixel,
    sdl_drawline,
    sdl_drawhline,
    sdl_drawvline,
    sdl_drawblock,
    sdl_drawbitmap,
    sdl_drawpattern,
    sdl_bitblt,
    bltv2r,
    sdl_bltr2v,
    _GrFrDrvGenericGetIndexedScanline,
    sdl_putscanline
};

#endif
