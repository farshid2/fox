#include "foxApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
foxApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

foxApp::foxApp(const InputParameters & parameters) : MooseApp(parameters)
{
  foxApp::registerAll(_factory, _action_factory, _syntax);
}

foxApp::~foxApp() {}

void
foxApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAllObjects<foxApp>(f, af, syntax);
  Registry::registerObjectsTo(f, {"foxApp"});
  Registry::registerActionsTo(af, {"foxApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
foxApp::registerApps()
{
  registerApp(foxApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
foxApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  foxApp::registerAll(f, af, s);
}
extern "C" void
foxApp__registerApps()
{
  foxApp::registerApps();
}
