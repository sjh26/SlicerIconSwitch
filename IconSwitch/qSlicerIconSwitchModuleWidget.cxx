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

// Slicer includes
#include "qSlicerIconSwitchModuleWidget.h"
#include "ui_qSlicerIconSwitchModuleWidget.h"

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
