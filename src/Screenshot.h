/**********************************************************************

  Tenacity

  Screenshot.h

  Dominic Mazzoni

*******************************************************************//**

\file Screenshot.h

  Opens a modeless dialog that aids in rearranging the project window
  to a canonical size and state and then capturing full and partial
  screenshots to disk.

*//*******************************************************************/

#pragma once



#include <wx/defs.h>

class AudacityProject;

TENACITY_DLL_API void OpenScreenshotTools( AudacityProject &project );
void CloseScreenshotTools();
