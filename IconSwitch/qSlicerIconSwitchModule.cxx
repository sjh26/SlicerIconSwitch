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

// IconSwitch Logic includes
#include <vtkSlicerIconSwitchLogic.h>

// IconSwitch includes
#include "qSlicerIconSwitchModule.h"
#include "qSlicerIconSwitchModuleWidget.h"

#include <QResource>
#include <QSettings>

//-----------------------------------------------------------------------------
class qSlicerIconSwitchModulePrivate
{
public:
  qSlicerIconSwitchModulePrivate();
};

//-----------------------------------------------------------------------------
// qSlicerIconSwitchModulePrivate methods

//-----------------------------------------------------------------------------
qSlicerIconSwitchModulePrivate::qSlicerIconSwitchModulePrivate()
{
}

//-----------------------------------------------------------------------------
// qSlicerIconSwitchModule methods

//-----------------------------------------------------------------------------
qSlicerIconSwitchModule::qSlicerIconSwitchModule(QObject* _parent)
  : Superclass(_parent)
  , d_ptr(new qSlicerIconSwitchModulePrivate)
{
}

//-----------------------------------------------------------------------------
qSlicerIconSwitchModule::~qSlicerIconSwitchModule()
{
}

//-----------------------------------------------------------------------------
QString qSlicerIconSwitchModule::helpText() const
{
  return "This is a loadable module that can be bundled in an extension";
}

//-----------------------------------------------------------------------------
QString qSlicerIconSwitchModule::acknowledgementText() const
{
  return "This work was partially funded by NIH grant NXNNXXNNNNNN-NNXN";
}

//-----------------------------------------------------------------------------
QStringList qSlicerIconSwitchModule::contributors() const
{
  QStringList moduleContributors;
  moduleContributors << QString("John Doe (AnyWare Corp.)");
  return moduleContributors;
}

//-----------------------------------------------------------------------------
QIcon qSlicerIconSwitchModule::icon() const
{
  return QIcon(":/Icons/IconSwitch.png");
}

//-----------------------------------------------------------------------------
QStringList qSlicerIconSwitchModule::categories() const
{
  return QStringList() << "Examples";
}

//-----------------------------------------------------------------------------
QStringList qSlicerIconSwitchModule::dependencies() const
{
  return QStringList();
}

//-----------------------------------------------------------------------------
void qSlicerIconSwitchModule::setup()
{
  this->Superclass::setup();

  vtkSlicerIconSwitchLogic* iconSwitchLogic = vtkSlicerIconSwitchLogic::SafeDownCast(this->logic());

  QSettings settingsApplication;
  QSettings settingsRegistry("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize", QSettings::NativeFormat);

  std::string resourcePath = iconSwitchLogic->GetModuleShareDirectory() + "/Icons/LightResource.rcc";

  if (settingsApplication.value("Styles/Style", "Slicer").toString() == "Dark Slicer")
  {
    resourcePath = iconSwitchLogic->GetModuleShareDirectory() + "/Icons/DarkResource.rcc";

  }
  else if (settingsApplication.value("Styles/Style", "Slicer").toString() == "Slicer")
  {
#ifdef Q_OS_WIN
    if (settingsRegistry.value("AppsUseLightTheme") == 0)
    {
      resourcePath = iconSwitchLogic->GetModuleShareDirectory() + "/Icons/DarkResource.rcc";
    }
#endif
  }
  QResource::registerResource(resourcePath.c_str());

}

//-----------------------------------------------------------------------------
qSlicerAbstractModuleRepresentation* qSlicerIconSwitchModule
::createWidgetRepresentation()
{
  return new qSlicerIconSwitchModuleWidget;
}

//-----------------------------------------------------------------------------
vtkMRMLAbstractLogic* qSlicerIconSwitchModule::createLogic()
{
  return vtkSlicerIconSwitchLogic::New();
}
