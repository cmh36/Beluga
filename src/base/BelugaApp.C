#include "BelugaApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<BelugaApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  return params;
}

BelugaApp::BelugaApp(InputParameters parameters) :
    MooseApp(parameters)
{

  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  BelugaApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  BelugaApp::associateSyntax(_syntax, _action_factory);
}

BelugaApp::~BelugaApp()
{
}

// External entry point for dynamic application loading
extern "C" void BelugaApp__registerApps() { BelugaApp::registerApps(); }
void
BelugaApp::registerApps()
{
  registerApp(BelugaApp);
}

// External entry point for dynamic object registration
extern "C" void BelugaApp__registerObjects(Factory & factory) { BelugaApp::registerObjects(factory); }
void
BelugaApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void BelugaApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { BelugaApp::associateSyntax(syntax, action_factory); }
void
BelugaApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
