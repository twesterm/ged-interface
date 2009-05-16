/* Written by Till Westermann
   If you like this Software and we meet in person one day you can buy me a beer in return
   This Software is LGPL. See http://www.gnu.org/licenses/lgpl.html for further information */

 /* this File handles most of the signals from the main program, exept the integration(output.cpp) and the calc of the angle
    (mainwindow.cpp) */
#include "geditem.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"
#include "qiodevice.h"
#include "mainwindow.h"
 #include <QMouseEvent>
#include <QPixmap>
#include <iostream>
#include <fstream>
#include <QFileDialog>
#include <QStringList>
#include <QList>
#include <QFile>
#include <QTextStream>

//void QLabel::mousePressEvent( QMouseEvent * event ) {
//      ui->XNULLlineEdit->setText(QString::number(event->x()));
//}

void MainWindowClass::on_comboBox_currentIndexChanged(QString text) {
    this->setValuesByMethod(text);

 }



bool MainWindowClass::eventFilter( QObject * watched, QEvent * event ) { // this eventfilter handels the clicking on the picture
    if (watched != ui->picLabel) return false;
                QMouseEvent *e = dynamic_cast<QMouseEvent*> (event);
                if (e != 0 && e->type() == QEvent::MouseButtonPress) {
                    if (ui->listWidget->count()>0) {
                     GEDItem *link = dynamic_cast <GEDItem*>(ui->listWidget->currentItem());
                     // x/yscale scales it back to original res.
                     float xscale = (link->getIXMA().toInt())/(ui->picLabel->width());
                     float yscale = (link->getJYMA().toInt())/ui->picLabel->height();
                      float x1 = e->x()*xscale*link->getPIXEL().toFloat();
                      float y1 = e->y()*yscale*link->getPIXEL().toFloat();

                     if (ui->centerRadioButton->isChecked()) {
                        ui->XNULLlineEdit->setText(QString::number(x1));
                        ui->YNULLlineEdit->setText(QString::number(y1));
                        ui->StartRadioButton->setChecked(true);
                     } else if (ui->StartRadioButton->isChecked()) {
                         float x2 = link->getXNULL().toFloat();
                         float y2 = link->getYNULL().toFloat();
                         ui->RMINTlineEdit->setText(QString::number(link->distance(x1, x2, y1, y2)));
                         ui->EndRadioButton->setChecked(true);
                     } else if (ui->EndRadioButton->isChecked()) {
                         float x2 = link->getXNULL().toFloat();
                         float y2 = link->getYNULL().toFloat();
                         ui->RMAXTlineEdit->setText(QString::number(link->distance(x1, x2, y1, y2)));
                         ui->XSCATlineEdit->setText(QString::number(link->distance(x1, x2, y1, y2)));
                         ui->YSCATlineEdit->setText(QString::number(link->distance(x1, x2, y1, y2)));
                         link->setxRMAXT(QString::number(x1));
                         link->setyRMAXT(QString::number(y1));
                     //    link->setxAngle(QString::number(x1));
                     //    link->setyAngle(QString::number(y1));
                         if (link->getMode() == "none") {
                             ui->comboBox->setItemText(0, "Choose method");
                             ui->comboBox->setEnabled(true);
                         }
                         this->setValuesByMethod(ui->comboBox->currentText());
                       //  ui->AngleRadioButton->setChecked(true);

                     } /*else if (ui->AngleRadioButton->isChecked()){
                         link->setxAngle(QString::number(x1));
                         link->setyAngle(QString::number(y1));
                         if (link->getMode() == "none") {
                             ui->comboBox->setItemText(0, "Choose method");
                             ui->comboBox->setEnabled(true);
                         }
                         this->setValuesByMethod(ui->comboBox->currentText());
                     } */

                 }
                }
                if (e!=0 && ui->listWidget->count()>0 && ui->listWidget->currentRow() != -1 && e->type() == QEvent::MouseMove ) {
                          GEDItem *link = dynamic_cast <GEDItem*>(ui->listWidget->currentItem());
                          float xscale = (link->getIXMA().toInt())/(ui->picLabel->width());
                          float yscale = (link->getJYMA().toInt())/ui->picLabel->height();
                          float x1 = e->x()*xscale;
                          float y1 = e->y()*yscale;
                          ui->XPIXlabel->setText(QString::number(x1));
                          ui->YPIXlabel->setText(QString::number(y1));
                          ui->XMMlabel->setText(QString::number(link->scalePixel(x1, "x")));
                          ui->YMMlabel->setText(QString::number(link->scalePixel(y1, "y")));

                      }
                return false;



}

