#include <limits.h>  /* UCHAR_MAX */
#include <time.h>    /* time, ctime */
#include <stdio.h>   /* FILE, print utilities */
#include <string.h>  /* strerro */
#include <stdlib.h>  /* exit */
#include <errno.h>   /* errno */

#if (UCHAR_MAX <= 255)
#	define FULL_TABLE      1
#	define DIGIT_TABLE_MAX ((unsigned int) UCHAR_MAX)
#else
#	define FULL_TABLE      1
#	define DIGIT_TABLE_MAX 'z'
#endif

#define SHIFT_WIDTH 8 /* spaces per tab */
#define LINE_WIDTH  (80 - SHIFT_WIDTH)


static FILE *output;
static char *path;
static int cell_width;
static int line_width; /* not including tab or newline */
static int rem_line_width;
static int room_for_another_cell;


void
open_output(int   argc,
	    char *argv[])
{
	if (argc < 2) {
		(void) fprintf(stderr,
			       "usage:\n\t%s <OUTPUT_PATH>\n", argv[0]);
		exit(1);
	}

	path   = argv[1];
	output = fopen(path, "w");

	if (output == NULL) {
		(void) fprintf(stderr,
			       "failed to open '%s' for writing: %s\n",
			       path,
			       strerror(errno));
		exit(2);
	}
}

void
put_header()
{
	time_t now = time(NULL);
	int status = fprintf(
		output,
		  "/**"
		"\n * token -> value lookup table for convert_base (DO NOT MODIFY)"
		"\n *"
		"\n * generated on: %s" /* terminated with  */
		"\n ******************************************************************************/"
		"\n#include \"get_digit.h\" /* declarations */"
		"\n#include \"limits.h\"    /* UCHAR_MAX */"
		"\n"
		"\nstatic const unsigned char digit_table[%u] = {",
		ctime(&now),
		DIGIT_TABLE_MAX + 1
	);
	if (status < 0) {
		perror("put_header() failure");
		exit(3);
	}

}

void
set_table_format()
{
	cell_width = snprintf(NULL, 0, "%u", DIGIT_TABLE_MAX);
	if (cell_width < 0) {
		perror("set_table_format() failure");
		exit(4);
	}

	int single_cell_line_width = cell_width + 1; /* '<CELL>,' */
	line_width = (single_cell_line_width > LINE_WIDTH)
		   ? single_cell_line_width : LINE_WIDTH;

	rem_line_width = line_width;
	room_for_another_cell = cell_width + 2;
}

void
put_next_digit(unsigned int digit)
{
	static const char *delim = "\n\t";
	static int delim_width   = 0; /* excluding tabs and newlines */

	int status = fprintf(output, "%s%*u", delim, cell_width, digit);
	if (status < 0) {
		perror("put_next_digit() failure");
		exit(5);
	}

	rem_line_width -= (cell_width + delim_width);

	if (rem_line_width <= room_for_another_cell) {
		rem_line_width = line_width;
		delim	       = ",\n\t";
		delim_width    = 0;
	} else {
		delim	       = ", ";
		delim_width    = 2;
	}
}

void
put_table_close()
{
	int status = fputs(
		"\n};"
		"\n"
		"\nunsigned char"
		"\nget_digit(unsigned char token)"
		"\n{"
#if !FULL_TABLE
		"\n\tif (token > 'z')"
		"\n\t\treturn UCHAR_MAX;"
		"\n"
#endif
		"\n\treturn digit_table[token];"
		"\n}",
		output
	);
	if (status == EOF) {
		perror("put_table_close() failure");
		exit(3);
	}
}

void
close_output()
{
	if (fclose(output) != 0) {
		(void) fprintf(stderr,
			       "failed to close '%s': %s\n",
			       path,
			       strerror(errno));
		exit(3);
	}
}

int
main(int   argc,
     char *argv[])
{
	open_output(argc, argv);

	put_header();

	set_table_format();

	unsigned int digit;
	unsigned int base;

	for (digit = '\0'; digit <= '0'; ++digit)
		put_next_digit(UCHAR_MAX);
	for (; digit <= '9'; ++digit)
		put_next_digit(digit & 15u);
	for (; digit < 'A'; ++digit)
		put_next_digit(UCHAR_MAX);
	for (base = 10; digit <= 'Z'; ++digit, ++base)
		put_next_digit(base);
	for (; digit < 'a'; ++digit)
		put_next_digit(UCHAR_MAX);
	for (base = 10; digit <= 'z'; ++digit, ++base)
		put_next_digit(base);
	for (; digit <= DIGIT_TABLE_MAX; ++digit)
		put_next_digit(UCHAR_MAX);

	put_table_close();

	close_output();

	return 0;
}
