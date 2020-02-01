/**********************************************************************

  Audacity: A Digital Audio Editor

  PlaybackPrefs.cpp

  Joshua Haberman
  Dominic Mazzoni
  James Crook

*******************************************************************//**

\class PlaybackPrefs
\brief A PrefsPanel used to select playback options.

  Presents interface for user to update the various playback options
  like previewing and seeking.

*//********************************************************************/

#include "../Audacity.h"
#include "PlaybackPrefs.h"

#include <wx/defs.h>
#include <wx/textctrl.h>

#include "../ShuttleGui.h"
#include "../Prefs.h"

PlaybackPrefs::PlaybackPrefs(wxWindow * parent, wxWindowID winid)
:  PrefsPanel(parent, winid, XO("Playback"))
{
   Populate();
}

PlaybackPrefs::~PlaybackPrefs()
{
}

ComponentInterfaceSymbol PlaybackPrefs::GetSymbol()
{
   return PLAYBACK_PREFS_PLUGIN_SYMBOL;
}

TranslatableString PlaybackPrefs::GetDescription()
{
   return XO("Preferences for Playback");
}

wxString PlaybackPrefs::HelpPageName()
{
   return "Playback_Preferences";
}

void PlaybackPrefs::Populate()
{
   //------------------------- Main section --------------------
   // Now construct the GUI itself.
   // Use 'eIsCreatingFromPrefs' so that the GUI is
   // initialised with values from gPrefs.
   ShuttleGui S(this, eIsCreatingFromPrefs);
   PopulateOrExchange(S);
   // ----------------------- End of main section --------------
}

namespace {
   const char *UnpinnedScrubbingPreferenceKey()
   {
      return "/AudioIO/UnpinnedScrubbing";
   }
   bool UnpinnedScrubbingPreferenceDefault()
   {
      return true;
   }
   int iPreferenceUnpinned = -1;
}

void PlaybackPrefs::PopulateOrExchange(ShuttleGui & S)
{
   const auto suffix = XO("seconds");

   S.StartScroller();
   S.SetBorder(2);

   S.StartStatic(XO("Effects Preview"));
   {
      S.StartThreeColumn();
      {
         S.NameSuffix(suffix)
            .TieNumericTextBox(XO("&Length:"),
                                 {wxT("/AudioIO/EffectsPreviewLen"),
                                  6.0},
                                 9);
         S.AddUnits(XO("seconds"));
      }
      S.EndThreeColumn();
   }
   S.EndStatic();

   /* i18n-hint: (noun) this is a preview of the cut */
   S.StartStatic(XO("Cut Preview"));
   {
      S.StartThreeColumn();
      {
         S.NameSuffix(suffix)
            .TieNumericTextBox(XO("&Before cut region:"),
                                 {wxT("/AudioIO/CutPreviewBeforeLen"),
                                  2.0},
                                 9);
         S.AddUnits(XO("seconds"));

         S.NameSuffix(suffix)
            .TieNumericTextBox(XO("&After cut region:"),
                                 {wxT("/AudioIO/CutPreviewAfterLen"),
                                  1.0},
                                 9);
         S.AddUnits(XO("seconds"));
      }
      S.EndThreeColumn();
   }
   S.EndStatic();

   S.StartStatic(XO("Seek Time when playing"));
   {
      S.StartThreeColumn();
      {
         S.NameSuffix(suffix)
            .TieNumericTextBox(XO("&Short period:"),
                                 {wxT("/AudioIO/SeekShortPeriod"),
                                  1.0},
                                 9);
         S.AddUnits(XO("seconds"));

         S.NameSuffix(suffix)
            .TieNumericTextBox(XO("Lo&ng period:"),
                                 {wxT("/AudioIO/SeekLongPeriod"),
                                  15.0},
                                 9);
         S.AddUnits(XO("seconds"));
      }
      S.EndThreeColumn();
   }
   S.EndStatic();

   S.StartStatic(XO("Options"));
   {
      S.StartVerticalLay();
      {
         S.TieCheckBox(XO("&Vari-Speed Play"), {"/AudioIO/VariSpeedPlay", true});
         S.TieCheckBox(XO("&Micro-fades"), {"/AudioIO/Microfades", false});
         S.TieCheckBox(XO("Always scrub un&pinned"),
            {UnpinnedScrubbingPreferenceKey(),
             UnpinnedScrubbingPreferenceDefault()});
      }
      S.EndVerticalLay();
   }
   S.EndStatic();


   S.EndScroller();

}

bool PlaybackPrefs::GetUnpinnedScrubbingPreference()
{
   if ( iPreferenceUnpinned >= 0 )
      return iPreferenceUnpinned == 1;
   bool bResult = gPrefs->ReadBool(
      UnpinnedScrubbingPreferenceKey(),
      UnpinnedScrubbingPreferenceDefault());
   iPreferenceUnpinned = bResult ? 1: 0;
   return bResult;
}

bool PlaybackPrefs::Commit()
{
   iPreferenceUnpinned = -1;

   ShuttleGui S(this, eIsSavingToPrefs);
   PopulateOrExchange(S);

   return true;
}

namespace{
PrefsPanel::Registration sAttachment{ "Playback",
   [](wxWindow *parent, wxWindowID winid, AudacityProject *)
   {
      wxASSERT(parent); // to justify safenew
      return safenew PlaybackPrefs(parent, winid);
   }
};
}
