/*
 * Copyright (c) 1999-2007 Ruda Moura <ruda.moura@gmail.com>
 */

#include <X11/Xlib.h>
#include <X11/extensions/xf86vmode.h>

#define NEXT_MODE	+1
#define PREVIOUS_MODE	-1

void open_display(void);
int close_display(void);
void get_current_mode(void);
void get_all_modes(void);
void set_mode(int, int);
void set_zoom_mode(int);
