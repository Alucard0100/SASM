/****************************************************************************
** SASM - simple IDE for assembler development
** Copyright (C) 2013 Dmitriy Manushin
** Contact: site: http://dman95.github.io/SASM/
**          e-mail: Dman1095@gmail.com
**
** This file is part of SASM.
**
** SASM is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** SASM is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with SASM.  If not, see <http://www.gnu.org/licenses/>.
**
** Этот файл — часть SASM.
**
** SASM - свободная программа: вы можете перераспространять ее и/или
** изменять ее на условиях Стандартной общественной лицензии GNU в том виде,
** в каком она была опубликована Фондом свободного программного обеспечения;
** либо версии 3 лицензии, либо (по вашему выбору) любой более поздней
** версии.
**
** SASM распространяется в надежде, что она будет полезной,
** но БЕЗО ВСЯКИХ ГАРАНТИЙ; даже без неявной гарантии ТОВАРНОГО ВИДА
** или ПРИГОДНОСТИ ДЛЯ ОПРЕДЕЛЕННЫХ ЦЕЛЕЙ. Подробнее см. в Стандартной
** общественной лицензии GNU.
**
** Вы должны были получить копию Стандартной общественной лицензии GNU
** вместе с этой программой. Если это не так, см.
** <http://www.gnu.org/licenses/>.)
**
****************************************************************************/

#ifndef DEBUGANYCOMMANDWIDGET_H
#define DEBUGANYCOMMANDWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QCheckBox>

/**
 * @file debuganycommandwidget.h
 *
 * File for the GDB arbitrary command widget.
 */




/*! \brief This class represents the GDB arbitrary command widget.
 */

class DebugAnyCommandWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DebugAnyCommandWidget(QWidget *parent = 0);
    ~DebugAnyCommandWidget();
    void setFocusOnLineEdit();
    void showPreviousCommand();
    void showNextCommand();
    int height();
    
signals:
    void performCommand(const QString command, bool print);
    
public slots:
    void processCommand();

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    QLabel *anyCommandLabel;
    QLineEdit *command;
    QPushButton *performButton;
    QHBoxLayout *layout;
    QCheckBox *printCheckBox;
    QStringList commands;
    int currentCommandPos;
};

#endif // DEBUGANYCOMMANDWIDGET_H
