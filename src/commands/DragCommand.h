/**********************************************************************

   Audacity - A Digital Audio Editor
   Copyright 1999-2009 Audacity Team
   License: wxwidgets

   James Crook

******************************************************************//**

\file DragCommand.h
\brief Declarations of DragCommand and DragCommandType classes

*//*******************************************************************/

#pragma once

#include "Command.h"
#include "CommandType.h"

class DragCommand : public AudacityCommand
{
public:
   static const ComponentInterfaceSymbol Symbol;

   DragCommand();
   // ComponentInterface overrides
   ComponentInterfaceSymbol GetSymbol() override {return Symbol;};
   TranslatableString GetDescription() override {return XO("Drags mouse from one place to another.");};
   bool DefineParams( ShuttleParams & S ) override;
   void PopulateOrExchange(ShuttleGui & S) override;

   // AudacityCommand overrides
   ManualPageID ManualPage() override {return L"Extra_Menu:_Scriptables_II#move_mouse";}

   bool Apply(const CommandContext & context) override;

public:
   double mFromX;
   double mFromY;
   double mToX;
   double mToY;
   int mRelativeTo;
   int mId;
   wxString mWinName;

   bool bHasFromX;
   bool bHasFromY;
   bool bHasToX;
   bool bHasToY;
   bool bHasRelativeTo;
   bool bHasId;
   bool bHasWinName;

};
