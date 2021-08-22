/**********************************************************************

  Tenacity

  HelpText.h

  James Crook

**********************************************************************/

#pragma once

class TranslatableString;
class wxString;
#include "Identifier.h"

struct URLStringTag;
//! Distinct type for URLs
using URLString = TaggedIdentifier< URLStringTag >;

TENACITY_DLL_API  wxString HelpText( const wxString & Key );
TENACITY_DLL_API TranslatableString TitleText( const wxString & Key );

extern TENACITY_DLL_API const wxString VerCheckArgs();
extern TENACITY_DLL_API wxString FormatHtmlText( const wxString & Text );
