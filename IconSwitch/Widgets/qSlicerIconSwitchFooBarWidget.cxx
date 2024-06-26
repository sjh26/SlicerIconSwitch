/*==============================================================================

  Program: 3D Slicer

  Copyright (c) Kitware Inc.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Jean-Christophe Fillion-Robin, Kitware Inc.
  and was partially funded by NIH grant 3P41RR013218-12S1

==============================================================================*/

// FooBar Widgets includes
#include "qSlicerIconSwitchFooBarWidget.h"
#include "ui_qSlicerIconSwitchFooBarWidget.h"

//-----------------------------------------------------------------------------
class qSlicerIconSwitchFooBarWidgetPrivate
  : public Ui_qSlicerIconSwitchFooBarWidget
{
  Q_DECLARE_PUBLIC(qSlicerIconSwitchFooBarWidget);
protected:
  qSlicerIconSwitchFooBarWidget* const q_ptr;

public:
  qSlicerIconSwitchFooBarWidgetPrivate(
    qSlicerIconSwitchFooBarWidget& object);
  virtual void setupUi(qSlicerIconSwitchFooBarWidget*);
};

// --------------------------------------------------------------------------
qSlicerIconSwitchFooBarWidgetPrivate
::qSlicerIconSwitchFooBarWidgetPrivate(
  qSlicerIconSwitchFooBarWidget& object)
  : q_ptr(&object)
{
}

// --------------------------------------------------------------------------
void qSlicerIconSwitchFooBarWidgetPrivate
::setupUi(qSlicerIconSwitchFooBarWidget* widget)
{
  this->Ui_qSlicerIconSwitchFooBarWidget::setupUi(widget);
}

//-----------------------------------------------------------------------------
// qSlicerIconSwitchFooBarWidget methods

//-----------------------------------------------------------------------------
qSlicerIconSwitchFooBarWidget
::qSlicerIconSwitchFooBarWidget(QWidget* parentWidget)
  : Superclass( parentWidget )
  , d_ptr( new qSlicerIconSwitchFooBarWidgetPrivate(*this) )
{
  Q_D(qSlicerIconSwitchFooBarWidget);
  d->setupUi(this);
}

//-----------------------------------------------------------------------------
qSlicerIconSwitchFooBarWidget
::~qSlicerIconSwitchFooBarWidget()
{
}
