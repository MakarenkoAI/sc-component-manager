/*
 * This source file is part of an OSTIS project. For the latest info, see http://ostis.net
 * Distributed under the MIT License
 * (See accompanying file COPYING.MIT or copy at http://opensource.org/licenses/MIT)
 */

#pragma once

#include <string>
#include <vector>

#include "sc-memory/sc_memory.hpp"

using CommandParameters = std::map<std::string, std::vector<std::string>>;
using ExecutionResult = std::vector<std::string>;

class ScComponentManagerCommand
{
public:
  virtual ExecutionResult Execute(ScMemoryContext * context, CommandParameters const & commandParameters) = 0;

  virtual ~ScComponentManagerCommand() = default;

  void SetReposPath(std::string const & reposPath)
  {
    m_reposPath = reposPath;
  }

protected:
  std::string m_reposPath;
};
