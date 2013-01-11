#ifndef RENDER_HH
#define RENDER_HH

#include <QWidget>
#include <QImage>

class Render : public QWidget
{
  Q_OBJECT;

public:
  Render(QWidget *parent=0);
  ~Render();
  
  QSize minimumSizeHint() const;
  QSize sizeHint() const;

protected:
  void paintEvent(QPaintEvent *event);

private:
  QImage *image;
};

#endif
