#ifndef PALETTE_PANEL_HH
#define PALETTE_PANEL_HH

#include <QWidget>
#include <QComboBox>

class QPalettePanel : public QWidget
{
  Q_OBJECT;

public:
  QPalettePanel();
  ~QPalettePanel();

protected:
  void setupLayout();

private:
  QComboBox *paletteSelector;
};

#endif
