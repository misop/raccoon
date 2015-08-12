#include "RaccoonApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<RaccoonApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  return params;
}

RaccoonApp::RaccoonApp(InputParameters parameters) :
    MooseApp(parameters)
{

  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  RaccoonApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  RaccoonApp::associateSyntax(_syntax, _action_factory);
}

RaccoonApp::~RaccoonApp()
{
}

// External entry point for dynamic application loading
extern "C" void RaccoonApp__registerApps() { RaccoonApp::registerApps(); }
void
RaccoonApp::registerApps()
{
  registerApp(RaccoonApp);
}

// External entry point for dynamic object registration
extern "C" void RaccoonApp__registerObjects(Factory & factory) { RaccoonApp::registerObjects(factory); }
void
RaccoonApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void RaccoonApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { RaccoonApp::associateSyntax(syntax, action_factory); }
void
RaccoonApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
