#include <stdio.h>			     /* fprintf, perror */
#include <stdlib.h>			     /* malloc, free, EXIT_* */
#include <string.h>			     /* strcmp, size_t */
#include "parse_points.h"		     /* parse_points */
#include "smallest_circle/smallest_circle.h" /* smallest_circle */


static inline void usage(const char *program)
{
	(void) fprintf(
		stderr,
		"\nusage:"
		"\n\t%s <X_0,Y_0> [X_i,Y_i ...]\n",
		program
	);
}

int main(int argc, char *argv[])
{
	if (   (argc <= 2)
	    || (strcmp(argv[1], "-h"    ) == 0)
	    || (strcmp(argv[1], "--help") == 0)) {
		usage(argv[0]);
		return EXIT_FAILURE;
	}

	size_t count_points = (size_t) (argc - 1);
	size_t length       = count_points * 2;
	double *points = malloc(count_points * sizeof(double));
	if (points == NULL) {
		perror("malloc() failure");
		return EXIT_FAILURE;
	}

	int exit_status  = EXIT_SUCCESS;
	long error_index = parse_points(points,
					(const char **) ++argv, count_points);
	if (error_index < 0) {
		double x, y, r;
		smallest_circle(&x, &y, &r, points, length);

		if (printf("x=%f, y=%f, r=%f\n", x, y, r) < 0) {
			perror("printf() failure");
			exit_status = EXIT_FAILURE;
		}
	} else {
		(void) fprintf(stderr,
			       "failed to parse point %lu: \"%s\"\n",
			       (unsigned long) error_index,
			       argv[error_index]);
		exit_status = EXIT_FAILURE;
	}

	free(points);
	return exit_status;
}
