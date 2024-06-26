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
#include <QMessageBox>
#include <ctkMessageBox.h>

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
  , nextAvailableColumnForIconDisplay(0)
  , nextAvailableRowForIconDisplay(0)
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
  this->addIconDisplay(":/Icons/MarkupsAddAngle.svg");
  this->addIconDisplay(":/Icons/MarkupsAddLine.svg");
  this->addIconDisplay(":/Icons/MarkupsAddROI.svg");
  this->addIconDisplay(":/Icons/MarkupsAddClosedCurve.svg");
  this->addIconDisplay(":/Icons/MarkupsAddOpenCurve.svg");
  this->addIconDisplay(":/Icons/MarkupsAddPlane.svg");
  this->addIconDisplay(":/Icons/MarkupsAddPoint.svg");
  this->addIconDisplay(":/Icons/MarkupsAddPointList.svg");
  this->addIconDisplay(":/Icons/IconSwitch.png");
  this->addIconDisplay(":/Icons/Annotations.svg");
  this->addIconDisplay(":/Icons/DataModule.svg");
  this->addIconDisplay(":/Icons/DefaultModule.svg");
  this->addIconDisplay(":/Icons/MarkupsModule.svg");
  this->addIconDisplay(":/Icons/ModelsModule.svg");
  this->addIconDisplay(":/Icons/SegmentEditorModule.svg");
  this->addIconDisplay(":/Icons/TransformsModule.svg");
  this->addIconDisplay(":/Icons/VolumesModule.svg");
  this->addIconDisplay(":/Icons/WelcomeModule.svg");

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
  QString reason = "Would you like to restart 3D Slicer to reload style and icons?";
  ctkMessageBox* confirmDialog = new ctkMessageBox(this);
  confirmDialog->setText(reason);
  confirmDialog->setIcon(QMessageBox::Question);
  confirmDialog->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
  bool restartConfirmed = (confirmDialog->exec() == QMessageBox::Ok);
  confirmDialog->deleteLater();

  if (restartConfirmed)
  {
    qSlicerApplication::application()->restart();
  }
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
  QString reason = "Would you like to restart 3D Slicer to reload style and icons?";
  ctkMessageBox* confirmDialog = new ctkMessageBox(this);
  confirmDialog->setText(reason);
  confirmDialog->setIcon(QMessageBox::Question);
  confirmDialog->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
  bool restartConfirmed = (confirmDialog->exec() == QMessageBox::Ok);
  confirmDialog->deleteLater();

  if (restartConfirmed)
  {
    qSlicerApplication::application()->restart();
  }
}

//-----------------------------------------------------------------------------

void qSlicerIconSwitchModuleWidget::addIconDisplay(QString iconPath)
{
  Q_D(qSlicerIconSwitchModuleWidget);
  QPushButton* button = new QPushButton();
  button->setIcon(QIcon(iconPath));
  button->setToolTip(iconPath);
  d->iconDisplayFrame->addWidget(button, nextAvailableRowForIconDisplay, nextAvailableColumnForIconDisplay);

  nextAvailableColumnForIconDisplay++;
  if (nextAvailableColumnForIconDisplay > 2)
  {
    nextAvailableColumnForIconDisplay = 0;
    nextAvailableRowForIconDisplay++;
  }

}