bool MainWindowClass::isIn(QString name) { // tests if we already have a item with this name
    if (ui->listWidget->count()>0) {
    for (int i=0; i<=ui->listWidget->count()-1;i++) {
                          GEDItem *ref = dynamic_cast <GEDItem*>(ui->listWidget->item(i));
                          if (ref->text() == name) {
                              return true;
                          }
    }

    }
    return false;
}
void MainWindowClass::on_SECFIpushButton_pressed() {
    QStringList fileName;
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setFileMode(QFileDialog::ExistingFile);
    dialog.setDirectory(".");
    if (dialog.exec()) {
        fileName = dialog.selectedFiles();
        ui->SECFIlineEdit->setText(fileName.at(0));
    }
}




void MainWindowClass::on_actionOpenFile_triggered()
{
  QStringList fileNames;
  QStringList tmpList;
  QFileDialog dialog(this);
  QString tmpString;
  QString tmp2String;
  QStringList tmpList2;
  int j;
  bool test;
  dialog.setFileMode(QFileDialog::AnyFile);
  dialog.setFileMode(QFileDialog::ExistingFiles);
  dialog.setNameFilter(tr("Images (*.tif)"));
  dialog.setDirectory(".");
  if (dialog.exec())
  {
     fileNames = dialog.selectedFiles();
      for (int i = 0; i < fileNames.size(); ++i)
     {
          GEDItem *newItem = new GEDItem;
          tmpList =  fileNames.at(i).split("/");
          if (tmpList.size()>1) { // true for all *nix systems
              tmpList2 = tmpList.at(tmpList.size()-1).split(".");
              if (tmpList2.size()>1) {
                  if (ui->listWidget->count()>0) {
                      test = true;
                      j = 0;
                      tmp2String = tmpList2.at(tmpList2.size()-2);
                      do {
                          test = this->isIn(tmp2String);
                          if (test) {
                              j++;
                              tmp2String = tmpList2.at(tmpList2.size()-2) + "_" + QString::number(j);
                          }
                      } while (test);
                  } else {
                      tmp2String = tmpList2.at(tmpList2.size()-2);
                  }
                  newItem->setText(tmp2String);
              }
          }
       //   newItem->setText(fileNames.at(i));
       //   newItem->setIPLA(fileNames.at(i));
          newItem->setPath(fileNames.at(i));

          ui->listWidget->insertItem(ui->listWidget->count(), newItem);
     }
   /*  if (ui->listWidget->count()>0) {
         ui->listWidget->setCurrentRow(0);
         emit ui->listWidget->itemClicked(ui->listWidget->currentItem());
     } */ //a nice test, but fails
  }
}

void MainWindowClass::on_UseCheckBox_clicked(bool state) {
     GEDItem *link = dynamic_cast <GEDItem*>(ui->listWidget->currentItem());
     link->setUseable(state);
}


