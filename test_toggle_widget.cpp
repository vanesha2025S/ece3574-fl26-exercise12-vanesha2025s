#include <QtTest/QtTest>
#include <QtWidgets>
#include <QDebug>

#include "toggle_widget.h"

class TestToggleWidget : public QObject {
  Q_OBJECT

private slots:

  void testToggle();
  
};

// Test that clicking the button toggles the light on and off
void TestToggleWidget::testToggle()
{
  ToggleWidget widget;

  QPushButton *button = widget.findChild<QPushButton *>();

  QVERIFY(button != nullptr);

  // Light should start off
  QVERIFY(!widget.isOn());

  // Click button and check that light turns on
  QTest::mouseClick(button, Qt::LeftButton);
  QVERIFY(widget.isOn());

  // Click button again and check that light turns off
  QTest::mouseClick(button, Qt::LeftButton);
  QVERIFY(!widget.isOn());
}


QTEST_MAIN(TestToggleWidget)
#include "test_toggle_widget.moc"
