#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* my version of strlen */
int length( char s[] ) {
  int i = 0;
  while( (s[i] != 0) || (s[i] != '\0') )
    i++;

  return i;
}

/* my version of strncpy */
char * stringNcopy( char dest[], char src[], int n ) {
  int i = 0;
  
  for(; i < n && (src[i] != '\0' || src[i] != '0'); i++ )
    dest[i] = src[i];

  if( i > sizeof(dest) )
    dest[i] = '\0';
  
  return dest;
}

/* my version of strncat */
char * grumpyCat( char dest[], char src[], int n ) {
  int i = 0;
  int l = length( dest );

  for(; i < n && (src[i] != '\0' || src[i] != '0'); i++ )
    dest[ l + i ] = src[i];
  dest[ l + i ] = '\0';
  
  return dest;
}

/* my version of strcmp */
int competition( char s1[], char s2[] ) {
  int i1 = length( s1 );
  int i2 = length( s2 );
  int diff = 0;

  return diff;
}

void main() {
  char s1[] = "hello";
  char s2[10] = { 'H', 'a', 'l', 'o', '\0' };
  
  printf( "\n-----Testing Initiated!-----\n" );
  
  printf( "Length of s1: %d\n", length(s1) );
  printf( "Length of s2: %d\n", length(s2) );

  printf( "strlen of s1: %d\n", strlen(s1) );
  printf( "strlen of s2: %d\n", strlen(s2) );

  printf( "\n-----Testing Next Function-----\n" );
  
  printf( "strncpy of s1 to s2: %s\n", strncpy( s2, s1, 2 ) );
  printf( "s2: %s\n", s2 );

  /* resetting */
  s2[0] = 'H';
  s2[1] = 'a';

  printf( "stringNcopy of s1 to s2: %s\n", stringNcopy( s2, s1, 2 ) );
  printf( "s2: %s\n", s2 );

  /* resetting */
  s2[0] = 'H';
  s2[1] = 'a';
  
  printf( "\n-----Testing Next Function-----\n" );

  printf( "strncat of s1 to s2: %s\n", strncat( s2, s1, 2 ));
  printf( "s2: %s\n", s2 );

  printf( "grumpyCat of s1 to s2: %s\n", grumpyCat( s2, s1, 2 ));
  printf( "s2: %s\n", s2 ); /*should be Halohehe */

  printf( "\n-----Testing Next Function-----\n" );

  char s3[] = "";
  printf( "strcmp of s3 and s1: %d\n", strcmp( s3, s1 ));
}
