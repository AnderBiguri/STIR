//
// $Id$
//
/*!

  \file

  \brief Instantiations of RegisteredObject

  Currently only necessary for VC

  \author Kris Thielemans

  $Date$
  $Revision$
*/
/*
    Copyright (C) 2000- $Date$, IRSL
    See STIR/LICENSE.txt for details
*/

#ifdef _MSC_VER
#pragma message("instantiating RegisteredObject<OutputFileFormat >")
#include "stir/IO/OutputFileFormat.h"
// add here all roots of hierarchies based on RegisteredObject

START_NAMESPACE_STIR

template <typename Root>
RegisteredObject<Root>::RegistryType& 
RegisteredObject<Root>::registry ()
{
  static RegistryType the_registry("None", 0);
  return the_registry;
}

#  ifdef _MSC_VER
// prevent warning message on reinstantiation,
// note that we get a linking error if we don't have the explicit instantiation below
#  pragma warning(disable:4660)
#  endif

template RegisteredObject<OutputFileFormat >;
// add here all roots of hierarchies based on RegisteredObject

END_NAMESPACE_STIR

#endif
