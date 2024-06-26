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
#include <QResource>
#include <QSettings>

// Slicer includes
#include "qSlicerIconSwitchModuleWidget.h"
#include "ui_qSlicerIconSwitchModuleWidget.h"
#include "vtkSlicerIconSwitchLogic.h"


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
}

//-----------------------------------------------------------------------------
void qSlicerIconSwitchModuleWidget::useDarkIcon()
{
  QResource::unregisterResource(this->currentResource.c_str());
  vtkSlicerIconSwitchLogic* iconSwitchLogic = vtkSlicerIconSwitchLogic::SafeDownCast(this->logic());
  std::string path = iconSwitchLogic->GetDarkResourcePath();
  auto res = QResource::registerResource(path.c_str());
  this->currentResource = path;
}

//-----------------------------------------------------------------------------
void qSlicerIconSwitchModuleWidget::useLightIcon()
{
  QResource::unregisterResource(this->currentResource.c_str());
  vtkSlicerIconSwitchLogic* iconSwitchLogic = vtkSlicerIconSwitchLogic::SafeDownCast(this->logic());
  std::string path = iconSwitchLogic->GetLightResourcePath();
  auto res = QResource::registerResource(path.c_str());
  this->currentResource = path;
}


void qSlicerIconSwitchModuleWidget::registerDefaultResources()
{
  vtkSlicerIconSwitchLogic* iconSwitchLogic = vtkSlicerIconSwitchLogic::SafeDownCast(this->logic());
  std::string path = iconSwitchLogic->GetDefaultResourcePath();
  QResource::registerResource(path.c_str());
}