void MainWindowClass::on_listWidget_itemClicked(QListWidgetItem *item) {
    GEDItem *link = dynamic_cast <GEDItem*>(item);
   // ui->IXMAlineEdit->setText(link->getIXMA());
   // ui->JYMAlineEdit->setText(link->getJYMA());
    ui->PIXELlineEdit->setText(link->getPIXEL());
    ui->XPIXFAlineEdit->setText(link->getXPIXFA());
    ui->YPIXFAlineEdit->setText(link->getYPIXFA());
    ui->XSCATlineEdit->setText(link->getXSCAT());
    ui->YSCATlineEdit->setText(link->getYSCAT());
    ui->ANGLElineEdit->setText(link->getANGLE());
    ui->XNULLlineEdit->setText(link->getXNULL());
    ui->YNULLlineEdit->setText(link->getYNULL());
    ui->RMINlineEdit->setText(link->getRMIN());
    ui->RMAXlineEdit->setText(link->getRMAX());
    ui->DRlineEdit->setText(link->getDR());
    ui->RMINTlineEdit->setText(link->getRMINT());
    ui->RMAXTlineEdit->setText(link->getRMAXT());
    ui->DRTlineEdit->setText(link->getDRT());
    ui->IRECOAlineEdit->setText(link->getIRECOA());
    ui->IRECOA2lineEdit->setText(link->getIRECOA2());
    ui->TUNEXPlineEdit->setText(link->getTUNEXP());
    ui->RADIlineEdit->setText(link->getRADI());
    ui->CADISTlineEdit->setText(link->getCADIST());
    ui->WAVElineEdit->setText(link->getWAVE());
    ui->DELTASlineEdit->setText(link->getDELTAS());
    ui->SEPLAlineEdit->setText(link->getSEPLA());
    ui->ISECTlineEdit->setText(link->getISECT());
    ui->UseCheckBox->setChecked(link->isUseable());
    ui->SECFIlineEdit->setText(link->getSECFI());

    QString newbildtext = link->getPath();
    QFile file(newbildtext);
    if (!file.open(QIODevice::ReadWrite))
    {
        QMessageBox::information( this, "Info", QString("Not able to open picture."), "&Ok" );
       return;
    }

    QImage image(newbildtext);
    link->setJYMA(QString::number(image.height()));
    link->setIXMA(QString::number(image.width()));
    ui->picLabel->setPixmap(QPixmap::fromImage(image));
    if (link->getMode() != "none") {

        for ( int i = 0; i< ui->comboBox->count(); i++) {
            if (ui->comboBox->itemText(i) == link->getMode()) {
                ui->comboBox->setEnabled(true);
                ui->comboBox->setCurrentIndex(i);
                this->setValuesByMethod(link->getMode());
            }
        }
    } else {
        ui->comboBox->setEnabled(false);
        ui->comboBox->setItemText(0, "Set Points first");
        ui->comboBox->setCurrentIndex(0);
    }
    ui->centerRadioButton->setChecked(true);
}

