#ifndef BELUGAAPP_H
#define BELUGAAPP_H

#include "MooseApp.h"

class BelugaApp;

template<>
InputParameters validParams<BelugaApp>();

class BelugaApp : public MooseApp
{
public:
  BelugaApp(const std::string & name, InputParameters parameters);
  virtual ~BelugaApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* BELUGAAPP_H */
