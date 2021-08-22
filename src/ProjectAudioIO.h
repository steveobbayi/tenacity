/**********************************************************************

Tenacity

ProjectAudioIO.h

Paul Licameli split from AudacityProject.h

**********************************************************************/

#pragma once

#include "ClientData.h" // to inherit
#include <wx/weakref.h>

class AudacityProject;

// Windows build needs complete type for parameter of wxWeakRef
// class MeterPanelBase;
#include "widgets/MeterPanelBase.h"

///\ brief Holds per-project state needed for interaction with AudioIO,
/// including the audio stream token and pointers to meters
class TENACITY_DLL_API ProjectAudioIO final
   : public ClientData::Base
{
public:
   static ProjectAudioIO &Get( AudacityProject &project );
   static const ProjectAudioIO &Get( const AudacityProject &project );

   explicit ProjectAudioIO( AudacityProject &project );
   ProjectAudioIO( const ProjectAudioIO & ) PROHIBITED;
   ProjectAudioIO &operator=( const ProjectAudioIO & ) PROHIBITED;
   ~ProjectAudioIO();

   int GetAudioIOToken() const;
   bool IsAudioActive() const;
   void SetAudioIOToken(int token);

   MeterPanelBase *GetPlaybackMeter();
   void SetPlaybackMeter(MeterPanelBase *playback);
   MeterPanelBase *GetCaptureMeter();
   void SetCaptureMeter(MeterPanelBase *capture);

private:
   AudacityProject &mProject;

   // Project owned meters
   wxWeakRef<MeterPanelBase> mPlaybackMeter{};
   wxWeakRef<MeterPanelBase> mCaptureMeter{};

   int  mAudioIOToken{ -1 };
};
