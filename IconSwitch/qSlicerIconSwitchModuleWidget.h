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

#ifndef __qSlicerIconSwitchModuleWidget_h
#define __qSlicerIconSwitchModuleWidget_h

// Slicer includes
#include "qSlicerAbstractModuleWidget.h"

#include "qSlicerIconSwitchModuleExport.h"

class qSlicerIconSwitchModuleWidgetPrivate;
class vtkMRMLNode;

class Q_SLICER_QTMODULES_ICONSWITCH_EXPORT qSlicerIconSwitchModuleWidget :
  public qSlicerAbstractModuleWidget
{
  Q_OBJECT

public:

  typedef qSlicerAbstractModuleWidget Superclass;
  qSlicerIconSwitchModuleWidget(QWidget *parent=0);
  virtual ~qSlicerIconSwitchModuleWidget();

public slots:

  void useLightIcon();
  void useDarkIcon();


protected:
  QScopedPointer<qSlicerIconSwitchModuleWidgetPrivate> d_ptr;

  void setup() override;

private:
  Q_DECLARE_PRIVATE(qSlicerIconSwitchModuleWidget);
  Q_DISABLE_COPY(qSlicerIconSwitchModuleWidget);
  std::string currentResource;
};

#endif
