#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"
#include "parser.h"

int main( int argc, char** argv ) {

  screen s;

  clear_screen(s);

  color c;
  c.red = 255;
  c.blue = 0;
  c.green = 0;
  struct matrix *edges;
  struct matrix *transform;

  edges = new_matrix(4, 4);
  transform = new_matrix(4, 4);
  //generate_sphere(edges, 0, 0, 100, 10);
  add_sphere(edges, 250, 250, 100, 10);
  draw_polygons(edges, s, c);
  //print_matrix(edges);
  //draw_lines(edges, s, c);
  display(s);
  /*  if ( argc == 2 )
    parse_file( argv[1], transform, edges, s );
  else
    parse_file( "stdin", transform, edges, s );
  */
  free_matrix( transform );
  free_matrix( edges );
}  
