#include <stdio.h>
#include <unistd.h>

/*
 *	Wrap the kernel time call so that it also
 *	returns a time_t (longlong). The kernel ABI
 *	doesn't deal in 64bit return values.
 */
time_t time(time_t *t)
{
  static time_t tr;
  __ktime_t tmp;
  _time(&tmp, 0);
  tr = tmp.time;
  if (t)
    *t = tr;
  return tr;
}
