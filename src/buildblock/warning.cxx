//
// $Id$
//
/*!
  \file 
 
  \brief defines the warning() function

  \author Kris Thielemans
  \author PARAPET project

  $Date$

  $Revision$

*/
/*
    Copyright (C) 2000 PARAPET partners
    Copyright (C) 2000- $Date$, Hammersmith Imanet Ltd
    See STIR/LICENSE.txt for details
*/
#include "stir/common.h"

#include <cstdarg>
#include <stdlib.h>
#include <iostream>
START_NAMESPACE_STIR

void warning(const char *const s, ...)
{
  va_list ap;
  va_start(ap, s);
  const unsigned size=10000;
  char tmp[size];
  const int returned_size= vsnprintf(tmp,size, s, ap);
  if (returned_size<0)
    std::cerr << "\nWARNING: error formatting warning message" << std::endl;
  else
    {
      std::cerr << "\nWARNING: " << tmp <<std::endl;
      if (static_cast<unsigned>(returned_size)>=size)
	std::cerr << "\nWARNING: previous warning message truncated as it exceeds "
		  << size << "bytes" << std::endl;
    }
}

END_NAMESPACE_STIR
