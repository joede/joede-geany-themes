#include <stdio.h>
#include <stdbool.h>

struct POINT { int x; int y; }
typedef struct POINT point_t;

// a simple comment
#define DEFAULT_STR "some text"

/** A sample for an doc comment
 *
 * @parm point
 */
void sample ( point_t *point )
{
    point->x = 321;
    point->y = 123;
}

int main ( int argc, char **argv )
{
    printf("Hello Geany\n");
    sample(&point);
    return 0;
}
