#pragma once

#include "astnode.hpp"

class Variable : public ASTNode {
  public:
    Variable(const std::string& name);
};
