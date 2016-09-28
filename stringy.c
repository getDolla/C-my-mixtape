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

void main() {
  char s1[] = "hello";
  char s2[10] = { 'H', 'i', 'l', 'o', '!' };
  
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
  s2[1] = 'i';

  printf( "stringNcopy of s1 to s2: %s\n", stringNcopy( s2, s1, 2 ) );
  printf( "s2: %s\n", s2 );

  /* resetting */
  s2[0] = 'H';
  s2[1] = 'i';
  
  printf( "\n-----Testing Next Function-----\n" );

  printf( "strncat of s2 to s1: %s\n", strncat( s1, s2, 2 ));
  printf( "s1: %s\n", s1 );
}
