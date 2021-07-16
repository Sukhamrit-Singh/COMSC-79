/*
This is the header file that declares the 
typedef for vec2d and declares the prototypes 
for the functions from vector2d.c
Sukhamrit Singh, July 16, 2021
*/

/*
preprocessor directives that prevent the 
file from being included twice.
*/
#ifndef _VECTOR2D_H
#define _VECTOR2D_H

// declaring the structures and prototype methods
// that will be used in the vector2d.c file
typedef  struct {
    double  x;
    double  y;
} vec2d;

void display_vector(const vec2d v);

double magnitude(const vec2d v);

vec2d add(const vec2d v1, const vec2d v2);

vec2d scale(const vec2d v, const double factor);

double dot_product(const vec2d v1, const vec2d v2);

// concluding the preprocessor directives
#endif /* _VECTOR2D_H */