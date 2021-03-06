/*
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef AVOIDTROUBLE_H
#define AVOIDTROUBLE_H

#include <QMainWindow>
#include <QTimer>
#include <QRect>
#include <QPaintEvent>
#include <QPainter>
#include <QKeyEvent>

#include "defines.h"
#include "player.h"
#include "obstacle.h"

class AvoidTrouble : public QMainWindow
{
    Q_OBJECT

public:
    explicit AvoidTrouble(QWidget *parent = 0);
    ~AvoidTrouble();

    void paintEvent(QPaintEvent * event);
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);

    void increaseStage();
    void startStuckTimer();

private slots:
    void update();
    void resetStuckTimer();

private:
    AvoidTrouble* ui;
    QRect* _safezone;
    Player* _player;
    QRect* _victoryDoor;
    Obstacle* _obstacles;
    QTimer* _gameTimer;
    QTimer* _stuckTimer;

    bool _gameActive = true;
    bool _isPaused = false;

    int _stage = 0;
    int _obstacleSize = START_OBS_NBR - 1;
};

#endif /* AVOIDTROUBLE_H */
