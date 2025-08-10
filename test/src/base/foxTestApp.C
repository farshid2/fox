//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "foxTestApp.h"
#include "foxApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
foxTestApp::validParams()
{
  InputParameters params = foxApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

foxTestApp::foxTestApp(const InputParameters & parameters) : MooseApp(parameters)
{
  foxTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

foxTestApp::~foxTestApp() {}

void
foxTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  foxApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"foxTestApp"});
    Registry::registerActionsTo(af, {"foxTestApp"});
  }
}

void
foxTestApp::registerApps()
{
  registerApp(foxApp);
  registerApp(foxTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
foxTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  foxTestApp::registerAll(f, af, s);
}
extern "C" void
foxTestApp__registerApps()
{
  foxTestApp::registerApps();
}