void MainWindowClass::on_RMINlineEdit_textEdited(QString text) {
    if (ui->listWidget->count()>0)  {
       GEDItem *link = dynamic_cast <GEDItem*>(ui->listWidget->currentItem());
        if (text.length()>0){
            if (!link->setRMIN(text)){
               QMessageBox::information( this, "Error", QString("You gave in a wrong type. Please check the box again (Don't use 0,2. Use 0.2, even if you are german)"), "&Ok" );
            } // of if setif
        } //of ifisEmpty
   }
}


     void MainWindowClass::on_PIXELlineEdit_textEdited(QString text ){
         if (ui->listWidget->count()>0)  {
       GEDItem *link = dynamic_cast <GEDItem*>(ui->listWidget->currentItem());
        if (text.length()>0){
            if (!link->setPIXEL(text)){
               QMessageBox::information( this, "Error", QString("You gave in a wrong type. Please check the box again (Don't use 0,2. Use 0.2, even if you are german)"), "&Ok" );
            } // of if setif
        } //of ifisEmpty
   }
}
     void MainWindowClass::on_XPIXFAlineEdit_textEdited(QString text){
         if (ui->listWidget->count()>0)  {
       GEDItem *link = dynamic_cast <GEDItem*>(ui->listWidget->currentItem());
        if (text.length()>0){
            if (!link->setXPIXFA(text)){
               QMessageBox::information( this, "Error", QString("You gave in a wrong type. Please check the box again (Don't use 0,2. Use 0.2, even if you are german)"), "&Ok" );
            } // of if setif
        } //of ifisEmpty
   }
}
     void MainWindowClass::on_YPIXFAlineEdit_textEdited(QString text){
         if (ui->listWidget->count()>0)  {
       GEDItem *link = dynamic_cast <GEDItem*>(ui->listWidget->currentItem());
        if (text.length()>0){
            if (!link->setYPIXFA(text)){
               QMessageBox::information( this, "Error", QString("You gave in a wrong type. Please check the box again (Don't use 0,2. Use 0.2, even if you are german)"), "&Ok" );
            } // of if setif
        } //of ifisEmpty
   }
}
     void MainWindowClass::on_XSCATlineEdit_textChanged(QString text){
         if (ui->listWidget->count()>0)  {
       GEDItem *link = dynamic_cast <GEDItem*>(ui->listWidget->currentItem());
        if (text.length()>0){
            if (!link->setXSCAT(text)){
               QMessageBox::information( this, "Error", QString("You gave in a wrong type. Please check the box again (Don't use 0,2. Use 0.2, even if you are german)"), "&Ok" );
            } // of if setif
        } //of ifisEmpty
   }
}
     void MainWindowClass::on_YSCATlineEdit_textChanged(QString text){
         if (ui->listWidget->count()>0)  {
       GEDItem *link = dynamic_cast <GEDItem*>(ui->listWidget->currentItem());
        if (text.length()>0){
            if (!link->setYSCAT(text)){
               QMessageBox::information( this, "Error", QString("You gave in a wrong type. Please check the box again (Don't use 0,2. Use 0.2, even if you are german)"), "&Ok" );
            } // of if setif
        } //of ifisEmpty
   }
}
     void MainWindowClass::on_ANGLElineEdit_textChanged(QString text){
         if (ui->listWidget->count()>0)  {
       GEDItem *link = dynamic_cast <GEDItem*>(ui->listWidget->currentItem());
        if (text.length()>0){
            if (!link->setANGLE(text)){
               QMessageBox::information( this, "Error", QString("You gave in a wrong type. Please check the box again (Don't use 0,2. Use 0.2, even if you are german)"), "&Ok" );
            } // of if setif
        } //of ifisEmpty
   }
}
     void MainWindowClass::on_XNULLlineEdit_textChanged(QString text){
         if (ui->listWidget->count()>0)  {
       GEDItem *link = dynamic_cast <GEDItem*>(ui->listWidget->currentItem());
        if (text.length()>0){
            if (!link->setXNULL(text)){
               QMessageBox::information( this, "Error", QString("You gave in a wrong type. Please check the box again (Don't use 0,2. Use 0.2, even if you are german)"), "&Ok" );
            } // of if setif
        } //of ifisEmpty
   }
}
     void MainWindowClass::on_YNULLlineEdit_textChanged(QString text){
         if (ui->listWidget->count()>0)  {
       GEDItem *link = dynamic_cast <GEDItem*>(ui->listWidget->currentItem());
        if (text.length()>0){
            if (!link->setYNULL(text)){
               QMessageBox::information( this, "Error", QString("You gave in a wrong type. Please check the box again (Don't use 0,2. Use 0.2, even if you are german)"), "&Ok" );
            } // of if setif
        } //of ifisEmpty
   }
}

     void MainWindowClass::on_RMAXlineEdit_textEdited(QString text){
         if (ui->listWidget->count()>0)  {
            GEDItem *link = dynamic_cast <GEDItem*>(ui->listWidget->currentItem());
            if (text.length()>0){
               if (!link->setRMAX(text)){
                   QMessageBox::information( this, "Error", QString("You gave in a wrong type. Please check the box again (Don't use 0,2. Use 0.2, even if you are german)"), "&Ok" );
               } // of if setif
           } //of ifisEmpty
        }
    }
     void MainWindowClass::on_DRlineEdit_textEdited(QString text){
         if (ui->listWidget->count()>0)  {
            GEDItem *link = dynamic_cast <GEDItem*>(ui->listWidget->currentItem());
            if (text.length()>0){
               if (!link->setDR(text)){
                   QMessageBox::information( this, "Error", QString("You gave in a wrong type. Please check the box again (Don't use 0,2. Use 0.2, even if you are german)"), "&Ok" );
               } // of if setif
           } //of ifisEmpty
        }
    }
     void MainWindowClass::on_RMINTlineEdit_textChanged(QString text){
         if (ui->listWidget->count()>0)  {
            GEDItem *link = dynamic_cast <GEDItem*>(ui->listWidget->currentItem());
            if (text.length()>0){
               if (!link->setRMINT(text)){
                   QMessageBox::information( this, "Error", QString("You gave in a wrong type. Please check the box again (Don't use 0,2. Use 0.2, even if you are german)"), "&Ok" );
               } // of if setif
           } //of ifisEmpty
        }
    }
     void MainWindowClass::on_RMAXTlineEdit_textChanged(QString text){
         if (ui->listWidget->count()>0)  {
            GEDItem *link = dynamic_cast <GEDItem*>(ui->listWidget->currentItem());
            if (text.length()>0){
               if (!link->setRMAXT(text)){
                   QMessageBox::information( this, "Error", QString("You gave in a wrong type. Please check the box again (Don't use 0,2. Use 0.2, even if you are german)"), "&Ok" );
               } // of if setif
           } //of ifisEmpty
        }
    }
     void MainWindowClass::on_DRTlineEdit_textEdited(QString text){
         if (ui->listWidget->count()>0)  {
            GEDItem *link = dynamic_cast <GEDItem*>(ui->listWidget->currentItem());
            if (text.length()>0){
               if (!link->setDRT(text)){
                   QMessageBox::information( this, "Error", QString("You gave in a wrong type. Please check the box again (Don't use 0,2. Use 0.2, even if you are german)"), "&Ok" );
               } // of if setif
           } //of ifisEmpty
        }
    }
     void MainWindowClass::on_TUNEXPlineEdit_textEdited(QString text){
         if (ui->listWidget->count()>0)  {
            GEDItem *link = dynamic_cast <GEDItem*>(ui->listWidget->currentItem());
            if (text.length()>0){
               if (!link->setTUNEXP(text)){
                   QMessageBox::information( this, "Error", QString("You gave in a wrong type. Please check the box again (Don't use 0,2. Use 0.2, even if you are german)"), "&Ok" );
               } // of if setif
           } //of ifisEmpty
        }
    }
     void MainWindowClass::on_RADIlineEdit_textEdited(QString text){
         if (ui->listWidget->count()>0)  {
            GEDItem *link = dynamic_cast <GEDItem*>(ui->listWidget->currentItem());
            if (text.length()>0){
               if (!link->setRADI(text)){
                   QMessageBox::information( this, "Error", QString("You gave in a wrong type. Please check the box again (Don't use 0,2. Use 0.2, even if you are german)"), "&Ok" );
               } // of if setif
           } //of ifisEmpty
        }
    }
     void MainWindowClass::on_CADISTlineEdit_textEdited(QString text){
         if (ui->listWidget->count()>0)  {
            GEDItem *link = dynamic_cast <GEDItem*>(ui->listWidget->currentItem());
            if (text.length()>0){
               if (!link->setCADIST(text)){
                   QMessageBox::information( this, "Error", QString("You gave in a wrong type. Please check the box again (Don't use 0,2. Use 0.2, even if you are german)"), "&Ok" );
               } // of if setif
           } //of ifisEmpty
        }
    }
     void MainWindowClass::on_WAVElineEdit_textEdited(QString text){
         if (ui->listWidget->count()>0)  {
            GEDItem *link = dynamic_cast <GEDItem*>(ui->listWidget->currentItem());
            if (text.length()>0){
               if (!link->setWAVE(text)){
                   QMessageBox::information( this, "Error", QString("You gave in a wrong type. Please check the box again (Don't use 0,2. Use 0.2, even if you are german)"), "&Ok" );
               } // of if setif
           } //of ifisEmpty
        }
    }
     void MainWindowClass::on_DELTASlineEdit_textEdited(QString text){
         if (ui->listWidget->count()>0)  {
            GEDItem *link = dynamic_cast <GEDItem*>(ui->listWidget->currentItem());
            if (text.length()>0){
               if (!link->setDELTAS(text)){
                   QMessageBox::information( this, "Error", QString("You gave in a wrong type. Please check the box again (Don't use 0,2. Use 0.2, even if you are german)"), "&Ok" );
               } // of if setif
           } //of ifisEmpty
        }
    }
     void MainWindowClass::on_IRECOAlineEdit_textEdited(QString text){
         if (ui->listWidget->count()>0)  {
            GEDItem *link = dynamic_cast <GEDItem*>(ui->listWidget->currentItem());
            if (text.length()>0){
               if (!link->setIRECOA(text)){
                   QMessageBox::information( this, "Error", QString("You gave in a wrong type. Please check the box again (Don't use 0,2. Use 0.2, even if you are german)"), "&Ok" );
               } // of if setif
           } //of ifisEmpty
        }
    }
     void MainWindowClass::on_IRECOA2lineEdit_textEdited(QString text){
         if (ui->listWidget->count()>0)  {
            GEDItem *link = dynamic_cast <GEDItem*>(ui->listWidget->currentItem());
            if (text.length()>0){
               if (!link->setIRECOA2(text)){
                   QMessageBox::information( this, "Error", QString("You gave in a wrong type. Please check the box again (Don't use 0,2. Use 0.2, even if you are german)"), "&Ok" );
               } // of if setif
           } //of ifisEmpty
        }
    }
     void MainWindowClass::on_SEPLAlineEdit_textEdited(QString text){
         if (ui->listWidget->count()>0)  {
            GEDItem *link = dynamic_cast <GEDItem*>(ui->listWidget->currentItem());
            if (text.length()>0){
               if (!link->setSEPLA(text)){
                   QMessageBox::information( this, "Error", QString("You gave in a wrong type. Please check the box again (Don't use 0,2. Use 0.2, even if you are german)"), "&Ok" );
               } // of if setif
           } //of ifisEmpty
        }
    }
     void MainWindowClass::on_ISECTlineEdit_textEdited(QString text){
         if (ui->listWidget->count()>0)  {
            GEDItem *link = dynamic_cast <GEDItem*>(ui->listWidget->currentItem());
            if (text.length()>0){
               if (!link->setISECT(text)){
                   QMessageBox::information( this, "Error", QString("You gave in a wrong type. Please check the box again (Don't use 0,2. Use 0.2, even if you are german)"), "&Ok" );
               } // of if setif
           } //of ifisEmpty
        }
    }

    void MainWindowClass::on_StartRadioButton_clicked(){ //tests if we have a center for the distance
        if (ui->listWidget->count()>0) {
           GEDItem *link = dynamic_cast <GEDItem*>(ui->listWidget->currentItem());
           if (link->getXNULL().toFloat()==0.0) {
               QMessageBox::information( this, "Error", QString("Please give a center first.)"), "&Ok" );
               ui->centerRadioButton->setChecked(true);
           }
       }
    }
       void MainWindowClass::on_EndRadioButton_clicked(){ //tests if we have a center for the distance
        if (ui->listWidget->count()>0) {
           GEDItem *link = dynamic_cast <GEDItem*>(ui->listWidget->currentItem());
           if (link->getXNULL().toFloat()==0.0) {
               QMessageBox::information( this, "Error", QString("Please give a center first.)"), "&Ok" );
               ui->centerRadioButton->setChecked(true);
           }
       }
    }


      void MainWindowClass::on_BeamPushButton_pressed(){
      if (ui->listWidget->count()>0) {
          GEDItem *ref = dynamic_cast <GEDItem*>(ui->listWidget->currentItem());
          for (int i=0; i<ui->listWidget->count(); i++) {
              GEDItem *link = dynamic_cast <GEDItem*>(ui->listWidget->item(i));
              link->setCADIST(ref->getCADIST());
              link->setWAVE(ref->getWAVE());
              link->setDELTAS(ref->getDELTAS());
          }


      }
    }

      void MainWindowClass::on_AdvPushButton_pressed(){
      if (ui->listWidget->count()>0) {
          GEDItem *ref = dynamic_cast <GEDItem*>(ui->listWidget->currentItem());
          for (int i=0; i<ui->listWidget->count(); i++) {
              GEDItem *link = dynamic_cast <GEDItem*>(ui->listWidget->item(i));
              link->setPIXEL(ref->getPIXEL());
              link->setXPIXFA(ref->getXPIXFA());
              link->setYPIXFA(ref->getYPIXFA());
              link->setIRECOA(ref->getIRECOA());
              link->setIRECOA2(ref->getIRECOA2());
              link->setTUNEXP(ref->getTUNEXP());
              link->setRADI(ref->getRADI());
              link->setSEPLA(ref->getSEPLA());
              link->setISECT(ref->getISECT());
              link->setSECFI(ref->getSECFI());
          }


      }
    }

      void MainWindowClass::on_SECFIlineEdit_textChanged(QString text){
         if (ui->listWidget->count()>0)  {
       GEDItem *link = dynamic_cast <GEDItem*>(ui->listWidget->currentItem());
        if (text.length()>0){
            link->setSECFI(text);

        } //of ifisEmpty
   }
}
using namespace std;
    void MainWindowClass::on_IntegratePushButton_pressed() {
        if (ui->listWidget->count()>0) {
            if (this->outputDir=="none") {
                     QFileDialog dialog(this);
                     QString fileName;
                     dialog.setFileMode(QFileDialog::Directory);
                     dialog.setDirectory(".");
                     if (dialog.exec())
                      {
                        this->outputDir = dialog.selectedFiles().at(0) + "/";
                    }
            }
            if (ui->IntegrateAllRadioButton->isChecked()) {
                for (int i=0; i<ui->listWidget->count();i++) {
                    GEDItem *ref = dynamic_cast <GEDItem*>(ui->listWidget->item(i));
                    this->fileList.append(ref->writeInputFile(this->outputDir));
                }
            } else if (ui->IntegrteUsableRadioButton->isChecked()) {
                for (int i=0; i<ui->listWidget->count();i++) {
                    GEDItem *ref = dynamic_cast <GEDItem*>(ui->listWidget->item(i));
                    if (ref->isUseable()) {
                       this->fileList.append(ref->writeInputFile(this->outputDir));
                   }
                }
            } else if (ui->IntegrateSelectedRadioButton->isChecked()) {
                QList<QListWidgetItem*> list = ui->listWidget->selectedItems();
                for (int i=0; i<list.size(); i++) {
                    GEDItem *ref = dynamic_cast <GEDItem*>(list.at(i));
                    this->fileList.append(ref->writeInputFile(this->outputDir));
                }
            }
            QString scriptFile = this->outputDir + "reduce.sh";
            QFile myfile(scriptFile);
             if (myfile.open(QIODevice::WriteOnly | QIODevice::Text)){
                 QTextStream out(&myfile);
                 out <<"#/bin/sh" << "\n";
         //        out << "if [ -e pimag ]; then \n";
                 out << "for each in ";
                 for (int i=0; i<this->fileList.size(); i++){
                     out << this->fileList.at(i) + " ";
                 }
                 out << " \n do \n cp $each pimag.txt \n";
                 out << "pimag \n";
                 out << "done \n";
       //          out << "printf 'pimag not found, plase copy it'";
      //           out << "\n fi";

                 myfile.close();
             }
             this->fileList.clear();
             this->outputDir="none";

        }
    }

    void MainWindowClass::on_actionLicenceAuthor_triggered() {
        QMessageBox msgBox;
        msgBox.setText("This software is LGPL (see: http://www.gnu.org/copyleft/lesser.html). \n Written by Till Wesermann \n University of Bielefeld \n Group of Prof. Mitzel,Chair of Inorganic & Structural Chemistry \n eMail: till@tillwestermann.de \n If we meet some day, you can buy me a drink.");
         msgBox.exec();
         //QMessageBox::information( this, "Info", QString("This software is LGPL (see: http://www.gnu.org/copyleft/lesser.html). \n Written by Till Wesermann \n Group of Prof. Mitzel,Chair of Inorganic & Structural Chemistry \n University of Bielefeld \n eMail: till@tillwestermann.de \n Chair for  If we meet some day, you can buy me a drink."), "&Ok" );
     }
    void MainWindowClass::on_actionSet_output_directory_triggered() {
          QFileDialog dialog(this);
          QString fileName;

           dialog.setFileMode(QFileDialog::Directory);
      //    dialog.setOption(ShowDirsOnly, true);
          dialog.setDirectory(".");
          if (dialog.exec())
             {
               this->outputDir = dialog.selectedFiles().at(0) + "/";
              // std::cout << this->outputDir.toStdString() << std::endl;
           }
   }





