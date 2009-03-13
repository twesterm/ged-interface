#include "geditem.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"
#include "qiodevice.h"
#include "mainwindow.h"

void MainWindowClass::on_actionOpenFile_triggered()
{
  QStringList fileNames;
  QStringList tmpList;
  QFileDialog dialog(this);
  dialog.setFileMode(QFileDialog::AnyFile);
  dialog.setFileMode(QFileDialog::ExistingFiles);
  dialog.setDirectory("/User/tillwestermann/GED/images/");
  if (dialog.exec())
  {
     fileNames = dialog.selectedFiles();
      for (int i = 0; i < fileNames.size(); ++i)
     {
          GEDItem *newItem = new GEDItem;
          tmpList =  fileNames.at(i).split("/");
          if (tmpList.size()>1) { // true for all *nix systems
              newItem->setText(tmpList.at(tmpList.size()-1));
          } else { // here come the M$-World (prob. never tested)
              tmpList =  fileNames.at(i).split("\\");
              newItem->setText(tmpList.at(tmpList.size()-1));
          }
       //   newItem->setText(fileNames.at(i));
       //   newItem->setIPLA(fileNames.at(i));
          newItem->setPath(fileNames.at(i));
          ui->listWidget->insertItem(ui->listWidget->count(), newItem);
     }
  }
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

    QString newbildtext = link->getPath();
    QFile file(newbildtext);
    if (!file.open(QIODevice::ReadWrite))
    {
        QMessageBox::information( this, "Info", QString("Bild konnte nicht geöffnet werden."), "&Ok" );
       return;
    }

    QImage image(newbildtext);
    ui->picLabel->setPixmap(QPixmap::fromImage(image));


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
     void MainWindowClass::on_XSCATlineEdit_textEdited(QString text){
         if (ui->listWidget->count()>0)  {
       GEDItem *link = dynamic_cast <GEDItem*>(ui->listWidget->currentItem());
        if (text.length()>0){
            if (!link->setXSCAT(text)){
               QMessageBox::information( this, "Error", QString("You gave in a wrong type. Please check the box again (Don't use 0,2. Use 0.2, even if you are german)"), "&Ok" );
            } // of if setif
        } //of ifisEmpty
   }
}
     void MainWindowClass::on_YSCATlineEdit_textEdited(QString text){
         if (ui->listWidget->count()>0)  {
       GEDItem *link = dynamic_cast <GEDItem*>(ui->listWidget->currentItem());
        if (text.length()>0){
            if (!link->setYSCAT(text)){
               QMessageBox::information( this, "Error", QString("You gave in a wrong type. Please check the box again (Don't use 0,2. Use 0.2, even if you are german)"), "&Ok" );
            } // of if setif
        } //of ifisEmpty
   }
}
     void MainWindowClass::on_ANGLElineEdit_textEdited(QString text){
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
     void MainWindowClass::on_RMINTlineEdit_textEdited(QString text){
         if (ui->listWidget->count()>0)  {
            GEDItem *link = dynamic_cast <GEDItem*>(ui->listWidget->currentItem());
            if (text.length()>0){
               if (!link->setRMINT(text)){
                   QMessageBox::information( this, "Error", QString("You gave in a wrong type. Please check the box again (Don't use 0,2. Use 0.2, even if you are german)"), "&Ok" );
               } // of if setif
           } //of ifisEmpty
        }
    }
     void MainWindowClass::on_RMAXTlineEdit_textEdited(QString text){
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


