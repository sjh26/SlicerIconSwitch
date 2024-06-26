/*==============================================================================

  Program: 3D Slicer

  Portions (c) Copyright Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

==============================================================================*/

// Qt includes
#include <QDebug>
#include <QSettings>
#include <QPushButton>
#include <QIcon>

// Slicer includes
#include "qSlicerIconSwitchModuleWidget.h"
#include "ui_qSlicerIconSwitchModuleWidget.h"
#include "vtkSlicerIconSwitchLogic.h"
#include "qSlicerApplication.h"


//-----------------------------------------------------------------------------
class qSlicerIconSwitchModuleWidgetPrivate: public Ui_qSlicerIconSwitchModuleWidget
{
public:
  qSlicerIconSwitchModuleWidgetPrivate();
};

//-----------------------------------------------------------------------------
// qSlicerIconSwitchModuleWidgetPrivate methods

//-----------------------------------------------------------------------------
qSlicerIconSwitchModuleWidgetPrivate::qSlicerIconSwitchModuleWidgetPrivate()
{
}

//-----------------------------------------------------------------------------
// qSlicerIconSwitchModuleWidget methods

//-----------------------------------------------------------------------------
qSlicerIconSwitchModuleWidget::qSlicerIconSwitchModuleWidget(QWidget* _parent)
  : Superclass( _parent )
  , d_ptr( new qSlicerIconSwitchModuleWidgetPrivate )
{
}

//-----------------------------------------------------------------------------
qSlicerIconSwitchModuleWidget::~qSlicerIconSwitchModuleWidget()
{
}

//-----------------------------------------------------------------------------
void qSlicerIconSwitchModuleWidget::setup()
{
  Q_D(qSlicerIconSwitchModuleWidget);
  d->setupUi(this);
  this->Superclass::setup();
  this->connect(d->lightButton, SIGNAL(clicked()), SLOT(goToLightStyle()));
  this->connect(d->darkButton, SIGNAL(clicked()), SLOT(goToDarkStyle()));
  this->addButton(":/Icons/MarkupsAddAngle.svg");
  this->addButton(":/Icons/MarkupsAddLine.svg");
  this->addButton(":/Icons/MarkupsAddROI.svg");
  this->addButton(":/Icons/MarkupsAddClosedCurve.svg");
  this->addButton(":/Icons/MarkupsAddOpenCurve.svg");
  this->addButton(":/Icons/MarkupsAddPlane.svg");
  this->addButton(":/Icons/MarkupsAddPoint.svg");
  this->addButton(":/Icons/MarkupsAddPointList.svg");

}

//-----------------------------------------------------------------------------
void qSlicerIconSwitchModuleWidget::goToDarkStyle()
{
  QSettings settingsApplication;
  auto currentStyle = settingsApplication.value("Styles/Style", "Slicer").toString();

  if (currentStyle == "Dark Slicer")
  {
    return;
  }

  settingsApplication.setValue("Styles/Style", "Dark Slicer");
  qSlicerApplication::application()->confirmRestart("Would you like to restart 3D Slicer to reload icons?");
}

//-----------------------------------------------------------------------------
void qSlicerIconSwitchModuleWidget::goToLightStyle()
{
  QSettings settingsApplication;
  auto currentStyle = settingsApplication.value("Styles/Style", "Slicer").toString();
  if (currentStyle == "Light Slicer")
  {
    return;
  }

  settingsApplication.setValue("Styles/Style", "Light Slicer");
  qSlicerApplication::application()->confirmRestart("Would you like to restart 3D Slicer to reload icons?");
}

//-----------------------------------------------------------------------------

void qSlicerIconSwitchModuleWidget::addButton(QString iconPath)
{
  Q_D(qSlicerIconSwitchModuleWidget);
  QPushButton* button = new QPushButton();
  button->setIcon(QIcon(iconPath));
  d->iconDisplayFrame->layout()->addWidget(button);
}
