#include "modelstate.h"

ModelState::ModelState(QObject *parent) :
    QObject(parent)
{
}

bool ModelState::itemWithOnePExist()
{
    foreach (Item* item, pItems) {
        if (item->getPossibility() >= 1)
            return true;
    }

    return false;
}

void ModelState::mergeItemsPos(const QVector<double>& pos)
{
    for (int i = 0; i < pItems.count(); i++) {
        pItems.at(i)->setPossibility(pos.at(i));
    }
}
