/**************************************************************************/
/*                                                                        */
/*                                 OCaml                                  */
/*                                                                        */
/*                 David Allsopp, OCaml Labs, Cambridge.                  */
/*                                                                        */
/*   Copyright 2017 MetaStack Solutions Ltd.                              */
/*                                                                        */
/*   All rights reserved.  This file is distributed under the terms of    */
/*   the GNU Lesser General Public License version 2.1, with the          */
/*   special exception on linking described in the file LICENSE.          */
/*                                                                        */
/**************************************************************************/

#include "defs.h"

#ifndef _WIN32

#include <string.h>

char * strdup_of_os(const char_os *s)
{
  return strdup(s);
}

#else

#include <windows.h>

static int windows_unicode_enabled = WINDOWS_UNICODE;
static int windows_unicode_strict = 1;

/* Adapted from runtime/win32.c */
static int wide_char_to_multi_byte(const wchar_t *s, int slen,
                                   char *out, int outlen)
{
  int retcode;

  if (slen == 0)
    return 0;

  if (windows_unicode_enabled != 0)
    retcode =
      WideCharToMultiByte(CP_UTF8,
                          windows_unicode_strict ? WC_ERR_INVALID_CHARS : 0,
                          s, slen, out, outlen, NULL, NULL);
  else
    retcode =
      WideCharToMultiByte(CP_ACP, 0, s, slen, out, outlen, NULL, NULL);

  if (retcode == 0)
    return -1;

  return retcode;
}

char* strdup_of_os(const char_os *s)
{
  char *out = NULL;
  int retcode;

  retcode = wide_char_to_multi_byte(s, -1, NULL, 0);
  if (retcode >= 0) {
    out = (char *)malloc(retcode);
    wide_char_to_multi_byte(s, -1, out, retcode);
  }

  return out;
}

#endif
