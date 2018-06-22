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

#pragma once

#include "Gui/Common/WalletWindowedItemModel.h"

namespace WalletGui {

class RecentTransactionsModel : public WalletWindowedItemModel {
  Q_OBJECT
  Q_DISABLE_COPY(RecentTransactionsModel)

public:
  RecentTransactionsModel(QAbstractItemModel* _sourceModel, QObject* _parent);
  ~RecentTransactionsModel();

protected:
  bool filterAcceptsColumn(int _source_column, const QModelIndex& _sourceParent) const override;
};

}
