/*
 * This source file is part of an OSTIS project. For the latest info, see http://ostis.net
 * Distributed under the MIT License
 * (See accompanying file COPYING.MIT or copy at http://opensource.org/licenses/MIT)
 */

#include "common_module.hpp"

#include "sc-memory/sc_memory.hpp"

#include "keynodes/ScComponentManagerKeynodes.hpp"
#include "utils/common_utils.hpp"

using namespace commonModule;

SC_MODULE_REGISTER(CommonModule);

void CommonModule::Initialize(ScMemoryContext * context)
{
  common_utils::CommonUtils::InitParametersMap();
  if (!common_utils::CommonUtils::CheckIfFullMyselfDecompositionExists(*context))
  {
    common_utils::CommonUtils::CreateMyselfDecomposition(*context);
  }
}

void CommonModule::Shutdown(ScMemoryContext * context)
{
  common_utils::CommonUtils::ClearParametersMap();
}
