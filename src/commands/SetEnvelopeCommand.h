/**********************************************************************

   Audacity - A Digital Audio Editor
   Copyright 1999-2018 Audacity Team
   License: wxwidgets

   James Crook

******************************************************************//**

\file SetEnvelopeCommand.h
\brief Declarations of SetEnvelopeCommand class

*//*******************************************************************/

#pragma once

#include "SetTrackInfoCommand.h"

class SetEnvelopeCommand : public SetTrackBase
{
public:
   static const ComponentInterfaceSymbol Symbol;

   SetEnvelopeCommand();
   // ComponentInterface overrides
   ComponentInterfaceSymbol GetSymbol() override {return Symbol;};
   TranslatableString GetDescription() override {return XO("Sets an envelope point position.");};
   bool DefineParams( ShuttleParams & S ) override;
   void PopulateOrExchange(ShuttleGui & S) override;

   // AudacityCommand overrides
   ManualPageID ManualPage() override {return L"Extra_Menu:_Scriptables_I#set_envelope";}
   bool ApplyInner( const CommandContext & context, Track * t ) override;

public:
   double mT;
   double mV;
   bool mbDelete;

   bool bHasT;
   bool bHasV;
   bool bHasDelete;
};
