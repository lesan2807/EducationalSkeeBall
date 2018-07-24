#include <QColor>
#include <QFont>

#include "Score.h"

Score::Score(const QString &legend, int initialScore, QColor color, QGraphicsItem *parent)
    : QGraphicsTextItem(parent)
    , legend(legend)
    , score(initialScore)
{
    /// Sets the color, font and size of the legend
    setDefaultTextColor(color);
    setFont(QFont("", 24));
    /// Updates the label after modifying its characteristics
    updateScore();
}

Score::~Score()
{
}

void Score::increase(int amount)
{
    /// Increases the current value of the score by adding amount
    score += amount;
    /// Updates the label after increasing the value
    updateScore();
}

void Score::decrease(int amount)
{
    /// Decreases the current value of the score by substracting amount
    score -= amount;
    /// Updates the label after increasing the value
    updateScore();
}

void Score::updateScore()
{
    /// Changes the text displayed at the scene
    setPlainText( QString("%1: %2").arg(legend).arg(score) );
}
