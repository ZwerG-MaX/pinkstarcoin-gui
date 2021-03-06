// Copyright (c) 2015-2018, The Bytecoin developers
// Copyright (c) 2018, The PinkstarcoinV2 developers
//
// This file is part of Bytecoin.
//
// PinkstarcoinV2 is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// PinkstarcoinV2 is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with PinkstarcoinV2.  If not, see <http://www.gnu.org/licenses/>.

#include "FusionTransactionsFilterModel.h"
#include "Settings/Settings.h"
#include "IOptimizationManager.h"
#include "Models/TransactionsModel.h"

namespace WalletGui {

FusionTransactionsFilterModel::FusionTransactionsFilterModel(QAbstractItemModel* _sourceModel, IOptimizationManager* _optimizationManager, QObject* _parent) : QSortFilterProxyModel(_parent),
  m_optimizationManager(_optimizationManager) {
  setSourceModel(_sourceModel);
  setDynamicSortFilter(true);
  setFilterRole(TransactionsModel::ROLE_IS_FUSION_TRANSACTION);
}

FusionTransactionsFilterModel::~FusionTransactionsFilterModel() {
}

bool FusionTransactionsFilterModel::filterAcceptsRow(int _sourceRow, const QModelIndex& _sourceParent) const {
  QModelIndex sourceIndex = sourceModel()->index(_sourceRow, 0);
  if (m_optimizationManager->isFusionTransactionsVisible()) {
    return true;
  }

  return !sourceIndex.data(TransactionsModel::ROLE_IS_FUSION_TRANSACTION).toBool();
}

}
