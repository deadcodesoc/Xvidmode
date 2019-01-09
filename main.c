/*
 * Copyright (c) 1999-2007 Ruda Moura <ruda.moura@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Xvidmode.h"

static char *Version = "Xvidmode 0.5";

static char *Usage = "Usage: Xvidmode [OPTIONS]\n\
Get/set X video modes.\n\n\
\tXvidmode\t\t\tget current video mode\n\
\tXvidmode -h, -help\t\tdisplay this help\n\
\tXvidmode -n, -next \t\tgo to the next mode\n\
\tXvidmode -p, -previous\t\tgo to the previous mode\n\
\tXvidmode -l, -listall\t\tget all video modes available\n\
\tXvidmode -v, -version\t\toutput version information\n\
\tXvidmode <hres>x<yres>\t\tswitch to video mode <hres>x<yres>\n\n\
Report bugs to Ruda Moura <ruda@rudix.org>\n";

void
display(const char *message)
{
	printf("%s\n", message);
	exit(0);
}

void
mode(char *mode)
{
	int hres, vres;
	char *s;
	s = strtok(mode, "x");
	hres = atoi(s);
	s = strtok(NULL, "x");
	vres = atoi(s);
	set_mode(hres, vres);	
	free(s);
}

int
main(int argc, char *argv[])
{
	int hres, vres;

	open_display();

	if (argc == 1) {
		get_current_mode();
		return 0;
	}
	while (*++argv) {
		if (!strcmp(*argv, "-h") || !strcmp(*argv, "-help"))
			display(Usage);
		else if (!strcmp(*argv, "-l") || !strcmp(*argv, "-listall"))
			get_all_modes();
		else if (!strcmp(*argv, "-n") || !strcmp(*argv, "-next"))
			set_zoom_mode(NEXT_MODE);
		else if (!strcmp(*argv, "-p") || !strcmp(*argv, "-previous"))
			set_zoom_mode(PREVIOUS_MODE);
		else if (!strcmp(*argv, "-v") || !strcmp(*argv, "-version"))
			display(Version);
		else if (!strcmp(*argv, "-m") || !strcmp(*argv, "-mode"))
			mode(*++argv);
		else
			display(Usage);
	}

	close_display();
	return 0;
}
