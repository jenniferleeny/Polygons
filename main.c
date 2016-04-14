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
  struct matrix *transform_y;

  edges = new_matrix(4, 4);
  transform = new_matrix(4, 4);
  ident(transform);
  transform = make_rotX(20);
  transform_y = new_matrix(4, 4);
  ident(transform_y);
  transform_y = make_rotY(20);

  add_box(edges, 0, 0, 0, 200, 100, 300);
  matrix_mult(transform, edges);
  matrix_mult(transform_y, edges);
  draw_polygons(edges, s, c);
  display(s);
  /*  if ( argc == 2 )
    parse_file( argv[1], transform, edges, s );
  else
    parse_file( "stdin", transform, edges, s );
  */
  free_matrix( transform );
  free_matrix( edges );
}  
