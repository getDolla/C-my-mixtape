/*
Yikai Wang
Period 4 Systems
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* 1: my version of strlen */
int length( char s[] ) {
  int i = 0;
  while( (s[i] != 0) || (s[i] != '\0') )
    i++;

  return i;
}

/* 2: my version of strncpy */
char * stringNcopy( char dest[], char src[], int n ) {
  int i = 0;
  
  for(; i < n && (src[i] != '\0' || src[i] != '0'); i++ )
    dest[i] = src[i];

  if( i > sizeof(dest) )
    dest[i] = '\0';
  
  return dest;
}

/* 3: my version of strncat */
char * grumpyCat( char dest[], char src[], int n ) {
  int i = 0;
  int l = length( dest );

  for(; i < n && (src[i] != '\0' || src[i] != '0'); i++ )
    dest[ l + i ] = src[i];
  dest[ l + i ] = '\0';
  
  return dest;
}

/* 4: my version of strcmp */
int competition( char s1[], char s2[] ) {
  int i1 = length( s1 );
  int i2 = length( s2 );
  int ctr = 0;
  int diff = 0;

  do
    diff = s1[ctr] - s2[ctr++];  
  while( (i1 > ctr) && (i2 > ctr) && (diff == 0) );
    
  return diff;
}

/* 5: my version of strchr */
char * stringyChar( char s[], char c ) {
  int i = 0;
  int l = length( s );
  
  while(s[i] != c) {
    if (i >= l)
      return '\0'; 
    i++;
  }

  return s + i;
}

void main() {
  char s1[] = "hello";
  char s2[10] = { 'H', 'a', 'l', 'o', '\0' };
  char s3[] = "";
  char s4[] = "hello";
  char s5[] = "hella";

  printf( "\n-----Variables-----\n" );

  printf( "s1: %s\n", s1 );
  printf( "s2: %s\n", s2 );
  printf( "s3: %s\n", s3 );
  printf( "s4: %s\n", s4 );
  printf( "s5: %s\n", s5 );
  
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
  
  printf( "strcmp of s3 and s1: %d\n", strcmp( s3, s1 ));
  printf( "strcmp of s1 and s2: %d\n", strcmp( s1, s2 ));
  printf( "strcmp of s4 and s1: %d\n", strcmp( s4, s1 ));
  printf( "strcmp of s4 and s5: %d\n", strcmp( s4, s5 ));
  printf( "competition of s3 and s1: %d\n", competition( s3, s1 ));
  printf( "competition of s1 and s2: %d\n", competition( s1, s2 ));
  printf( "competition of s4 and s1: %d\n", competition( s4, s1 ));
  printf( "competition of s4 and s5: %d\n", competition( s4, s5 ));

  printf( "\n-----Testing Next Function-----\n" );

  printf( "strchr of 'c' in 'hello': %s\n", strchr( s1, 'c' ) );
  printf( "strchr of 'e' in 'hello': %s\n", strchr( s1, 'e' ) );
  printf( "strchr of 'l' in 'hello': %s\n", strchr( s1, 'l' ) );
  printf( "stringyChar of 'c' in 'hello': %s\n", stringyChar( s1, 'c' ) );
  printf( "stringyChar of 'l' in 'hello': %s\n", stringyChar( s1, 'l' ) );
  printf( "stringyChar of 'e' in 'hello': %s\n", stringyChar( s1, 'e' ) );
}
