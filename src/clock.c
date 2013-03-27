/***************************************************************************
 *   Copyright (C) 2013 by Gilles Talis                                    *
 *   gilles.talis@gmail.com                                                *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <fcntl.h>
#include <unistd.h>
#include <SDL.h>
#include <SDL_image.h>

#include "gfx.h"
#include "clock.h"
#include <time.h>

extern SFont_Font *font_normal;
time_t  time_now;
struct tm *local_time_now;
char timestr[10];

int clock_init()
{
    return 0;
}

int clock_draw(SDL_Surface * screen)
{
    /* get time now */
    time(&time_now);

    local_time_now = localtime(&time_now);
    snprintf(timestr, 10, "%02d:%02d", local_time_now->tm_hour, local_time_now->tm_min);

    /* Draw digital clock */
    gfx_draw_text(screen, font_normal, 10, 10, 0, 0, timestr);

    return 0;
}
