/* 
 * fmap.c
 * --------------
 * Deals with everything involving float maps.
 * Note that FMAP is just FTYPE*
 * FTYPE is a preprocessor definition
*/

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

#include "fmap.h"

// Load a voltage map containing floats/doubles in a row.
// The last float/double is a NaN.
// Don't forget to release the memory allocated!
FMAP loadmap_raw(char* fname)
{
	FILE* f = fopen(fname, "r");

	if (f == NULL)
		return NULL;
        
	fseek(f, 0, SEEK_END);
	// The number of FTYPEs in the file to load.
	long len = ftell(f) / sizeof(FTYPE);
	rewind(f);

    // The len does not include the last NaN, although the space is allocated.
	FMAP vmap = calloc(len + 1, sizeof(FTYPE));
	if (vmap == NULL)
    {
        fclose(f);
		return NULL;
    }

	// Actually read the data.
	fread(vmap, sizeof(FTYPE), len, f);
	fclose(f);
    
    // Set the trailing NaN
    vmap[len] = (FTYPE)NAN;
    
    return vmap;
}

// Generate a voltage map in a sine wave.
FMAP genmap_sin(FTYPE maxv, FTYPE hz, FTYPE startt, FTYPE sec, FTYPE dt)
{
	FTYPE w = TWOPI * hz;
    
    long len = ((long)(sec / dt));
    // The last float is a NaN. The len does not include this.
    FTYPE* vmap = calloc(len + 1, sizeof(FTYPE));
    
    FTYPE t = startt;
    for (int i=0; i < len; i++, t += dt)
    {
        vmap[i] = maxv * (FTYPE)sin((double)(w * t));
    }
    
    // Set the trailing NaN
    vmap[len] = (FTYPE)NAN;
    
    return vmap;
}

// Return the length of a mapping.
// The last entry in a map is a NaN.
long maplen(FMAP map)
{
    long i = 0;
    // NaN does not compare equal to itself.
    while (map[i] == map[i])
        i++;
    return i;
}

// Save a float map to file
int savemap(FMAP map, char* fname)
{
    FILE* f = fopen(fname, "w");
    if (f == NULL)
        return 0;
        
    long len = maplen(map);
    size_t writelen = fwrite(map, sizeof(FTYPE), len, f);
    fclose(f);
    
    if (writelen == len)
        return 1;
    else
        return 0;
}

void freemap(FMAP map)
{
    free(map);
}



// END OF LINE.
