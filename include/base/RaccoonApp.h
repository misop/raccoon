#ifndef RACCOONAPP_H
#define RACCOONAPP_H

#include "MooseApp.h"

class RaccoonApp;

template<>
InputParameters validParams<RaccoonApp>();

class RaccoonApp : public MooseApp
{
public:
  RaccoonApp(const std::string & name, InputParameters parameters);
  virtual ~RaccoonApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* RACCOONAPP_H */
