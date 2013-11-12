/* 
 * fmap.h
 * --------------
 * Deals with everything involving float maps.
 * A float map can be thought of as the graph of a signal.
 * Note that FMAP is just FTYPE*
 * FTYPE is a preprocessor definition
*/
#pragma once

/*
------------------------------------------------------------------------
    This file is part of rlcsim.

    rlcsim is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    rlcsim is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with rlcsim.  If not, see <http://www.gnu.org/licenses/>.
------------------------------------------------------------------------
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define TWOPI 6.283185307

#ifndef FTYPE
#define FTYPE double
#endif

#ifndef FMAP
#define FMAP FTYPE*
#endif


FMAP loadmap_raw(char* fname);
FMAP genmap_sin(FTYPE maxv, FTYPE hz, FTYPE startt, FTYPE sec, FTYPE dt);
long maplen(FMAP map);
int savemap(FMAP map, char* fname);
void freemap(FMAP map);

// END OF LINE.
