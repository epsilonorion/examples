#include <stdio.h>
#include <stdlib.h>
#include <gnu/libc-version.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  printf("GNU libc version: %s\n", gnu_get_libc_version());

/* Test for GCC > 4.8.2 */
/* Can also use #if GCC_VERSION > 40802 */
#if __GNUC__ > 4 || \
    (__GNUC__ == 4 && (__GNUC_MINOR__ > 8 || \
                       (__GNUC_MINOR__ == 8 && \
                       (__GNUC_PATCHLEVEL__ > 2 || \
                       (__GNUC_PATCHLEVEL__ == 2)))))
  printf("GNUC is >= 4.8.2\n");
#else
  printf("GNUC is < 4.8.2\n");		
#endif

#ifdef __GLIBCXX__
#  if defined(_GLIBCXX_HAVE_GTHR_DEFAULT) \
        || defined(_GLIBCXX__PTHREADS) \
        || defined(_GLIBCXX_HAS_GTHREADS) \
        || defined(_WIN32) \
        || defined(_AIX) \
        || defined(__HAIKU__)
    printf("Can Have Threads\n");
#  else
    printf("Can't Have Threads\n");
#  endif
#else
  printf("GLIBCXX not defined\n");
#endif

  exit(EXIT_SUCCESS);
}
