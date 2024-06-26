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

  QSettings settings;
  QSettings settingsRegistry("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize", QSettings::NativeFormat);

  vtkSlicerIconSwitchLogic* iconSwitchLogic = vtkSlicerIconSwitchLogic::SafeDownCast(this->logic());
  std::string path = iconSwitchLogic->GetLightResourcePath();
  
  if (settings.value("Styles/Style", "Slicer").toString() == "Dark Slicer")
  {
    path = iconSwitchLogic->GetDarkResourcePath();
    
  }
  else if (settings.value("Styles/Style", "Slicer").toString() == "Slicer")
  {
#ifdef Q_OS_WIN
    if (settingsRegistry.value("AppsUseLightTheme") == 0)
    {
      path = iconSwitchLogic->GetDarkResourcePath();
    }
#endif
  }

  

  auto res = QResource::registerResource(path.c_str());
  std::cout << "Resource registered: " << res << std::endl;


  d->setupUi(this);
  this->Superclass::setup();
}
