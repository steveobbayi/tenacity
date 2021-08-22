/**********************************************************************

  Audacity: A Digital Audio Editor

  Keyboard.h

  Dominic Mazzoni
  Brian Gunlogson

**********************************************************************/

#pragma once

#include "Identifier.h"
#include <wx/defs.h>

class wxKeyEvent;

struct NormalizedKeyStringTag;
// Case insensitive comparisons
using NormalizedKeyStringBase = TaggedIdentifier<NormalizedKeyStringTag, false>;

struct TENACITY_DLL_API NormalizedKeyString : NormalizedKeyStringBase
{
   NormalizedKeyString() = default;
   explicit NormalizedKeyString( const wxString &key );

   wxString Display(bool usesSpecialChars = false) const;
};

namespace std
{
   template<> struct hash< NormalizedKeyString >
      : hash< NormalizedKeyStringBase > {};
}

TENACITY_DLL_API
NormalizedKeyString KeyEventToKeyString(const wxKeyEvent & keyEvent);
