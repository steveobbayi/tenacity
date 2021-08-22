/**********************************************************************

   Audacity - A Digital Audio Editor
   Copyright 1999-2018 Audacity Team
   License: wxwidgets

   James Crook

******************************************************************//**

\file SetLabelCommand.h
\brief Declarations of SetLabelCommand and SetLabelCommandType classes

*//*******************************************************************/

#pragma once

#include "Command.h"
#include "CommandType.h"

class SetLabelCommand : public AudacityCommand
{
public:
   static const ComponentInterfaceSymbol Symbol;

   SetLabelCommand();
   // ComponentInterface overrides
   ComponentInterfaceSymbol GetSymbol() override {return Symbol;};
   TranslatableString GetDescription() override {return XO("Sets various values for a label.");};
   bool DefineParams( ShuttleParams & S ) override;
   void PopulateOrExchange(ShuttleGui & S) override;

   // AudacityCommand overrides
   ManualPageID ManualPage() override {return L"Extra_Menu:_Scriptables_I#set_label";}

   bool Apply(const CommandContext & context) override;

public:
   // zero-based index of the desired label, within the concatenation of the
   // arrays of labels of all label tracks
   int mLabelIndex;
   wxString mText;
   double mT0;
   double mT1;
   bool mbSelected;

// For tracking optional parameters.
   bool bHasText;
   bool bHasT0;
   bool bHasT1;
   bool bHasSelected;
};
