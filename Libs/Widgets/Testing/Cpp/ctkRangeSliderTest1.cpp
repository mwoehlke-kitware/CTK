/*=========================================================================

  Library:   CTK

  Copyright (c) Kitware Inc. 
  All rights reserved.
  Distributed under a BSD License. See LICENSE.txt file.

  This software is distributed "AS IS" WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the above copyright notice for more information.

=========================================================================*/

// Qt includes
#include <QApplication>
#include <QString>

// CTK includes
#include "ctkRangeSlider.h"

// STD includes
#include <cstdlib>
#include <iostream>

//-----------------------------------------------------------------------------
bool checkSlider(const ctkRangeSlider& slider)
{
  return slider.minimum()  <= slider.minimumValue() &&
    slider.minimumValue() <= slider.maximumValue() &&
    slider.maximumValue() <= slider.maximum();
}

//-----------------------------------------------------------------------------
bool checkSlider(const ctkRangeSlider& slider,
                 int min, int minVal, int maxVal, int max)
{
  return slider.minimum() == min &&
    slider.minimumValue() == minVal &&
    slider.maximumValue() == maxVal &&
    slider.maximum() == max;
}

//-----------------------------------------------------------------------------
int ctkRangeSliderTest1(int argc, char * argv [] )
{
  QApplication app(argc, argv);

  ctkRangeSlider slider;
  if (!checkSlider(slider))
    {
    std::cerr << "ctkRangeSlider:: 1) "
              << slider.minimum() << " " 
              << slider.minimumValue() << " " 
              << slider.maximumValue() << " " 
              << slider.maximum() << std::endl;
    return EXIT_FAILURE;
    }
  slider.setMinimum(40);
  slider.setMaximum(4000);
  slider.setValues(50, 500);
  if (!checkSlider(slider, 40, 50, 500, 4000))
    {
    std::cerr << "ctkRangeSlider:: 2) "
              << slider.minimum() << " " 
              << slider.minimumValue() << " " 
              << slider.maximumValue() << " " 
              << slider.maximum() << std::endl;
    return EXIT_FAILURE;
    }
  slider.setValues(700, 60);
  if (!checkSlider(slider, 40, 60, 700, 4000))
    {
    std::cerr << "ctkRangeSlider:: 3) "
              << slider.minimum() << " " 
              << slider.minimumValue() << " " 
              << slider.maximumValue() << " " 
              << slider.maximum() << std::endl;
    return EXIT_FAILURE;
    }
  slider.setValues(800, 900);
  if (!checkSlider(slider, 40, 800, 900, 4000))
    {
    std::cerr << "ctkRangeSlider:: 4) "
              << slider.minimum() << " " 
              << slider.minimumValue() << " " 
              << slider.maximumValue() << " " 
              << slider.maximum() << std::endl;
    return EXIT_FAILURE;
    }
  slider.setValues(5000, 6000);
  if (!checkSlider(slider, 40, 4000, 4000, 4000))
    {
    std::cerr << "ctkRangeSlider:: 5) "
              << slider.minimum() << " " 
              << slider.minimumValue() << " " 
              << slider.maximumValue() << " " 
              << slider.maximum() << std::endl;
    return EXIT_FAILURE;
    }
  slider.setRange(-15, 40);
  if (!checkSlider(slider, -15, 40, 40, 40))
    {
    std::cerr << "ctkRangeSlider:: 6) "
              << slider.minimum() << " " 
              << slider.minimumValue() << " " 
              << slider.maximumValue() << " " 
              << slider.maximum() << std::endl;
    return EXIT_FAILURE;
    }
  // nothing happen yet but it would be nice if it moves the 2 values at 
  // the same time.
  slider.triggerAction(QAbstractSlider::SliderSingleStepSub);
  if (!checkSlider(slider, -15, 40, 40, 40))
    {
    std::cerr << "ctkRangeSlider:: 7) "
              << slider.minimum() << " " 
              << slider.minimumValue() << " " 
              << slider.maximumValue() << " " 
              << slider.maximum() << std::endl;
    return EXIT_FAILURE;
    }
  slider.setMaximumValue(30);
  if (!checkSlider(slider, -15, 30, 30, 40))
    {
    std::cerr << "ctkRangeSlider:: 8) "
              << slider.minimum() << " " 
              << slider.minimumValue() << " " 
              << slider.maximumValue() << " " 
              << slider.maximum() << std::endl;
    return EXIT_FAILURE;
    }
  slider.setMinimumValue(40);
  if (!checkSlider(slider, -15, 40, 40, 40))
    {
    std::cerr << "ctkRangeSlider:: 9) "
              << slider.minimum() << " " 
              << slider.minimumValue() << " " 
              << slider.maximumValue() << " " 
              << slider.maximum() << std::endl;
    return EXIT_FAILURE;
    }
  slider.setMinimumValue(-20);
  if (!checkSlider(slider, -15, -15, 40, 40))
    {
    std::cerr << "ctkRangeSlider:: 10) "
              << slider.minimum() << " " 
              << slider.minimumValue() << " " 
              << slider.maximumValue() << " " 
              << slider.maximum() << std::endl;
    return EXIT_FAILURE;
    }
  slider.setTracking(false);
  slider.setPositions(-5, 30);
  if (!checkSlider(slider, -15, -15, 40, 40) ||
      slider.minimumPosition() != -5 || 
      slider.maximumPosition() != 30)
    {
    std::cerr << "ctkRangeSlider:: 10) "
              << slider.minimum() << " " 
              << slider.minimumValue() << " " 
              << slider.maximumValue() << " " 
              << slider.maximum() << std::endl;
    std::cerr << "ctkRangeSlider:: 10) "
              << slider.minimumPosition() << " " 
              << slider.maximumPosition() << std::endl;
    return EXIT_FAILURE;
    }
  slider.setValues(-10, 30);
  if (!checkSlider(slider, -15, -10, 30, 40) ||
      slider.minimumPosition() != -10 || 
      slider.maximumPosition() != 30)
    {
    std::cerr << "ctkRangeSlider:: 11) "
              << slider.minimum() << " " 
              << slider.minimumValue() << " " 
              << slider.maximumValue() << " " 
              << slider.maximum() << std::endl;
    std::cerr << "ctkRangeSlider:: 11) "
              << slider.minimumPosition() << " " 
              << slider.maximumPosition() << std::endl;
    return EXIT_FAILURE;
    }
  slider.setMaximumPosition(20);
  if (!checkSlider(slider, -15, -10, 30, 40) ||
      slider.minimumPosition() != -10 || 
      slider.maximumPosition() != 20)
    {
    std::cerr << "ctkRangeSlider:: 12) "
              << slider.minimum() << " " 
              << slider.minimumValue() << " " 
              << slider.maximumValue() << " " 
              << slider.maximum() << std::endl;
    std::cerr << "ctkRangeSlider:: 12) "
              << slider.minimumPosition() << " " 
              << slider.maximumPosition() << std::endl;
    return EXIT_FAILURE;
    }
  slider.setMinimumPosition(25);
  if (!checkSlider(slider, -15, -10, 30, 40) ||
       slider.minimumPosition() != 25 || 
       slider.maximumPosition() != 25)
    {
    std::cerr << "ctkRangeSlider:: 13) "
              << slider.minimum() << " " 
              << slider.minimumValue() << " " 
              << slider.maximumValue() << " " 
              << slider.maximum() << std::endl;
    std::cerr << "ctkRangeSlider:: 13) "
              << slider.minimumPosition() << " " 
              << slider.maximumPosition() << std::endl;
    return EXIT_FAILURE;
    }
  slider.setTracking(true);
  slider.setPositions(0, 10);
  if (!checkSlider(slider, -15, 0, 10, 40) ||
      slider.minimumPosition() != 0 || 
      slider.maximumPosition() != 10)
    {
    std::cerr << "ctkRangeSlider:: 14) "
              << slider.minimum() << " " 
              << slider.minimumValue() << " " 
              << slider.maximumValue() << " " 
              << slider.maximum() << std::endl;
    std::cerr << "ctkRangeSlider:: 14) "
              << slider.minimumPosition() << " " 
              << slider.maximumPosition() << std::endl;
    return EXIT_FAILURE;
    }
  slider.setValues(-5, 15);
  if (!checkSlider(slider, -15, -5, 15, 40) ||
      slider.minimumPosition() != -5 || 
      slider.maximumPosition() != 15)
    {
    std::cerr << "ctkRangeSlider:: 15) "
              << slider.minimum() << " " 
              << slider.minimumValue() << " " 
              << slider.maximumValue() << " " 
              << slider.maximum() << std::endl;
    std::cerr << "ctkRangeSlider:: 15) "
              << slider.minimumPosition() << " " 
              << slider.maximumPosition() << std::endl;
    return EXIT_FAILURE;
    }

  return EXIT_SUCCESS;
}