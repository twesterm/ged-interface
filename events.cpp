#include "geditem.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"
#include "qiodevice.h"

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

