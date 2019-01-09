/*
 * Copyright (c) 1999-2007 by Ruda Moura <ruda.moura@gmail.com>
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Xvidmode.h"

Display *Dpy;
XF86VidModeModeInfo **ModesInfo;

void
open_display(void)
{
	Dpy = XOpenDisplay(NULL);
	if (!Dpy) {
		perror("can't open display");
		exit(1);
	}
}

int
close_display(void)
{
	return XCloseDisplay(Dpy);
}

void
get_current_mode(void)
{
	int max;
	
	XF86VidModeGetAllModeLines(Dpy, XDefaultScreen(Dpy), &max, &ModesInfo);
	printf("%ix%i\n", ModesInfo[0]->hdisplay, ModesInfo[0]->vdisplay);
}

void
get_all_modes()
{
	int i, max;

	XF86VidModeGetAllModeLines(Dpy, XDefaultScreen(Dpy), &max, &ModesInfo);
	for(i=0; i < max; i++)
		printf("%ix%i\n", ModesInfo[i]->hdisplay,
				  ModesInfo[i]->vdisplay);
}

void
set_mode(int hres, int vres)
{
	int i, max;
	
	XF86VidModeGetAllModeLines(Dpy, XDefaultScreen(Dpy), &max, &ModesInfo);
	for (i=0; i < max; i++)
		if ((ModesInfo[i]->hdisplay == hres) &&
		    (ModesInfo[i]->vdisplay == vres)) {
			XF86VidModeSwitchToMode(Dpy,
						XDefaultScreen(Dpy),
						ModesInfo[i]);
			XFlush(Dpy);
			return;
		}
	fprintf(stderr, "could not set screen to %dx%d\n", hres, vres);
	exit(1);
}

void
set_zoom_mode(int zoom)
{
	XF86VidModeSwitchMode(Dpy, XDefaultScreen(Dpy), zoom);
	XFlush(Dpy);
}

void
next_mode(void) { set_zoom_mode(NEXT_MODE); }

void
previous_mode(void) { set_zoom_mode(PREVIOUS_MODE); }
