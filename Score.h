#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

/**
 * @brief The Score class is a label on the screen that shows a legend and a counter value
 */

class Score : public QGraphicsTextItem
{
    Q_OBJECT
    Q_DISABLE_COPY(Score)

  protected:
    /// This scores measures something: points, balls...
    QString legend;
    /// The amount scored
    int score;

  public:
    /// Constructor
    Score(const QString& legend, int initialScore, QColor color, QGraphicsItem* parent = nullptr);
    /// Destructor
    ~Score();
    /// Returns a copy if the current score
    inline int getScore() const { return score; }
    /// Increases the score and updates the view
    void increase( int amount = 1);
    /// Decreases the score and updates the view
    void decrease( int amount = 1);

  protected:
    /// Updates the interface to match the score
    void updateScore();
};

#endif // SCORE_H
