/* 
 * main.c
 * --------------
 * Controls everything related to the actual startup of the program.
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

#include "main.h"

int main(int argc, char* argv[])
{
    printf("Generating vmap...\n");
    FMAP vmap = genmap_sin(.8, 440.0, 0.1, 2.0, 1e-5);
    printf("Generated.\n");
    if (!savemap(vmap, "test"))
    {
        printf("Could not save...\n");
        return 1;
    }
    freemap(vmap);
    printf("Finished!\n");
    return 0;
}





// END OF LINE.
